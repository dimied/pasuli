
#include "milk_bag.h"
#include "surfaces_c_includes.h"

#if (USE_MILK_BAG != 0)
void MilkBag(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MILK_BAG)

    pasuli_consttype K = constants[0];
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(K * (1 + u) * cos_v);
    P_Y(K * (1 - u) * sin_v);
    P_Z(u);

    UD_X(K * cos_v);
    UD_Y(-K * sin_v);
    UD_Z(1);

    VD_X(-K * (1 + u) * sin_v);
    VD_Y(K * (1 - u) * cos_v);
    VD_Z(0);

    N_X(-K * (1 - u) * cos_v);
    N_Y(K * (1 + u) * sin_v);
    pasuli_calctype difference = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
    N_Z(K * K * (difference - u));

    UUD_ALL(0);

    UVD_X(-K * sin_v);
    UVD_Y(-K * cos_v);
    UVD_Z(0);

    VVD_X(-PASULI_COND_COPY_POS_X(K * (1 + u) * cos_v));
    VVD_Y(-PASULI_COND_COPY_POS_Y(K * (1 - u) * sin_v));
    VVD_Z(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMilkBag = {
PSLDD_ID( MILK_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descMilkBag =
    "name: Milk Bag;\
ut:c; vt:c;\
us: -1; ue: 1;\
vs:pi: -1; ve:pi:1;\
c1:k: 1.0;\
x: k*(1 + u)*cos(v);\
y: k*(1 - u)*sin(v);\
z: u;\
xu: k*cos(v);\
yu: -k*sin(v);\
zu: 1;\
xv: -k*(1+u)*sin(v);\
yv: k*(1-u)*cos(v);\
zv: 0;\
xn: -k*(1-u)*cos(v);\
yn: -k*(1+u)*sin(v);\
zn: -k^2*u + k^2*(cos(v)^2 - sin(v)^2);\
xuu: 0;\
yuu: 0;\
zuu: 0;\
xuv: -k*sin(v);\
yuv: -k*cos(v);\
zuv: 0;\
xvv: -k*(1+u)*cos(v);\
yvv: -k*(1 - u)*sin(v);\
zvv: 0;  ";
#endif