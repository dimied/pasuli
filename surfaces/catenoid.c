
#include "catenoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_CATENOID != 0)
void Catenoid(double u, double v,
              double *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CATENOID)

    double c = constants[0];

    double cdc = cosh(v / c);

    P_X(cos(u) * cdc);
    P_Y(sin(u) * cdc);
    P_Z(v);

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
PaSuLiDefDesc pslddCatenoid = {
PSLDD_ID( CATENOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(1),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descCatenoid =
    "name: Catenoid; \
ut:c; vt:c; \
us:pi:-1; ue:pi:1; \
vs:-2; ve:2; \
c1:c:!=0: 1.5 ; \
x: c*cosh(v/c)*cos(u); \
y: c*cosh(v/c)*sin(u); \
z: v; \
xu: -c*cosh(v/c)*sin(u); \
yu: c*cosh(v/c)*cos(u); \
zu: 0; \
xv: sinh(v/c)*cos(u); \
yv: sinh(v/c)*sin(u); \
zv: 1; \
xn: c*cos(u)*cosh(v/c); \
yn: c*cosh(v/c)*sin(u); \
zn: -c*cosh(v/c)*sinh(v/c); \
xuu: -c*cos(u)*cosh(v/c); \
yuu: -c*sin(u)*cosh(v/c); \
zuu: 0; \
xuv: sinh(v/c)*sin(u); \
yuv: sinh(v/c)*cos(u); \
zuv: 0; \
xvv: (cos(u)*cosh(v/c))/c; \
yvv: (sin(u)*cosh(v/c))/c; \
zvv: 0; ";
#endif