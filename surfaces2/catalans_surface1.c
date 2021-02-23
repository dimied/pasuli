
#include "catalans_surface1.h"
#include "surfaces_c_includes.h"

#if (USE_CATALANS_SURFACE1 != 0)
void CatalansSurface1(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO) {

                      }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface1 =
    "name: Catalan's Surface 1;\
ut:c; vt:o;\
us:pi:-2; ue:pi:2;\
vs:-1.4; ve:1.4;\
x: u-cosh(v)*sin(u);\
y: 1-cosh(v)*cos(u);\
z: -4*sin(u/2)*sinh(v/2);";
#endif
