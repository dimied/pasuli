
#include "cuspidal_butterfly.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_BUTTERFLY != 0)
void CuspidalButterfly(pasuli_vartype u,
                       pasuli_vartype v,
                       pasuli_consttype *constants,
                       PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CUSPIDAL_BUTTERFLY)

    pasuli_calctype v2 = v * v;

    P_X(u);
    P_Y(5 * v2 * v2 + 2 * u * v);
    P_Z(5 * v2 * v2 * v + u * v2);

    UD_X(1);
    UD_Y(2 * v);
    UD_Z(v * v);

    // Ignore scaling by 2*u+20*v^3
    pasuli_calctype factor = 2 * u + 20 * v2 * v;
    factor = PASULI_CALC_SIGN(factor);
    VD_X(0);
    VD_Y(factor);
    VD_Z(v * factor);

    // Ignore scaling by 2*u+20*v^3
    N_X(v2 * factor);
    N_Y(-v * factor);
    N_Z(factor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalButterfly =
    "name: Cuspidal Butterfly;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.5; ve:0.5;\
x: u;\
y: 5*v^4+2*u*v;\
z: 4*v^5+u*v^2;\
xu: 1;\
yu: 2*v;\
zu: v*v;\
xv: 0;\
yv: 2*u+20*v^3;\
zv: v*(2*u+20*v^3);\
xn: v*v*(2*u+20*v^3);\
yn: -v*(2*u+20*v^3);\
zn: 2*u+20*v^3;";
#endif
