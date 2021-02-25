
#include "wavy_enneper_surface.h"
#include "surfaces_c_includes.h"

#if (USE_WAVY_ENNEPER_SURFACE != 0)
void WavyEnneperSurface(pasuli_vartype u,
                        pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(WAVY_ENNEPER_SURFACE)

    pasuli_consttype s = constants[0];

    pasuli_calctype s_factor = 2 * s - 1;
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_sv = cos(s * v);

    pasuli_calctype cos_v_2s_minus_1 = cos(s_factor * v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_v_2s_minus_1 = sin(s_factor * v);

    pasuli_calctype u_pow_2s_minus_1 = pow(u, s_factor);
    pasuli_calctype u_pow_s = pow(u, s);

    P_X(u * cos_v - u_pow_2s_minus_1 * cos_v_2s_minus_1 / s_factor);
    P_Y(-u * sin_v - u_pow_2s_minus_1 * sin_v_2s_minus_1 / s_factor);
    P_Z(2 * u_pow_s * cos_sv / s);

    pasuli_calctype u_pow_2s_minus_2 = pow(u, s_factor - 1);
    pasuli_calctype u_pow_s_minus_1 = pow(u, s - 1);
    UD_X(cos_v - u_pow_2s_minus_2 * cos_v_2s_minus_1);
    UD_Y(-sin_v - u_pow_2s_minus_2 * sin_v_2s_minus_1);
    UD_Z(2 * u_pow_s_minus_1 * cos_sv);

    VD_X(u_pow_s_minus_1 * sin_v_2s_minus_1 - u * sin_v);
    VD_Y(-u_pow_s_minus_1 * cos_v_2s_minus_1 - u * cos_v);
    VD_Z(-2 * u_pow_s * sin(s * v));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWavyEnneperSurface =
    "name: Wavy Enneper Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
c1:s: 2;\
x: u*cos(v)-u^(2*s-1)*cos((2*s-1)*v)/(2*s-1);\
y: -u*sin(v)-u^(2*s-1)*sin((2*s-1)*v)/(2*s-1);\
z: 2*u^s*cos(s*v)/s;\
xu: cos(v)-u^(2*s-2)*cos((2*s-1)*v);\
yu: -sin(v)-u^(2*s-2)*sin((2*s-1)*v);\
zu: 2*u^(s-1)*cos(s*v);\
xv: u^(2*s-1)*sin((2*s-1)*v)-u*sin(v);\
yv: -u^(2*s-1)*cos((2*s-1)*v)-u*cos(v);\
zv: -2*u^s*sin(s*v);";
#endif