/* ISO C complex arithmetic for TinyCC's Windows runtime. */
#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

#define complex _Complex
#define _Complex_I (__builtin_complex(0.0f, 1.0f))
#define I _Complex_I

double complex __cdecl cacos(double complex);
float complex __cdecl cacosf(float complex);
long double complex __cdecl cacosl(long double complex);
double complex __cdecl casin(double complex);
float complex __cdecl casinf(float complex);
long double complex __cdecl casinl(long double complex);
double complex __cdecl catan(double complex);
float complex __cdecl catanf(float complex);
long double complex __cdecl catanl(long double complex);
double complex __cdecl ccos(double complex);
float complex __cdecl ccosf(float complex);
long double complex __cdecl ccosl(long double complex);
double complex __cdecl csin(double complex);
float complex __cdecl csinf(float complex);
long double complex __cdecl csinl(long double complex);
double complex __cdecl ctan(double complex);
float complex __cdecl ctanf(float complex);
long double complex __cdecl ctanl(long double complex);

double complex __cdecl cacosh(double complex);
float complex __cdecl cacoshf(float complex);
long double complex __cdecl cacoshl(long double complex);
double complex __cdecl casinh(double complex);
float complex __cdecl casinhf(float complex);
long double complex __cdecl casinhl(long double complex);
double complex __cdecl catanh(double complex);
float complex __cdecl catanhf(float complex);
long double complex __cdecl catanhl(long double complex);
double complex __cdecl ccosh(double complex);
float complex __cdecl ccoshf(float complex);
long double complex __cdecl ccoshl(long double complex);
double complex __cdecl csinh(double complex);
float complex __cdecl csinhf(float complex);
long double complex __cdecl csinhl(long double complex);
double complex __cdecl ctanh(double complex);
float complex __cdecl ctanhf(float complex);
long double complex __cdecl ctanhl(long double complex);

double complex __cdecl cexp(double complex);
float complex __cdecl cexpf(float complex);
long double complex __cdecl cexpl(long double complex);
double complex __cdecl clog(double complex);
float complex __cdecl clogf(float complex);
long double complex __cdecl clogl(long double complex);
double __cdecl cabs(double complex);
float __cdecl cabsf(float complex);
long double __cdecl cabsl(long double complex);
double complex __cdecl cpow(double complex, double complex);
float complex __cdecl cpowf(float complex, float complex);
long double complex __cdecl cpowl(long double complex,
                                  long double complex);
double complex __cdecl csqrt(double complex);
float complex __cdecl csqrtf(float complex);
long double complex __cdecl csqrtl(long double complex);

double __cdecl carg(double complex);
float __cdecl cargf(float complex);
long double __cdecl cargl(long double complex);
double __cdecl cimag(double complex);
float __cdecl cimagf(float complex);
long double __cdecl cimagl(long double complex);
double complex __cdecl conj(double complex);
float complex __cdecl conjf(float complex);
long double complex __cdecl conjl(long double complex);
double complex __cdecl cproj(double complex);
float complex __cdecl cprojf(float complex);
long double complex __cdecl cprojl(long double complex);
double __cdecl creal(double complex);
float __cdecl crealf(float complex);
long double __cdecl creall(long double complex);

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define CMPLX(x, y) __builtin_complex((double)(x), (double)(y))
#define CMPLXF(x, y) __builtin_complex((float)(x), (float)(y))
#define CMPLXL(x, y) \
    __builtin_complex((long double)(x), (long double)(y))
#endif

#ifdef __cplusplus
}
#endif
#endif
