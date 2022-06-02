#include "s21_math.h"

long double s21_log(double n) {
    long double eps = 1e-99l;
    long double res = 0;
    if (n < 0) {
        res = 0 / 0.0;
    } else if (n == 0) {
        res = -1 / 0.0;
    } else if (n > 1) {
        int counter = 0;
        while (n > 1) {
            n /= 10;
            counter++;
        }
        res = s21_log(n) + counter * s21_LN10;
    } else if (n < 0.1) {
        int counter = 0;
        while (n < 0.1) {
            n *= 10;
            counter++;
        }
        res = s21_log(n) - counter * s21_LN10;
    } else {
        n -= 1;
        long double dif = 1;
        long double res2 = n;
        int k = 1;
        while (dif > eps) {
            long double current = 1;
            for (int j = 1; j <= k; ++j) {
                current *= n;
            }
            current /= k;
            res += s21_umn(-1, k + 1) * current;
            if (k > 1) dif = s21_fabs(res - res2);
            res2 = res;
            k++;
        }
    }
    return res;
}
