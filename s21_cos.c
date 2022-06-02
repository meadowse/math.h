#include "s21_math.h"

long double s21_cos(double x) {
    const long double eps = 1e-99l;
    long double res = 0;
    long double row = 1, dx = x;
    u_int64_t n = 0;
    if (s21_fabs(x) >= s21_2P)
        dx = s21_fmod(dx, s21_2P);
    while (s21_fabs(row) > eps) {
        res = res + row;
        n = n + 2;
        row = -row * dx * dx / (n * (n - 1));
    }
    return res;
}
