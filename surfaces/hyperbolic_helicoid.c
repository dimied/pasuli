
#include "hyperbolic_helicoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HYPERBOLIC_HELICOID != 0)
void HyperbolicHelicoid(pasuli_vartype u, pasuli_vartype v,
                        pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HYPERBOLIC_HELICOID)

    pasuli_consttype a = constants[0];

    pasuli_calctype cosh_u = cosh(u);
    pasuli_calctype cosh_v = cosh(v);
    pasuli_calctype sinh_u = sinh(u);
    pasuli_calctype sinh_v = sinh(v);
    pasuli_calctype divisor = 1.0 + cosh_u * cosh_v;

    pasuli_calctype ua = u * a;
    pasuli_calctype cos_au = cos(ua);
    pasuli_calctype sin_au = sin(ua);

    P_X(sinh_v * cos_au / divisor);
    P_Y(sinh_v * sin_au / divisor);
    P_Z(cosh_v * sinh_u / divisor);

    pasuli_calctype cosh_u_plus_cosh_v = (cosh_u + cosh_v);
    // Ignore division by (1+cosh(u)*cosh(v))^2
    UD_X(-(a * (1 + cosh_u * cosh_v) * sin_au + cos_au * cosh_v * sinh_u) * sinh_v);
    UD_Y((a * (1 + cosh_u * cosh_v) * cos_au - sin_au * cosh_v * sinh_u) * sinh_v);
    UD_Z(cosh_u_plus_cosh_v * cosh_v);

    // Ignore division by (1+cosh(u)*cosh(v))^2
    VD_X(cosh_u_plus_cosh_v * cos_au);
    VD_Y(cosh_u_plus_cosh_v * sin_au);
    VD_Z(sinh_u * sinh_v);

    PASULI_CALC_NORMAL_FROM_UD_VD
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
#if (COMPILE_DESC_SURFACES != 0)
char *descHyperbolicHelicoid =
    "name: Hyperbolic Helicoid; \
ut:c; vt:c; \
us: -4; ue: 4; \
vs: -4; ve: 4; \
c1:a: 0.5; \
x: sinh(v)*cos(a*u)/(1+cosh(u)*cosh(v));  \
y: sinh(v)*sin(a*u)/(1+cosh(u)*cosh(v)); \
z: cosh(v)*sinh(u)/(1+cosh(u)*cosh(v)); \
xu: -(a*(1+cosh(u)*cosh(v))*sin(a*u) + cos(a*u)*cosh(v)*sinh(u))*sinh(v)/(1+cosh(u)*cosh(v))^2; \
yu: (a*(1+cosh(u)*cosh(v))*cos(a*u) - sin(a*u)*cosh(v)*sinh(u))*sinh(v)/(1+cosh(u)*cosh(v))^2; \
zu: (cosh(u) + cosh(v))*cosh(v)/(1+cosh(u)*cosh(v))^2; \
xv: (cosh(u) + cosh(v))*cos(a*u)/(1+cosh(u)*cosh(v))^2; \
yv: (cosh(u) + cosh(v))*sin(a*u)/(1+cosh(u)*cosh(v))^2; \
zv: sinh(u)*sinh(v)/(1+cosh(u)*cosh(v))^2; ";
#endif