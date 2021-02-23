
#include "four_intersecting_discs.h"
#include "surfaces_c_includes.h"

#if (USE_FOUR_INTERSECTING_DISCS != 0)
void FourIntersectingDiscs(pasuli_vartype u,
                           pasuli_vartype v,
                           pasuli_consttype *constants,
                           PaSuLiObject *pO) {

                           }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descFourIntersectingDiscs =
    "name: Four intersecting discs;\
ut:c; vt:o;\
us:0; ue:pi:4;\
vs:0; ve:pi:2;\
x: v*cos(u)-v^2*cos(2*u)/2;\
y: -v*sin(u)-v^2*sin(2*u)/2;\
z: 4*v^(3/2)*cos(3*u/2)/3;";
#endif
