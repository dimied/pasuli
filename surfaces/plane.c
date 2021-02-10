
#include <math.h>

#include "plane.h"
#include "../pasuli_const.h"
#include "../pasuli_macros.h"

PaSuLiDefDesc pslddPlane = {
    PSLDD_ID(0)
        PASULI_FULL_IMPL,
    0, 1, 0, 1, 0};

char *descPlane =
    "name:plane; \
utype:open; vtype:open; \
ustart: 0; uend: 1; \
vstart: 0; vend: 1; \
x: u; y: v; z: 0; \
xu: 1; yu: 0); zu: 0); \
xv: 0); yv: 1; zv: 0); \
xn: 0); yn: 0); zn: 1; \
xuu: 0); yuu: 0); zuu: 0); \
xuv: 0); yuv: 0); zuv: 0); \
xvv: 0); yvv: 0); zvv: 0);";

void initConstPlane(PaSuLiObject *pO, pasuli_consttype *constants)
{
    initConstAll(pO, 0);
    UD_X(1);
    VD_Y(1);
    N_Z(1);
}

void Plane(double u, double v, double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PLANE)

    initConstPlane(pO, constants);
    P_X(u);
    P_Y(v);
    P_Z_CONST(0);

    UD_X_CONST(1);
    UD_Y_CONST(0);
    UD_Z_CONST(0);

    VD_X_CONST(0);
    VD_Y_CONST(1);
    VD_Z_CONST(0);

    N_X_CONST(0);
    N_Y_CONST(0);
    N_Z_CONST(1);

    UUD_X_CONST(0);
    UUD_Y_CONST(0);
    UUD_Z_CONST(0);

    UVD_X_CONST(0);
    UVD_Y_CONST(0);
    UVD_Z_CONST(0);

    VVD_X_CONST(0);
    VVD_Y_CONST(0);
    VVD_Z_CONST(0);
}