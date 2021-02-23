
#include "cross_cup2.h"
#include "surfaces_c_includes.h"

#if (USE_CROSS_CUP2 != 0)
void CrossCup2(pasuli_vartype u,
               pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO) {

               }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup2 =
    "name: Cross Cup 2;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
x: cos(u)*sin(2*v)/2;\
y: sin(u)*sin(2*v)/2;\
z: (cos(v)^2-cos(u)^2*sin(v)^2)/2;";
#endif
