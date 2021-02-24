
#include "enneper_surface3.h"
#include "surfaces_c_includes.h"

#if (USE_ENNEPER_SURFACE3 != 0)
void EnneperSurface3(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ENNEPER_SURFACE3)

    pasuli_calctype u2 = u * u;
    pasuli_calctype v2 = v * v;
    pasuli_calctype divisor = 6 * sqrt(2.0);

    P_X(-u * (-6 + u2 - 3 * v2) / divisor);
    P_Y(v * (-6 + v2 - 3 * u2) / divisor);
    P_Z((u2 - v2) * 0.5);

    pasuli_calctype factor = 2 * sqrt(2.0);
    pasuli_calctype v2_minus_u2 = v2 - u2;
    // Multiplied by (2*sqrt(2))
    UD_X(2 + v2_minus_u2);
    UD_Y(-2 * u * v);
    UD_Z(u * factor);

    // Multiplied by (2*sqrt(2))
    VD_X(2 * u * v);
    VD_Y(-2 + v2_minus_u2);
    VD_Z(-v * factor);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface3 =
    "name: Enneper Surface 3;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: -u*(-6+u^2-3*v^2)/(6*sqrt(2));\
y: v*(-6+v^2-3*u^2)/(6*sqrt(2));\
z: (u^2-v^2)/2;\
xu: (2-u*u+v*v)/(2*sqrt(2));\
yu: -u*v/sqrt(2);\
zu: u;\
xv: u*v/sqrt(2);\
yv: (-2-u*u+v*v)/(2*sqrt(2));\
zv: -v;";
#endif
