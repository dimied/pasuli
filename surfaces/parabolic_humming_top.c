
#include "parabolic_humming_top.h"
#include "surfaces_c_includes.h"

#if (USE_PARABOLIC_HUMMING_TOP != 0)
void ParabolicHummingTop(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PARABOLIC_HUMMING_TOP)

    pasuli_consttype h = constants[0];
    pasuli_consttype p = constants[1];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype factor = fabs(v) - h;
    pasuli_calctype factor2 = factor * factor;

    P_X(factor * cos_u / (2 * p));
    P_Y(factor * sin_u / (2 * p));
    P_Z(v);

    // Ignore scaling by (abs(v)-h)^2/(2*p)
    factor2 /= 2 * p;
    factor2 = PASULI_CALC_SIGN(factor2);
    UD_X(-factor2 * sin_u);
    UD_Y(factor2 * cos_u);
    UD_Z(0);

    factor *= PASULI_CALC_SIGN(v);
    VD_X(cos_u * factor / p);
    VD_Y(sin_u * factor / p);
    VD_Z(1);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descParabolicHummingTop =
    "name: Parabolic Humming Top;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs: -h; ve: h;\
c1:h: 1; c2:p: 1;\
x: (abs(v)-h)^2*cos(u)/(2*p);\
y: (abs(v)-h)^2*sin(u)/(2*p);\
z: v;\
xu: -(abs(v)-h)^2*sin(u)/(2*p);\
yu: (abs(v)-h)^2*cos(u)/(2*p);\
zu: 0;\
xv: cos(u)*sgn(v)*(abs(v)-1)/p;\
yv: sin(u)*sgn(v)*(abs(v)-1)/p;\
zv: 1;";
#endif
