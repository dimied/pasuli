
#include "cuspidal_beaks.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_BEAKS != 0)
void CuspidalBeaks(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO) {

                   }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalBeaks =
    "name: Cuspidal Beaks;\
ut:c; vt:o;\
us:-1.75; ue:1.75;\
vs:-0.75; ve:0.75;\
x: u;\
y: 2*v^3-u^2*v;\
z: 3*v^4-u^2*v^2;";
#endif
