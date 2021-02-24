
#include "bowtie.h"
#include "surfaces_c_includes.h"

#if (USE_BOWTIE != 0)
void Bowtie(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOWTIE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sqrt2 = sqrt(2.0);

    pasuli_calctype divisor_by_cos_v = (sqrt2 + cos_v);
    pasuli_calctype divisor_by_sin_v = (sqrt2 + sin_v);

    P_X(sin_u / divisor_by_sin_v);
    P_Y(sin_u / divisor_by_cos_v);
    P_Z(cos_u / (1 + sqrt2));

    UD_X(cos_u / divisor_by_sin_v);
    UD_Y(cos_u / divisor_by_cos_v);
    UD_Z(-sin_u / (1 + sqrt2));

    VD_X(-sin_u * cos_v / (divisor_by_sin_v * divisor_by_sin_v));
    VD_Y(sin_u * sin_v / (divisor_by_cos_v * divisor_by_cos_v));
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBowtie =
    "name: Bowtie;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: sin(u)/(sqrt(2)+sin(v));\
y: sin(u)/(sqrt(2)+cos(v));\
z: cos(u)/(1+sqrt(2));\
xu: cos(u)/(sqrt(2)+sin(v));\
yu: cos(u)/(sqrt(2)+cos(v));\
zu: -sin(u)/(1+sqrt(2));\
xv: -sin(u)*cos(v)/(sqrt(2)+sin(v))^2;\
yv: sin(u)*sin(v)/(sqrt(2)+cos(v))^2;\
zv: 0;";
#endif
