/* SSE intrinsics for TinyCC.  Requires SSE on the executing CPU and OS. */
#ifndef _XMMINTRIN_H_INCLUDED
#define _XMMINTRIN_H_INCLUDED
#if !defined(__i386__) && !defined(__x86_64__)
#error SSE intrinsics require an x86 target
#endif
#include <tccsimd.h>
#include <mmintrin.h>
#include <mm_malloc.h>
typedef __builtin_tcc_m128 __m128;
#define _MM_SHUFFLE(z,y,x,w) (((z)<<6)|((y)<<4)|((x)<<2)|(w))
#define __TCC_SIMD_SHUF(T,op,a,b,i) __extension__ ({ T __a=(a), __b=(b), __r; __builtin_tcc_simd(op,&__r,&__a,&__b,(i)); __r; })
#define __TCC_SIMD_PERM(T,op,a,i) __extension__ ({ T __a=(a), __r; __builtin_tcc_simd(op,&__r,&__a,&__a,(i)); __r; })
#define __TCC_SIMD_SHIFT(T,op,a,i) __extension__ ({ T __a=(a), __r; __builtin_tcc_simd(op,&__r,&__a,0,(i)); __r; })
typedef union { __m128 v; float f[4]; unsigned int u[4]; } __tcc_m128;
static __inline__ __m128 _mm_set_ps(float w,float z,float y,float x) { __tcc_m128 a; a.f[0]=x; a.f[1]=y; a.f[2]=z; a.f[3]=w; return a.v; }
static __inline__ __m128 _mm_setr_ps(float x,float y,float z,float w) { return _mm_set_ps(w,z,y,x); }
static __inline__ __m128 _mm_set1_ps(float x) { return _mm_set_ps(x,x,x,x); }
static __inline__ __m128 _mm_set_ps1(float x) { return _mm_set1_ps(x); }
static __inline__ __m128 _mm_setzero_ps(void) { return _mm_set1_ps(0); }
static __inline__ __m128 _mm_set_ss(float x) { return _mm_set_ps(0,0,0,x); }
static __inline__ float _mm_cvtss_f32(__m128 x) { __tcc_m128 a; a.v=x; return a.f[0]; }
static __inline__ __m128 _mm_move_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_move_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_add_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_add_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_sub_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_sub_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_mul_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_mul_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_div_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_div_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_min_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_min_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_max_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_max_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_sqrt_ps(__m128 a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_sqrt_ps, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_cmpeq_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_cmplt_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 1); return r; }
static __inline__ __m128 _mm_cmple_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 2); return r; }
static __inline__ __m128 _mm_cmpunord_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 3); return r; }
static __inline__ __m128 _mm_cmpneq_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 4); return r; }
static __inline__ __m128 _mm_cmpnlt_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 5); return r; }
static __inline__ __m128 _mm_cmpnle_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 6); return r; }
static __inline__ __m128 _mm_cmpord_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &a, &b, 7); return r; }
static __inline__ __m128 _mm_cmpgt_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &b, &a, 1); return r; }
static __inline__ __m128 _mm_cmpge_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &b, &a, 2); return r; }
static __inline__ __m128 _mm_cmpngt_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &b, &a, 5); return r; }
static __inline__ __m128 _mm_cmpnge_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ps, &r, &b, &a, 6); return r; }
static __inline__ __m128 _mm_add_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_add_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_sub_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_sub_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_mul_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_mul_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_div_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_div_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_min_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_min_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_max_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_max_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_sqrt_ss(__m128 a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_sqrt_ss, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_cmpeq_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_cmplt_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 1); return r; }
static __inline__ __m128 _mm_cmple_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 2); return r; }
static __inline__ __m128 _mm_cmpunord_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 3); return r; }
static __inline__ __m128 _mm_cmpneq_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 4); return r; }
static __inline__ __m128 _mm_cmpnlt_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 5); return r; }
static __inline__ __m128 _mm_cmpnle_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 6); return r; }
static __inline__ __m128 _mm_cmpord_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &a, &b, 7); return r; }
static __inline__ __m128 _mm_cmpgt_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &b, &a, 1); return _mm_move_ss(a, r); }
static __inline__ __m128 _mm_cmpge_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &b, &a, 2); return _mm_move_ss(a, r); }
static __inline__ __m128 _mm_cmpngt_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &b, &a, 5); return _mm_move_ss(a, r); }
static __inline__ __m128 _mm_cmpnge_ss(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S_cmp_ss, &r, &b, &a, 6); return _mm_move_ss(a, r); }
static __inline__ __m128 _mm_and_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_and_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_andnot_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_andnot_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_or_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_or_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_xor_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_xor_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_unpacklo_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_unpacklo_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_unpackhi_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_unpackhi_ps, &r, &a, &b, 0); return r; }
#define _mm_shuffle_ps(a,b,i) __TCC_SIMD_SHUF(__m128,__TCC_S_shuffle_ps,a,b,i)
static __inline__ int _mm_movemask_ps(__m128 a) { int r; __builtin_tcc_simd(__TCC_S_movemask_ps, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_rcp_ps(__m128 a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_rcp_ps, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_rsqrt_ps(__m128 a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_rsqrt_ps, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_rcp_ss(__m128 a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_rcp_ss, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_rsqrt_ss(__m128 a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_rsqrt_ss, &r, &a, 0, 0); return r; }
static __inline__ __m128 _mm_movehl_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_movehl_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_movelh_ps(__m128 a, __m128 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_movelh_ps, &r, &a, &b, 0); return r; }
static __inline__ __m128 _mm_load_ps(const float *a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_load_ps, &r, a, 0, 0); return r; }
static __inline__ __m128 _mm_loadu_ps(const float *a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_loadu_ps, &r, a, 0, 0); return r; }
static __inline__ void _mm_store_ps(float *p, __m128 a) { __builtin_tcc_simd(__TCC_S__mm_store_ps, p, &a, 0, 0);  }
static __inline__ void _mm_storeu_ps(float *p, __m128 a) { __builtin_tcc_simd(__TCC_S__mm_storeu_ps, p, &a, 0, 0);  }
static __inline__ void _mm_stream_ps(float *p, __m128 a) { __builtin_tcc_simd(__TCC_S__mm_stream_ps, p, &a, 0, 0);  }
static __inline__ __m128 _mm_load_ss(const float *a) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_load_ss, &r, a, 0, 0); return r; }
static __inline__ void _mm_store_ss(float *p, __m128 a) { __builtin_tcc_simd(__TCC_S__mm_store_ss, p, &a, 0, 0);  }
static __inline__ __m128 _mm_cvtsi32_ss(__m128 a, int b) { __m128 r; __builtin_tcc_simd(__TCC_S_cvtsi32_ss, &r, &a, &b, 0); return r; }
static __inline__ int _mm_cvtss_si32(__m128 a) { int r; __builtin_tcc_simd(__TCC_S_cvtss_si32, &r, &a, 0, 0); return r; }
static __inline__ int _mm_cvttss_si32(__m128 a) { int r; __builtin_tcc_simd(__TCC_S_cvttss_si32, &r, &a, 0, 0); return r; }
#ifdef __x86_64__
static __inline__ __m128 _mm_cvtsi64_ss(__m128 a, long long b) { __m128 r; __builtin_tcc_simd(__TCC_S_cvtsi64_ss, &r, &a, &b, 0); return r; }
static __inline__ long long _mm_cvtss_si64(__m128 a) { long long r; __builtin_tcc_simd(__TCC_S_cvtss_si64, &r, &a, 0, 0); return r; }
static __inline__ long long _mm_cvttss_si64(__m128 a) { long long r; __builtin_tcc_simd(__TCC_S_cvttss_si64, &r, &a, 0, 0); return r; }
#endif
static __inline__ unsigned int _mm_getcsr(void) { unsigned int r; __builtin_tcc_simd(__TCC_S_getcsr, &r, 0, 0, 0); return r; }
static __inline__ void _mm_setcsr(unsigned int a) { __builtin_tcc_simd(__TCC_S_setcsr, 0, &a, 0, 0);  }
static __inline__ void _mm_sfence(void) { __builtin_tcc_simd(__TCC_S_sfence, 0, 0, 0, 0);  }
static __inline__ __m128 _mm_load1_ps(const float *p) { return _mm_set1_ps(*p); }
#define _mm_load_ps1 _mm_load1_ps
static __inline__ __m128 _mm_loadr_ps(const float *p) { __m128 a = _mm_load_ps(p); return _mm_shuffle_ps(a,a,27); }
static __inline__ void _mm_store1_ps(float *p,__m128 a) { _mm_store_ps(p,_mm_shuffle_ps(a,a,0)); }
#define _mm_store_ps1 _mm_store1_ps
static __inline__ void _mm_storer_ps(float *p,__m128 a) { _mm_store_ps(p,_mm_shuffle_ps(a,a,27)); }
#define _MM_ROUND_MASK 0x6000
#define _MM_ROUND_NEAREST 0x0000
#define _MM_ROUND_DOWN 0x2000
#define _MM_ROUND_UP 0x4000
#define _MM_ROUND_TOWARD_ZERO 0x6000
#define _MM_GET_ROUNDING_MODE() (_mm_getcsr() & _MM_ROUND_MASK)
#define _MM_SET_ROUNDING_MODE(m) _mm_setcsr((_mm_getcsr() & ~_MM_ROUND_MASK) | (m))
static __inline__ int _mm_comieq_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_comieq_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_comilt_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_comilt_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_comile_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_comile_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_comigt_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_comigt_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_comige_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_comige_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_comineq_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_comineq_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomieq_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomieq_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomilt_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomilt_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomile_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomile_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomigt_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomigt_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomige_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomige_ss, &r,&a,&b,0); return r; }
static __inline__ int _mm_ucomineq_ss(__m128 a,__m128 b) { int r; __builtin_tcc_simd(__TCC_S__mm_ucomineq_ss, &r,&a,&b,0); return r; }
#define _mm_prefetch(p,h) __builtin_tcc_simd(__TCC_S__mm_prefetch,0,(p),0,(h))
static __inline__ __m128 _mm_loadl_pi(__m128 a,const __m64 *p) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_loadl_pi, &r,&a,p,0); return r; }
static __inline__ void _mm_storel_pi(__m64 *p,__m128 a) { __builtin_tcc_simd(__TCC_S__mm_storel_pi, p,&a,0,0); }
static __inline__ __m128 _mm_loadh_pi(__m128 a,const __m64 *p) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_loadh_pi, &r,&a,p,0); return r; }
static __inline__ void _mm_storeh_pi(__m64 *p,__m128 a) { __builtin_tcc_simd(__TCC_S__mm_storeh_pi, p,&a,0,0); }
static __inline__ __m128 _mm_undefined_ps(void) { return _mm_setzero_ps(); }
static __inline__ __m128 _mm_cvtpi32_ps(__m128 a,__m64 b) { __m128 r; __builtin_tcc_simd(__TCC_S__mm_cvtpi32_ps, &r,&a,&b,0); return r; }
static __inline__ __m64 _mm_cvtps_pi32(__m128 a) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cvtps_pi32, &r,&a,0,0); return r; }
static __inline__ __m64 _mm_cvttps_pi32(__m128 a) { __m64 r; __builtin_tcc_simd(__TCC_S__mm_cvttps_pi32, &r,&a,0,0); return r; }
static __inline__ __m128 _mm_cvtpi32x2_ps(__m64 a,__m64 b) { __m128 lo=_mm_cvtpi32_ps(_mm_setzero_ps(),a),hi=_mm_cvtpi32_ps(_mm_setzero_ps(),b); return _mm_movelh_ps(lo,hi); }
static __inline__ __m128 _mm_cvtpi8_ps(__m64 a) { __tcc_m64 u; __m128 r0,r1,r2,r3; u.v=a; r0=_mm_cvtsi32_ss(_mm_setzero_ps(),u.b[0]); r1=_mm_cvtsi32_ss(_mm_setzero_ps(),u.b[1]); r2=_mm_cvtsi32_ss(_mm_setzero_ps(),u.b[2]); r3=_mm_cvtsi32_ss(_mm_setzero_ps(),u.b[3]); return _mm_movelh_ps(_mm_unpacklo_ps(r0,r1),_mm_unpacklo_ps(r2,r3)); }
static __inline__ __m128 _mm_cvtpu8_ps(__m64 a) { __tcc_m64 u; __m128 r0,r1,r2,r3; u.v=a; r0=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned char)u.b[0]); r1=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned char)u.b[1]); r2=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned char)u.b[2]); r3=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned char)u.b[3]); return _mm_movelh_ps(_mm_unpacklo_ps(r0,r1),_mm_unpacklo_ps(r2,r3)); }
static __inline__ __m128 _mm_cvtpi16_ps(__m64 a) { __tcc_m64 u; __m128 r0,r1,r2,r3; u.v=a; r0=_mm_cvtsi32_ss(_mm_setzero_ps(),u.w[0]); r1=_mm_cvtsi32_ss(_mm_setzero_ps(),u.w[1]); r2=_mm_cvtsi32_ss(_mm_setzero_ps(),u.w[2]); r3=_mm_cvtsi32_ss(_mm_setzero_ps(),u.w[3]); return _mm_movelh_ps(_mm_unpacklo_ps(r0,r1),_mm_unpacklo_ps(r2,r3)); }
static __inline__ __m128 _mm_cvtpu16_ps(__m64 a) { __tcc_m64 u; __m128 r0,r1,r2,r3; u.v=a; r0=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned short)u.w[0]); r1=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned short)u.w[1]); r2=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned short)u.w[2]); r3=_mm_cvtsi32_ss(_mm_setzero_ps(),(unsigned short)u.w[3]); return _mm_movelh_ps(_mm_unpacklo_ps(r0,r1),_mm_unpacklo_ps(r2,r3)); }
static __inline__ __m64 _mm_cvtps_pi16(__m128 a) { __m64 lo=_mm_cvtps_pi32(a),hi=_mm_cvtps_pi32(_mm_movehl_ps(a,a)); return _mm_packs_pi32(lo,hi); }
static __inline__ __m64 _mm_cvtps_pi8(__m128 a) { return _mm_packs_pi16(_mm_cvtps_pi16(a),_mm_setzero_si64()); }
#define _mm_cvt_si2ss _mm_cvtsi32_ss
#define _mm_cvt_ss2si _mm_cvtss_si32
#define _mm_cvtt_ss2si _mm_cvttss_si32
#define _mm_cvt_pi2ps _mm_cvtpi32_ps
#define _mm_cvt_ps2pi _mm_cvtps_pi32
#define _mm_cvtt_ps2pi _mm_cvttps_pi32
#define _MM_EXCEPT_MASK 0x3f
#define _MM_EXCEPT_INVALID 0x1
#define _MM_EXCEPT_DENORM 0x2
#define _MM_EXCEPT_DIV_ZERO 0x4
#define _MM_EXCEPT_OVERFLOW 0x8
#define _MM_EXCEPT_UNDERFLOW 0x10
#define _MM_EXCEPT_INEXACT 0x20
#define _MM_GET_EXCEPTION_STATE() (_mm_getcsr() & _MM_EXCEPT_MASK)
#define _MM_SET_EXCEPTION_STATE(m) _mm_setcsr((_mm_getcsr() & ~_MM_EXCEPT_MASK) | (m))
#define _MM_MASK_MASK 0x1f80
#define _MM_MASK_INVALID 0x80
#define _MM_MASK_DENORM 0x100
#define _MM_MASK_DIV_ZERO 0x200
#define _MM_MASK_OVERFLOW 0x400
#define _MM_MASK_UNDERFLOW 0x800
#define _MM_MASK_INEXACT 0x1000
#define _MM_GET_EXCEPTION_MASK() (_mm_getcsr() & _MM_MASK_MASK)
#define _MM_SET_EXCEPTION_MASK(m) _mm_setcsr((_mm_getcsr() & ~_MM_MASK_MASK) | (m))
#define _MM_FLUSH_ZERO_MASK 0x8000
#define _MM_FLUSH_ZERO_ON 0x8000
#define _MM_FLUSH_ZERO_OFF 0x0
#define _MM_GET_FLUSH_ZERO_MODE() (_mm_getcsr() & _MM_FLUSH_ZERO_MASK)
#define _MM_SET_FLUSH_ZERO_MODE(m) _mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | (m))
#define _MM_DENORMALS_ZERO_MASK 0x40
#define _MM_DENORMALS_ZERO_ON 0x40
#define _MM_DENORMALS_ZERO_OFF 0x0
#define _MM_GET_DENORMALS_ZERO_MODE() (_mm_getcsr() & _MM_DENORMALS_ZERO_MASK)
#define _MM_SET_DENORMALS_ZERO_MODE(m) _mm_setcsr((_mm_getcsr() & ~_MM_DENORMALS_ZERO_MASK) | (m))
#define _MM_HINT_NTA 0
#define _MM_HINT_T0 3
#define _MM_HINT_T1 2
#define _MM_HINT_T2 1
#define _MM_ALIGN16 __attribute__((aligned(16)))
#define _MM_TRANSPOSE4_PS(r0,r1,r2,r3) do { \
    __m128 __t0=_mm_unpacklo_ps((r0),(r1)),__t1=_mm_unpackhi_ps((r0),(r1)); \
    __m128 __t2=_mm_unpacklo_ps((r2),(r3)),__t3=_mm_unpackhi_ps((r2),(r3)); \
    (r0)=_mm_movelh_ps(__t0,__t2); (r1)=_mm_movehl_ps(__t2,__t0); \
    (r2)=_mm_movelh_ps(__t1,__t3); (r3)=_mm_movehl_ps(__t3,__t1); \
} while(0)
#define _mm_cmp_ps(a,b,i) __TCC_SIMD_SHUF(__m128,__TCC_S_cmp_ps,a,b,i)
#define _mm_cmp_ss(a,b,i) __TCC_SIMD_SHUF(__m128,__TCC_S_cmp_ss,a,b,i)
#endif
