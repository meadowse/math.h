#include "s21_math.h"

long double s21_acos(double x) {
    return -1 <= x && x <= 1 ? s21_P_2 - s21_asin(x) : 0 / 0.0;
}
