
#include "pluecker_conoid2.h"
#include "surfaces_c_includes.h"

#if (USE_PLUECKER_CONOID2 != 0)
void PlueckerConoid2(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPlueckersConoid2 =
    "name: Pluecker's Conoid 2;\
ut:u; vt:c;\
us:0; ue:2;\
vs:0; ve:pi:2;\
x: u*cos(v);\
y: u*sin(v);\
z: sin(2*v);";
#endif
