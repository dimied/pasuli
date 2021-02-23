
#include "parabolic_humming_top.h"
#include "surfaces_c_includes.h"

#if (USE_PARABOLIC_HUMMING_TOP != 0)
void ParabolicHummingTop(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO) {

                         }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descParabolicHummingTop =
    "name: Parabolic Humming Top;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: -h; ve: h;\
c1:h: 1; c2:p: 1;\
x: (|v|-h)^2*cos(u)/(2*p);\
y: (|v|-h)^2*sin(u)/(2*p);\
z: v;";
#endif
