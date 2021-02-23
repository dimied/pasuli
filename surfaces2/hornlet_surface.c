
#include "hornlet_surface.h"
#include "surfaces_c_includes.h"

#if (USE_HORNLET_SURFACE != 0)
void HornletSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO) {

                    }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHornletSurface =
    "name: Hornlet Surface;\
ut:c; vt:o;\
us:0; ue:2;\
vs:0; ve:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: (a+sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v);\
y: (a+sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v);\
z: cos(b*pi*u)*sin(b*pi*v)+h*v;";
#endif
