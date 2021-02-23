
#include "crossed_trough_surface.h"
#include "surfaces_c_includes.h"

#if (USE_CROSSED_TROUGH_SURFACE != 0)
void CrossedTroughSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO) {

                          }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCrossedTroughSurface =
    "name: Crossed Trough Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:pi:-1; ve:pi:1;\
c1:c: 1;\
x: u*sin(v);\
y: u*cos(v);\
z: c*u^4*sin(2*v)^2/4;";
#endif
