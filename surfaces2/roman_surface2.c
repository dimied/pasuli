
#include "roman_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_ROMAN_SURFACE2 != 0)
void RomanSurface2(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO) {

                   }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRomanSurface2 =
    "name: Roman Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:pi:-0.5; ve:pi:0.5;\
x: sin(2*u)*sin(v)^2/2;\
y: sin(u)*cos(2*v)/2;\
z: cos(u)*sin(2*v)/2;";
#endif