
#include "pseudodevelopable_helicoid.h"
#include "surfaces_c_includes.h"

#if (USE_PSEUDODEVELOPABLE_HELICOID != 0)
void PseudodevelopableHelicoid(pasuli_vartype u,
                               pasuli_vartype v,
                               pasuli_consttype *constants,
                               PaSuLiObject *pO) {

                               }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPseudodevelopableHelicoid =
    "name: Pseudodevelopable Helicoid;\
ut:c; vt:o;\
us:-1.5; ue:0;\
vs:0; ve:pi:4;\
c1:a: 1; c2:b: 1;\
x: a*cos(v)-u*sin(v);\
y: a*sin(v)+u*cos(v);\
z: b*v;";
#endif
