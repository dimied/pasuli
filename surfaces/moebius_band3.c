
#include "moebius_band3.h"
#include "surfaces_c_includes.h"

#if (USE_MOEBIUS_BAND3 != 0)
void MoebiusBand3(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MOEBIUS_BAND3)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_u_pow2 = cos_u * cos_u;
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype v2 = v * v;
    pasuli_calctype divisor = 3 + v2 * v;

    P_X((2 * v2 * (v2 - 1) - 6 * v * (1 + v2 * v2) * cos_u + (v2 * v2 * v2 - 1) * (4 * cos_u_pow2)) * sin_u / divisor);
    P_Y((4 * (1 - v2 * v2 * v2) * cos_u_pow2 * cos_u - 3 * v * (1 + v2 * v2) + 3 * (v2 - 1) * (1 + v2 * v2) * cos_u + 6 * v * (1 + v2 * v2) * cos_u_pow2) / divisor);
    P_Z(2 * sin_u * (v2 - 1) / v);
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
