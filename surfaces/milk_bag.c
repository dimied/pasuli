
#include "milk_bag.h"
#include "surfaces_c_includes.h"

#if (USE_MILK_BAG != 0)
void MilkBag(double u, double v,
             double *constants,
             PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MILK_BAG)

    double K = constants[0];
    double cv = cos(v);
    double sv = sin(v);

    P_X(K * (1 + u) * cos(v));
    P_Y(K * (1 - u) * sin(v));
    P_Z(u);

    UD_X(K * cv);
    UD_Y(-K * sv);
    UD_Z(1);

    VD_X(-K * (1 + u) * sv);
    VD_Y(K * (1 - u) * cv);
    VD_Z(0);

    N_X(-K * (1 - u) * cv);
    N_Y(K * (1 + u) * sv);
    N_Z(K * K * (cv * cv * (1 - u) + sv * sv * (1 + u)));

    UUD_X(0);
    UUD_Y(0);
    UUD_Z(0);

    UVD_X(-sv);
    UVD_Y(-cv);
    UVD_Z(0);

    VVD_X(-K * (1 + u) * cv);
    VVD_Y(-K * (1 + u) * sv);
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
    "name: Milk Bag; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs:pi: -1; ve:pi: 1; \
c1:k: 1.0; \
x: k*(1 + u)*cos(v); \
y: k*(1 - u)*sin(v); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif