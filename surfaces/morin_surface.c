
#include "morin_surface.h"
#include "surfaces_c_includes.h"

#if (USE_MORIN_SURFACE != 0)
void MorinSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MORIN_SURFACE)

    pasuli_consttype k = constants[0];
    pasuli_consttype n = constants[1];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sqrt_of_2 = sqrt(2);
    pasuli_calctype divisor = sqrt_of_2 - k * sin(2 * u) * sin(n * v);

    P_X((2 * cos_u * cos((n - 1) * v) / (n - 1) + sqrt_of_2 * sin_u * cos_v) * cos_u / divisor);
    P_Y((2 * cos_u * sin((n - 1) * v) / (n - 1) - sqrt_of_2 * sin_u * sin_v) * cos_u / divisor);
    P_Z(cos_u * cos_u / divisor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descMorinSurface =
    "name: Morin Surface;\
ut:c; vt:o;\
us:0; ue:pi:1;\
vs:0; ve:pi:1;\
c1:k: 1; c2:n: 1;\
a1:K: cos(u)/(sqrt(2)-k*sin(2*u)*sin(n*v));\
x: K*((2/(n-1))*cos(u)*cos((n-1)*v)+sqrt(2)*sin(u)*cos(v));\
y: K*((2/(n-1))*cos(u)*sin((n-1)*v)-sqrt(2)*sin(u)*sin(v));\
z: K*cos(u);";
#endif
