#include <stdio.h>

typedef float _Complex complex_float;
typedef double _Complex complex_double;
typedef long double _Complex complex_long_double;

static volatile double left_real = 3.0;
static volatile double left_imaginary = 4.0;
static volatile double right_real = 1.0;
static volatile double right_imaginary = -2.0;

static int check_float(void)
{
    union { complex_float value; float part[2]; } product, quotient;

    product.value = __builtin_complex((float)left_real,
                                      (float)left_imaginary)
        * __builtin_complex((float)right_real, (float)right_imaginary);
    quotient.value = __builtin_complex((float)left_real,
                                       (float)left_imaginary)
        / __builtin_complex((float)right_real, (float)right_imaginary);
    return product.part[0] == 11.0f && product.part[1] == -2.0f
        && quotient.part[0] == -1.0f && quotient.part[1] == 2.0f;
}

static int check_double(void)
{
    union { complex_double value; double part[2]; } product, quotient;

    product.value = __builtin_complex(left_real, left_imaginary)
        * __builtin_complex(right_real, right_imaginary);
    quotient.value = __builtin_complex(left_real, left_imaginary)
        / __builtin_complex(right_real, right_imaginary);
    return product.part[0] == 11.0 && product.part[1] == -2.0
        && quotient.part[0] == -1.0 && quotient.part[1] == 2.0;
}

static int check_long_double(void)
{
    union {
        complex_long_double value;
        long double part[2];
    } product, quotient;

    product.value = __builtin_complex((long double)left_real,
                                      (long double)left_imaginary)
        * __builtin_complex((long double)right_real,
                            (long double)right_imaginary);
    quotient.value = __builtin_complex((long double)left_real,
                                       (long double)left_imaginary)
        / __builtin_complex((long double)right_real,
                            (long double)right_imaginary);
    return product.part[0] == 11.0L && product.part[1] == -2.0L
        && quotient.part[0] == -1.0L && quotient.part[1] == 2.0L;
}

int main(void)
{
    if (!check_float() || !check_double() || !check_long_double()) {
        printf("complex runtime helpers: failed\n");
        return 1;
    }
    printf("complex runtime helpers: ok\n");
    return 0;
}
