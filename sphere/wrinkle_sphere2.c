
#include "wrinkle_sphere2.h"
#include "sphere_c_includes.h"

#if (USE_WRINKLE_SPHERE2 != 0)
/**
 * Some new surface based on wirnkle sphere definition, 
 * but with configurable "wrinkle parameter" n
 */
void WrinkleSphere2(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(WRINKLE_SPHERE2)

    pasuli_consttype n = constants[0];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(sin_u * sin_v + cos(n * v) / n);
    P_Y(cos_u * sin_v + cos(n * u) / n);
    P_Z(cos_v);

    pasuli_calctype sin_n_u = sin(n * u);
    UD_X(cos_u * sin_v);
    UD_Y(-sin_u * sin_v - sin_n_u);
    UD_Z(0);

    pasuli_calctype sin_n_v = sin(n * v);
    VD_X(cos_v * sin_u - sin_n_v);
    VD_Y(cos_u * cos_v);
    VD_Z(-sin_v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWrinkleSphere2 =
    "name: Wrinkle Sphere 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
c1:n: 20;\
x: sin(u)*sin(v)+cos(n*v)/n;\
y: cos(u)*sin(v)+cos(n*u)/n;\
z: cos(v);\
xu: cos(u)*sin(v);\
yu: -sin(u)*sin(v)-sin(n*u);\
zu: 0;\
xv: cos(v)*sin(u)-sin(n*v);\
yv: cos(u)*cos(v);\
zv: -sin(v);\
xn: sin(u)*sin(v)^2+sin(v)*sin(n*u);\
yn: cos(u)*sin(v)^2;\
zn: cos(v)*sin(v) + cos(v)*sin(u)*sin(n*u)-sin(u)*sin(v)*sin(n*v)-sin(n*u)*sin(n*V);";
#endif
