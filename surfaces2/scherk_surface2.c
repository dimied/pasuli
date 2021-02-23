
#include "scherk_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_SCHERK_SURFACE2 != 0)
void ScherkSurface2(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO) {

                    }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descScherkSurface2 =
    "name: Scherk Surface 2;\
ut:c; vt:o;\
us:0; ue:0.75;\
vs:0; ve:pi:2;\
x: log*((1+u^2+2*u*cos(v))/(1+u^2-2*u*cos(v)));\
y: log*((1+u^2-2*u*cos(v))/(1+u^2+2*u*cos(v)));\
z: 2*arctan(2*u^2*sin(2*v)/(u^2-1));";
#endif