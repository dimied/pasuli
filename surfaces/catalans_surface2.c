
#include "catalans_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_CATALANS_SURFACE2 != 0)
void CatalansSurface2(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CATALANS_SURFACE2)

    pasuli_consttype a = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_2v = cos(2 * v);
    pasuli_calctype sin_2v = sin(2 * v);

    pasuli_calctype factor = 1 + 2 * u * u;

    P_X(a * (2 * v - factor) * sin_2v);
    P_Y(a * factor * cos_2v);
    P_Z(4 * a * u * sin_v * cos_v);

    // Ignore scaling by 4*a*u
    pasuli_calctype sign_value = 4 * a * u;
    sign_value = PASULI_CALC_SIGN(sign_value);
    UD_X(-sign_value * sin_2v);
    UD_Y(sign_value * cos_2v);
    UD_Z(sign_value * cos_v * sin_v);

    // Ignore scaling by 2*a
    sign_value = PASULI_CALC_SIGN(a);

    VD_X(sign_value * (1 - cos_2v * factor));
    VD_Y(-sin_2v * factor);
    factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
    VD_Z(2 * u * factor);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface2 =
    "name: Catalan Surface 2;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-5; ve:5;\
c1:a: 1;\
x: a*(2*v-(1+2*u^2)*sin(2*v));\
y: a*(1+2*u^2)*cos(2*v);\
z: 4*a*u*sin(v)*cos(v);\
xu: -4*a*u*sin(2*v);\
yu: 4*a*u*cos(2*v);\
zu: 4*a*cos(v)*sin(v);\
xv: 2*a*(1-cos(2*v)*(2*u^2+1));\
yv: -2*a*sin(2*v)*(2*u^2+1);\
zv: 4*a*u*(cos(v)^2-sin(v)^2);";
#endif
