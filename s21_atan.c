#include "s21_math.h"

long double s21_atan(double x) {
    double a, z, p, r, s, q, o;
    z = s21_fabs(x);
    a = (z > 1.0) ? 1.0 / z : z;
    s = a * a;
    q = s * s;
    o = q * q;
    p = fma(fma(fma(-0x1.53e1d2a25ff34p-16, s, 0x1.d3b63dbb65af4p-13), q,
                fma(-0x1.312788dde0801p-10, s, 0x1.f9690c82492dbp-9)), o,
             fma(fma(-0x1.2cf5aabc7cef3p-7, s, 0x1.162b0b2a3bfcep-6), q,
                fma(-0x1.a7256feb6fc5cp-6, s, 0x1.171560ce4a483p-5)));
    p = fma(fma(fma(fma(fma(fma(fma(fma(fma(fma(fma(fma(p, s,
        -0x1.4f44d841450e1p-5), s,
         0x1.7ee3d3f36bb94p-5), s,
        -0x1.ad32ae04a9fd1p-5), s,
         0x1.e17813d66954fp-5), s,
        -0x1.11089ca9a5bcdp-4), s,
         0x1.3b12b2db51738p-4), s,
        -0x1.745d022f8dc5cp-4), s,
         0x1.c71c709dfe927p-4), s,
        -0x1.2492491fa1744p-3), s,
         0x1.99999999840d2p-3), s,
        -0x1.555555555544cp-2) * s, a, a);
    r = (z > 1.0) ? (0x1.921fb54442d18p+0 - p) : p;
    return copysign (r, x);
}
