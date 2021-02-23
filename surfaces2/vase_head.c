
#include "vase_head.h"
#include "surfaces_c_includes.h"

#if (USE_VASE_HEAD != 0)
void VaseHead(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

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
z: a*v^2;";
#endif