
#include "enneper_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_ENNEPER_SURFACE2 != 0)
void EnneperSurface2(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO) {

                     }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface2 =
    "name: Enneper Surface 2;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: exp(u)*(3*cos(v)-exp(2*u)*cos(3*v))/6;\
y: exp(u)*(-3*sin(v)-exp(2*u)*sin(3*v))/6;\
z: exp(2*u)*cos(2*v)/2;";
#endif
