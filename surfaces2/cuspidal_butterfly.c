
#include "cuspidal_butterfly.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_BUTTERFLY != 0)
void CuspidalButterfly(pasuli_vartype u,
                       pasuli_vartype v,
                       pasuli_consttype *constants,
                       PaSuLiObject *pO) {

                       }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalButterfly =
    "name: Cuspidal Butterfly;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.5; ve:0.5;\
x: u;\
y: 5*v^4+2*u*v;\
z: 4*v^5+u*v^2;";
#endif
