
#include "kiss_surface.h"
#include "surfaces_c_includes.h"

#if (USE_KISS_SURFACE != 0)
void KissSurface(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO) {

                 }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKissSurface =
    "name: Kiss Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:-1; ve:1;\
x: v^2*sqrt((1-v)/2)*cos(u);\
y: v^2*sqtt((1-v)/2)*sin(u);\
z: v;";
#endif