
#include "balls_cylindroid.h"
#include "surfaces_c_includes.h"

#if (USE_BALLS_CYLINDROID != 0)
void BallsCylindroid(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO) {

                     }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBallsCylindroid =
    "name: Balls Cylindroid;\
ut:c; vt:o;\
us:0; ue:2;\
vs:0; ve:pi:2;\
c1:k: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: k*sin(v)*cos(v);";
#endif
