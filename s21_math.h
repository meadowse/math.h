#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

#define s21_E           2.71828182845  // e
#define s21_LOG2E       1.44269504088  // log 2e
#define s21_LOG10E      0.43429448190  // log 10e
#define s21_LN2         0.69314718055  // log e2
#define s21_LN10        2.30258509299  // log e10
#define s21_1_P         0.31830988618  // 1/pi
#define s21_2_P         0.63661977236  // 2/pi
#define s21_2_SQRTP     1.12837916709  // 2/sqrt(pi)
#define s21_SQRT2       1.41421356237  // sqrt(2)
#define s21_SQRT1_2     0.70710678118  // 1/sqrt(2)

#define s21_NUN         0.0 / 0.0
#define s21_INF         1.0 / 0.0
#define s21_MAX_D       9223372036854775807.0

#define s21_P_6         0.52359877559
#define s21_P_4         0.78539816339  // pi/4
#define s21_P_3         1.0471975512
#define s21_P_2         1.57079632679  // pi/2
#define s21_2P_3        2.09439510239
#define s21_3P_4        2.35619449019
#define s21_5P_6        2.61799387799
#define s21_P           3.14159265358  // pi
#define s21_7P_6        3.66519142919
#define s21_5P_4        3.92699081699
#define s21_4P_3        4.18879020479
#define s21_3P_2        4.71238898038
#define s21_5P_3        5.23598775598
#define s21_7P_4        5.49778714378
#define s21_11P_6       5.75958653158
#define s21_5P_3        5.23598775598
#define s21_2P          6.28318530718
#define s21_EPS         1e-99l

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_sqrt(double x);
long double s21_umn(double x, int i);
#endif  //  SRC_S21_MATH_H_
