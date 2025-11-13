
#include "epitrochoidal_surface.h"
#include "surfaces_c_includes.h"

#if (USE_EPITROCHOIDAL_SURFACE != 0)
void EpitrochoidalSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(EPITROCHOIDAL_SURFACE)

    pasuli_consttype a = constants[0];
    pasuli_consttype m = constants[1];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_2v = sin(2 * v);

    pasuli_calctype R = a * (1 + m * cos_u);
    pasuli_calctype factor = 2 * R * cos_v * cos_v;
    P_X(factor * cos_u);
    P_Y(factor * sin_u);
    P_Z(R * sin_2v);

    UD_X(-factor * sin_u);
    UD_Y(2 * a * cos_v * cos_v * (m * (2 * cos_u * cos_u - 1) + cos_u));
    UD_Z(-a * m * sin_u * sin_2v);

    pasuli_calctype cos_2v = cos(2 * v);
    //2*sin(2*v)= sin(v)*cos(v)
    // Ignore factor 2*a*(m*cos(u)+1)
    factor = PASULI_CALC_SIGN(factor);
    VD_X(factor * cos_u * sin_2v);
    VD_Y(factor * sin_u * sin_2v);
    VD_Z(cos_2v * factor);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEpitrochoidalSurface =
    "name: Epitrochoidal Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:pi:-0.5; ve:pi:0.5;\
c1:a: 1; c2:m: 1;\
a1:R: a*(1+m*cos(u));\
x: 2*R*cos(v)^2*cos(u);\
y: 2*R*cos(v)^2*sin(u);\
z: R*sin(2*v);\
xu: -2*a*cos(v)^2*sin(u)*(2*m*cos(u)+1);\
yu: 2*a*cos(v)^2*(m*(cos(u)^2-sin(u)^2) + cos(u));\
zu: -a*m*sin(u)*sin(2*v);\
xv: -4*a*cos(u)*cos(v)*sin(v)*(m*cos(u)+1);\
yv: -4*a*sin(u)*cos(v)*sin(v)*(m*cos(u)+1);\
zv: 2*a*cos(2*v)*(m*cos(u)+1);";
#endif
