
#include "eight_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_EIGHT_SURFACE != 0)
void EightSurface(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(EIGHT_SURFACE)

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_2v = sin(2 * v);

    P_X(cos_u * sin_2v);
    P_Y(sin_u * sin_2v);
    P_Z(sin_v);

    UD_X(-PASULI_COND_COPY_POS_Y(sin_u * sin_2v));
    UD_Y(PASULI_COND_COPY_POS_X(cos_u * sin_2v));
    UD_Z_CONST(0);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_2v = cos(2 * v);
    VD_X(2 * cos_u * cos_2v);
    VD_Y(2 * sin_u * cos_2v);
    VD_Z(cos_v);

    N_X(cos_v * PASULI_COND_COPY_POS_X(cos_u * sin_2v));
    N_Y(sin_v * PASULI_COND_COPY_POS_Y(sin_u * sin_2v));
    N_Z(-2 * cos_2v * sin_2v);

    UUD_X(-PASULI_COND_COPY_POS_X(cos_u * sin_2v));
    UUD_Y(-PASULI_COND_COPY_POS_Y(sin_u * sin_2v));
    UUD_Z_CONST(0);

    // No scaling by 2
    UVD_X(-cos_2v * sin_u);
    UVD_Y(cos_2v * cos_u);
    UVD_Z_CONST(0);

    VVD_X(-4 * PASULI_COND_COPY_POS_X(cos_u * sin_2v));
    VVD_Y(-4 * PASULI_COND_COPY_POS_Y(sin_u * sin_2v));
    VVD_Z(-sin_v);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEightSurface = {
    PSLDD_ID(EIGHT_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
    0, 2, -0.5, 0.5, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descEightSurface =
    "name: Eight Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs:pi: -0.5; ve:pi: 0.5; \
x: cos(u)*sin(2*v); \
y: sin(u)*sin(2*v); \
z: sin(v); \
xu: -sin(u)*sin(2*v); \
yu: cos(u)*sin(2*v); \
zu: 0; \
xv: 2*cos(u)*cos(2*v); \
yv: 2*sin(u)*cos(2*v); \
zv: cos(v); \
xn: cos(u)*cos(v)*sin(2*v); \
yn: sin(u)*cos(v)*sin(2*v); \
zn: -2*cos(2*v)*sin(2*v); \
xuu: -cos(u)*sin(2*v); \
yuu: -sin(u)*sin(2*v); \
zuu: 0; \
xuv: -2*cos(2*v)*sin(u); \
yuv: 2*cos(2*v)*cos(u); \
zuv: 0; \
xvv: -4*cos(u)*sin(2*v); \
yvv: -4*sin(u)*sin(2*v); \
zvv: -sin(v); ";
#endif