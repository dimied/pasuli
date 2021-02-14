
#include "cosine_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_COSINE_SURFACE != 0)
void CosineSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants, 
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(COSINE_SURFACE)

    double cu = cos(u);
    double cv = cos(v);

    P_X(cu);
    P_Y(cv);
    P_Z(cos(u + v));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double su = sin(u);
    double sv = sin(v);
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
z: cos(u + v); "
    "xu: -sin(u); yu: 0; zu: -sin(u+v); "
    "xv: 0; yv: -sin(v); zv: -sin(u+v); "
    "xn: -sin(v)*sin(u+v); \
yn: -sin(u)*sin(u+v); \
zn: sin(u)*sin(v); "
    "xuu: -cos(u); yuu: 0; zuu: -cos(u+v); "
    "xuv: 0; yuv: 0; zuv: -cos(u+v); "
    "xvv: 0; yvv: -cos(v); zvv: -cos(u+v); "
    "end;";
#endif