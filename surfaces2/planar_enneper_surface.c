
#include "planar_enneper_surface.h"
#include "surfaces_c_includes.h"

#if (USE_PLANAR_ENNEPER_SURFACE != 0)
void PlanarEnneperSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO) {

                          }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPlanarEnneperSurface =
    "name: Planar Enneper Surface;\
ut:c; vt:o;\
us:-0.8; ue:0.5;\
vs:-1.5; ve:1.5;\
c1:n: 2; c1:A: 0.4;\
x: exp(2*a*u)*(exp(-(n+1)*u)*cos((2*a-(n+1))*v)/(2*a*A-A*(n+1)) - A*exp((n+1)*u)*cos((2*a+(n+1))*v)/(2*a+(n+1)))/(2*(n+1));\
y: exp(2*a*u)*(exp(-(n+1)*u)*sin((2*a-(n+1))*v)/(2*a*A-A*(n+1)) + A*exp((n+1)*u)*sin((2*a+(n+1))*v)/(2*a+(n+1)))/(2*(n+1));\
z: -exp(2*a*u)*cos(2*a*v)/(2*a*(n+1));";
#endif
