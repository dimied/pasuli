
#include "catenoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_CATENOID != 0)
void Catenoid(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CATENOID)

    pasuli_consttype c = constants[0];

    pasuli_calctype cosh_vc = cosh(v / c);
    pasuli_calctype c_cosh_vc = cosh_vc*c;
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = cos(u);

    P_X(cos_u * c_cosh_vc);
    P_Y(sin_u * c_cosh_vc);
    P_Z(v);

    UD_X(-c_cosh_vc*sin_u);
    UD_Y(c_cosh_vc*cos_u);
    UD_Z_CONST(0);

    pasuli_calctype sinh_vc = sinh(v / c);
    VD_X(sinh_vc*cos_u);
    VD_Y(sinh_vc*sin_u);
    VD_Z(1);

    // Ignore costant c
    N_X(cosh_vc*cos_u);
    N_Y(cosh_vc*sin_u);
    N_Z(cosh_vc*sinh_vc);

    // Ignore c
    UUD_X(-PASULI_COND_COPY_POS_X(cosh_vc*cos_u));
    UUD_Y(-PASULI_COND_COPY_POS_Y(cosh_vc*sin_u));
    UUD_Z_CONST(0);

    UVD_X(-sinh_vc*sin_u);
    UVD_Y(sinh_vc*cos_u);
    UVD_Z_CONST(0);

    // Ignore c
    VVD_X(PASULI_COND_COPY_POS_X(cosh_vc*cos_u));
    VVD_Y(PASULI_COND_COPY_POS_Y(cosh_vc*sin_u));
    VVD_Z_CONST(0);
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
xuv: -sinh(v/c)*sin(u); \
yuv: sinh(v/c)*cos(u); \
zuv: 0; \
xvv: (cos(u)*cosh(v/c))/c; \
yvv: (sin(u)*cosh(v/c))/c; \
zvv: 0; ";
#endif