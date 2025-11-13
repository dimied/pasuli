
#include "cross_cup2.h"
#include "surfaces_c_includes.h"

#if (USE_CROSS_CUP2 != 0)
void CrossCup2(pasuli_vartype u,
               pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CROSS_CUP2)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype cos_2v = cos(2.0 * v);
    pasuli_calctype sin_2v = sin(2.0 * v);

    P_X(cos_u * sin_2v * 0.5);
    P_Y(sin_u * sin_2v * 0.5);
    P_Z((cos_v * cos_v - cos_u * cos_u * sin_v * sin_v) * 0.5);

    UD_X(-PASULI_COND_COPY_POS_Y(sin_u * sin_2v * 0.5));
    UD_Y(PASULI_COND_COPY_POS_X(cos_u * sin_2v * 0.5));
    UD_Z(cos_u * sin_u * sin_v * sin_v);

    VD_X(cos_u * cos_2v);
    VD_Y(sin_u * sin_2v);
    VD_Z(-cos_v * sin_v * (1 + cos_u * cos_u));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup2 =
    "name: Cross Cup 2;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
x: cos(u)*sin(2*v)/2;\
y: sin(u)*sin(2*v)/2;\
z: (cos(v)^2-cos(u)^2*sin(v)^2)/2;\
xu: -sin(u)*sin(2*v)/2;\
yu: cos(u)*sin(2*v)/2;\
zu: cos(u)*sin(u)*sin(v)^2;\
xv: cos(u)*cos(2*v);\
yv: sin(u)*cos(2*v);\
zv: -cos(v)*sin(v)*(1+cos(u)^2);";
#endif
