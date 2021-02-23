
#include "cayley_surface.h"
#include "surfaces_c_includes.h"

#if (USE_CAYLEY_SURFACE != 0)
void CayleySurface(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO) {

                   }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCayleySurface =
    "name: Cayley Surface;\
ut:c; vt:o;\
us:-1.5; ue:1;\
vs:-1.5; ve:1.5;\
x: u+v;\
y: (u^2+v^2)/2+a(v-u);\
z: (u^3+v^3)/3+a(v^2-u^2);";
#endif
