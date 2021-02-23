
#include "ruled_rotor_cylindroid.h"
#include "surfaces_c_includes.h"

#if (USE_RULED_ROTOR_CYLINDROID != 0)
void RuledRotorCylindroid(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO) {

                          }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRuledRotorCylindroid =
    "name: Ruled Rotor Cylindroid;\
ut:c; vt:o;\
us: 0; ue:pi: 2;\
vs: 0; ve: 2;\
c1:1:a: 1; c2:b: 1; c3:n: 1;\
x: (a+b*sin(n*u))*cos(u)-v*sin(u);\
y: (a+b*sin(n*u))*sin(u)+v*cos(u);\
z: b*cos(n*u);";
#endif
