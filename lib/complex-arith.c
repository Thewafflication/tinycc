/*
 * Recovery helpers for complex multiplication and division.
 *
 * Finite operands use power-of-two scaling. Infinite operands follow the
 * recovery structure used by established compiler runtimes.
 */
#include <math.h>

#define DEFINE_COMPLEX_ARITHMETIC(type, suffix, absolute, exponent,     \
                                  scale_power)                          \
void __tcc_mul##suffix(type a, type b, type c, type d, type *out)       \
{                                                                      \
    type ac = a * c;                                                    \
    type bd = b * d;                                                    \
    type ad = a * d;                                                    \
    type bc = b * c;                                                    \
    type x = ac - bd;                                                   \
    type y = ad + bc;                                                   \
                                                                       \
    if (isfinite(a) && isfinite(b) && isfinite(c) && isfinite(d)) {     \
        type left_scale = absolute(a) > absolute(b)                     \
            ? absolute(a) : absolute(b);                               \
        type right_scale = absolute(c) > absolute(d)                    \
            ? absolute(c) : absolute(d);                               \
        if (left_scale != 0 && right_scale != 0) {                      \
            int left_exponent = exponent(left_scale);                  \
            int right_exponent = exponent(right_scale);                \
            type scaled_a = scale_power(a, -left_exponent);            \
            type scaled_b = scale_power(b, -left_exponent);            \
            type scaled_c = scale_power(c, -right_exponent);           \
            type scaled_d = scale_power(d, -right_exponent);           \
            type scaled_x = scaled_a * scaled_c                        \
                - scaled_b * scaled_d;                                 \
            type scaled_y = scaled_a * scaled_d                        \
                + scaled_b * scaled_c;                                 \
            x = scale_power(scaled_x,                                  \
                            left_exponent + right_exponent);           \
            y = scale_power(scaled_y,                                  \
                            left_exponent + right_exponent);           \
        }                                                              \
    }                                                                  \
                                                                       \
    if (isnan(x) && isnan(y)) {                                        \
        int recalculate = 0;                                           \
        if (isinf(a) || isinf(b)) {                                    \
            a = copysign(isinf(a) ? (type)1 : (type)0, a);             \
            b = copysign(isinf(b) ? (type)1 : (type)0, b);             \
            if (isnan(c))                                              \
                c = copysign((type)0, c);                              \
            if (isnan(d))                                              \
                d = copysign((type)0, d);                              \
            recalculate = 1;                                           \
        }                                                              \
        if (isinf(c) || isinf(d)) {                                    \
            c = copysign(isinf(c) ? (type)1 : (type)0, c);             \
            d = copysign(isinf(d) ? (type)1 : (type)0, d);             \
            if (isnan(a))                                              \
                a = copysign((type)0, a);                              \
            if (isnan(b))                                              \
                b = copysign((type)0, b);                              \
            recalculate = 1;                                           \
        }                                                              \
        if (!recalculate                                               \
            && (isinf(ac) || isinf(bd) || isinf(ad) || isinf(bc))) {   \
            if (isnan(a))                                              \
                a = copysign((type)0, a);                              \
            if (isnan(b))                                              \
                b = copysign((type)0, b);                              \
            if (isnan(c))                                              \
                c = copysign((type)0, c);                              \
            if (isnan(d))                                              \
                d = copysign((type)0, d);                              \
            recalculate = 1;                                           \
        }                                                              \
        if (recalculate) {                                             \
            x = (type)INFINITY * (a * c - b * d);                      \
            y = (type)INFINITY * (a * d + b * c);                      \
        }                                                              \
    }                                                                  \
    out[0] = x;                                                        \
    out[1] = y;                                                        \
}                                                                      \
                                                                       \
void __tcc_div##suffix(type a, type b, type c, type d, type *out)       \
{                                                                      \
    type ratio;                                                        \
    type denominator;                                                  \
    type x;                                                            \
    type y;                                                            \
                                                                       \
    if (isfinite(a) && isfinite(b) && isfinite(c) && isfinite(d)       \
        && (c != 0 || d != 0)) {                                       \
        type denominator_scale = absolute(c) > absolute(d)             \
            ? absolute(c) : absolute(d);                               \
        type numerator_scale = absolute(a) > absolute(b)               \
            ? absolute(a) : absolute(b);                               \
        int denominator_exponent = exponent(denominator_scale);        \
        type scaled_c = scale_power(c, -denominator_exponent);         \
        type scaled_d = scale_power(d, -denominator_exponent);         \
        denominator = scaled_c * scaled_c + scaled_d * scaled_d;       \
        if (numerator_scale == 0) {                                    \
            x = scale_power((a * scaled_c + b * scaled_d)              \
                            / denominator, -denominator_exponent);     \
            y = scale_power((b * scaled_c - a * scaled_d)              \
                            / denominator, -denominator_exponent);     \
        } else {                                                       \
            int numerator_exponent = exponent(numerator_scale);        \
            type scaled_a = scale_power(a, -numerator_exponent);       \
            type scaled_b = scale_power(b, -numerator_exponent);       \
            int result_exponent = numerator_exponent                   \
                - denominator_exponent;                               \
            x = scale_power((scaled_a * scaled_c                       \
                             + scaled_b * scaled_d) / denominator,     \
                            result_exponent);                          \
            y = scale_power((scaled_b * scaled_c                       \
                             - scaled_a * scaled_d) / denominator,     \
                            result_exponent);                          \
        }                                                              \
    } else if (absolute(c) < absolute(d)) {                            \
        ratio = c / d;                                                 \
        denominator = c * ratio + d;                                  \
        x = (a * ratio + b) / denominator;                             \
        y = (b * ratio - a) / denominator;                             \
    } else {                                                           \
        ratio = d / c;                                                 \
        denominator = d * ratio + c;                                  \
        x = (b * ratio + a) / denominator;                             \
        y = (b - a * ratio) / denominator;                             \
    }                                                                  \
                                                                       \
    if (isnan(x) && isnan(y)) {                                        \
        if (c == 0 && d == 0 && (!isnan(a) || !isnan(b))) {            \
            type infinity = copysign((type)INFINITY, c);               \
            x = infinity * a;                                         \
            y = infinity * b;                                         \
        } else if ((isinf(a) || isinf(b))                              \
                   && isfinite(c) && isfinite(d)) {                    \
            a = copysign(isinf(a) ? (type)1 : (type)0, a);             \
            b = copysign(isinf(b) ? (type)1 : (type)0, b);             \
            x = (type)INFINITY * (a * c + b * d);                      \
            y = (type)INFINITY * (b * c - a * d);                      \
        } else if ((isinf(c) || isinf(d))                              \
                   && isfinite(a) && isfinite(b)) {                    \
            c = copysign(isinf(c) ? (type)1 : (type)0, c);             \
            d = copysign(isinf(d) ? (type)1 : (type)0, d);             \
            x = (type)0 * (a * c + b * d);                            \
            y = (type)0 * (b * c - a * d);                            \
        }                                                              \
    }                                                                  \
    out[0] = x;                                                        \
    out[1] = y;                                                        \
}

DEFINE_COMPLEX_ARITHMETIC(double, dc3, fabs, ilogb, scalbn)
DEFINE_COMPLEX_ARITHMETIC(long double, xc3, fabsl, ilogbl, scalbnl)
