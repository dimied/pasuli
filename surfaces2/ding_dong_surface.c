
#include "ding_dong_surface.h"
#include "surfaces_c_includes.h"

#if (USE_DING_DONG_SURFACE != 0)
void DingDongSurface(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(DING_DONG_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sqrt_1_minus_v = sqrt(1 - v);
    pasuli_calctype factor = v * sqrt_1_minus_v;

    P_X(factor * cos_u);
    P_Y(factor * sin_u);
    P_Z(v);

    // Ignore scaling by v*sqrt(1-v)
    factor = PASULI_CALC_SIGN(factor);
    UD_X(-factor * sin_u);
    UD_Y(factor * cos_u);
    UD_Z(0);

    // Scale by 2*sqrt(1-v)
    factor = 2 - 3 * v;
    VD_X(factor * cos_u);
    VD_Y(factor * sin_u);
    VD_Z(2 * sqrt_1_minus_v);

    factor = v * sqrt_1_minus_v;
    N_X(PASULI_COND_COPY_POS_X(factor * cos_u));
    N_Y(PASULI_COND_COPY_POS_Y(factor * sin_u));
    N_Z(v * (1.5 * v - 1));
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descDingDongSurface =
    "name: Ding Dong Surface;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:-1; ve:1;\
x: v*sqrt(1-v)*cos(u);\
y: v*sqrt(1-v)*sin(u);\
z: v;\
xu: -v*sqrt(1-v)*sin(u);\
yu: v*sqrt(1-v)*cos(u);\
zu: 0;\
xv: cos(u)*(2-3*v)/(2*sqrt(1-v));\
yv: sin(u)*(2-3*v)/(2*sqrt(1-v));\
zv: 1;\
xn: v*sqrt(1-v)*cos(u);\
yn: v*sqrt(1-v)*sin(u);\
zn: 3*v*v/2 - v;";
#endif
