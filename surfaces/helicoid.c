
#include "helicoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HELICOID != 0)
void Helicoid(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HELICOID)

    double c = constants[0];
    double cos_v = cos(v);
    double sin_v = sin(v);

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(c * v);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
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
PaSuLiDefDesc pslddHelicoid = {
PSLDD_ID( HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descHelicoid =
    "name: Helicoid; \
ut: c; vt: c; \
us:-2; ue:2; \
vs: 0; ve:pi: 2; \
c1:c: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: c*v; \
xu: cos(v); yu: sin(v); zu: 0; \
xv: -u*sin(v); yv: u*cos(v); zv: c; \
xn: c*sin(v); yn: -c*cos(v); zn: u; \
xuu: 0; yuu: 0; zuu: 0; \
xuv: -sin(v); yuv: cos(v); zuv: 0; \
xvv: -u*cos(v); yvv: -u*sin(v); zvv: 0; ";
#endif