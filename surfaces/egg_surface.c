#include "bours_minimal_surface.h"
#include "surfaces_c_includes.h"

#if (USE_EGG_SURFACE != 0)
void EggSurface(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO) {
PASULI_SET_TYPE_ID(EGG_SURFACE)

pasuli_consttype a = constants[0];
pasuli_consttype c = constants[1];

pasuli_calctype cos_v = cos(v);
pasuli_calctype sin_v = sin(v);

// Need to be divided by 2 
pasuli_calctype r = (u+a);
r = sqrt(3*u*(2*a-u)*(1-c*c/(r*r)));

P_X(r*cos_v);
P_Y(r*sin_v);
P_Z(u);
               }
#endif

#if (COMPILE_DESC_SURFACES != 0)
// Seems to be easy, but is hard to differentiate for u
char *descEggSurface =
    "name: Egg surface;\
ut:c; vt:c;\
us:0; ue:a:2;\
vs:0; ve:pi:2;\
c1:a: 2; c2:c: 1.5;\
a1:r: sqrt(3*u*(2*a-u)*(1-c^2/((u+a)^2))/4);\
x: r*cos(v);\
y: r*sin(v);\
z: u;";
#endif