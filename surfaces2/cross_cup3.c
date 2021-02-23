
#include "cross_cup3.h"
#include "surfaces_c_includes.h"

#if (USE_CROSS_CUP3 != 0)
void CrossCup3(pasuli_vartype u,
               pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO) {

               }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossCup3 =
    "name: Cross Cup 3;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
c1:a: 1;\
x: a*sin(u)*sin(2*v)/2;\
y: a*sin(2*u)*sin(v)^2;\
z: a*cos(2*u)*sin(v)^2;";
#endif
