
#include "peano_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_PEANO_SURFACE2 != 0)
void PeanoSurface2(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PEANO_SURFACE2)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];
    pasuli_consttype d = constants[3];

    pasuli_calctype u2 = u * u;

    P_X(u);
    P_Y(v);
    P_Z((2 * a * u2 - b * v) * (c * v - d * u2));

    UD_X(1);
    UD_Y(0);
    UD_Z(2 * u * (3 * a * c * v - 4 * a * d * u2 + 2 * b * d * v));

    VD_X(0);
    VD_Y(1);
    VD_Z(2 * (a * c * u2 - b * c * v + b * d * u2));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
// Own invention
char *descPeanoSurface2 =
    "name: Peano Surface 2;\
ut:o; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
c1:a: 1; c2:b: 1; c3:c: 1; c4:d: 1;\
x: u;\
y: v;\
z: (2*a*u^2-b*v)*(c*v-d*u^2);\
xu: 1;\
yu: 0;\
zu: 2*u*(3*a*c*v-4*a*d*u^2 + 2*b*d*v);\
xv: 0;\
yv: 1;\
zv: 2*(a*c*u*u-b*c*v+b*d*u*u);";
#endif
