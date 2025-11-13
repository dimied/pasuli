
#include "pillow_shape.h"
#include "surfaces_c_includes.h"

#if (USE_PILLOW_SHAPE != 0)
void PillowShape(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PILLOW_SHAPE)

    pasuli_consttype a = constants[0];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(cos_u);
    P_Y(cos_v);
    P_Z(a * sin_u * sin_v);

    UD_X(-sin_u);
    UD_Y_CONST(0);
    UD_Z(a * cos_u * sin_v);

    VD_X_CONST(0);
    VD_Y(-sin_v);
    VD_Z(a * cos_v * sin_u);

    N_X(a * cos_u * sin_v * sin_v);
    N_Y(a * cos_v * sin_u * sin_u);
    N_Z(sin_u * sin_v);

    UUD_X(-cos_u);
    UUD_Y_CONST(0);
    UUD_Z(-PASULI_COND_COPY_POS_Z(a * sin_u * sin_v));

    UVD_X_CONST(0);
    UVD_Y_CONST(0);
    UVD_Z(a * cos_u * cos_v);

    VVD_X_CONST(0);
    VVD_Y(-cos_v);
    VVD_Z(-PASULI_COND_COPY_POS_Z(a * sin_u * sin_v));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPillowShape = {
PSLDD_ID( PILLOW_SHAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_FULL_IMPL| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descPillowShape =
    "name: Pillow Shape;\
ut:c; vt:c;\
us:0; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
c1:a: 1.5;\
x: cos(u);\
y: cos(v);\
z: a*sin(u)*sin(v);\
xu: -sin(u);\
yu: 0;\
zu: a*cos(u)*sin(v);\
xv: 0;\
yv: -sin(v);\
zv: a*cos(v)*sin(u);\
xn: a*cos(u)*sin(v)*sin(v);\
yn: a*cos(v)*sin(u)*sin(u);\
zn: sin(u)*sin(v);\
xuu: -cos(u);\
yuu: 0;\
zuu: -a*sin(u)*sin(v);\
xuv: 0;\
yuv: 0;\
zuv: a*cos(u)*cos(v);\
xvv: 0;\
yvv: -cos(v);\
zvv: -a*sin(u)*sin(v);";
#endif