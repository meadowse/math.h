#include "s21_math.h"

long double s21_tan(double x) {
    long double out;
    long double s = s21_sin(x);
    long double c = s21_cos(x);
    out = s / c;
    return out;
}
