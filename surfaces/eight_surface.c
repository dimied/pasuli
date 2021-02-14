
#include "eight_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_EIGHT_SURFACE != 0)
void EightSurface(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(EIGHT_SURFACE)

    double su = sin(u);
    double cu = cos(u);

    P_X(cu * sin(2 * v));
    P_Y(su * sin(2 * v));
    P_Z(sin(v));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEightSurface = {
PSLDD_ID( EIGHT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
0, 2 , -0.5 , 0.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEightSurface =
"name: Eight Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs:pi: -0.5; ve:pi: 0.5; \
x: cos(u)*sin(2*v); \
y: sin(u)*sin(2*v); \
z: sin(v); "
"xu: -sin(u)*sin(2*v); \
yu: cos(u)*sin(2*v); \
zu: 0; "
"xv: 2*cos(u)*cos(2*v); \
yv: 2*cos(2*v)*sin(u); \
zv: cos(v); "
"xn: cos(u)*cos(v)*sin(2*v); \
yn: sin(u)*cos(v)*sin(2*v); \
zn: -2*cos(2*v)*sin(2*v); "
"xuu: -cos(u)*sin(2*v); \
yuu: -sin(u)*sin(2*v); \
zuu: 0; "
"xuv: -2*cos(2*v)*sin(u); \
yuv: 2*cos(2*v)*cos(u); \
zuv: 0; "
"xvv: -4*cos(u)*sin(2*v); \
yvv: -4*sin(u)*sin(2*v); \
zvv: -sin(v); "
"end;";
#endif