
#include "cross_cup3.h"
#include "surfaces_c_includes.h"

#if (USE_CROSS_CUP3 != 0)
void CrossCup3(pasuli_vartype u,
               pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CROSS_CUP3)

    pasuli_consttype a = constants[0];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_2u = cos(2 * u);
    pasuli_calctype sin_2u = sin(2 * u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_2v = sin(2 * v);

    P_X(a * sin_u * sin_2v * 0.5);
    P_Y(a * sin_2u * sin_v * sin_v);
    P_Z(a * cos_2u * sin_v * sin_v);

    UD_X(a * cos_u * sin_2v * 0.5);
    UD_Y(2 * PASULI_COND_COPY_POS_Z(a * cos_2u * sin_v * sin_v));
    UD_Z(-2 * PASULI_COND_COPY_POS_Y(a * sin_2u * sin_v * sin_v));

    pasuli_calctype cos_2v = cos(2 * v);
    // Ignore scaling by a
    a = PASULI_CALC_SIGN(a);
    VD_X(a * cos_2v * sin_u);
    cos_v *= sin_v;
    VD_Y(2 * a * cos_v * sin_2u);
    VD_Z(2 * a * cos_v * cos_2u);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup3 =
    "name: Cross Cup 3;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
c1:a: 1;\
x: a*sin(u)*sin(2*v)/2;\
y: a*sin(2*u)*sin(v)^2;\
z: a*cos(2*u)*sin(v)^2;\
xu: a*cos(u)*sin(2*v)/2;\
yu: 2*a*cos(2*u)*sin(v)^2;\
zu: -2*a*sin(2*u)*sin(v)^2;\
xv: a*cos(2*v)*sin(u);\
yv: 2*a*cos(v)*sin(v)*sin(2*u);\
zv: 2*a*cos(v)*sin(v)*cos(2*u);";
#endif
