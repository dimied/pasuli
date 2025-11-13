
#include "cuspidal_beaks.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_BEAKS != 0)
void CuspidalBeaks(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CUSPIDAL_BEAKS)

    pasuli_calctype u2 = u * u;
    pasuli_calctype v2 = v * v;

    P_X(u);
    P_Y(v * (2 * v2 - u2));
    P_Z(v2 * (3 * v2 - u2));

    UD_X(1);
    UD_Y(-2 * u * v);
    UD_Z(-2 * u * v2);

    pasuli_calctype factor = 6 * v2 - u2;
    //Ignore scaling by 6*v*v-u*u
    factor = PASULI_CALC_SIGN(factor);
    VD_X(0);
    VD_Y(factor);
    VD_Z(2 * v * factor);

    //Ignore scaling by 6*v*v-u*u
    N_X(-2 * u * v2 * factor);
    N_Y(-2 * v * factor);
    N_Z(factor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalBeaks =
    "name: Cuspidal Beaks;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.75; ve:0.75;\
x: u;\
y: 2*v^3-u^2*v;\
z: 3*v^4-u^2*v^2;\
xu: 1;\
yu: -2*u*v;\
zu: -2*u*v*v;\
xv: 0;\
yv: 6*v*v-u*u;\
zv: 2*v*(6*v*v-u*u);\
xn: 2*u*v*v*(u^2-6*v*v);\
yn: 2*v*(u^2-6*v*v);\
zn: 6*v*v-u*u;";
#endif
