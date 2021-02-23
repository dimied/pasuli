
#include "wrinkle_sphere.h"
#include "surfaces_c_includes.h"

#if (USE_WRINKLE_SPHERE != 0)
void WrinkleSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO) {
                       
                   }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descWrinkleSphere =
    "name: Wrinkle Sphere;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
x: sin(u)*sin(v)+0.05*cos(20*v);\
y: cos(u)*sin(v)+0.05*cos(20*u);\
z: cos(v);";
#endif