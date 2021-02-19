
#include "plane.h"
#include "../pasuli_const.h"
#include "../pasuli_macros.h"
#include <math.h>

PaSuLiDefDesc pslddPlane = {
    PSLDD_ID(0)
        PASULI_FULL_IMPL,
    0, 1, 0, 1, 0};

char *descPlane =
    "name:plane; \
ut:o; vt:o; \
us: 0; ue: 1; vs: 0; ve: 1; \
x: u; y: v; z: 0; \
c1:z:0; \
xu:1); yu:0);zu:0); \
xv:0); yv:1); zv:0); \
xn:0); yn:0); zn:1); \
xuu:0); yuu:0); zuu: 0); \
xuv:0); yuv:0); zuv: 0); \
xvv:0); yvv:0); zvv: 0);";

#if (USE_PLANE != 0)
void Plane(pasuli_vartype u,
           pasuli_vartype v,
           pasuli_consttype *constants,
           PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PLANE)
    pasuli_consttype z = constants[0];

    P_X(u);
    P_Y(v);
    P_Z(z);

    UD_X_CONST(1);
    UD_Y_CONST(0);
    UD_Z_CONST(0);

    VD_X_CONST(0);
    VD_Y_CONST(1);
    VD_Z_CONST(0);

    N_X_CONST(0);
    N_Y_CONST(0);
    N_Z_CONST(1);

    UUD_CONST_ALL(0);
    UVD_CONST_ALL(0);
    VVD_CONST_ALL(0);
}
#endif