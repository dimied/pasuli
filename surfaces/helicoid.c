
#include "helicoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HELICOID != 0)
void Helicoid(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HELICOID)

    pasuli_consttype c = constants[0];
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(c * v);

    UD_X(cos_v);
    UD_Y(sin_v);
    UD_Z_CONST(0);

    VD_X(-PASULI_COND_COPY_POS_Y(u * sin_v));
    VD_Y(PASULI_COND_COPY_POS_X(u * cos_v));
    VD_Z(c);

    N_X(c * sin_v);
    N_Y(-c * cos_v);
    N_Z(u);

    UUD_ALL(0);

    UVD_X(-sin_v);
    UVD_Y(cos_v);
    UVD_Z_CONST(0);

    VVD_X(-PASULI_COND_COPY_POS_X(u * cos_v));
    VVD_Y(-PASULI_COND_COPY_POS_Y(u * sin_v));
    VVD_Z_CONST(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHelicoid = {
PSLDD_ID( HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descHelicoid =
    "name: Helicoid;\
ut: c; vt: c;\
us:-2; ue:2;\
vs:0; ve:pi:2;\
c1:c: 1.5;\
x: u*cos(v);\
y: u*sin(v);\
z: c*v;\
xu: cos(v);\
yu: sin(v);\
zu: 0;\
xv: -u*sin(v);\
yv: u*cos(v);\
zv: c;\
xn: c*sin(v);\
yn: -c*cos(v);\
zn: u;\
xuu: 0;\
yuu: 0;\
zuu: 0;\
xuv: -sin(v);\
yuv: cos(v);\
zuv: 0;\
xvv: -u*cos(v);\
yvv: -u*sin(v);\
zvv: 0; ";
#endif