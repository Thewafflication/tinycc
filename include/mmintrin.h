/* MMX interfaces. Call _mm_empty before using x87 floating point after MMX. */
#ifndef _MMINTRIN_H_INCLUDED
#define _MMINTRIN_H_INCLUDED
#if !defined(__i386__) && !defined(__x86_64__)
#error MMX intrinsics require an x86 target
#endif
#include <tccsimd.h>
typedef __builtin_tcc_m64 __m64;
typedef union { __m64 v; long long q; int d[2]; short w[4]; signed char b[8]; } __tcc_m64;
static __inline__ __m64 _mm_cvtsi64_m64(long long x) { __tcc_m64 r; r.q=x; return r.v; }
static __inline__ long long _mm_cvtm64_si64(__m64 a) { __tcc_m64 r; r.v=a; return r.q; }
static __inline__ __m64 _mm_cvtsi32_si64(int x) { return _mm_cvtsi64_m64((unsigned int)x); }
static __inline__ int _mm_cvtsi64_si32(__m64 a) { __tcc_m64 r; r.v=a; return r.d[0]; }
static __inline__ __m64 _mm_setzero_si64(void) { return _mm_cvtsi64_m64(0); }
static __inline__ __m64 _mm_set_pi32(int x1,int x0) { __tcc_m64 r; r.d[0]=x0; r.d[1]=x1; return r.v; }
static __inline__ __m64 _mm_setr_pi32(int x0,int x1) { return _mm_set_pi32(x1,x0); }
static __inline__ __m64 _mm_set1_pi32(int x) { return _mm_set_pi32(x,x); }
static __inline__ __m64 _mm_set_pi16(short x3,short x2,short x1,short x0) { __tcc_m64 r; r.w[0]=x0; r.w[1]=x1; r.w[2]=x2; r.w[3]=x3; return r.v; }
static __inline__ __m64 _mm_setr_pi16(short x0,short x1,short x2,short x3) { return _mm_set_pi16(x3,x2,x1,x0); }
static __inline__ __m64 _mm_set1_pi16(short x) { return _mm_set_pi16(x,x,x,x); }
static __inline__ __m64 _mm_set_pi8(signed char x7,signed char x6,signed char x5,signed char x4,signed char x3,signed char x2,signed char x1,signed char x0) { __tcc_m64 r; r.b[0]=x0; r.b[1]=x1; r.b[2]=x2; r.b[3]=x3; r.b[4]=x4; r.b[5]=x5; r.b[6]=x6; r.b[7]=x7; return r.v; }
static __inline__ __m64 _mm_setr_pi8(signed char x0,signed char x1,signed char x2,signed char x3,signed char x4,signed char x5,signed char x6,signed char x7) { return _mm_set_pi8(x7,x6,x5,x4,x3,x2,x1,x0); }
static __inline__ __m64 _mm_set1_pi8(signed char x) { return _mm_set_pi8(x,x,x,x,x,x,x,x); }
static __inline__ __m64 _mm_add_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_add_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_add_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_add_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_add_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_add_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_add_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_add_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sub_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sub_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sub_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sub_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sub_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sub_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sub_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sub_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_adds_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_adds_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_adds_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_adds_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_adds_pu8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_adds_pu8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_adds_pu16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_adds_pu16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_subs_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_subs_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_subs_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_subs_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_subs_pu8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_subs_pu8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_subs_pu16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_subs_pu16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_and_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_and_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_andnot_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_andnot_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_or_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_or_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_xor_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_xor_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cmpeq_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cmpeq_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cmpeq_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cmpeq_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cmpeq_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cmpeq_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cmpgt_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cmpgt_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cmpgt_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cmpgt_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cmpgt_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cmpgt_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_mulhi_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_mulhi_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_mullo_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_mullo_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_madd_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_madd_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_mul_su32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_mul_su32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_packs_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_packs_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_packs_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_packs_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_packs_pu16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_packs_pu16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_unpacklo_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_unpacklo_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_unpacklo_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_unpackhi_pi8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_pi8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_unpackhi_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_unpackhi_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_avg_pu8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_avg_pu8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_avg_pu16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_avg_pu16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_max_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_max_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_max_pu8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_max_pu8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_min_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_min_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_min_pu8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_min_pu8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_mulhi_pu16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_mulhi_pu16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sad_pu8(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sad_pu8, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sll_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sll_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sll_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sll_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sll_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sll_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_srl_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_srl_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_srl_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_srl_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_srl_si64(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_srl_si64, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sra_pi16(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sra_pi16, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_sra_pi32(__m64 a, __m64 b) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_sra_pi32, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_slli_pi16(__m64 a, int n) { return _mm_sll_pi16(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_slli_pi32(__m64 a, int n) { return _mm_sll_pi32(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_slli_si64(__m64 a, int n) { return _mm_sll_si64(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_srli_pi16(__m64 a, int n) { return _mm_srl_pi16(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_srli_pi32(__m64 a, int n) { return _mm_srl_pi32(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_srli_si64(__m64 a, int n) { return _mm_srl_si64(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_srai_pi16(__m64 a, int n) { return _mm_sra_pi16(a,_mm_cvtsi32_si64(n)); }
static __inline__ __m64 _mm_srai_pi32(__m64 a, int n) { return _mm_sra_pi32(a,_mm_cvtsi32_si64(n)); }
static __inline__ void _mm_empty(void) { __builtin_tcc_simd(__TCC_S__mm_empty, 0,0,0,0); }
#define _mm_extract_pi16(a,i) __extension__ ({ __m64 __a=(a); int __r; __builtin_tcc_simd(__TCC_S__mm_extract_pi16,&__r,&__a,0,(i)); __r; })
#define _mm_insert_pi16(a,b,i) __extension__ ({ __m64 __a=(a),__r; int __b=(b); __builtin_tcc_simd(__TCC_S__mm_insert_pi16,&__r,&__a,&__b,(i)); __r; })
#define _mm_shuffle_pi16(a,i) __extension__ ({ __m64 __a=(a),__r; __builtin_tcc_simd(__TCC_S__mm_shuffle_pi16,&__r,&__a,0,(i)); __r; })
static __inline__ int _mm_movemask_pi8(__m64 a) { int r; __builtin_tcc_simd(__TCC_S__mm_movemask_pi8, &r,&a,0,0); return r; }
static __inline__ void _mm_stream_pi(__m64 *p,__m64 a) { __builtin_tcc_simd(__TCC_S__mm_stream_pi, p,&a,0,0); }
static __inline__ void _mm_maskmove_si64(__m64 a,__m64 mask,char *p) { __builtin_tcc_simd(__TCC_S__mm_maskmove_si64, p,&a,&mask,0); }
#define _m_empty _mm_empty
#define _m_from_int _mm_cvtsi32_si64
#define _m_from_int64 _mm_cvtsi64_m64
#define _m_to_int _mm_cvtsi64_si32
#define _m_to_int64 _mm_cvtm64_si64
#define _m_packsswb _mm_packs_pi16
#define _m_packssdw _mm_packs_pi32
#define _m_packuswb _mm_packs_pu16
#define _m_punpckhbw _mm_unpackhi_pi8
#define _m_punpckhwd _mm_unpackhi_pi16
#define _m_punpckhdq _mm_unpackhi_pi32
#define _m_punpcklbw _mm_unpacklo_pi8
#define _m_punpcklwd _mm_unpacklo_pi16
#define _m_punpckldq _mm_unpacklo_pi32
#define _m_paddb _mm_add_pi8
#define _m_paddw _mm_add_pi16
#define _m_paddd _mm_add_pi32
#define _m_paddsb _mm_adds_pi8
#define _m_paddsw _mm_adds_pi16
#define _m_paddusb _mm_adds_pu8
#define _m_paddusw _mm_adds_pu16
#define _m_psubb _mm_sub_pi8
#define _m_psubw _mm_sub_pi16
#define _m_psubd _mm_sub_pi32
#define _m_psubsb _mm_subs_pi8
#define _m_psubsw _mm_subs_pi16
#define _m_psubusb _mm_subs_pu8
#define _m_psubusw _mm_subs_pu16
#define _m_pmaddwd _mm_madd_pi16
#define _m_pmulhw _mm_mulhi_pi16
#define _m_pmullw _mm_mullo_pi16
#define _m_psllw _mm_sll_pi16
#define _m_psllwi _mm_slli_pi16
#define _m_pslld _mm_sll_pi32
#define _m_pslldi _mm_slli_pi32
#define _m_psllq _mm_sll_si64
#define _m_psllqi _mm_slli_si64
#define _m_psraw _mm_sra_pi16
#define _m_psrawi _mm_srai_pi16
#define _m_psrad _mm_sra_pi32
#define _m_psradi _mm_srai_pi32
#define _m_psrlw _mm_srl_pi16
#define _m_psrlwi _mm_srli_pi16
#define _m_psrld _mm_srl_pi32
#define _m_psrldi _mm_srli_pi32
#define _m_psrlq _mm_srl_si64
#define _m_psrlqi _mm_srli_si64
#define _m_pand _mm_and_si64
#define _m_pandn _mm_andnot_si64
#define _m_por _mm_or_si64
#define _m_pxor _mm_xor_si64
#define _m_pcmpeqb _mm_cmpeq_pi8
#define _m_pcmpeqw _mm_cmpeq_pi16
#define _m_pcmpeqd _mm_cmpeq_pi32
#define _m_pcmpgtb _mm_cmpgt_pi8
#define _m_pcmpgtw _mm_cmpgt_pi16
#define _m_pcmpgtd _mm_cmpgt_pi32
#define _m_pextrw _mm_extract_pi16
#define _m_pinsrw _mm_insert_pi16
#define _m_pmaxsw _mm_max_pi16
#define _m_pmaxub _mm_max_pu8
#define _m_pminsw _mm_min_pi16
#define _m_pminub _mm_min_pu8
#define _m_pmovmskb _mm_movemask_pi8
#define _m_pmulhuw _mm_mulhi_pu16
#define _m_pshufw _mm_shuffle_pi16
#define _m_maskmovq _mm_maskmove_si64
#define _m_pavgb _mm_avg_pu8
#define _m_pavgw _mm_avg_pu16
#define _m_psadbw _mm_sad_pu8
#endif
