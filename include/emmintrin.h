/* SSE2 intrinsics for TinyCC.  Requires SSE2 on the executing CPU and OS. */
#ifndef _EMMINTRIN_H_INCLUDED
#define _EMMINTRIN_H_INCLUDED
#include <xmmintrin.h>
typedef __builtin_tcc_m128d __m128d;
typedef __builtin_tcc_m128i __m128i;
typedef union { __m128d d; __m128i i; __m128 f; double f64[2]; long long i64[2]; int i32[4]; short i16[8]; signed char i8[16]; } __tcc_m128x;
static __inline__ __m128d _mm_set_pd(double y,double x) { __tcc_m128x a; a.f64[0]=x; a.f64[1]=y; return a.d; }
static __inline__ __m128d _mm_setr_pd(double x,double y) { return _mm_set_pd(y,x); }
static __inline__ __m128d _mm_set1_pd(double x) { return _mm_set_pd(x,x); }
#define _mm_set_pd1 _mm_set1_pd
static __inline__ __m128d _mm_setzero_pd(void) { return _mm_set_pd(0,0); }
static __inline__ __m128d _mm_set_sd(double x) { return _mm_set_pd(0,x); }
static __inline__ double _mm_cvtsd_f64(__m128d x) { __tcc_m128x a; a.d=x; return a.f64[0]; }
static __inline__ __m128i _mm_set_epi64x(long long y,long long x) { __tcc_m128x a; a.i64[0]=x; a.i64[1]=y; return a.i; }
static __inline__ __m128i _mm_set1_epi64x(long long x) { return _mm_set_epi64x(x,x); }
static __inline__ __m128i _mm_setzero_si128(void) { return _mm_set_epi64x(0,0); }
static __inline__ __m128i _mm_cvtsi32_si128(int x) { return _mm_set_epi64x(0,(unsigned int)x); }
static __inline__ __m128i _mm_cvtsi64_si128(long long x) { return _mm_set_epi64x(0,x); }
static __inline__ int _mm_cvtsi128_si32(__m128i x) { __tcc_m128x a; a.i=x; return a.i32[0]; }
static __inline__ long long _mm_cvtsi128_si64(__m128i x) { __tcc_m128x a; a.i=x; return a.i64[0]; }
static __inline__ __m128i _mm_set_epi32(int x3,int x2,int x1,int x0) { __tcc_m128x a; a.i32[0]=x0; a.i32[1]=x1; a.i32[2]=x2; a.i32[3]=x3; return a.i; }
static __inline__ __m128i _mm_setr_epi32(int x0,int x1,int x2,int x3) { return _mm_set_epi32(x3,x2,x1,x0); }
static __inline__ __m128i _mm_set1_epi32(int x) { return _mm_set_epi32(x,x,x,x); }
static __inline__ __m128i _mm_set_epi16(short x7,short x6,short x5,short x4,short x3,short x2,short x1,short x0) { __tcc_m128x a; a.i16[0]=x0; a.i16[1]=x1; a.i16[2]=x2; a.i16[3]=x3; a.i16[4]=x4; a.i16[5]=x5; a.i16[6]=x6; a.i16[7]=x7; return a.i; }
static __inline__ __m128i _mm_setr_epi16(short x0,short x1,short x2,short x3,short x4,short x5,short x6,short x7) { return _mm_set_epi16(x7,x6,x5,x4,x3,x2,x1,x0); }
static __inline__ __m128i _mm_set1_epi16(short x) { return _mm_set_epi16(x,x,x,x,x,x,x,x); }
static __inline__ __m128i _mm_set_epi8(signed char x15,signed char x14,signed char x13,signed char x12,signed char x11,signed char x10,signed char x9,signed char x8,signed char x7,signed char x6,signed char x5,signed char x4,signed char x3,signed char x2,signed char x1,signed char x0) { __tcc_m128x a; a.i8[0]=x0; a.i8[1]=x1; a.i8[2]=x2; a.i8[3]=x3; a.i8[4]=x4; a.i8[5]=x5; a.i8[6]=x6; a.i8[7]=x7; a.i8[8]=x8; a.i8[9]=x9; a.i8[10]=x10; a.i8[11]=x11; a.i8[12]=x12; a.i8[13]=x13; a.i8[14]=x14; a.i8[15]=x15; return a.i; }
static __inline__ __m128i _mm_setr_epi8(signed char x0,signed char x1,signed char x2,signed char x3,signed char x4,signed char x5,signed char x6,signed char x7,signed char x8,signed char x9,signed char x10,signed char x11,signed char x12,signed char x13,signed char x14,signed char x15) { return _mm_set_epi8(x15,x14,x13,x12,x11,x10,x9,x8,x7,x6,x5,x4,x3,x2,x1,x0); }
static __inline__ __m128i _mm_set1_epi8(signed char x) { return _mm_set_epi8(x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x); }
static __inline__ __m128d _mm_castps_pd(__m128 a) { return (__m128d)a; }
static __inline__ __m128i _mm_castps_si128(__m128 a) { return (__m128i)a; }
static __inline__ __m128 _mm_castpd_ps(__m128d a) { return (__m128)a; }
static __inline__ __m128i _mm_castpd_si128(__m128d a) { return (__m128i)a; }
static __inline__ __m128 _mm_castsi128_ps(__m128i a) { return (__m128)a; }
static __inline__ __m128d _mm_castsi128_pd(__m128i a) { return (__m128d)a; }
static __inline__ __m128d _mm_move_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_move_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_add_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_add_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_sub_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_sub_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_mul_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_mul_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_div_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_div_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_min_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_min_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_max_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_max_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_sqrt_pd(__m128d a) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_sqrt_pd, &r, &a, 0, 0); return r; }
static __inline__ __m128d _mm_cmpeq_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_cmplt_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 1); return r; }
static __inline__ __m128d _mm_cmple_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 2); return r; }
static __inline__ __m128d _mm_cmpunord_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 3); return r; }
static __inline__ __m128d _mm_cmpneq_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 4); return r; }
static __inline__ __m128d _mm_cmpnlt_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 5); return r; }
static __inline__ __m128d _mm_cmpnle_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 6); return r; }
static __inline__ __m128d _mm_cmpord_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &a, &b, 7); return r; }
static __inline__ __m128d _mm_cmpgt_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &b, &a, 1); return r; }
static __inline__ __m128d _mm_cmpge_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &b, &a, 2); return r; }
static __inline__ __m128d _mm_cmpngt_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &b, &a, 5); return r; }
static __inline__ __m128d _mm_cmpnge_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_pd, &r, &b, &a, 6); return r; }
static __inline__ __m128d _mm_add_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_add_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_sub_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_sub_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_mul_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_mul_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_div_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_div_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_min_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_min_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_max_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_max_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_sqrt_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_sqrt_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_cmpeq_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_cmplt_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 1); return r; }
static __inline__ __m128d _mm_cmple_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 2); return r; }
static __inline__ __m128d _mm_cmpunord_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 3); return r; }
static __inline__ __m128d _mm_cmpneq_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 4); return r; }
static __inline__ __m128d _mm_cmpnlt_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 5); return r; }
static __inline__ __m128d _mm_cmpnle_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 6); return r; }
static __inline__ __m128d _mm_cmpord_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &a, &b, 7); return r; }
static __inline__ __m128d _mm_cmpgt_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &b, &a, 1); return _mm_move_sd(a, r); }
static __inline__ __m128d _mm_cmpge_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &b, &a, 2); return _mm_move_sd(a, r); }
static __inline__ __m128d _mm_cmpngt_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &b, &a, 5); return _mm_move_sd(a, r); }
static __inline__ __m128d _mm_cmpnge_sd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S_cmp_sd, &r, &b, &a, 6); return _mm_move_sd(a, r); }
static __inline__ __m128d _mm_and_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_and_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_andnot_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_andnot_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_or_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_or_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_xor_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_xor_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_unpacklo_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_pd, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_unpackhi_pd(__m128d a, __m128d b) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_pd, &r, &a, &b, 0); return r; }
#define _mm_shuffle_pd(a,b,i) __TCC_SIMD_SHUF(__m128d,__TCC_S_shuffle_pd,a,b,i)
static __inline__ int _mm_movemask_pd(__m128d a) { int r; __builtin_tcc_simd(__TCC_S_movemask_pd, &r, &a, 0, 0); return r; }
static __inline__ __m128d _mm_load_pd(const double *a) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_load_pd, &r, a, 0, 0); return r; }
static __inline__ __m128d _mm_loadu_pd(const double *a) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_loadu_pd, &r, a, 0, 0); return r; }
static __inline__ void _mm_store_pd(double *p, __m128d a) { __builtin_tcc_simd(__TCC_S__mm_store_pd, p, &a, 0, 0);  }
static __inline__ void _mm_storeu_pd(double *p, __m128d a) { __builtin_tcc_simd(__TCC_S__mm_storeu_pd, p, &a, 0, 0);  }
static __inline__ void _mm_stream_pd(double *p, __m128d a) { __builtin_tcc_simd(__TCC_S__mm_stream_pd, p, &a, 0, 0);  }
static __inline__ __m128d _mm_load_sd(const double *a) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_load_sd, &r, a, 0, 0); return r; }
static __inline__ void _mm_store_sd(double *p, __m128d a) { __builtin_tcc_simd(__TCC_S__mm_store_sd, p, &a, 0, 0);  }
static __inline__ __m128i _mm_load_si128(const __m128i *a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_load_si128, &r, a, 0, 0); return r; }
static __inline__ __m128i _mm_loadu_si128(const __m128i *a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_loadu_si128, &r, a, 0, 0); return r; }
static __inline__ __m128i _mm_loadl_epi64(const __m128i *a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_loadl_epi64, &r, a, 0, 0); return r; }
static __inline__ void _mm_store_si128(__m128i *p, __m128i a) { __builtin_tcc_simd(__TCC_S__mm_store_si128, p, &a, 0, 0);  }
static __inline__ void _mm_storeu_si128(__m128i *p, __m128i a) { __builtin_tcc_simd(__TCC_S__mm_storeu_si128, p, &a, 0, 0);  }
static __inline__ void _mm_storel_epi64(__m128i *p, __m128i a) { __builtin_tcc_simd(__TCC_S__mm_storel_epi64, p, &a, 0, 0);  }
static __inline__ void _mm_stream_si128(__m128i *p, __m128i a) { __builtin_tcc_simd(__TCC_S__mm_stream_si128, p, &a, 0, 0);  }
static __inline__ __m128i _mm_add_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_add_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_add_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_add_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_add_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_add_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_add_epi64(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_add_epi64, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_adds_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_adds_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_adds_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_adds_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_adds_epu8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_adds_epu8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_adds_epu16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_adds_epu16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sub_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sub_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sub_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sub_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sub_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sub_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sub_epi64(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sub_epi64, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_subs_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_subs_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_subs_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_subs_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_subs_epu8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_subs_epu8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_subs_epu16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_subs_epu16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_and_si128(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_and_si128, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_andnot_si128(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_andnot_si128, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_or_si128(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_or_si128, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_xor_si128(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_xor_si128, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_avg_epu8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_avg_epu8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_avg_epu16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_avg_epu16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_min_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_min_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_max_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_max_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_min_epu8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_min_epu8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_max_epu8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_max_epu8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_mulhi_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_mulhi_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_mulhi_epu16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_mulhi_epu16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_mullo_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_mullo_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_mul_epu32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_mul_epu32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_madd_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_madd_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sad_epu8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sad_epu8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_packs_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_packs_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_packs_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_packs_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_packus_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_packus_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmpeq_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cmpeq_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmpeq_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cmpeq_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmpeq_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cmpeq_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmpgt_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cmpgt_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmpgt_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cmpgt_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmpgt_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cmpgt_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpacklo_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpacklo_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpacklo_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpacklo_epi64(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_epi64, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpackhi_epi8(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_epi8, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpackhi_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpackhi_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_unpackhi_epi64(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_epi64, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sll_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sll_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sll_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sll_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sll_epi64(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sll_epi64, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_srl_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_srl_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_srl_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_srl_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_srl_epi64(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_srl_epi64, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sra_epi16(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sra_epi16, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_sra_epi32(__m128i a, __m128i b) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_sra_epi32, &r, &a, &b, 0); return r; }
static __inline__ __m128i _mm_cmplt_epi8(__m128i a, __m128i b) { return _mm_cmpgt_epi8(b,a); }
static __inline__ __m128i _mm_cmplt_epi16(__m128i a, __m128i b) { return _mm_cmpgt_epi16(b,a); }
static __inline__ __m128i _mm_cmplt_epi32(__m128i a, __m128i b) { return _mm_cmpgt_epi32(b,a); }
static __inline__ __m128i _mm_slli_epi16(__m128i a,int n) { return _mm_sll_epi16(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_slli_epi32(__m128i a,int n) { return _mm_sll_epi32(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_slli_epi64(__m128i a,int n) { return _mm_sll_epi64(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_srli_epi16(__m128i a,int n) { return _mm_srl_epi16(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_srli_epi32(__m128i a,int n) { return _mm_srl_epi32(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_srli_epi64(__m128i a,int n) { return _mm_srl_epi64(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_srai_epi16(__m128i a,int n) { return _mm_sra_epi16(a,_mm_cvtsi32_si128(n)); }
static __inline__ __m128i _mm_srai_epi32(__m128i a,int n) { return _mm_sra_epi32(a,_mm_cvtsi32_si128(n)); }
#define _mm_slli_si128(a,i) __TCC_SIMD_SHIFT(__m128i,__TCC_S__mm_slli_si128,a,i)
#define _mm_srli_si128(a,i) __TCC_SIMD_SHIFT(__m128i,__TCC_S__mm_srli_si128,a,i)
#define _mm_shuffle_epi32(a,i) __TCC_SIMD_PERM(__m128i,__TCC_S_shuffle_epi32,a,i)
#define _mm_shufflelo_epi16(a,i) __TCC_SIMD_PERM(__m128i,__TCC_S_shufflelo_epi16,a,i)
#define _mm_shufflehi_epi16(a,i) __TCC_SIMD_PERM(__m128i,__TCC_S_shufflehi_epi16,a,i)
static __inline__ int _mm_movemask_epi8(__m128i a) { int r; __builtin_tcc_simd(__TCC_S_movemask_epi8, &r, &a, 0, 0); return r; }
static __inline__ __m128d _mm_cvtps_pd(__m128 a) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_cvtps_pd, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_cvtpd_ps(__m128d a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_cvtpd_ps, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_cvtepi32_ps(__m128i a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_cvtepi32_ps, &r, &a, 0, 0); return r; }
static __inline__ __m128i _mm_cvtps_epi32(__m128 a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cvtps_epi32, &r, &a, 0, 0); return r; }
static __inline__ __m128i _mm_cvttps_epi32(__m128 a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cvttps_epi32, &r, &a, 0, 0); return r; }
static __inline__ __m128d _mm_cvtepi32_pd(__m128i a) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_cvtepi32_pd, &r, &a, 0, 0); return r; }
static __inline__ __m128i _mm_cvtpd_epi32(__m128d a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cvtpd_epi32, &r, &a, 0, 0); return r; }
static __inline__ __m128i _mm_cvttpd_epi32(__m128d a) { __m128i r; __builtin_tcc_simd(__TCC_S__mm_cvttpd_epi32, &r, &a, 0, 0); return r; }
static __inline__ __m128d _mm_cvtss_sd(__m128d a, __m128 b) { __m128d r; __builtin_tcc_simd(__TCC_S_cvtss_sd, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_cvtsd_ss(__m128 a, __m128d b) { __m128 r; __builtin_tcc_simd(__TCC_S_cvtsd_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128d _mm_cvtsi32_sd(__m128d a, int b) { __m128d r; __builtin_tcc_simd(__TCC_S_cvtsi32_sd, &r, &a, &b, 0); return r; }
static __inline__ int _mm_cvtsd_si32(__m128d a) { int r; __builtin_tcc_simd(__TCC_S_cvtsd_si32, &r, &a, 0, 0); return r; }
static __inline__ int _mm_cvttsd_si32(__m128d a) { int r; __builtin_tcc_simd(__TCC_S_cvttsd_si32, &r, &a, 0, 0); return r; }
#ifdef __x86_64__
static __inline__ __m128d _mm_cvtsi64_sd(__m128d a, long long b) { __m128d r; __builtin_tcc_simd(__TCC_S_cvtsi64_sd, &r, &a, &b, 0); return r; }
static __inline__ long long _mm_cvtsd_si64(__m128d a) { long long r; __builtin_tcc_simd(__TCC_S_cvtsd_si64, &r, &a, 0, 0); return r; }
static __inline__ long long _mm_cvttsd_si64(__m128d a) { long long r; __builtin_tcc_simd(__TCC_S_cvttsd_si64, &r, &a, 0, 0); return r; }
#endif
static __inline__ void _mm_lfence(void) { __builtin_tcc_simd(__TCC_S_lfence, 0, 0, 0, 0);  }
static __inline__ void _mm_mfence(void) { __builtin_tcc_simd(__TCC_S_mfence, 0, 0, 0, 0);  }
static __inline__ void _mm_maskmoveu_si128(__m128i a, __m128i b, char *p) { __builtin_tcc_simd(__TCC_S_maskmoveu, p, &a, &b, 0);  }
static __inline__ __m128d _mm_load1_pd(const double *p) { return _mm_set1_pd(*p); }
#define _mm_load_pd1 _mm_load1_pd
static __inline__ void _mm_store1_pd(double *p,__m128d a) { _mm_store_pd(p,_mm_shuffle_pd(a,a,0)); }
#define _mm_store_pd1 _mm_store1_pd
#define _mm_bslli_si128 _mm_slli_si128
#define _mm_bsrli_si128 _mm_srli_si128
static __inline__ int _mm_comieq_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_comieq_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_comilt_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_comilt_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_comile_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_comile_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_comigt_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_comigt_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_comige_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_comige_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_comineq_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_comineq_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomieq_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomieq_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomilt_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomilt_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomile_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomile_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomigt_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomigt_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomige_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomige_sd, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomineq_sd(__m128d a,__m128d b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomineq_sd, &r,&a,&b,0); return r; }
#define _mm_extract_epi16(a,i) __extension__ ({ __m128i __a=(a); int __r; __builtin_tcc_simd(__TCC_S__mm_extract_epi16,&__r,&__a,0,(i)); __r; })
#define _mm_insert_epi16(a,b,i) __extension__ ({ __m128i __a=(a),__r; int __b=(b); __builtin_tcc_simd(__TCC_S__mm_insert_epi16,&__r,&__a,&__b,(i)); __r; })
static __inline__ void _mm_clflush(const void *p) { __builtin_tcc_simd(__TCC_S__mm_clflush, 0,p,0,0); }
static __inline__ void _mm_pause(void) { __builtin_tcc_simd(__TCC_S__mm_pause, 0,0,0,0); }
static __inline__ void _mm_stream_si32(int *p,int a) { __builtin_tcc_simd(__TCC_S__mm_stream_si32, p,&a,0,0); }
#ifdef __x86_64__
static __inline__ void _mm_stream_si64(long long *p,long long a) { __builtin_tcc_simd(__TCC_S__mm_stream_si64, p,&a,0,0); }
#endif
static __inline__ __m128d _mm_loadl_pd(__m128d a,const double *p) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_loadl_pd, &r,&a,p,0); return r; }
static __inline__ void _mm_storel_pd(double *p,__m128d a) { __builtin_tcc_simd(__TCC_S__mm_storel_pd, p,&a,0,0); }
static __inline__ __m128d _mm_loadh_pd(__m128d a,const double *p) { __m128d r; __builtin_tcc_simd(__TCC_S__mm_loadh_pd, &r,&a,p,0); return r; }
static __inline__ void _mm_storeh_pd(double *p,__m128d a) { __builtin_tcc_simd(__TCC_S__mm_storeh_pd, p,&a,0,0); }
static __inline__ __m128d _mm_loadr_pd(const double *p) { __m128d a=_mm_load_pd(p); return _mm_shuffle_pd(a,a,1); }
static __inline__ void _mm_storer_pd(double *p,__m128d a) { _mm_store_pd(p,_mm_shuffle_pd(a,a,1)); }
static __inline__ __m128i _mm_move_epi64(__m128i a) { return _mm_unpacklo_epi64(a,_mm_setzero_si128()); }
static __inline__ __m128i _mm_loadu_si16(const void *p) { __tcc_m128x r; const unsigned char *s=p; unsigned char *d=(unsigned char *)&r; int j; r.i=_mm_setzero_si128(); for(j=0;j<2;++j) d[j]=s[j]; return r.i; }
static __inline__ void _mm_storeu_si16(void *p,__m128i a) { __tcc_m128x r; unsigned char *d=p; const unsigned char *s=(const unsigned char *)&r; int j; r.i=a; for(j=0;j<2;++j) d[j]=s[j]; }
static __inline__ __m128i _mm_loadu_si32(const void *p) { __tcc_m128x r; const unsigned char *s=p; unsigned char *d=(unsigned char *)&r; int j; r.i=_mm_setzero_si128(); for(j=0;j<4;++j) d[j]=s[j]; return r.i; }
static __inline__ void _mm_storeu_si32(void *p,__m128i a) { __tcc_m128x r; unsigned char *d=p; const unsigned char *s=(const unsigned char *)&r; int j; r.i=a; for(j=0;j<4;++j) d[j]=s[j]; }
static __inline__ __m128i _mm_loadu_si64(const void *p) { __tcc_m128x r; const unsigned char *s=p; unsigned char *d=(unsigned char *)&r; int j; r.i=_mm_setzero_si128(); for(j=0;j<8;++j) d[j]=s[j]; return r.i; }
static __inline__ void _mm_storeu_si64(void *p,__m128i a) { __tcc_m128x r; unsigned char *d=p; const unsigned char *s=(const unsigned char *)&r; int j; r.i=a; for(j=0;j<8;++j) d[j]=s[j]; }
static __inline__ __m128d _mm_undefined_pd(void) { return _mm_setzero_pd(); }
static __inline__ __m128i _mm_undefined_si128(void) { return _mm_setzero_si128(); }
static __inline__ __m128d _mm_cvtpi32_pd(__m64 b) { __m128d a=_mm_setzero_pd(),r; __builtin_tcc_simd(__TCC_S__mm_cvtpi32_pd,&r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cvtpd_pi32(__m128d a) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cvtpd_pi32, &r,&a,0,0); return r; }
static __inline__ __m64 _mm_cvttpd_pi32(__m128d a) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cvttpd_pi32, &r,&a,0,0); return r; }
static __inline__ __m128i _mm_set_epi64(__m64 hi,__m64 lo) { return _mm_set_epi64x(_mm_cvtm64_si64(hi),_mm_cvtm64_si64(lo)); }
static __inline__ __m128i _mm_setr_epi64(__m64 lo,__m64 hi) { return _mm_set_epi64(hi,lo); }
static __inline__ __m128i _mm_set1_epi64(__m64 a) { return _mm_set_epi64(a,a); }
static __inline__ __m128i _mm_movpi64_epi64(__m64 a) { return _mm_set_epi64x(0,_mm_cvtm64_si64(a)); }
static __inline__ __m64 _mm_movepi64_pi64(__m128i a) { return _mm_cvtsi64_m64(_mm_cvtsi128_si64(a)); }
#define _MM_SHUFFLE2(x,y) (((x)<<1)|(y))
#define _mm_cmp_pd(a,b,i) __TCC_SIMD_SHUF(__m128d,__TCC_S_cmp_pd,a,b,i)
#define _mm_cmp_sd(a,b,i) __TCC_SIMD_SHUF(__m128d,__TCC_S_cmp_sd,a,b,i)
#endif
