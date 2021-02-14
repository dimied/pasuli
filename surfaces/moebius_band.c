
#include "moebius_band.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_MOEBIUS_BAND != 0)
void MoebiusBand(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MOEBIUS_BAND)

    double r = constants[0];
    double s_cost = u * cos(v * 0.5f);
    s_cost += r;

    P_X(s_cost * cos(v));
    P_Y(s_cost * sin(v));
    P_Z(u * sin(v * 0.5f));

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
PaSuLiDefDesc pslddMoebiusBand = {
PSLDD_ID( MOEBIUS_BAND )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descMoebiusBand =
"name: Moebius Band; \
ut: c; \
vt: c; \
us: -1; \
ue: 1; \
vs: 0; \
ve:pi: 2; \
c1:r: 1.5; \
x: (r + u*cos(v/2))*cos(v); \
y: (r + u*cos(v/2))*sin(v); \
z: u*sin(v/2); "
"xu: cos(v)*cos(0.5*v); \
yu: cos(0.5*v)*sin(v); \
zu: sin(0.5*v); "
"xv: -r*sin(v) - 0.5*u*cos(v)*sin(0.5*v)-u*cos(0.5*v)*sin(v); \
yv: r*cos(v) + u*(cos(v)*cos(0.5*v)-sin(v)*sin(0.5*v)); \
zv: 0.5*u*cos(0.5*v); "
"xn: -sin(0.5*v)*(r*cos(v) + u*cos(v)*cos(0.5*v)) + 0.5*u*sin(v); \
yn: -sin(0.5*v)*(r*sin(v)+u*cos(0.5*v)*sin(v)) - 0.5*u*cos(v); \
zn: (r+u*cos(0.5*v))*cos(0.5*v); "
"xuu: 0; \
yuu: 0; \
zuu: 0; "
"xuv: -0.5*cos(v)*sin(0.5*v) - cos(0.5*v)*sin(v); \
yuv: cos(v)*cos(0.5*v) - 0.5*sin(v)*sin(0.5*v); \
zuv: 0.5*cos(0.5*v); "
"xvv: u*(sin(v)*sin(0.5*v) - 1.25*cos(v)*cos(0.5*v)) - r*cos(v); \
yvv: -u*(cos(v)*sin(0.5*v) + 1.25*cos(0.5*v)*sin(v)) - r*sin(v); \
zvv: -0.25*u*sin(0.5*v); "
"end;";
#endif