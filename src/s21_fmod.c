#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double res = 0;
    if (y == 0)
        res = 0 / 0.0;
    else if (x < 0 && y < 0)
        res = s21_abs(x / y);
    else if (x < 0 || y < 0)
        res = -s21_abs(x / y);
    else
        res = s21_abs(x / y);
    if (res != 0 / 0.0)
        res = x - res * y;
    return res;
}
