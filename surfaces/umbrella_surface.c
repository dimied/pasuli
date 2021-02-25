#include "umbrella_surface.h"
#include "surfaces_c_includes.h"

#if (USE_UMBRELLA_SURFACE != 0)
void UmbrellaSurface(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(UMBRELLA_SURFACE)

    pasuli_consttype R = constants[0];
    pasuli_consttype h = constants[1];
    pasuli_consttype n = constants[2];

    pasuli_calctype u_pow_1_3 = cbrt(u);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype n_minus_1 = n - 1;
    pasuli_calctype cos_v_n_minus_1 = cos(n_minus_1 * v);
    pasuli_calctype sin_v_n_minus_1 = sin(n_minus_1 * v);

    pasuli_calctype factor_x = n_minus_1 * R * cos_v + R * cos_v_n_minus_1;
    pasuli_calctype factor_y = n_minus_1 * R * sin_v + R * sin_v_n_minus_1;

    P_X(u_pow_1_3 * factor_x / n);
    P_Y(u_pow_1_3 * factor_y / n);
    P_Z(h * (1 - u));

    // Skip scaling by 1/n
    // And multiply by 3*u^(2/3);
    pasuli_calctype u_pow_2_3 = 3 * cbrt(u * u);
    pasuli_calctype sign_value = PASULI_CALC_SIGN(1.0 / n);
    UD_X(factor_x * sign_value);
    UD_Y(factor_y * sign_value);
    UD_Z(-h * u_pow_2_3 * n);

    //Skip scaling by u^(1/3)*(R-r)
    sign_value = u_pow_1_3 * n_minus_1 * R / n;
    sign_value = PASULI_CALC_SIGN(sign_value);
    VD_X(sign_value * (-sin_v_n_minus_1 - sin_v));
    VD_Y(sign_value * (cos_v_n_minus_1 + cos_v));
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descUmbrellaSurface =
    "name: Umbrella surface;\
ut:c; vt:c;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:R: 1; c2:h: 1; c3:n: 1;\
a1:r: R/n;\
x: u^(1/3)*((R-r)*cos(v)+r*cos((n-1)*v));\
y: u^(1/3)*((R-r)*sin(v)+r*sin((n-1)*v));\
z: h*(1-u);\
xu: ((R-r)*cos(v)+r*cos((n-1)*v))/(3*u^(2/3));\
yu: ((R-r)*sin(v)+r*sin((n-1)*v))/(3*u^(2/3));\
zu: -h;\
xv: u^(1/3)*(-(n-1)*r*sin(n*v-v) - (R-r)*sin(v));\
yv: u^(1/3)*((n-1)*r*cos(n*v-v) + (R-r)*cos(v));\
zv: 0;";
#endif