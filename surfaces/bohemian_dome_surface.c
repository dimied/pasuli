
#include "bohemian_dome_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_BOHEMIAN_DOME_SURFACE != 0)

void BohemianDomeSurface(double u, double v,
                         double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOHEMIAN_DOME_SURFACE)
    double a = constants[0];
    double b = constants[1];
    double c = constants[2];

    double cos_u = cos(u);
    double sin_u = sin(u);
    double cos_v = cos(v);
    double sin_v = sin(v);

    P_X(a * cos_u);
    P_Y(b * cos_v + a * sin_u);
    P_Z(c * sin_v);

    UD_X(-a * sin_u);
    UD_Y(a * cos_u);
    UD_Z(0);

    VD_X(0);
    VD_Y(-b * sin_v);
    VD_Z(c * cos_v);

    N_X(a * c * cos_u * cos_v);
    N_Y(-a * c * sin_u * cos_v);
    N_Z(a * b * sin_u * cos_v);

    UUD_X(-a * cos_u);
    UUD_Y(-a * sin_u);
    UUD_Z(0);

    UVD_X(0);
    UVD_Y(0);
    UVD_Z(0);

    VVD_X(0);
    VVD_Y(-b * cos_v);
    VVD_Z(-c * sin_v);
}

#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBohemianDomeSurface = {
PSLDD_ID( BOHEMIAN_DOME_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBohemianDomeSurface =
"name: Bohemian Dome Surface; \
ut:c; \
vt:c; \
us: 0; ue:pi:2; vs:0; ve:pi:2; \
c1:a:1; \
c2:b:1; \
c3:c:1; \
x: a*cos(u); \
y: b*cos(v) + a*sin(u); \
z: c*sin(v); \
xu: -a*sin(u); \
yu: a*cos(u); \
zu: 0; \
xv: 0; \
yv: -b*sin(v); \
zv: c*cos(v); \
xn: a*c*cos(u)*cos(v); \
yn: -a*c*sin(u)*cos(v); \
zn: a*b*sin(u)*sin(v); \
xuu: -a*cos(u); \
yuu: -a*sin(u); \
zuu: 0; \
xuv: 0; yuv: 0; zuv: 0; \
xvv: 0; \
yvv: -b*cos(v); \
zvv: -c*sin(v);";
#endif