
#include "enneper_surface3.h"
#include "surfaces_c_includes.h"

#if (USE_ENNEPER_SURFACE3 != 0)
void EnneperSurface3(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO) {

                     }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface3 =
    "name: Enneper Surface 3;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: -u*(-6+u^2-3*v^2)/(6*sqrt(2));\
y: v*(-6+v^2-3*u^2)/(6*sqrt(2));\
z: (u^2-v^2)/2;";
#endif
