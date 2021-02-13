
#include "hennebergs_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HENNEBERGS_SURFACE != 0)
void HennebergsSurface(double u, double v,
                       double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HENNEBERGS_SURFACE)

    double sinh_u_2 = 2 * sinh(u);
    double sinh_3u_2 = 2 * sinh(3.0 * u);
    double cv = cos(v);
    double sv = sin(v);
    double c3v = cos(3.0 * v);
    double s3v = sin(3.0 * v);

    P_X(cv * sinh_u_2 - (c3v * sinh_3u_2) / 3.0);
    P_Y(sv * sinh_u_2 + (s3v * sinh_3u_2) / 3.0);
    P_Z(cos(2 * v) * 2 * cosh(2.0 * u));

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
PaSuLiDefDesc pslddHennebergsSurface = {
    PSLDD_ID(HENNEBERGS_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_START_PI | PASULI_V_END_PI,
    -1, 1, -0.5, 0.5, 0};
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHennebergsSurface =
    "name: Hennerbergs Surface; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs:pi: -0.5; \
ve:pi: 0.5; \
x: 2*cos(v)*sinh(u) - (2.0/3.0)*cos(3*v)*sinh(3*u); \
y: 2*sin(v)*sinh(u) + (2.0/3.0)*sin(3*v)*sinh(3*u); \
z: 2*cos(2*v)*cosh(2*u); \
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