
#include "hector_guinards_surface.h"
#include "surfaces_c_includes.h"

#if (USE_HECTOR_GUINARDS_SURFACE != 0)
void HectorGuinardsSurface(pasuli_vartype u,
                           pasuli_vartype v,
                           pasuli_consttype *constants,
                           PaSuLiObject *pO) {

                           }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descHectorGuinardsSurface =
    "name: Hector Guinards Surface;\
ut:c; vt:o;\
us:0; ue:1;\
vs:pi:-1; ve:pi:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: ((1-u)*a+u*b)*cos(v);\
y: b*u*sin(v);\
z: c*u*sin(v)^2;";
#endif
