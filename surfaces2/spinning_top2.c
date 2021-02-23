
#include "spinning_top2.h"
#include "surfaces_c_includes.h"

#if (USE_SPINNING_TOP2 != 0)
void SpinningTop2(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descSpinningTop2 =
    "name: Spinning Top 2;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:2;\
x: cos(2*u)*sin(u)*cos(v);\
y: cos(2*u)*sin(u)*sin(v);\
z: cos(2*u)*cos(u);";
#endif
