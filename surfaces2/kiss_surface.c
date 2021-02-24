
#include "kiss_surface.h"
#include "surfaces_c_includes.h"

#if (USE_KISS_SURFACE != 0)
void KissSurface(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KISS_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype v2 = v * v;

    pasuli_calctype factor = v2 * sqrt((1 - v) * 0.5);
    P_X(factor * cos_u);
    P_Y(factor * sin_u);
    P_Z(v);

    // Ignore v^2*sqrt((1-v)/2)
    pasuli_calctype sign_value = PASULI_CALC_SIGN(factor);
    UD_X(-sign_value * sin_u);
    UD_Y(sign_value * cos_u);
    UD_Z(0);

    pasuli_calctype factor2 = v * sqrt(2) * (4 - 5 * v);
    pasuli_calctype divisor = 4 * sqrt(1 - v);
    VD_X(cos_u * factor2 / divisor);
    VD_Y(sin_u * factor2 / divisor);
    VD_Z(1);

    factor = sqrt((1 - v) * 0.5);
    // Ignore scaling by v^2
    N_X(factor * cos_u);
    N_Y(factor * sin_u);
    N_Z(v2 * 1.25f - v);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKissSurface =
    "name: Kiss Surface;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:-1; ve:1;\
x: v^2*sqrt((1-v)/2)*cos(u);\
y: v^2*sqrt((1-v)/2)*sin(u);\
z: v;\
xu: -v^2*sqrt((1-v)/2)*sin(u);\
yu: v^2*sqrt((1-v)/2)*cos(u);\
zu: 0;\
xv: cos(u)*v*sqrt(2)*(4-5*v)/(4*sqrt(1-v));\
yv: sin(u)*v*sqrt(2)*(4-5*v)/(4*sqrt(1-v));\
zv: 1;\
xn: v^2*sqrt((1-v)/2)*cos(u);\
yn: v^2*sqrt((1-v)/2)*sin(u);\
zn: 5*v^4/4-v^3;";
#endif