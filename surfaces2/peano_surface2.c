
#include "peano_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_PEANO_SURFACE2 != 0)
void PeanoSurface2(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
// Own invention
char *descPeanoSurface2 =
    "name: Peano Surface 2;\
ut:o; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
c1:a: 1; c2:b: 1; c3:c: 1; c4:d: 1;\
x: u;\
y: v;\
z: (2*a*u^2-b*v)*(c*v-d*u^2);";
#endif
