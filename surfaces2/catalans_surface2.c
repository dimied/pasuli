
#include "catalans_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_CATALANS_SURFACE2 != 0)
void CatalansSurface2(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO) {

                      }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCatalanSurface2 =
    "name: Catalan Surface 2;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-5; ve:5;\
c1:a: 1;\
x: a*(2*v-(1+2*u^2)*sin(2*v));\
y: a*(1+2*u^2)*cos(2*v);\
z: 4*a*u*sin(v)*cos(v);";
#endif
