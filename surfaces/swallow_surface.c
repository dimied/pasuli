
#include "swallow_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_SWALLOW_SURFACE != 0)
void SwallowSurface(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SWALLOW_SURFACE)

    pasuli_calctype v2 = v * v;

    P_X(u * v2 + 3.0 * v2 * v2);
    P_Y(-2 * u * v - 4.0 * v * v2);
    P_Z(u);

    UD_X(v2);
    UD_Y(-2 * v);
    UD_Z(1);

    // No scaling by 2
    VD_X(v * (u + 6 * v * v));
    VD_Y(u - 6 * v * v);
    VD_Z(0);

    // No scaling by 2*(u+6*v*v)
    pasuli_calctype factor = PASULI_CALC_SIGN((u + 6 * v * v));
    N_X(factor);
    N_Y(v * factor);
    N_Z(v * v * factor);

    UUD_ALL(0);

    UVD_X(2 * v);
    UVD_Y(-2);
    UVD_Z(0);

    VVD_X(2 * u + 36 * v * v);
    VVD_Y(-24 * v);
    VVD_Z(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSwallowSurface = {
    PSLDD_ID(SWALLOW_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_FULL_IMPL,
    -2, 2, -0.75, 0.75, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descSwallowSurface =
    "name: Swallow Surface; \
ut:c; vt:c; \
us: -2; ue: 2; \
vs: 0.75; ve: 0.75; \
x: u*v*v + 3*v*v*v*v; \
y: -2*u*v - 4*v*v*v; \
z: u; \
xu: v*v; \
yu: -2*v; \
zu: 1; \
xv: 2*v*(6*v*v + u); \
yv: -2*u - 12*v*v; \
zv: 0; \
xn: 2*(u+6*v*v); \
yn: 2*v*(u+6*v*v); \
zn: 2*v*v*(u+6*v*v); \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 2*v; \
yuv: -2; \
zuv: 0; \
xvv: 2*u+36*v*v; \
yvv: -24*v; \
zvv: 0;";
#endif