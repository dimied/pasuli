
#include "moebius_band2.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_MOEBIUS_BAND2 != 0)
void MoebiusBand2(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MOEBIUS_BAND2)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype m = constants[2];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_mv_half = cos(m * v * 0.5);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_mv_half = sin(m * v * 0.5);

    P_X((a + u * sin_mv_half) * cos_v);
    P_Y((b + u * sin_mv_half) * sin_v);
    P_Z(u * cos_mv_half);

    UD_X(sin_mv_half * cos_v);
    UD_Y(sin_mv_half * sin_v);
    UD_Z(cos_mv_half);

    VD_X(-a * sin_v + u * (0.5 * m * cos_v * cos_mv_half - sin_mv_half * sin_v));
    VD_Y(b * cos_v + u * (0.5 * m * sin_v * cos_mv_half + cos_v * sin_mv_half));
    VD_Z(-0.5 * m * u * sin_mv_half);

    PASULI_CALC_NORMAL_FROM_UD_VD
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
char *descMoebiusBand2 =
    "name: Moebius Band 2;\
ut: c; vt: c;\
us: -0.4; ue: 0.4;\
vs: 0; ve:pi: 2;\
c1:a: 1; c2:b: 1; c3:m: 1;\
x: (a + u*sin(m*v/2))*cos(v);\
y: (b + u*sin(m*v/2))*sin(v);\
z: u*cos(m*v/2);\
xu: cos(v)*sin(0.5*m*v);\
yu: sin(v)*sin(0.5*m*v);\
zu: cos(0.5*m*v);\
xv: -a*sin(v) - 0.5*m*u*cos(v)*cos(0.5*m*v)-u*sin(0.5*m*v)*sin(v);\
yv: b*cos(v) + u*(0.5*m*sin(v)*cos(0.5*m*v) + cos(v)*sin(0.5*m*v));\
zv: -0.5*m*u*sin(0.5*m*v);";
#endif