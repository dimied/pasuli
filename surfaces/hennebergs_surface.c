
#include "hennebergs_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HENNEBERGS_SURFACE != 0)
void HennebergsSurface(pasuli_vartype u, pasuli_vartype v,
                       pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HENNEBERGS_SURFACE)

    pasuli_calctype sinh_u = sinh(u);
    pasuli_calctype sinh_u_2 = 2 * sinh_u;
    pasuli_calctype sinh_3u = sinh(3.0 * u);
    pasuli_calctype sinh_3u_2 = 2 * sinh_3u;
    pasuli_calctype cosh_2u_2 = 2 * cosh(2.0 * u);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_2v = cos(2 * v);

    pasuli_calctype cos_3v = cos(3.0 * v);
    pasuli_calctype sin_3v = sin(3.0 * v);

    P_X(cos_v * sinh_u_2 - (cos_3v * sinh_3u_2) / 3.0);
    P_Y(sin_v * sinh_u_2 + (sin_3v * sinh_3u_2) / 3.0);
    P_Z(cos_2v * cosh_2u_2);

    pasuli_calctype cosh_u = cosh(u);
    pasuli_calctype cosh_3u = cosh(3 * u);
    // No scaling by 2
    UD_X(cos_v * cosh_u - cos_3v * cosh_3u);
    UD_Y(sin_v * cosh_u + sin_3v * cosh_3u);
    UD_Z(2 * cos_2v * sinh(2 * u));

    // No scaling by 2
    VD_X(sin_3v * sinh_3u - sin_v * sinh_u);
    VD_Y(cos_3v * sinh_3u + cos_v * sinh_u);
    VD_Z(-sin(2 * v) * cosh_2u_2);

    PASULI_CALC_NORMAL_FROM_UD_VD
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
    "name: Hennerbergs Surface;\
ut:c; vt:c;\
us: -1; ue: 1;\
vs:pi: -0.5; ve:pi: 0.5;\
x: 2*cos(v)*sinh(u) - (2/3)*cos(3*v)*sinh(3*u);\
y: 2*sin(v)*sinh(u) + (2/3)*sin(3*v)*sinh(3*u);\
z: 2*cos(2*v)*cosh(2*u);\
xu: 2*(cos(v)*cosh(u) - cos(3*v)*cosh(3*u));\
yu: 2*(sin(v)*cosh(u) + sin(3*v)*cosh(3*u));\
zu: 4*cos(2*v)*sinh(2*u);\
xv: 2*(sin(3*v)*sinh(3*u) - sin(v)*sinh(u));\
yv: 2*(cos(3*v)*sinh(3*u) + cos(v)*sinh(u));\
zv: -4*sin(2*v)*cosh(2*u); ";
#endif