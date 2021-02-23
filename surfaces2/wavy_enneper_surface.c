
#include "wavy_enneper_surface.h"
#include "surfaces_c_includes.h"

#if (USE_WAVY_ENNEPER_SURFACE != 0)
void WavyEnneperSurface(pasuli_vartype u,
                        pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO) {

                        }
#endif


#if (COMPILE_DESC_SURFACES != 0)
char *descWavyEnneperSurface =
    "name: Wavy Enneper Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
c1:s: 2;\
x: u*cos(v)-u^(2*s-1)*cos((2*s-1)*v)/(2*s-1);\
y: -u*sin(v)-u^(2*s-1)*sin((2*s-1)*v)/(2*s-1);\
z: 2/s*u^s*cos(s*v);";
#endif