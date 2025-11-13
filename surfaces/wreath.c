#include "bours_minimal_surface.h"
#include "surfaces_c_includes.h"

#if (USE_WREATH != 0)
void Wreath(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(WREATH)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype factor = cos_u * cos_v * sin_u * sin_v;
    P_X(cos(u + 4) / 3.0);
    P_Y(factor * cos_v + 0.5 * cos_u);
    P_Z(factor);

    factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_u, sin_u);
    factor *= sin_v;
    UD_X(-sin(u + 4) / 3.0);
    UD_Y(cos_v * cos_v * factor - 0.5 * sin_u);
    UD_Z(cos_v * factor);

    // Ignore scaling by cos(u)*sin(u)
    cos_u *= sin_u;
    cos_u = PASULI_CALC_SIGN(cos_u);
    factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
    VD_X(0);
    VD_Y(cos_u * (cos_v * (cos_v * cos_v - 2 * sin_v * sin_v)));
    VD_Z(cos_u * factor);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWreath =
    "name: Wreath;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
x: cos(u+4)/3;\
y: cos(u)*sin(v)*cos(v)*sin(u)*cos(v)+0.5*cos(u);\
z: cos(v)*sin(u)*cos(u)*sin(v);\
xu: -sin(u+4)/3;\
yu: cos(v)^2*sin(v)*(cos(u)^2-sin(u)^2)-0.5*sin(u);\
zu: cos(v)*sin(v)*(cos(u)^2-sin(u)^2);\
xv: 0;\
yv: cos(u)*sin(u)*(cos(v)^3-2*cos(v)*sin(v)^2);\
zv: cos(u)*sin(u)*(cos(v)^2-sin(v)^2);";
#endif