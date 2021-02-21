
#include "sine_surface.h"

#include "../pasuli_macros.h"
#include <math.h>

#if (USE_SINE_SURFACE != 0)

void SineSurface(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SINE_SURFACE)

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_uv = sin(u + v);

    P_X(sin_u);
    P_Y(sin_v);
    P_Z(sin_uv);

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_uv = cos(u + v);

    UD_X(cos_u);
    UD_Y_CONST(0);
    UD_Z(cos_uv);

    VD_X_CONST(0);
    VD_Y(cos_v);
    VD_Z(cos_uv);

    N_X(-cos_v * cos_uv);
    N_Y(-cos_u * cos_uv);
    N_Z(cos_u * cos_v);

    UUD_X(-sin_u);
    UUD_Y_CONST(0);
    UUD_Z(-sin_uv);

    UVD_X_CONST(0);
    UVD_Y_CONST(0);
    UVD_Z(-sin_uv);

    VVD_X_CONST(0);
    VVD_Y(-sin_v);
    VVD_Z(-sin_uv);
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
    "name: Sine Surface;\
ut:c; vt:c;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: sin(u);\
y: sin(v);\
z: sin(u+v);\
xu: cos(u);\
yu: 0;\
zu: cos(u+v);\
xv: 0;\
yv: cos(v);\
zv: cos(u+v);\
xn: -cos(v)*cos(u+v);\
yn: -cos(u)*cos(u+v);\
zn: cos(u)*cos(v);\
xuu: -sin(u);\
yuu: 0;\
zuu: -sin(u+v);\
xuv: 0;\
yuv: 0;\
zuv: -sin(u+v);\
xvv: 0;\
yvv: -sin(v);\
zvv: -sin(u+v); ";
#endif