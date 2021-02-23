
#include "richmond_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_RICHMOND_SURFACE2 != 0)
void RichmondSurface2(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO) {

                      }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface2 =
    "name: Richmond Surface 2;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u^3/3-u*v^2+u/(u^2+v^2);\
y: v^3/3-v*u^2-v/(u^2+v^2);\
z: 2*u;";
#endif
