
#include "four_intersecting_discs.h"
#include "surfaces_c_includes.h"

#if (USE_FOUR_INTERSECTING_DISCS != 0)
void FourIntersectingDiscs(pasuli_vartype u,
                           pasuli_vartype v,
                           pasuli_consttype *constants,
                           PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(FOUR_INTERSECTING_DISCS)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_2u = cos(2 * u);
    pasuli_calctype cos_3u_half = cos(1.5 * u);
    pasuli_calctype sin_2u = sin(2 * u);
    pasuli_consttype sqrt_v = sqrt(v);

    P_X(v * (cos_u - v * cos_2u * 0.5));
    P_Y(-v * (sin_u + v * sin_2u * 0.5));
    P_Z(4 * v * sqrt_v * cos_3u_half / 3.0);

    // Skip scaling by v
    pasuli_calctype sign_value = PASULI_CALC_SIGN(v);
    UD_X(sign_value * (v * sin_2u - sin_u));
    UD_Y(-sign_value * (v * cos_2u + cos_u));
    UD_Z(-2 * sign_value * sqrt_v * sin(1.5 * u));

    VD_X(cos_u - v * cos_2u);
    VD_Y(-sin_u - v * sin_2u);
    VD_Z(2 * sqrt_v * cos_3u_half);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descFourIntersectingDiscs =
    "name: Four intersecting discs;\
ut:c; vt:o;\
us:0; ue:pi:4;\
vs:0; ve:pi:2;\
x: v*cos(u)-v^2*cos(2*u)/2;\
y: -v*sin(u)-v^2*sin(2*u)/2;\
z: 4*v^(3/2)*cos(3*u/2)/3;\
xu: v*v*sin(2*u)-v*sin(u);\
yu: -v*v*cos(2*u)-v*cos(u);\
zu: -2*v^(3/2)*sin(3*u/2);\
xv: cos(u)-v*cos(2*u);\
yv: -sin(u)-v*sin(2*u);\
zv: 2*sqrt(v)*cos(3*u/2);";
#endif
