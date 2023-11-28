#include "s21_math.h"

long double s21_fabs(double x) {
    return ( x > 0 ? (long double)x : (long double)(x *= -1));
}
