
#include "cuspidal_lips.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_LIPS != 0)
void CuspidalLips(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CUSPIDAL_LIPS)

    pasuli_calctype u2 = u * u;
    pasuli_calctype v2 = v * v;

    P_X(u);
    P_Y((2 * v2 + u2) * v);
    P_Z((3 * v2 + u2) * v2);

    UD_X(1);
    UD_Y(2 * u * v);
    UD_Z(2 * u * v2);

    // Ignore scaling by u^2+6*v^2
    pasuli_calctype factor = u2 + 6 * v2;
    factor = PASULI_CALC_SIGN(factor);
    VD_X(0);
    VD_Y(factor);
    VD_Z(2 * v * factor);

    // Ignore scaling by u^2+6*v^2
    N_X(2 * u * v2 * factor);
    N_Y(-2 * v * factor);
    N_Z(factor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalLips =
    "name: Cuspidal Lips;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.5; ve:0.5;\
x: u;\
y: 2*v^3+u^2*v;\
z: 3*v^4+u^2*v^2;\
xu: 1;\
yu: 2*u*v;\
zu: 2*u*v^2;\
xv: 0;\
yv: u^2+6*v^2;\
zv: 2*v*(u^2+6*v^2);\
xn: 2*u*v*v*(u^2+6*v^2);\
yn: -2*v*(u^2+6*v^2);\
zn: u^2+6*v^2;";
#endif
