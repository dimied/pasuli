
#include "goblet.h"
#include "surfaces_c_includes.h"

#if (USE_GOBLET != 0)

void Goblet(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(GOBLET)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_2v = cos(2 * v);
    pasuli_calctype sin_v = sin(v);

    P_X(cos_u * cos_2v);
    P_Y(sin_u * cos_2v);
    P_Z(-2 * sin_v);

    // NO scaling by cos_2v
    pasuli_calctype sign_value = PASULI_CALC_SIGN(cos_2v);
    UD_X(-sin_u * sign_value);
    UD_Y(cos_u * sign_value);
    UD_Z(0);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_2v = sin(2 * v);
    VD_X(-2 * cos_u * sin_2v);
    VD_Y(-2 * sin_u * sin_2v);
    VD_Z(-2 * cos_v);

    // sin(2*v) = 2*cos(v)*sin(v)
    sign_value = PASULI_CALC_SIGN(cos_v * cos_2v);
    // No scaling by cos(2*v)*cos(v)
    N_X(-cos_u * sign_value);
    N_Y(-sin_u * sign_value);
    N_Z(2 * sin_v * sign_value);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descGoblet =
    "name: Goblet;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: cos(u)*cos(2*v);\
y: sin(u)*cos(2*v);\
z: -2*sin(v);\
xu: -sin(u)*cos(2*v);\
yu: cos(u)*cos(2*v);\
zu: 0;\
xv: -2*cos(u)*sin(2*v);\
yv: -2*sin(u)*sin(2*v);\
zv: -2*cos(v);\
xn: -2*cos(u)*cos(v)*cos(2*v);\
yn: -2*sin(u)*cos(v)*cos(2*v);\
zn: 2*cos(2*v)*sin(2*v);";
#endif
