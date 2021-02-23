
#include "wrinkle_sphere2.h"
#include "surfaces_c_includes.h"

#if (USE_WRINKLE_SPHERE2 != 0)
void WrinkleSphere2(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO) {

                    }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWrinkleSphere2 =
    "name: Wrinkle Sphere 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
c1:n: 20;\
x: sin(u)*sin(v)+cos(n*v)/n;\
y: cos(u)*sin(v)+cos(n*u)/n;\
z: cos(v);";
#endif
