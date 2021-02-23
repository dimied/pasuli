
#include "epitrochoidal_surface.h"
#include "surfaces_c_includes.h"

#if (USE_EPITROCHOIDAL_SURFACE != 0)
void EpitrochoidalSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO) {

                          }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEpitrochoidalSurface =
    "name: Epitrochoidal Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:pi:-0.5; ve:pi:0.5;\
c1:a: 1; c2:m: 1;\
a1:R: a*(1+m*cos(u));\
x: 2*R*cos(v)^2*cos(u);\
y: 2*R*cos(v)^2*sin(u);\
z: R*sin(2*v);";
#endif
