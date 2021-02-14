
#include "bow_curve.h"
#include "surfaces_c_includes.h"

#if (USE_BOW_CURVE != 0)

void BowCurve(double u, double v,
              double *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOW_CURVE)

    double T = constants[0];

    u = 2.0 * MY_PI * u;
    double cu = T * cos(u);
    double su = T * sin(u);
    double sv = sin(2 * v);
    double cv = cos(2 * v);
    double xy = 2.0 + su;

    P_X(xy * sv);
    P_Y(xy * cv);
    P_Z(cu + 3.0 * cv);

    UD_X(0);
    UD_Y(0);
    UD_Z(0);

    VD_X(0);
    VD_Y(0);
    VD_Z(0);

    N_X(0);
    N_Y(0);
    N_Z(0);

    UUD_X(0);
    UUD_Y(0);
    UUD_Z(0);

    UVD_X(0);
    UVD_Y(0);
    UVD_Z(0);

    VVD_X(0);
    VVD_Y(0);
    VVD_Z(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBowCurve = {
PSLDD_ID( BOW_CURVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBowCurve =
    "name: Bow Curve; \
ut:c; vt:c; \
us: 0; ue: 1; \
vs: 0; ve: 1; \
c1:T: 1.5; \
x: (2 + T*sin(2*pi*u))*sin(4*pi*v); \
y: (2 + T*sin(2*pi*u))*cos(4*pi*v); \
z: T*cos(2*pi*u) + 3*cos(2*pi*v); \
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