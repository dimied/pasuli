
#include "hyperbolic_helicoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HYPERBOLIC_HELICOID != 0)
void HyperbolicHelicoid(double u, double v,
                        double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HYPERBOLIC_HELICOID)

    double a = constants[0];

    double cosh_uv = 1.0 + cosh(u) * sinh(v);
    double ua = u * a;

    P_X((sinh(v) * cos(ua)) / cosh_uv);
    P_Y((sinh(v) * sin(ua)) / cosh_uv);
    P_Z(cosh(v) * sinh(u) / cosh_uv);

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
PaSuLiDefDesc pslddHyperbolicHelicoid = {
PSLDD_ID( HYPERBOLIC_HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-4, 4 , -4 , 4 , &psldd_15_05_constants[1] };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicHelicoid =
"name: Hyperbolic Helicoid; \
ut:c; \
vt:c; \
us: -4; \
ue: 4; \
vs: -4; \
ve: 4; \
c1:a: 0.5; \
x: sinh(v)*cos(a*u)/(1+cosh(u)*cosh(v));  \
y: sinh(v)*sin(a*u)/(1+cosh(u)*cosh(v)); \
z: cosh(v)*sinh(u)/(1+cosh(u)*cosh(v)); \
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