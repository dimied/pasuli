
#include "spinning_top1.h"
#include "surfaces_c_includes.h"

#if (USE_SPINNING_TOP1 != 0)
void SpinningTop1(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

// Schon vorhanden ???
#if (COMPILE_DESC_SURFACES != 0)
char *descSpinningTop1 =
    "name: Spinning Top 1;\
ut:c; vt:o;\
us:-1; ue:pi:1;\
vs:0; ve:pi:2;\
x: (|u|-1)^2*cos(v);\
y: (|u|-1)^2*sin(v);\
z: u;";
#endif
