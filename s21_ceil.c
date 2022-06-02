#include "s21_math.h"

long double s21_ceil(double x) {
    long int tmp = x + 0.0;
    return x < 0 ? (long double)tmp : x - tmp == 0 ? (long double)tmp : (long double)(tmp + 1);
}
