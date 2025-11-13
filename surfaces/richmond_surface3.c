
#include "richmond_surface3.h"
#include "surfaces_c_includes.h"

#if (USE_RICHMOND_SURFACE3 != 0)
void RichmondSurface3(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(RICHMOND_SURFACE3)

    pasuli_consttype n = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype u_pow_2n_1 = pow(u, 2 * n + 1);
    pasuli_calctype divisor = 4 * n + 2;

    P_X(-cos_v / (2 * u) - (u_pow_2n_1 * cos(-(2 * n + 1) * v)) / divisor);
    P_Y(-sin_v / (2 * u) + (u_pow_2n_1 * sin(-(2 * n + 1) * v)) / divisor);
    P_Z(pow(u, n) * cos(n * v) / n);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface3 =
    "name: Richmond Surface 3;\
ut:c; vt:o;\
us:0.5; ue:1;\
vs:0; ve:pi:2;\
c1:n: 2;\
x: -cos(v)/(2*u)-(u^(2*n+1)*cos(-(2*n+1)*v))/(4*n+2);\
y: -sin(v)/(2*u)+(u^(2*n+1)*sin(-(2*n+1)*v))/(4*n+2);\
z: u^n*cos(n*v)/n;";
#endif
