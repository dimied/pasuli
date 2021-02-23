
#include "snail2.h"
#include "surfaces_c_includes.h"

#if (USE_SNAIL2 != 0)
void Snail2(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO) {

            }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSnail2 =
    "name: Snail 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:pi:-2; ve:pi:2;\
c1:a: 1;\
x: a^v*sin(u)^2*sin(v);\
y: a^v*sin(u)^2*cos(v);\
z: a^v*sin(u)*cos(u);";
#endif

