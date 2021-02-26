#include "bours_minimal_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BOURS_MINIMAL_SURFACE != 0)
void BoursMinimalSurface(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOURS_MINIMAL_SURFACE)

    pasuli_calctype u2 = u * u;
    pasuli_calctype sqrt_u = sqrt(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_2v = cos(v);
    pasuli_calctype sin_2v = sin(v);
    pasuli_calctype cos_3u_half = cos(1.5 * u);

    P_X(u * cos_v - u2 * cos_2v * 0.5);
    P_Y(-u * sin_v - u2 * sin_2v * 0.5);
    P_Z(4.0 * u * sqrt_u * cos_3u_half / 3.0);

    UD_X(-u * cos_2v + cos_v);
    UD_Y(-u * sin_2v - sin_v);
    UD_Z(2 * (sqrt_u * cos_3u_half - u * sqrt_u * sin(1.5 * u)));

    // Ignore scaling by u
    pasuli_calctype sign_value = PASULI_CALC_SIGN(u);
    VD_X(sign_value * (u * sin_2v - v));
    VD_Y(-sign_value * (u * cos_2v + cos_v));
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBoursMinimalSurface =
    "name: Bour's Minimal surface;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:pi: -2; ve:pi:2;\
x: u*cos(v)-u^2*cos(2*v)/2;\
y: -u*sin(v)-u^2*sin(2*v)/2;\
z: 4*u^(3/2)*cos(3*u/2)/3;\
xu: -u*cos(2*v)+cos(v);\
yu: -u*sin(2*v)-sin(v);\
zu: 2*(sqrt(u)*cos(3*u/2)-u*sqrt(u)*sin(3*u/2);\
xv: u*(u*sin(2*v)-sin(v));\
yv: -u*(u*cos(2*v)+cos(v));\
zv: 0;";
#endif