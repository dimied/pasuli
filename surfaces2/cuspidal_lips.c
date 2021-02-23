
#include "cuspidal_lips.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_LIPS != 0)
void CuspidalLips(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalLips =
    "name: Cuspidal Lips;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.5; ve:0.5;\
x: u;\
y: 2*v^3+u^2*v;\
z: 3*v^4+u^2*v^2;";
#endif
