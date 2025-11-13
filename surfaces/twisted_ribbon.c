
#include "twisted_ribbon.h"
#include "surfaces_c_includes.h"

#if (USE_TWISTED_RIBBON != 0)
void TwistedRibbon(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_RIBBON)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(3 * sin_u * cos_v);
    P_Y(3 * sin_u * sin_v);
    P_Z(cos_v);

    // Skip scaling by 3*cos(u)
    pasuli_calctype sign_value = PASULI_CALC_SIGN(cos_u);
    UD_X(sign_value * cos_v);
    UD_Y(sign_value * sin_v);
    UD_Z(0);

    VD_X(-3 * sin_u * sin_v);
    VD_Y(3 * sin_u * cos_v);
    VD_Z(-sin_v);

    // Skip scaling by 3*cos(u)
    N_X(-sign_value * sin_v * sin_v);
    N_Y(sign_value * cos_v * sin_v);
    N_Z(3 * sign_value * sin_u);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descTwistedRibbon =
    "name: Twisted Ribbon;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: 3*sin(u)*cos(v);\
y: 3*sin(u)*sin(v);\
z: cos(v);\
xu: 3*cos(u)*cos(v);\
yu: 3*cos(u)*sin(v);\
zu: 0;\
xv: -3*sin(u)*sin(v);\
yv: 3*sin(u)*cos(v);\
zv: -sin(v);\
xn: -3*cos(u)*sin(v)^2;\
yn: 3*cos(u)*cos(v)*sin(v);\
zn: 9*cos(u)*sin(u);";
#endif
