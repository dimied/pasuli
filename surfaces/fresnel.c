
#include "fresnel.h"
#include "surfaces_c_includes.h"

#if (USE_FRESNEL != 0)
void Fresnel(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(FRESNEL)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype c_squared = c * c;
    pasuli_calctype c2_div_a = c_squared / a;
    pasuli_calctype c2_div_b = c_squared / b;

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_u_sq = cos_u * cos_u;
    pasuli_calctype sin_u = sin(u);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype divisor = sin_v * sin_v + c_squared * cos_v * cos_v * (cos_u * cos_u / (a * a) + sin_u * sin_u / (b * b));

    P_X(cos_u_sq * c_squared / (b * divisor));
    P_Y((sin_u * cos_v * c_squared) / (b * divisor));
    P_Z(c * sin_v / divisor);

    divisor = a * (-1 - c_squared - (1 - c_squared) * cos(2 * v));
    // No scaling by c^2
    UD_X(2 * sin(2 * u) / divisor);

    pasuli_calctype common_divisor = sin_v * sin_v + c_squared * cos_v * cos_v;
    divisor = b * common_divisor * common_divisor;
    UD_Y(cos_u * cos_v / divisor);
    UD_Z(0);

    divisor = a * common_divisor * common_divisor;
    VD_X(2 * c_squared * cos_u * cos_u * (c_squared - 1) * cos_v * sin_v / divisor);

    divisor = b * common_divisor * common_divisor;
    VD_Y(-c_squared * sin_u * sin_v / divisor);

    divisor = common_divisor * common_divisor;
    VD_Z(c * (c_squared - (1 - c_squared) * sin_v * sin_v) * cos_v / divisor);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFresnel = {
PSLDD_ID( FRESNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-1, 1 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descFresnel =
    "name: Fresnel; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -0.5; ve:pi: 0.5; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
a1:d: (sin(v)^(2)+c*c*cos(v)^(2)*(cos(u)^(2)/a*a + sin(u)^(2)/b*b)); \
x: (c*c/a)*(cos(u)^(2))/d; \
y: (c*c/b)*(sin(u)*cos(v))/d; \
z: c*(sin(v))/d; \
xu: 2*c^2*sin(2*u)/(a*(-1 -c^2 - c^2*cos(2*v) + cos(2*v))); \
yu: c^2*cos(u)*cos(v)/(b*(sin(v)^2 + c^2*cos(v)^2)^2); \
zu: 0; \
xv: 2*c^2*cos(u)^2*(c^2 - 1)*cos(v)*sin(v)/(a*(sin(v)^2 + c^2*cos(v)^2)^2); \
yv: -c^2*()*sin(u)*sin(v)/(b*(sin(v)^2 + c^2*cos(v)^2)^2); \
zv: c*(c^2 - sin(v)^2 + c^2*sin(v)^2)*cos(v)/(sin(v)^2 + c^2*cos(v)^2)^2; ";
#endif