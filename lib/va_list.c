/* va_list.c - tinycc support for va_list on X86_64 */

#if defined __x86_64__

/* Avoid include files, they may not be available when cross compiling */
extern void abort(void);

/* This should be in sync with our include/stdarg.h */
enum __va_arg_type {
    __va_gen_reg, __va_float_reg, __va_stack, __va_vector_reg, __va_mixed_is, __va_mixed_si
};

/* GCC compatible definition of va_list. */
/*predefined by TCC (tcc_predefs.h):
typedef struct {
    unsigned int gp_offset;
    unsigned int fp_offset;
    union {
        unsigned int overflow_offset;
        char *overflow_arg_area;
    };
    char *reg_save_area;
} __builtin_va_list[1];
*/

extern void *memcpy(void *dest, const void *src, unsigned long n);

void *__va_arg(__builtin_va_list ap,
               int arg_type,
               int size, int align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    switch ((enum __va_arg_type)arg_type) {
    case __va_gen_reg:
        if (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            return ap->reg_save_area + ap->gp_offset - size;
        }
        goto use_overflow_area;

    case __va_vector_reg:
        if (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            return ap->reg_save_area + ap->fp_offset - 16;
        }
        goto use_overflow_area;

    case __va_float_reg:
        if (ap->fp_offset + (size == 8 ? 16 : 32) <= 176) {
            ap->fp_offset += 16;
            if (size == 8)
                return ap->reg_save_area + ap->fp_offset - 16;
            if (ap->fp_offset < 128 + 48) {
                memcpy(ap->reg_save_area + ap->fp_offset - 8,
                       ap->reg_save_area + ap->fp_offset, 8);
                ap->fp_offset += 16;
                return ap->reg_save_area + ap->fp_offset - 32;
            }
        }
        goto use_overflow_area;

    case __va_stack:
    use_overflow_area:
        ap->overflow_arg_area = (char*)((long long)(ap->overflow_arg_area + align - 1) & -align);
        ap->overflow_arg_area += size;
        return ap->overflow_arg_area - size;

    default: /* should never happen */
        abort();
        return 0;
    }
}
/* Mixed arguments need caller-owned storage: modifying the saved source
   registers would make a va_copy traversal observe corrupted values. */
void *__va_arg_mixed(__builtin_va_list ap, int kind, int align, void *dest)
{
    char *p = dest;
    int io = kind == __va_mixed_is ? 0 : 8;
    if (ap->gp_offset < 48 && ap->fp_offset < 176) {
        memcpy(p + io, ap->reg_save_area + ap->gp_offset, 8);
        memcpy(p + 8 - io, ap->reg_save_area + ap->fp_offset, 8);
        ap->gp_offset += 8;
        ap->fp_offset += 16;
        return p;
    }
    return __va_arg(ap, __va_stack, 16, align);
}
#endif
