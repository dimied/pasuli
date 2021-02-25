
#include "roman_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_ROMAN_SURFACE2 != 0)
void RomanSurface2(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ROMAN_SURFACE2)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_2u = sin(2 * u);

    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_2v = cos(2 * v);
    pasuli_calctype sin_2v = sin(2 * v);

    P_X(sin_2u * sin_v * sin_v * 0.5);
    P_Y(sin_u * cos_2v * 0.5);
    P_Z(cos_u * sin_2v * 0.5);

    pasuli_calctype cos_2u = cos(2 * u);
    UD_X(cos_2u * sin_v * sin_v);
    UD_Y(cos_u * cos_2v * 0.5);
    UD_Z(-sin_u * sin_2v * 0.5);

    //sin(2*v) = 2*cos_v*sin_v
    VD_X(sin_2v * sin_2u * 0.5);
    VD_Y(-sin_u * sin_2v);
    VD_Z(cos_u * cos_2v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRomanSurface2 =
    "name: Roman Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:pi:-0.5; ve:pi:0.5;\
x: sin(2*u)*sin(v)^2/2;\
y: sin(u)*cos(2*v)/2;\
z: cos(u)*sin(2*v)/2;\
xu: cos(2*u)*sin(v)^2;\
yu: cos(u)*cos(2*v)/2;\
zu: -sin(u)*sin(2*v)/2;\
xv: cos(v)*sin(v)*sin(2*u);\
yv: -sin(u)*sin(2*v);\
zv: cos(u)*cos(2*v);";
#endif