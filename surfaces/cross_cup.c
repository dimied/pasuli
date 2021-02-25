
#include "cross_cup.h"
#include "surfaces_c_includes.h"

#if (USE_CROSS_CUP != 0)

void CrossCup(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CROSS_CUP)

    pasuli_calctype u_squared = u * u;
    pasuli_calctype sqrt_1_minus_u2 = sqrt((1 - u_squared) * 0.5f) * u;

    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sinv2 = sin_v * sin_v;

    P_X(1 - u_squared + u_squared * sinv2);
    P_Y(u_squared * sinv2 + 2 * u_squared * sin_v * cos_v);
    P_Z(sqrt_1_minus_u2 * (sin_v + cos_v));

    //-1 + sin(v)^2 = -cos(v)^2
    UD_X(-2 * u * cos_v * cos_v);
    UD_Y(4 * u * cos_v * sin_v + 2 * u * sin_v * sin_v);
    //-u^2*cos(v)/(2*sqrt((1 - u*u)/2)) - u^2*sin(v)/sqrt((1 - u*u)/2) +
    //sqrt((1 - u*u)/2)*cos(v) + sqrt((1 - u*u)/2)*sin(v)
    // (-u^2*cos(v) - u^2*sin(v) + (1 - u*u)*(cos(v) + sin(v)))/(2*sqrt((1 - u*u)/2))
    // ((1 - 2*u*u)*(cos(v) + sin(v)))/(2*sqrt((1 - u*u)/2))
    UD_Z((0.5 - u * u) * (cos(v) + sin(v)) / (sqrt_1_minus_u2));

    VD_X(2 * u * u * cos_v * sin_v);
    VD_Y(2 * u * u * (cos_v * cos_v + cos_v * sin_v - sin_v * sin_v));
    VD_Z(u * sqrt_1_minus_u2 * (cos_v - sin_v));

    PASULI_CALC_NORMAL_FROM_UD_VD

}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrossCup = {
    CROSS_CUP,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI,
    0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup =
    "name: Cross Cup;\
ut: c; vt: c;\
us:0; ue:1; vs:0; ve:pi:2;\
u:cond:<:1;\
x: 1 - u*u + u*u*sin(v)*sin(v);\
y: u*u*sin(v)*sin(v) + 2*u*u*sin(v)*cos(v);\
z: sqrt((1 - u*u)/2)*u*(sin(v) + cos(v));\
xu: -2*u+2*u*sin(v)^2;\
yu: 4*u*cos(v)*sin(v) + 2*u*sin(v)^2;\
zu: -u^2*cos(v)/(2*sqrt((1 - u*u)/2)) - u^2*sin(v)/sqrt((1 - u*u)/2) + sqrt((1 - u*u)/2)*cos(v) + sqrt((1 - u*u)/2)*sin(v);\
xv: 2*u^2*cos(v)*sin(v);\
yv: 2*u^2*cos(v)^2 + 2*u^2*cos(v)*sin(v) - 2*u^2*sin(v)^2;\
zv: u*sqrt((1 - u*u)/2)*(cos(v) - sin(v));";
#endif