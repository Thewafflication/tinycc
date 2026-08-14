/* C99 complex library support for TinyCC's Windows runtime. */
#include <complex.h>
#include <float.h>
#include <math.h>

#define CX_PI_2 1.57079632679489661923132169163975144

#define DCMPLX(x, y) __builtin_complex((double)(x), (double)(y))
#define FCMPLX(x, y) __builtin_complex((float)(x), (float)(y))
#define LCMPLX(x, y) \
    __builtin_complex((long double)(x), (long double)(y))

typedef union {
    double complex value;
    double part[2];
} double_complex_parts;

typedef union {
    float complex value;
    float part[2];
} float_complex_parts;

typedef union {
    long double complex value;
    long double part[2];
} long_double_complex_parts;

double (creal)(double complex z)
{
    double_complex_parts value;
    value.value = z;
    return value.part[0];
}

float (crealf)(float complex z)
{
    float_complex_parts value;
    value.value = z;
    return value.part[0];
}

long double (creall)(long double complex z)
{
    long_double_complex_parts value;
    value.value = z;
    return value.part[0];
}

double (cimag)(double complex z)
{
    double_complex_parts value;
    value.value = z;
    return value.part[1];
}

float (cimagf)(float complex z)
{
    float_complex_parts value;
    value.value = z;
    return value.part[1];
}

long double (cimagl)(long double complex z)
{
    long_double_complex_parts value;
    value.value = z;
    return value.part[1];
}

double cabs(double complex z)
{
    return hypot(creal(z), cimag(z));
}

float cabsf(float complex z)
{
    return hypotf(crealf(z), cimagf(z));
}

long double cabsl(long double complex z)
{
    return hypotl(creall(z), cimagl(z));
}

double carg(double complex z)
{
    return atan2(cimag(z), creal(z));
}

float cargf(float complex z)
{
    return atan2f(cimagf(z), crealf(z));
}

long double cargl(long double complex z)
{
    return atan2l(cimagl(z), creall(z));
}

double complex conj(double complex z)
{
    return DCMPLX(creal(z), -cimag(z));
}

float complex conjf(float complex z)
{
    return FCMPLX(crealf(z), -cimagf(z));
}

long double complex conjl(long double complex z)
{
    return LCMPLX(creall(z), -cimagl(z));
}

double complex cproj(double complex z)
{
    double x = creal(z);
    double y = cimag(z);
    if (isinf(x) || isinf(y))
        return DCMPLX(INFINITY, copysign(0.0, y));
    return z;
}

float complex cprojf(float complex z)
{
    float x = crealf(z);
    float y = cimagf(z);
    if (isinf(x) || isinf(y))
        return FCMPLX(INFINITY, copysignf(0.0f, y));
    return z;
}

long double complex cprojl(long double complex z)
{
    long double x = creall(z);
    long double y = cimagl(z);
    if (isinf(x) || isinf(y))
        return LCMPLX(INFINITY, copysignl(0.0L, y));
    return z;
}

double complex cexp(double complex z)
{
    double x = creal(z);
    double y = cimag(z);
    double magnitude;

    if (y == 0)
        return DCMPLX(exp(x), y);
    if (x == 0)
        return DCMPLX(cos(y), sin(y));
    if (!isfinite(y)) {
        if (isinf(x) && signbit(x))
            return DCMPLX(0.0, 0.0);
        if (isinf(x))
            return DCMPLX(INFINITY, y - y);
        return DCMPLX(y - y, y - y);
    }
    magnitude = exp(x);
    return DCMPLX(magnitude * cos(y), magnitude * sin(y));
}

double complex clog(double complex z)
{
    return DCMPLX(log(cabs(z)), carg(z));
}

double complex csqrt(double complex z)
{
    double x = creal(z);
    double y = cimag(z);
    double t;
    int scale = 0;

    if (x == 0 && y == 0)
        return DCMPLX(0.0, y);
    if (isinf(y))
        return DCMPLX(INFINITY, y);
    if (isnan(x)) {
        t = (y - y) / (y - y);
        return DCMPLX(x, t);
    }
    if (isinf(x)) {
        if (signbit(x))
            return DCMPLX(fabs(y - y), copysign(INFINITY, y));
        return DCMPLX(x, copysign(y - y, y));
    }

    if (fabs(x) >= DBL_MAX / 4 || fabs(y) >= DBL_MAX / 4) {
        x *= 0.25;
        y *= 0.25;
        scale = 1;
    } else if (fabs(x) < DBL_MIN * 4 && fabs(y) < DBL_MIN * 4) {
        x *= 0x1p54;
        y *= 0x1p54;
        scale = -27;
    }

    if (x >= 0) {
        double real = sqrt((x + hypot(x, y)) * 0.5);
        z = DCMPLX(real, y / (2 * real));
    } else {
        double imaginary = sqrt((-x + hypot(x, y)) * 0.5);
        z = DCMPLX(fabs(y) / (2 * imaginary),
                   copysign(imaginary, y));
    }
    if (scale == 1)
        return z * 2.0;
    if (scale == -27)
        return z * 0x1p-27;
    return z;
}

double complex ccosh(double complex z)
{
    double x = creal(z);
    double y = cimag(z);

    if (y == 0)
        return DCMPLX(cosh(x), x * y);
    if (x == 0 && !isfinite(y))
        return DCMPLX(y - y, copysign(0.0, x * (y - y)));
    if (!isfinite(y) && isfinite(x))
        return DCMPLX(y - y, x * (y - y));
    if (isinf(x)) {
        if (!isfinite(y))
            return DCMPLX(INFINITY, x * (y - y));
        return DCMPLX(INFINITY * cos(y), x * sin(y));
    }
    if (isnan(x))
        return DCMPLX((x * x) * (y - y), (x + x) * (y - y));
    return DCMPLX(cosh(x) * cos(y), sinh(x) * sin(y));
}

double complex csinh(double complex z)
{
    double x = creal(z);
    double y = cimag(z);

    if (y == 0)
        return DCMPLX(sinh(x), y);
    if (x == 0 && !isfinite(y))
        return DCMPLX(copysign(0.0, x * (y - y)), y - y);
    if (!isfinite(y) && isfinite(x))
        return DCMPLX(y - y, x * (y - y));
    if (isinf(x)) {
        if (!isfinite(y))
            return DCMPLX(INFINITY, x * (y - y));
        return DCMPLX(x * cos(y), INFINITY * sin(y));
    }
    if (isnan(x))
        return DCMPLX((x * x) * (y - y), (x + x) * (y - y));
    return DCMPLX(sinh(x) * cos(y), cosh(x) * sin(y));
}

double complex ctanh(double complex z)
{
    double x = creal(z);
    double y = cimag(z);
    double tangent;
    double beta;
    double sine;
    double denominator;

    if (!isfinite(x)) {
        if (isnan(x))
            return DCMPLX(x, y == 0 ? y : x * y);
        return DCMPLX(copysign(1.0, x),
                      copysign(0.0, isinf(y) ? y : sin(y) * cos(y)));
    }
    if (!isfinite(y))
        return DCMPLX(x ? y - y : x, y - y);
    if (fabs(x) >= 22) {
        double small = exp(-fabs(x));
        return DCMPLX(copysign(1.0, x),
                      4 * sin(y) * cos(y) * small * small);
    }
    tangent = tan(y);
    beta = 1 + tangent * tangent;
    sine = sinh(x);
    denominator = 1 + beta * sine * sine;
    return DCMPLX(beta * sqrt(1 + sine * sine) * sine / denominator,
                  tangent / denominator);
}

double complex ccos(double complex z)
{
    return ccosh(DCMPLX(-cimag(z), creal(z)));
}

double complex csin(double complex z)
{
    double complex value = csinh(DCMPLX(-cimag(z), creal(z)));
    return DCMPLX(cimag(value), -creal(value));
}

double complex ctan(double complex z)
{
    double complex value = ctanh(DCMPLX(-cimag(z), creal(z)));
    return DCMPLX(cimag(value), -creal(value));
}

double complex catan(double complex z)
{
    double x = creal(z);
    double y = cimag(z);
    double x2 = x * x;
    double real = 0.5 * atan2(2 * x, 1 - x2 - y * y);
    double lower = x2 + (y - 1) * (y - 1);
    double upper = x2 + (y + 1) * (y + 1);
    return DCMPLX(real, 0.25 * log(upper / lower));
}

double complex casin(double complex z)
{
    double x = creal(z);
    double y = cimag(z);
    double complex root = csqrt(DCMPLX(1 - (x - y) * (x + y),
                                        -2 * x * y));
    double complex value = clog(DCMPLX(-y + creal(root),
                                       x + cimag(root)));
    return DCMPLX(cimag(value), -creal(value));
}

double complex cacos(double complex z)
{
    double complex value = casin(z);
    return DCMPLX(CX_PI_2 - creal(value), -cimag(value));
}

double complex casinh(double complex z)
{
    double complex value = casin(DCMPLX(-cimag(z), creal(z)));
    return DCMPLX(cimag(value), -creal(value));
}

double complex cacosh(double complex z)
{
    int negative_imaginary = signbit(cimag(z));
    double complex value = cacos(z);
    if (negative_imaginary)
        return DCMPLX(cimag(value), -creal(value));
    return DCMPLX(-cimag(value), creal(value));
}

double complex catanh(double complex z)
{
    double complex value = catan(DCMPLX(-cimag(z), creal(z)));
    return DCMPLX(cimag(value), -creal(value));
}

double complex cpow(double complex base, double complex exponent)
{
    double complex logarithm = clog(base);
    double a = creal(exponent);
    double b = cimag(exponent);
    double c = creal(logarithm);
    double d = cimag(logarithm);
    return cexp(DCMPLX(a * c - b * d, a * d + b * c));
}

#define DEFINE_UNARY_WRAPPERS(name)                                    \
float complex name##f(float complex z)                                 \
{                                                                      \
    double complex value = name(DCMPLX(crealf(z), cimagf(z)));         \
    return FCMPLX(creal(value), cimag(value));                          \
}                                                                      \
long double complex name##l(long double complex z)                     \
{                                                                      \
    double complex value = name(DCMPLX(creall(z), cimagl(z)));         \
    return LCMPLX(creal(value), cimag(value));                          \
}

DEFINE_UNARY_WRAPPERS(cacos)
DEFINE_UNARY_WRAPPERS(casin)
DEFINE_UNARY_WRAPPERS(catan)
DEFINE_UNARY_WRAPPERS(ccos)
DEFINE_UNARY_WRAPPERS(csin)
DEFINE_UNARY_WRAPPERS(ctan)
DEFINE_UNARY_WRAPPERS(cacosh)
DEFINE_UNARY_WRAPPERS(casinh)
DEFINE_UNARY_WRAPPERS(catanh)
DEFINE_UNARY_WRAPPERS(ccosh)
DEFINE_UNARY_WRAPPERS(csinh)
DEFINE_UNARY_WRAPPERS(ctanh)
DEFINE_UNARY_WRAPPERS(cexp)
DEFINE_UNARY_WRAPPERS(clog)
DEFINE_UNARY_WRAPPERS(csqrt)

float complex cpowf(float complex base, float complex exponent)
{
    double complex value = cpow(DCMPLX(crealf(base), cimagf(base)),
                                DCMPLX(crealf(exponent), cimagf(exponent)));
    return FCMPLX(creal(value), cimag(value));
}

long double complex cpowl(long double complex base,
                          long double complex exponent)
{
    double complex value = cpow(DCMPLX(creall(base), cimagl(base)),
                                DCMPLX(creall(exponent), cimagl(exponent)));
    return LCMPLX(creal(value), cimag(value));
}
