
#include "swallow_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_SWALLOW_SURFACE != 0)
void SwallowSurface(double u, double v,
                    double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SWALLOW_SURFACE)

    double v2 = v * v;

    P_X(u * v2 + 3.0 * v2 * v2);
    P_Y(-2 * u * v - 4.0 * v * v2);
    P_Z(u);

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
ut:c; \
vt:c; \
us: -2; \
ue: 2; \
vs: 0.75; \
ve: 0.75; \
x: u*v*v + 3*v*v*v*v; \
y: -2*u*v - 4*v*v*v; \
z: u; "
    "xu: v*v; \
yu: -2*v; \
zu: 1; "
    "xv: 2*v*(6*v*v + u); \
yv: -2*u - 12*v*v; \
zv: 0; "
    "xn: 2*(u+6*v*v); \
yn: 2*v*(u+6*v*v); \
zn: 2*v*v*(u+6*v*v); "
    "xuu: 0; yuu: 0; zuu: 0; "
    "xuv: 2*v; yuv: -2; zuv: 0; "
    "xvv: 2*u+36*v*v; \
yvv: -24*v; \
zvv: 0; "
    "end;";
#endif