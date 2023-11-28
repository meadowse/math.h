#include "s21_math.h"

long double s21_umn(double x, int i) {
    long double res = 1;
    for (int j = 0; j < i; j++) {
        res = res * x;
    }
    return res;
}
