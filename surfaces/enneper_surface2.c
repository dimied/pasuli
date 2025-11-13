
#include "enneper_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_ENNEPER_SURFACE2 != 0)
void EnneperSurface2(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ENNEPER_SURFACE2)

    pasuli_calctype exp_u = exp(u);
    pasuli_calctype exp_2u = exp(2.0 * u);
    pasuli_calctype exp_3u = exp(3.0 * u);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_2v = cos(2 * v);
    pasuli_calctype cos_3v = cos(3 * v);
    pasuli_calctype sin_3v = sin(3 * v);

    P_X(exp_u * (3 * cos_v - exp_2u * cos_3v) / 6.0);
    P_Y(-exp_u * (3 * sin_v + exp_2u * sin_3v) / 6.0);
    pasuli_calctype z_factor = exp_2u * cos_2v;
    P_Z(z_factor * 0.5);

    pasuli_calctype cos_v_exp_u = cos_v * exp_u;
    pasuli_calctype cos_3v_exp_3u = cos_3v * exp_3u;
    pasuli_calctype sin_v_exp_u = sin_v * exp_u;
    pasuli_calctype sin_3v_exp_3u = sin_3v * exp_3u;

    UD_X((cos_v_exp_u - cos_3v_exp_3u) * 0.5);
    UD_Y(-(sin_v_exp_u + sin_3v_exp_3u) * 0.5);
    UD_Z(z_factor);

    VD_X((sin_3v_exp_3u - sin_v_exp_u) * 0.5);
    VD_Y(-(cos_3v_exp_3u + cos_v_exp_u) * 0.5);
    VD_Z(-sin(2 * v) * exp_2u);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface2 =
    "name: Enneper Surface 2;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: exp(u)*(3*cos(v)-exp(2*u)*cos(3*v))/6;\
y: exp(u)*(-3*sin(v)-exp(2*u)*sin(3*v))/6;\
z: exp(2*u)*cos(2*v)/2;\
xu: (cos(v)*exp(u)-cos(3*v)*exp(3*u))/2;\
yu: -(sin(v)*exp(u)+sin(3*v)*exp(3*u))/2;\
zu: cos(2*v)*exp(2*u);\
xv: (sin(3*v)*exp(3*u)-sin(v)*exp(u))/2;\
yv: -(cos(3*v)*exp(3*u)+cos(v)*exp(u))/2;\
zv: -sin(2*v)*exp(2*u);";
#endif
