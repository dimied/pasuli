
#include "bowtie.h"
#include "surfaces_c_includes.h"

#if (USE_BOWTIE != 0)
void Bowtie(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO) {

            }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descBowtie =
    "name: Bowtie;\
ut:c; vt:o;\
us:pi:-1; ue:pi:1;\
vs:pi:-1; ve:pi:1;\
x: sin(u)/(sqrt(2)+sin(v));\
y: sin(u)/(sqrt(2)+cos(v));\
z: cos(u)/(1+sqrt(2));";
#endif
