
#include "twisted_ribbon.h"
#include "surfaces_c_includes.h"

#if (USE_TWISTED_RIBBON != 0)
void TwistedRibbon(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO) {

                   }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descTwistedRibbon =
    "name: Twisted Ribbon;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:1;\
x: 3*sin(u)*cos(v);\
y: 3*sin(u)*sin(v);\
z: cos(v);";
#endif
