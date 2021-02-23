
#include "cuspidal_edge.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_EDGE != 0)
void CuspidalEdge(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalEdge =
    "name: Cuspidal Edge;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u;\
y: v^2;\
z: v^3;";
#endif