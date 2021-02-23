
#include "monkey_saddle2.h"
#include "surfaces_c_includes.h"

#if (USE_MONKEY_SADDLE2 != 0)
void MonkeySaddle2(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO) {

                }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descMonkeySaddle2 =
    "name: Monkey Saddle 2;\
ut:u; vt:c;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:a: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: a*u^3*sin(3*v);";
#endif
