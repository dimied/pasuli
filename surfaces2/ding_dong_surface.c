
#include "ding_dong_surface.h"
#include "surfaces_c_includes.h"

#if (USE_DING_DONG_SURFACE != 0)
void DingDongSurface(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO) {

                     }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descDingDongSurface =
    "name: Ding Dong Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:-1; ve:1;\
x: v*sqrt(1-v)*cos(u);\
y: v*sqrt(1-v)*sin(u);\
z: v;";
#endif
