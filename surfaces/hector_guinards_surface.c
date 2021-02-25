
#include "hector_guinards_surface.h"
#include "surfaces_c_includes.h"

#if (USE_HECTOR_GUINARDS_SURFACE != 0)
void HectorGuinardsSurface(pasuli_vartype u,
                           pasuli_vartype v,
                           pasuli_consttype *constants,
                           PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HECTOR_GUINARDS_SURFACE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype factor = ((1 - u) * a + u * b);

    P_X(factor * cos_v);
    P_Y(b * u * sin_v);
    P_Z(c * u * sin_v * sin_v);

    UD_X(cos_v * (b - a));
    UD_Y(b * sin_v);
    UD_Z(c * sin_v * sin_v);

    VD_X(-sin_v * factor);
    VD_Y(b * u * cos_v);
    VD_Z(2 * c * u * cos_v * sin_v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHectorGuinardsSurface =
    "name: Hector Guinards Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:pi:-1; ve:pi:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: ((1-u)*a+u*b)*cos(v);\
y: b*u*sin(v);\
z: c*u*sin(v)^2;\
xu: cos(v)*(b-a);\
yu: b*sin(v);\
zu: c*sin(v)^2;\
xv: sin(v)*((u-1)*a-b*u);\
yv: b*u*cos(v);\
zv: 2*c*u*cos(v)*sin(v);";
#endif
