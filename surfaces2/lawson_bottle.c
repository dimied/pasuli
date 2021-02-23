
#include "lawson_bottle.h"
#include "surfaces_c_includes.h"

#if (USE_LAWSON_BOTTLE != 0)
void LawsonBottle(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descLawsonBottle =
    "name: Lawson Bottle;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
a1:w: (sin(u)*sin(v)+sin(u/2)*cos(v))/2;\
x: (sin(u)*sin(v)-sin(u/2)*cos(v))*sqrt(1/2)/(1+w);\
y: cos(u)*sin(v)/(1+w);\
z: cos(u/2)*cos(v)/(1+w);";
#endif
