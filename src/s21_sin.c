#include "s21_math.h"

long double s21_sin(double x) {
    const long double eps = 1e-99l;
    long double sum = 0;
    long double row, xx = x;
    u_int64_t n = 1;
    if (s21_fabs(x) >= s21_2P)
        xx = s21_fmod(xx, s21_2P);
    row = xx;
    while (s21_fabs(row) > eps) {
        sum = sum + row;
        n = n + 2;
        row = -row * xx * xx / (n * (n - 1));
    }
    return sum;
}
