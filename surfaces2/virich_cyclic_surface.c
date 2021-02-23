
#include "virich_cyclic_surface.h"
#include "surfaces_c_includes.h"

#if (USE_VIRICH_CYCLIC_SURFACE != 0)
void VirichCyclicSurface(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO) {

                         }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descVirichCyclicSurface =
    "name: Virich Cyclic Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:a: 1; c2:b: 1; c3:c: 1; c4:d: 1;\
a1:f: a*b/sqrt(a^2*sin(v)^2+b^2*cos(v)^2);\
x: (f*(1+cos(u))+(d^2-c^2)*(1-cos(u))/f)*cos(v)/2;\
y: (f*(1+cos(u))+(d^2-c^2)*(1-cos(u))/f)*sin(v)/2;\
z: (f-(d^2-c^2)/f)*sin(u);";
#endif