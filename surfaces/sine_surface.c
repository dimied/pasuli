
#include "sine_surface.h"

#include "../pasuli_macros.h"
#include <math.h>

#if (USE_SINE_SURFACE != 0)
void SineSurface(double u, double v,
                 double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SINE_SURFACE)

    double su = sin(u);
    double sv = sin(v);
    double suv = sin(u + v);

    P_X(su);
    P_Y(sv);
    P_Z(suv);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
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
PaSuLiDefDesc pslddSineSurface = {
    PSLDD_ID(SINE_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
    -1, 1, -1, 1, 0};
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSineSurface =
    "name: Sine Surface; \
ut:c; vt:c; \
us:pi:-1; ue:pi:1; \
vs:pi:-1; ve:pi:1; \
x: sin(u); \
y: sin(v); \
z: sin(u+v); \
xu: cos(u); \
yu: 0; \
zu: cos(u+v); \
xv: 0; \
yv: cos(v); \
zv: cos(u+v); \
xn: -cos(v)*cos(u+v); \
yn: -cos(u)*cos(u+v); \
zn: cos(u)*cos(v); \
xuu: -sin(u); \
yuu: 0; \
zuu: -sin(u+v); \
xuv: 0; \
yuv: 0; \
zuv: -sin(u+v); \
xvv: 0; \
yvv: -sin(v); \
zvv: -sin(u+v); ";
#endif