/* x86 SIMD values stay addressable on the value stack.  This deliberately
   avoids treating a 128-bit value as either a scalar or two independent XMMs. */
#include "include/tccsimd.h"

enum { SB_BINARY, SB_UNARY, SB_IMM, SB_SHIFT, SB_LOAD, SB_STORE,
       SB_MASK, SB_INTIN, SB_INTOUT, SB_LDMXCSR, SB_STMXCSR, SB_FENCE,
       SB_MASKSTORE, SB_MERGE_LOAD, SB_INSERT, SB_EXTRACT, SB_COMI,
       SB_CACHE, SB_STREAMINT, SB_RAW, SB_MMX_BINARY, SB_MMX_SHIFT,
       SB_MMX_IMM, SB_MMX_INSERT, SB_MMX_EXTRACT, SB_MMX_MASK,
       SB_MMX_STORE, SB_MMX_MASKSTORE, SB_XMM_MMX };
typedef struct SimdBuiltin {
    unsigned opcode;
    unsigned char mode, group, wide;
} SimdBuiltin;
#define SIMD_ENTRY(name, opcode, mode, group, wide) { opcode, mode, group, wide },
static const SimdBuiltin simd_builtins[] = {
    __TCC_SIMD_OPS(SIMD_ENTRY)
};
#undef SIMD_ENTRY

ST_FUNC int simd_aligned_local(int size, int align)
{
    int area, slot;
    loc = (loc - size - align + 1) & -PTR_SIZE;
    area = loc;
    slot = loc -= PTR_SIZE;
    vseti(VT_LOCAL | VT_LVAL, slot);
    vseti(VT_LOCAL, area + align - 1);
    vpushi(-align);
    gen_op('&');
    vstore();
    vpop();
    return slot;
}

ST_FUNC void simd_temp(CType *type, SValue *value)
{
    int size, align;
    size = type_size(type, &align);
#ifdef TCC_TARGET_I386
    vset(type, VT_LLOCAL | VT_LVAL, simd_aligned_local(size, align));
#else
    loc = (loc - size) & -align;
    vset(type, VT_LOCAL | VT_LVAL, loc);
#endif
    *value = *vtop--;
}

/* Transfer a full register to/from an addressable C value.  Only integer
   address registers are allocated, so previously loaded XMM arguments survive. */
ST_FUNC void simd_transfer(int xmm, SValue *value, int store_value)
{
    int r, bt = value->type.t & VT_BTYPE;
#ifdef TCC_TARGET_X86_64
    if (tcc_state->nosse)
        tcc_error("SSE disabled");
#endif
    vpushv(value);
    gaddrof();
    vtop->type.t = VT_PTR;
    r = gv(RC_INT);
#ifdef TCC_TARGET_I386
    if (value->type.t & VT_MMX) {
        gen_simd_mem(store_value ? 0x7f0f : 0x6f0f, xmm, r, 0);
        /* C uses x87 on i386. Once the value is homed, release the MMX tags;
           EMMS leaves the payloads of other incoming MM registers intact. */
        if (store_value) o(0x770f);
    }
    else
#endif
    if (bt == VT_FLOAT || bt == VT_DOUBLE)
        gen_simd_mem(((store_value ? 0x110f : 0x100f) << 8)
                     | (bt == VT_FLOAT ? 0xf3 : 0xf2), xmm, r, 0);
    else
        gen_simd_mem(store_value ? 0x110f : 0x100f, xmm, r, 0);
    vpop();
}

static void simd_pointer_mem(int opcode, int reg, SValue *pointer, int wide)
{
    int r;
    vpushv(pointer);
    r = gv(RC_INT);
    gen_simd_mem(opcode, reg, r, wide);
    vpop();
}

/* Save the integer result before allocating its destination address. */
static void simd_integer_result(SValue *out, int wide)
{
    CType type;
    SValue result;
    int r;
    type.t = wide ? VT_LLONG : VT_INT;
    type.ref = NULL;
    loc = (loc - 8) & -8;
    vset(&type, VT_LOCAL | VT_LVAL, loc);
    store(REG_IRET, vtop);
    result = *vtop--;
    vpushv(out);
    r = gv(RC_INT);
    vtop->type = type;
    vtop->r = r | VT_LVAL;
    vpushv(&result);
    vstore();
    vpop();
}

/* Internal, checked primitive used by the intrinsic headers:
   __builtin_tcc_simd(operation, destination, source1, source2, immediate).
   Pointers are evaluated once; operation and immediate must be constants.
   The operation table is shared with the installed headers. */
static void simd_builtin(void)
{
    const SimdBuiltin *b;
    int id, imm, i, r, mmx, result_size;
    SValue *out, *a, *c;
    next();
    skip('(');
    id = expr_const();
    if ((unsigned)id >= sizeof(simd_builtins) / sizeof(simd_builtins[0]))
        tcc_error("invalid SIMD builtin operation");
    b = &simd_builtins[id];
    for (i = 0; i < 3; ++i) {
        skip(',');
        expr_eq();
        if ((vtop->type.t & VT_BTYPE) != VT_PTR && !is_null_pointer(vtop))
            tcc_error("SIMD builtin requires pointer operands");
        if (i == 0 && (vtop->type.t & VT_BTYPE) == VT_PTR
            && (pointed_type(&vtop->type)->t & VT_CONSTANT))
            tcc_error("SIMD builtin destination is const");
        vtop->type.t = VT_PTR;
    }
    skip(',');
    imm = expr_const();
    if ((unsigned)imm > 255)
        tcc_error("SIMD immediate must be in the range 0..255");
    skip(')');
    if (b->mode == SB_IMM && b->group == 7 && imm > 7)
        tcc_error("SSE comparison predicate must be in the range 0..7 (AVX predicates unsupported)");
    if (b->mode == SB_CACHE && b->group == 255 && imm > 3)
        tcc_error("SSE prefetch hint must be in the range 0..3");
    if ((b->mode == SB_INSERT || b->mode == SB_EXTRACT
         || b->mode == SB_MMX_INSERT || b->mode == SB_MMX_EXTRACT)
        && imm > b->group)
        tcc_error("SIMD lane index out of range");
#ifdef TCC_TARGET_I386
    if (b->wide)
        tcc_error("64-bit SIMD integer operation requires x86-64");
#else
    if (tcc_state->nosse)
        tcc_error("SSE disabled");
#endif
    if (!nocode_wanted) {
        save_regs(0);
        out = vtop - 2;
        a = vtop - 1;
        c = vtop;
        mmx = b->mode >= SB_MMX_BINARY && b->mode <= SB_MMX_MASKSTORE;
        result_size = mmx || b->mode == SB_XMM_MMX ? 8 : 16;
        if (b->mode == SB_RAW) {
            o(b->opcode);
            result_size = 0;
        } else if (b->mode == SB_CACHE) {
            simd_pointer_mem(b->opcode, b->group == 255 ? imm : b->group, a, 0);
            result_size = 0;
        } else if (b->mode == SB_STREAMINT) {
            vpushv(a);
            r = gv(RC_INT);
            vtop->type.t = b->wide ? VT_LLONG : VT_INT;
            vtop->r = r | VT_LVAL;
            r = gv(RC_INT);
            simd_pointer_mem(b->opcode, r, out, b->wide);
            vpop();
            result_size = 0;
        } else if (b->mode == SB_LOAD) {
            simd_pointer_mem(b->opcode, 0, a, b->wide);
        } else if (b->mode == SB_LDMXCSR) {
            simd_pointer_mem(0xae0f, 2, a, 0);
            result_size = 0;
        } else if (b->mode == SB_STMXCSR) {
            simd_pointer_mem(0xae0f, 3, out, 0);
            result_size = 0;
        } else if (b->mode == SB_FENCE) {
            o(0xae0f); o(0xc0 | (b->group << 3));
            result_size = 0;
        } else {
            simd_pointer_mem(mmx ? 0x6f0f : 0x100f, 0, a, 0);
            if (b->mode == SB_STORE || b->mode == SB_MMX_STORE) {
                simd_pointer_mem(b->opcode, 0, out, b->wide);
                result_size = 0;
            } else if (b->mode == SB_INTIN || b->mode == SB_MERGE_LOAD
                       || b->mode == SB_INSERT || b->mode == SB_MMX_INSERT) {
                simd_pointer_mem(b->opcode, 0, c, b->wide);
                if (b->mode == SB_INSERT || b->mode == SB_MMX_INSERT)
                    g(imm);
            } else if (b->mode == SB_COMI) {
                simd_pointer_mem(0x100f, 1, c, 0);
                o(b->opcode); o(0xc1);
                /* Ordered EQ/LT/LE and unordered NE, matching C/Intel semantics. */
                o(0x0f); o(0x90 | b->group); o(0xc0);
                if (b->group == 4 || b->group == 2 || b->group == 6) {
                    o(0xc29b0f); /* setnp dl */
                    o(0xd020);   /* and dl,al */
                } else if (b->group == 5) {
                    o(0xc29a0f); /* setp dl */
                    o(0xd008);   /* or dl,al */
                }
                o(0xc0b60f);
                simd_integer_result(out, 0);
                result_size = 0;
            } else if (b->mode == SB_MASK || b->mode == SB_INTOUT
                       || b->mode == SB_EXTRACT || b->mode == SB_MMX_EXTRACT
                       || b->mode == SB_MMX_MASK) {
                if (b->wide) o(b->opcode & 255), o(0x48), o(b->opcode >> 8);
                else o(b->opcode);
                o(0xc0);
                if (b->mode == SB_EXTRACT || b->mode == SB_MMX_EXTRACT)
                    g(imm);
                simd_integer_result(out, b->wide);
                result_size = 0;
            } else if (b->mode == SB_MASKSTORE || b->mode == SB_MMX_MASKSTORE) {
                simd_pointer_mem(mmx ? 0x6f0f : 0x100f, 1, c, 0);
                vpushv(out);
                r = gv(RC_INT);
                o(0x57); /* preserve (r)di */
#ifdef TCC_TARGET_X86_64
                o(0x48 | ((r >> 3) << 2));
#endif
                o(0x89); o(0xc7 | ((r & 7) << 3));
                o(b->opcode); o(0xc1);
                o(0x5f);
                vpop();
                result_size = 0;
            } else {
                if (b->mode == SB_BINARY || b->mode == SB_IMM || b->mode == SB_MMX_BINARY)
                    simd_pointer_mem(mmx ? 0x6f0f : 0x100f, 1, c, 0);
                o(b->opcode);
                if (b->mode == SB_SHIFT || b->mode == SB_MMX_SHIFT)
                    o(0xc0 | (b->group << 3));
                else if (b->mode == SB_UNARY || b->mode == SB_MMX_IMM || b->mode == SB_XMM_MMX)
                    o(0xc0);
                else
                    o(0xc1);
                if (b->mode == SB_IMM || b->mode == SB_SHIFT
                    || b->mode == SB_MMX_SHIFT || b->mode == SB_MMX_IMM)
                    g(imm);
            }
        }
        if (result_size)
            simd_pointer_mem(result_size == 8 ? 0x7f0f : 0x110f, 0, out, 0);
        if (mmx || b->mode == SB_XMM_MMX)
            o(0x770f); /* values are in memory; allow subsequent scalar C */
    }
    vtop -= 3;
    vpushi(0);
    vtop->type.t = VT_VOID;
}
