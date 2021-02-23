
#include "tooth_surface.h"
#include "surfaces_c_includes.h"

#if (USE_TOOTH_SURFACE != 0)
void ToothSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descToothSurface =
    "name: Tooth Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:0.5;\
a1:R: sqrt(1/((sin(u)^4+cos(u)^4)*cos(v)^4+sin(v)^4));\
x: R*cos(v)*cos(u);\
y: R*cos(v)*sin(u);\
z: R*sin(v);";
#endif
