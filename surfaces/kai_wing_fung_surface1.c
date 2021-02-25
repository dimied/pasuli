
#include "kai_wing_fung_surface1.h"
#include "surfaces_c_includes.h"

#if (USE_KAI_WING_FUNG_SURFACE1 != 0)
void KaiWingFungSurface1(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KAI_WING_FUNG_SURFACE1)

    pasuli_consttype n = constants[0];

    pasuli_calctype cosh_u = cosh(u);
    pasuli_calctype cosh_u_pow_2 = cosh_u * cosh_u;
    pasuli_calctype sinh_u = sinh(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype a = sin(MY_PI / n);
    pasuli_calctype b = cos(MY_PI / n);

    pasuli_calctype C = cosh(u) + sinh(u);
    pasuli_calctype D = sin_v * cosh_u * sinh_u;
    pasuli_calctype E = cos_v * cosh_u * sinh_u;

    P_X((-b * cos_v * cosh_u_pow_2 - b * E + a * sin_v * cosh_u_pow_2 + a * D - a * sin_v) / C);
    P_Y((-a * cos_v * cosh_u_pow_2 + a * E - a * cos_v + b * sin_v * cosh_u_pow_2 + b * D) / C);
    P_Z(b * u - a * v);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKaiWingFungSurface1 =
    "name: Kai-WingFung Surface 1;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:0; ve:pi:2;\
c1:n: 2;\
a1:a: sin(pi/n);\
a2:b: cos(pi/n);\
a3:C: cosh(u)+sinh(u);\
a4:D: sin(v)*cosh(u)*sinh(u);\
a5:E: cos(v)*cosh(u)*sinh(u);\
x: (-b*cos(v)*cosh(u)^2-b*E+a*sin(v)*cosh(u)^2+a*D-a*sin(v))/C;\
y: (-a*cos(v)*cosh(u)^2+a*E-a*cos(v)+b*sin(v)*cosh(u)^2+b*D)/C;\
z: b*u-a*v;";
#endif
