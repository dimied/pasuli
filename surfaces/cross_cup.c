
#include "cross_cup.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_CROSS_CUP != 0)

void CrossCup(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CROSS_CUP)

    double u_squared = u * u;
    double sqrtu = sqrt((1 - u_squared) * 0.5f) * u;

    double sin_v = sin(v);
    double sinv2 = sin_v * sin_v;

    P_X(1 - u_squared + u_squared * sinv2);
    P_Y(u_squared * sinv2 + 2 * u_squared * sin(v) * cos(v));
    P_Z(sqrtu * (sin(v) + cos(v)));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrossCup = {
    PSLDD_ID(CROSS_CUP)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI,
    0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup =
    "name: Cross Cup; \
ut: c; \
vt: c; \
us:0; ue:1; vs:0; ve:pi:2; \
x: 1 - u*u + u*u*sin(v)*sin(v); \
y: u*u*sin(v)*sin(v) + 2*u*u*sin(v)*cos(v); \
z: sqrt((1 - u*u)/2)*u*(sin(v) + cos(v)); \
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
zvv: 0;";
#endif