
#include "skidan_ruled_surface.h"
#include "surfaces_c_includes.h"

#if (USE_SKIDAN_RULED_SURFACE != 0)
void SkidanRuledSurface(pasuli_vartype u,
                        pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SKIDAN_RULED_SURFACE)

    pasuli_consttype a = constants[0];
    pasuli_consttype h = constants[1];
    pasuli_consttype n = constants[2];

    pasuli_calctype cos_a = cos(a);
    pasuli_calctype sin_a = sin(a);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype cos_nv = cos(n * v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype b = h * fabs(cos_nv);
    pasuli_calctype factor = u * sin_a + b * cos_a;
    pasuli_calctype pos_x = factor * cos_v;
    pasuli_calctype pos_y = factor * sin_v;

    P_X(pos_x);
    P_Y(pos_y);
    P_Z(u * cos_a * b * sin_a);

    UD_X(cos_v * sin_a);
    UD_Y(sin_v * sin_a);
    UD_Z(cos_a);

    pasuli_calctype sign_value = PASULI_CALC_SIGN(cos_nv);
    pasuli_calctype sin_nv = sin(n * v);
    factor = -h * n * cos_a * sign_value * sin_nv;
    VD_X(factor * cos_v - pos_y);
    VD_Y(factor * sin_v + pos_x);
    VD_Z(h * n * sign_value * sin_a * sin_nv);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSkidanRuledSurface =
    "name: Skidan Ruled Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:a: 1; c2:h: 1; c3:n: 1;\
a1:b: h*abs(cos(n*v));\
x: (u*sin(a)+b*cos(a))*cos(v);\
y: (u*sin(a)+b*cos(a))*sin(v);\
z: u*cos(a)-b*sin(a);\
xu: cos(v)*sin(a);\
yu: sin(v)*sin(a);\
zu: cos(a);\
xv: -h*n*cos(a)*cos(v)*sgn(cos(n*v))*sin(n*v) - h*abs(cos(n*v))*cos(a)*sin(v) - u*sin(a)*sin(v);\
yv: -h*n*cos(a)*sin(v)*sgn(cos(n*v))*sin(n*v) + h*abs(cos(n*v))*cos(a)*cos(v) + u*sin(a)*cos(v);\
zv: h*n*sgn(cos(n*v))*sin(a)*sin(n*v);";
#endif
