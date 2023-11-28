#include "s21_math.h"

long double s21_exp(double x) {
    long double res = 0;
    if (x < 0) {
        res = 1 / s21_exp((-1) * x);
    } else {
        long double eps = 1e-99l;
        long double dif = 1;
        long double res2;
        int k = 0;
        while (dif > eps) {
            double buffer = 1;
            for (int j = 1; j <= k; j++) {
                buffer *= x;
                buffer /= j;
            }
            res += buffer;
            if (k > 0) dif = s21_fabs(res - res2);
            res2 = res;
            k++;
        }
    }
    return res;
}
