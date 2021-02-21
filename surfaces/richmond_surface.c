
#include "richmond_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_RICHMOND_SURFACE != 0)
void RichmondSurface(pasuli_vartype u, pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(RICHMOND_SURFACE)

    pasuli_calctype u2 = u * u;
    pasuli_calctype u3 = u2 * u;
    pasuli_calctype u4 = u2 * u2;

    pasuli_calctype v2 = v * v;
    pasuli_calctype v3 = v2 * v;

    pasuli_calctype divisor = 6.0 * (u2 + v2);

    P_X((-3.0 * u - u2 * u3 + 2.0 * u3 * v2 + 3.0 * u * v2 * v2) / divisor);
    P_Y((-3.0 * v - 3.0 * u4 * v - 2 * u2 * v3 + v2 * v3) / divisor);
    P_Z(u);

    pasuli_calctype v4 = v2 * v2;
    // Multiply by divisor divisor
    //divisor = (u4 + v4 + 2 * u2 * v2);
    divisor = u2 + v2;
    divisor *= divisor;
    UD_X(u2 * (1 - u4) + v4 * v2 + u2 * v4 - u4 * v2);
    UD_Y(2 * u * v * (1 - divisor));
    UD_Z(divisor);

    VD_X(2 * u * v * (1 + divisor));
    VD_Y(v2 * (1 + v4) - u2 * (1 + u4) + u2 * v4 - u4 * v2);
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddRichmondSurface = {
    PSLDD_ID(RICHMOND_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED,
    -1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface =
    "name: Richmond Surface;\
ut:c; vt:c;\
us: -1; ue: 1;\
vs: -1; ve: 1;\
x: (-3*u - u^(5) + 2*u^3*v^2 + 3*u*v^4)/(6*(u^2 + v^2));\
y: (-3*v - 3*u^4*v - 2*u^2*v^3 + v^(5))/(6*(u^2 + v^2));\
z: u;\
xu: (u^2+v^6-u^6-v^2+u^2*v^4-u^4*v^2)/(2*(u^4+v^4+2*u^2*v^2));\
yu: u*v*(1-u^4-v^4-2*u^2*v^2)/(u^4+v^4+2*u^2*v^2);\
zu: 1;\
xv: u*v*(1+u^4+v^4+2*u^2*v^2)/(u^4+v^4+2*u^2*v^2);\
yv: (v^2+v^6-u^2-u^6+u^2*v^4-u^4*v^2)/(2*(u^4+v^4+2*u^2*v^2));\
zv: 0;";
#endif