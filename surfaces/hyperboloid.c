
#include "hyperboloid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HYPERBOLOID != 0)
void Hyperboloid(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HYPERBOLOID)

    double a = constants[0];
    double b = constants[1];

    double cosh_v = cosh(v);
    double acu = a * cos(u);
    double asu = a * sin(u);

    P_X(asu * cosh_v);
    P_Y(acu * cosh_v);
    P_Z(b * sinh(v));

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
PaSuLiDefDesc pslddHyperboloid = {
PSLDD_ID( HYPERBOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descHyperboloid =
    "name: Hyperboloid; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs: -2; \
ve: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: a*cosh(v)*cos(u); \
y: a*cosh(v)*sin(u); \
z: b*sinh(v); "
    "xu: -a*cosh(v)*sin(u); \
yu: a*cos(u)*cosh(v); \
zu: 0; "
    "xv: a*cos(u)*sinh(v); \
yv: a*sin(u)*sinh(v); \
zv: b*cosh(v); "
    "xn: a*b*cos(u)*cosh(v)*cosh(v); \
yn: a*b*sin(u)*cosh(v)*cosh(v); \
zn: -a*a*cosh(v)*sinh(v); "
    "xuu: -a*cos(u)*cosh(v); \
yuu: -a*sin(u)*cosh(v); \
zuu: 0; "
    "xuv: -a*sin(u)*sinh(v); \
yuv: a*cos(u)*sinh(v); \
zuv: 0; "
    "xvv: a*cos(u)*cosh(v); \
yvv: a*sin(u)*cosh(v); \
zvv: b*sinh(v);";
#endif