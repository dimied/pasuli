
#include "bell_polar.h"
#include "surfaces_c_includes.h"

#if (USE_BELL_POLAR != 0)
void BellPolar(double u, double v,
               double *constants,
               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BELL_POLAR)

    double a = constants[0];
    double b = constants[1];

    double be = b * exp(-a * a * v * v);
    P_X(v * cos(u));
    P_Y(v * sin(u));
    //v = sqrt(v*cos(u)*v*cos(u) + v*sin(u)*v*sin(u)) = sqrt(v*v) = v
    P_Z(be);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);
#endif

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
PaSuLiDefDesc pslddBellPolar = {
PSLDD_ID( BELL_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBellPolar =
    "name: Bell Polar; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs: 0; ve: 12; \
c1:a: 1.5; c2:b: 0.5; \
a:1:r: sqrt(2*v*v) = sqrt(x*x + y*y); \
x: v*cos(u); \
y: v*sin(u); \
z: b*exp(-(a*r)^(2)); \
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