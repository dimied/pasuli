
#include "moebius_band3.h"
#include "surfaces_c_includes.h"

#if (USE_MOEBIUS_BAND3 != 0)
void MoebiusBand3(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO) {

                  }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descMoebiusBand3 =
    "name: Moebius Band 3;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0.7; ve:1;\
x: (3*v^2*(v^2-1)-6*v*(1+v^4)*cos(u)+(v^6-1)*(4*cos(u)^2-1))*sin(u)/(3*v^3);\
y: (4*(1-v^6)*cos(u)^3-3*v*(1+v^4)+3*(v^2-1)*(1+v^4)*cos(u)+6*v*(1+v^4)*cos(u)^2)/(3*v^3);\
z: 2*sin(u)*(v^2-1)/v;";
#endif
