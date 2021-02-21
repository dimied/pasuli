
#include "fish_surface.h"
#include "surfaces_c_includes.h"

#if (USE_FISH_SURFACE != 0)
void FishSurface(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(FISH_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_2u = cos(2 * u);
    pasuli_calctype sin_2u = sin(2 * u);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X((cos_u - cos_2u) * 0.25 * cos_v);
    P_Y((sin_u - sin_2u) * 0.25 * sin_v);
    P_Z(cos_u);

    UD_X((4 * cos_u - 1) * cos_v * sin_u * 0.25);
    UD_Y((cos_u - 2 * cos_2u) * sin_v * 0.25);
    UD_Z(-sin_u);

    VD_X(-(cos_u - cos_2u) * sin_v * 0.25);
    VD_Y((sin_u - sin_2u) * cos_v * 0.25);
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFishSurface = {
    PSLDD_ID(FISH_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
    0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descFishSurface =
    "name: Fish Surface;\
ut:c; vt:c;\
us: 0; ue:pi: 1;\
vs: 0; ve:pi: 2;\
x: (cos(u) - cos(2*u))*cos(v)/4;\
y: (sin(u) - sin(2*u))*sin(v)/4;\
z: cos(u);\
xu: (4*cos(u) - 1)*cos(v)*sin(u)/4;\
yu: (cos(u) - 2*cos(2*u))*sin(v)/4;\
zu: -sin(u);\
xv: -(cos(u) - cos(2*u))*sin(v)/4;\
yv: (sin(u) - sin(2*u))*cos(v)/4;\
zv: 0; ";
#endif