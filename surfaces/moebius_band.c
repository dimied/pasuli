
#include "moebius_band.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_MOEBIUS_BAND != 0)
void MoebiusBand(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MOEBIUS_BAND)

    pasuli_consttype r = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_v_half = cos(v * 0.5);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_v_half = sin(v * 0.5);

    pasuli_calctype factor = u * cos_v_half + r;

    P_X(factor * cos_v);
    P_Y(factor * sin_v);
    P_Z(u * sin_v_half);

    UD_X(cos_v_half * cos_v);
    UD_Y(cos_v_half * sin_v);
    UD_Z(sin_v_half);

    VD_X(-r * sin_v - u * (0.5 * cos_v * sin_v_half + cos_v_half * sin_v));
    VD_Y(r * cos_v + u * (cos_v * cos_v_half - 0.5*sin_v * sin_v_half));
    VD_Z(0.5 * u * cos_v_half);

    N_X(-factor * sin_v_half * cos_v + 0.5 * u * sin_v);
    N_Y(-factor * sin_v_half * cos_v - 0.5 * u * cos_v);
    N_Z(factor * cos_v_half);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMoebiusBand = {
PSLDD_ID( MOEBIUS_BAND )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descMoebiusBand =
    "name: Moebius Band;\
ut: c; vt: c;\
us: -1; ue: 1;\
vs:0; ve:pi:2;\
c1:r: 1.5;\
x: (r + u*cos(v/2))*cos(v);\
y: (r + u*cos(v/2))*sin(v);\
z: u*sin(v/2);\
xu: cos(v)*cos(0.5*v);\
yu: sin(v)*cos(0.5*v);\
zu: sin(0.5*v);\
xv: -r*sin(v) - 0.5*u*cos(v)*sin(0.5*v)-u*cos(0.5*v)*sin(v);\
yv: r*cos(v) + u*(cos(v)*cos(0.5*v)-0.5*sin(v)*sin(0.5*v));\
zv: 0.5*u*cos(0.5*v);\
xn: -sin(0.5*v)*cos(v)*(r + u*cos(0.5*v)) + 0.5*u*sin(v);\
yn: -sin(0.5*v)*sin(v)*(r+u*cos(0.5*v)) - 0.5*u*cos(v);\
zn: (r+u*cos(0.5*v))*cos(0.5*v);\
xuu: 0;\
yuu: 0;\
zuu: 0;\
xuv: -0.5*cos(v)*sin(0.5*v) - cos(0.5*v)*sin(v);\
yuv: cos(v)*cos(0.5*v) - 0.5*sin(v)*sin(0.5*v);\
zuv: 0.5*cos(0.5*v);\
xvv: u*(sin(v)*sin(0.5*v) - 5*cos(v)*cos(0.5*v)/4) - r*cos(v);\
yvv: -u*(cos(v)*sin(0.5*v) + 5*cos(0.5*v)*sin(v)/4) - r*sin(v);\
zvv: -u*sin(0.5*v)/4; ";
#endif