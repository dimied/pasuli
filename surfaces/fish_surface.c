
#include "fish_surface.h"
#include "surfaces_c_includes.h"

#if (USE_FISH_SURFACE != 0)
void FishSurface(double u, double v,
                 double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(FISH_SURFACE)

    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);

    P_X((cu - cos(2 * u)) * 0.25 * cv);
    P_Y((sin(u) - sin(2 * u)) * 0.25 * sv);
    P_Z(cu);

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
PaSuLiDefDesc pslddFishSurface = {
    PSLDD_ID(FISH_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
    0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descFishSurface =
    "name: Fish Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 1; \
vs: 0; \
ve:pi: 2; \
x: (cos(u) - cos(2*u))*cos(v)/4; \
y: (sin(u) - sin(2*u))*sin(v)/4; \
z: cos(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif