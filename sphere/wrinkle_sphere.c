
#include "wrinkle_sphere.h"
#include "sphere_c_includes.h"

#if (USE_WRINKLE_SPHERE != 0)
void WrinkleSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(WRINKLE_SPHERE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(sin_u * sin_v + 0.05 * cos(20 * v));
    P_Y(cos_u * sin_v + 0.05 * cos(20 * u));
    P_Z(cos_v);

    pasuli_calctype sin_20u = sin(20 * u);
    UD_X(cos_u * sin_v);
    UD_Y(-sin_u * sin_v - sin_20u);
    UD_Z(0);

    pasuli_calctype sin_20v = sin(20 * v);
    VD_X(cos_v * sin_u - sin_20v);
    VD_Y(cos_u * cos_v);
    VD_Z(-sin_v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWrinkleSphere =
    "name: Wrinkle Sphere;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
x: sin(u)*sin(v)+0.05*cos(20*v);\
y: cos(u)*sin(v)+0.05*cos(20*u);\
z: cos(v);\
xu: cos(u)*sin(v);\
yu: -sin(u)*sin(v)-sin(20*u);\
zu: 0;\
xv: cos(v)*sin(u)-sin(20*v);\
yv: cos(u)*cos(v);\
zv: -sin(v);\
xn: sin(u)*sin(v)^2+sin(v)*sin(20*u);\
yn: cos(u)*sin(v)^2;\
zn: cos(v)*sin(v) + cos(v)*sin(u)*sin(20*u)-sin(u)*sin(v)*sin(20*v)-sin(20*u)*sin(20*v);";
#endif