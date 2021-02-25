
#include "virich_cyclic_surface.h"
#include "surfaces_c_includes.h"

#if (USE_VIRICH_CYCLIC_SURFACE != 0)
void VirichCyclicSurface(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(VIRICH_CYCLIC_SURFACE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];
    pasuli_consttype d = constants[3];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype f = (a == b) ? a / sqrt(2) : a * b / sqrt(a * a * sin_v * sin_v + b * b * cos_v * cos_v);
    pasuli_calctype factor = (f * (1 + cos_u) + (d * d - c * c) * (1 - cos_u) / f);
    P_X(factor * cos_v * 0.5);
    P_Y(factor * sin_v * 0.5);
    P_Z((f - (d * d - c * c) / f) * sin_u * 0.5);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descVirichCyclicSurface =
    "name: Virich Cyclic Surface;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:a: 1; c2:b: 1; c3:c: 1; c4:d: 1;\
a1:f: a*b/sqrt(a^2*sin(v)^2+b^2*cos(v)^2);\
x: (f*(1+cos(u))+(d^2-c^2)*(1-cos(u))/f)*cos(v)/2;\
y: (f*(1+cos(u))+(d^2-c^2)*(1-cos(u))/f)*sin(v)/2;\
z: (f-(d^2-c^2)/f)*sin(u)/2;";
#endif