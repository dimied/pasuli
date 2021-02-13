
#include "richmond_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_RICHMOND_SURFACE != 0)
void RichmondSurface(double u, double v,
                     double *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(RICHMOND_SURFACE)

    double u2 = u * u;
    double u3 = u2 * u;
    double u4 = u2 * u2;

    double v2 = v * v;
    double v3 = v2 * v;
    double divisor = 6.0 * (u2 + v2);

    P_X(((-3.0) * u - u2 * u3 + 2.0 * u3 * v2 + 3.0 * u * v2 * v2) / divisor);
    P_Y((-3.0 * v - 3.0 * u4 * v - 2 * u2 * v3 + v2 * v3) / divisor);
    P_Z(u);

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
PaSuLiDefDesc pslddRichmondSurface = {
    PSLDD_ID(RICHMOND_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED,
    -1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface =
    "name: Richmond Surface; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs: -1; \
ve: 1; \
x: (-3*u - u^(5) + 2*u*u*u*v*v + 3*u*v*v*v*v)/(6*(u*u + v*v)); \
y: (-3*v - 3*u*u*u*u*v - 2*u*u*v*v*v + v^(5))/(6*(u*u + v*v)); \
z: u; \
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