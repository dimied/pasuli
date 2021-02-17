
#include "cosine_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_COSINE_SURFACE != 0)
void CosineSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(COSINE_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_uv = cos(u + v);

    P_X(cos_u);
    P_Y(cos_v);
    P_Z(cos_uv);

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_uv = sin(u + v);

    UD_X(-sin_u);
    UD_Y_CONST(0);
    UD_Z(-sin_uv);

    pasuli_calctype sin_v = sin(v);

    VD_X_CONST(0);
    VD_Y(-sin_v);
    VD_Z(-sin_uv);

    N_X(-sin_v * sin_uv);
    N_Y(-sin_u * sin_uv);
    N_Z(sin_u * sin_v);

    UUD_X(-cos_u);
    UUD_Y_CONST(0);
    UUD_Z(-cos_uv);

    UVD_X_CONST(0);
    UVD_Y_CONST(0);
    UVD_Z(-cos_uv);

    VVD_X_CONST(0);
    VVD_Y(-cos_v);
    VVD_Z(-cos_uv);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface = {
    PSLDD_ID(COSINE_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
    -1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCosineSurface =
    "name: Cosine Surface; \
ut:c; vt:c; \
us:pi:-1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
x: cos(u); \
y: cos(v); \
z: cos(u + v); \
xu: -sin(u); \
yu: 0; \
zu: -sin(u+v); \
xv: 0; \
yv: -sin(v); \
zv: -sin(u+v); \
xn: -sin(v)*sin(u+v); \
yn: -sin(u)*sin(u+v); \
zn: sin(u)*sin(v); \
xuu: -cos(u); \
yuu: 0; \
zuu: -cos(u+v); \
xuv: 0; \
yuv: 0; \
zuv: -cos(u+v); \
xvv: 0; \
yvv: -cos(v); \
zvv: -cos(u+v);";
#endif