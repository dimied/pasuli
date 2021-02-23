
#include "morin_surface.h"
#include "surfaces_c_includes.h"

#if (USE_MORIN_SURFACE != 0)
void MorinSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descMorinSurface =
    "name: Morin Surface;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:1;\
c1:k: 1; c2:n: 1;\
a1:K: cos(u)/(sqrt(2)-k*sin(2*u)*sin(n*v));\
x: K*((2/(n-1))*cos(u)*cos((n-1)*v)+sqrt(2)*sin(u)*cos(v));\
y: K*((2/(n-1))*cos(u)*sin((n-1)*v)-sqrt(2)*sin(u)*sin(v));\
z: K*cos(u);";
#endif
