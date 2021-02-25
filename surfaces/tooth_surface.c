
#include "tooth_surface.h"
#include "surfaces_c_includes.h"

#if (USE_TOOTH_SURFACE != 0)
void ToothSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TOOTH_SURFACE)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype cos_u_pow_4 = PASULI_TRIG_CALC_COS_POW_4(cos_u, u);
    pasuli_calctype sin_u_pow_4 = PASULI_TRIG_CALC_SIN_POW_4(sin_u, u);
    pasuli_calctype cos_v_pow_4 = PASULI_TRIG_CALC_COS_POW_4(cos_v, v);
    pasuli_calctype sin_v_pow_4 = PASULI_TRIG_CALC_SIN_POW_4(sin_v, v);

    pasuli_calctype R = sqrt(1.0 / ((sin_u_pow_4 + cos_u_pow_4) * cos_v_pow_4 + sin_v_pow_4));

    P_X(R * cos_v * cos_u);
    P_Y(R * cos_v * sin_u);
    P_Z(R * sin_v);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descToothSurface =
    "name: Tooth Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
a1:R: sqrt(1/((sin(u)^4+cos(u)^4)*cos(v)^4+sin(v)^4));\
x: R*cos(v)*cos(u);\
y: R*cos(v)*sin(u);\
z: R*sin(v);";
#endif
