
#include "klein_bottle_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_KLEIN_BOTTLE_SURFACE != 0)
void KleinBottleSurface(pasuli_vartype u, pasuli_vartype v,
                        pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KLEIN_BOTTLE_SURFACE)

    pasuli_calctype cos_u_half = cos(u * 0.5);
    pasuli_calctype sin_u_half = sin(u * 0.5);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype pos_factor = cos_u_half * (sqrt(2) + cos_v) + sin_u_half * sin_v * cos_v;
    P_X(cos(u) * pos_factor);
    P_Y(sin(u) * pos_factor);
    P_Z(-sin_u_half * (sqrt(2) + cos_v) + cos_u_half * sin_v * cos_v);
}
#endif
/*
 * This formula is not implemented
r = 4 (1 - cos(u)/2)

0 <= u <pi
x = a cos(u) (1 + sin(u)) + r cos(u) cos(v)
y = b sin(u) + r sin(u) cos(v)
z = r sin(v)

pi < u <= 2pi
x = a cos(u) (1 + sin(u)) + r cos(v +pi)
y = b sin(u)
z = r sin(v)
*/
/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinBottleSurface = {
PSLDD_ID( KLEIN_BOTTLE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
//TODO TODO TODO
char *descKleinBottleSurface =
    "name: Klein Bottle Surface;\
ut:c; vt:c;\
us:0; ue:pi:2;  \
vs:0; ve:pi:2;  \
a1:r: (cos(u/2)*(sqrt(2)+cos(v)) + sin(u/2)*sin(v)*cos(v));\
x: cos(u)*r;\
y: sin(u)*r;\
z: -sin(u/2)*(sqrt(2)+cos(v)) + cos(u/2)*sin(v)*cos(v);";
#endif