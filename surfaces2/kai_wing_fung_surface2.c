
#include "kai_wing_fung_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_KAI_WING_FUNG_SURFACE2 != 0)
void KaiWingFungSurface2(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO) {

                         }
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descKaiWingFungSurface2 =
    "name: Kai-WingFung Surface 2;\
ut:c; vt:o;\
us:0; ue:pi:6;\
vs:-1; ve:1;\
x: -u/2+sin(u)*(cosh(v)-sinh(v))/2;\
y: -v/2+cos(u)*(cosh(v)-sinh(v))/2;\
z: 2*(cosh(v/2)-sinh(v/2))*sin(u/2);";
#endif
