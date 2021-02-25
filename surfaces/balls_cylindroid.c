
#include "balls_cylindroid.h"
#include "surfaces_c_includes.h"

#if (USE_BALLS_CYLINDROID != 0)
void BallsCylindroid(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BALLS_CYLINDROID)

    pasuli_consttype k = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(k * sin_v * cos_v);

    UD_X(cos_v);
    UD_Y(sin_v);
    UD_Z(0);

    pasuli_calctype factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
    VD_X(-u * sin_v);
    VD_Y(u * cos_v);
    VD_Z(k * factor);

    N_X(k * sin_v * factor);
    N_Y(-k * cos_v * factor);
    N_Z(u);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBallsCylindroid =
    "name: Balls Cylindroid;\
ut:c; vt:o;\
us:0; ue:2;\
vs:0; ve:pi:2;\
c1:k: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: k*sin(v)*cos(v);\
xu: cos(v);\
yu: sin(v);\
zu: 0;\
xv: -u*sin(v);\
yv: u*cos(v);\
zv: k*(cos(v)^2-sin(v)^2);\
xn: k*sin(v)*(cos(v)^2-sin(v)^2);\
yn: -k*cos(v)*(cos(v)^2-sin(v)^2);\
zn: u;";
#endif
