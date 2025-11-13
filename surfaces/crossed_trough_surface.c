
#include "crossed_trough_surface.h"
#include "surfaces_c_includes.h"

#if (USE_CROSSED_TROUGH_SURFACE != 0)
void CrossedTroughSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CROSSED_TROUGH_SURFACE)

    pasuli_consttype c = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_2v = sin(2 * v);
    pasuli_calctype u2 = u * u;

    P_X(u * sin_v);
    P_Y(u * cos_v);
    P_Z(c * u2 * u2 * sin_2v * sin_2v * 0.5);

    UD_X(sin_v);
    UD_Y(cos_v);
    UD_Z(c * u2 * u * sin_2v * sin_2v);

    pasuli_calctype cos_2v = cos(2 * v);
    VD_X(PASULI_COND_COPY_POS_Y(u * cos_v));
    VD_Y(-PASULI_COND_COPY_POS_X(u * sin_v));
    VD_Z(-c * u2 * u2 * cos_2v * sin_2v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossedTroughSurface =
    "name: Crossed Trough Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:pi:-1; ve:pi:1;\
c1:c: 1;\
x: u*sin(v);\
y: u*cos(v);\
z: c*u^4*sin(2*v)^2/4;\
xu: sin_v;\
yu: cos_v;\
zu: c*u^3*sin(2*v)^2;\
xv: u*cos(v);\
yv: -u*sin(v);\
zv: c*u^4*cos(2*v)*sin(2*v);";
#endif
