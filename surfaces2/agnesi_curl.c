
#include "agnesi_curl.h"
#include "surfaces_c_includes.h"

#if (USE_AGNESI_CURL != 0)
void AgnesiCurl(pasuli_vartype u,
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(AGNESI_CURL)
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descAgnesiCurl =
    "name: Agnesi Curl;\
ut:c; vt:o;\
us:0; ue:T;\
vs:0; ve:pi:2;\
c1:T: 1; c2:L: 1;\
x: u*sin(v);\
y: u*cos(v);\
z: L*sqrt((T-u)/(T+u));";
#endif
