
#include "neovius_surface.h"
#include "surfaces_c_includes.h"

#if (USE_NEOVIUS_SURFACE != 0)
void NeoviusSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO) {

                    }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descNeoviusSurface =
    "name: Neovius Surface;\
ut:c; vt:o;\
us:pi: -0.5; ue:pi: 0.5;\
vs:pi: -0.5; ve:pi: 0.5;\
x: u;\
y: v;\
z: arccos((-3*(cos(u)+cos(v)))/(3+4*cos(u)*cos(v)));";
#endif
