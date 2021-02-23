
#include "goblet.h"
#include "surfaces_c_includes.h"

#if (USE_GOBLET != 0)
void Goblet(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO) {

            }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descGoblet =
    "name: Goblet;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: cos(u)*cos(2*v);\
y: sin(u)*cos(2*v);\
z: -2*sin(v);";
#endif
