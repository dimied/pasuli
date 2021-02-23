
#include "skidan_ruled_surface.h"
#include "surfaces_c_includes.h"

#if (USE_SKIDAN_RULED_SURFACE != 0)
void SkidanRuledSurface(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSkidanRuledSurface =
    "name: Skidan Ruled Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:a: 1; c2:h: 1; c3:n: 1;\
a1:b: h*|cos(n*v)|;\
x: (u*sin(a)+b*cos(a))*cos(v);\
y: (u*sin(a)+b*cos(a))*sin(v);\
z: u*cos(a)-b*sin(a);";
#endif
