
#include "scherk_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_SCHERK_SURFACE2 != 0)
void ScherkSurface2(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SCHERK_SURFACE2)

    pasuli_calctype u2 = u * u;
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype a = 1 + u2 + 2 * u * cos_v;
    pasuli_calctype b = 1 + u2 - 2 * u * cos_v;

    P_X(log(a / b));
    P_Y(log(b / a));
    P_Z(2 * atan(2 * u2 * sin(2 * v) / (u2 - 1)));
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descScherkSurface2 =
    "name: Scherk Surface 2;\
ut:c; vt:o;\
us:0; ue:0.75;\
vs:0; ve:pi:2;\
x: log*((1+u^2+2*u*cos(v))/(1+u^2-2*u*cos(v)));\
y: log*((1+u^2-2*u*cos(v))/(1+u^2+2*u*cos(v)));\
z: 2*arctan(2*u^2*sin(2*v)/(u^2-1));";
#endif