
#include "peano_surface.h"
#include "surfaces_c_includes.h"

#if (USE_PEANO_SURFACE != 0)
void PeanoSurface(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPeanoSurface =
    "name: Peano Surface;\
ut:o; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u;\
y: v;\
z: (2*u^2-v)*(v-u^2);";
#endif
