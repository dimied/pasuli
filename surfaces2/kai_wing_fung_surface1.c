
#include "kai_wing_fung_surface1.h"
#include "surfaces_c_includes.h"

#if (USE_KAI_WING_FUNG_SURFACE1 != 0)
void KaiWingFungSurface1(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO) {

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
