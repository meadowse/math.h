#include "s21_math.h"

long double s21_pow(double x, double y) {
    return y < 0 ? 1 / s21_exp(-y * s21_log(x)) : (y == 0) ? 1 : s21_exp(y * s21_log(x));
}
