
#include "spinning_top2.h"
#include "surfaces_c_includes.h"

#if (USE_SPINNING_TOP2 != 0)
void SpinningTop2(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SPINNING_TOP2)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_2u = cos(2 * u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype factor = cos_2u * sin_u;
    P_X(factor * cos_v);
    P_Y(factor * sin_v);
    P_Z(cos_2u * cos_u);

    pasuli_calctype sin_2u = sin(2 * u);
    factor = cos_u * cos_2u - 2 * sin_u * sin_2u;
    UD_X(cos_v * factor);
    UD_Y(sin_v * factor);
    UD_Z(-2 * (cos_u * sin_2u + sin_u * cos_2u));

    // Skip scaling by cos(2*u)*sin(u)
    factor = cos_2u * sin_u;
    factor = PASULI_CALC_SIGN(factor);
    VD_X(-factor * sin_v);
    VD_Y(factor * cos_v);
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSpinningTop2 =
    "name: Spinning Top 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
x: cos(2*u)*sin(u)*cos(v);\
y: cos(2*u)*sin(u)*sin(v);\
z: cos(2*u)*cos(u);\
xu: cos(v)*(cos(u)*cos(2*u)-2*sin(u)*sin(2*u));\
yu: sin(v)*(cos(u)*cos(2*u)-2*sin(u)*sin(2*u));\
zu: -2*(cos(u)*sin(2*u)+sin(u)*cos(2*u));\
xv: -cos(2*u)*sin(u)*sin(v);\
yv: cos(2*u)*sin(u)*cos(v);\
zv: 0;";
#endif
