
#include "boys_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_BOYS_SURFACE2 != 0)
void BoysSurface2(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBoySurface2 =
    "name: Boy Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:1;\
a1:A: sin(u)*sin(v);\
a2:B: cos(u)*sin(v);\
a3:C: cos(v);\
x: ((2*B^2-A^2-C^2)*(A^2+B^2+C^2)+2*A*C*(A^2-C^2)+B*C*(B^2-C^2)+A*B*(A^2-B^2))/2;\
y: ((A^2-C^2)*(A^2+B^2+C^2)+B*C*(C^2-B^2)+A*B*(A^2-B^2))*sqrt(3)/2;\
z: (A+B+C)*((A+B+C)^3+4*(A-B)*(C-A)*(B-C))/8;";
#endif
