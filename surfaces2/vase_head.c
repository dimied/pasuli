
#include "vase_head.h"
#include "surfaces_c_includes.h"

#if (USE_VASE_HEAD != 0)
void VaseHead(pasuli_vartype u,
              pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(VASE_HEAD)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_bv_u = cos(b * v + u);

    P_X(v * cos_bv_u);
    P_Y(v * sin_u);
    P_Z(a * v * v);

    pasuli_calctype sin_bv_u = sin(b * v + u);
    UD_X(-v * sin_bv_u);
    UD_Y(v * cos_u);
    UD_Z(0);

    VD_X(-b * v * sin_bv_u + cos_bv_u);
    VD_Y(sin_u);
    VD_Z(2 * a * v);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descVaseHead =
    "name: Vase Head;\
ut:u; vt:c;\
us:0; ue:pi:2;\
vs:-2; ve:2;\
c1:a: 1; c2:b: 1;\
x: v*cos(b*v+u);\
y: v*sin(u);\
z: a*v^2;\
xu: -v*sin(b*v+u);\
yu: v*cos(u);\
zu: 0;\
xv: -b*v*sin(b*v+u)+cos(b*v+u);\
yv: sin(u);\
zv: 2*a*v;";
#endif