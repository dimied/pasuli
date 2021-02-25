
#include "snail2.h"
#include "surfaces_c_includes.h"

#if (USE_SNAIL2 != 0)
void Snail2(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SNAIL2)

    pasuli_consttype a = constants[0];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_u2 = sin_u * sin_u;
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype a_pow_v = pow(a, v);

    P_X(a_pow_v * sin_u2 * sin_v);
    P_Y(a_pow_v * sin_u2 * cos_v);
    P_Z(a_pow_v * sin_u * cos_u);

    // Ignore scaling by a^v
    pasuli_calctype factor = PASULI_CALC_SIGN(a_pow_v);
    pasuli_calctype diff = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_u, sin_u);
    UD_X(2 * factor * cos_u * sin_u * sin_v);
    UD_Y(2 * factor * cos_u * sin_u * cos_v);
    UD_Z(factor * diff);

    // Ignore scaling by a^v*sin(u)
    factor *= sin_u;
    factor = PASULI_CALC_SIGN(factor);
    pasuli_calctype log_a = log(a);
    VD_X(factor * sin_u * (cos_v + log_a * sin_v));
    VD_Y(factor * sin_u * (-sin_v + log_a * cos_v));
    VD_Z(factor * cos_u * log_a);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSnail2 =
    "name: Snail 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:pi:-2; ve:pi:2;\
c1:a: 1;\
x: a^v*sin(u)^2*sin(v);\
y: a^v*sin(u)^2*cos(v);\
z: a^v*sin(u)*cos(u);\
xu: 2*a^v*cos(u)*sin(u)*sin(v);\
yu: 2*a^v*cos(u)*sin(u)*cos(v);\
zu: a^v*(cos(u)^2-sin(u)^2);\
xv: a^v*sin(u)^2*(cos(v)+log(a)*sin(v));\
yv: a^v*sin(u)^2*(-sin(v)+log(a)*cos(v));\
zv: a^v*cos(u)*log(a)*sin(u);";
#endif
