
#include "pluecker_conoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_PLUECKER_CONOID != 0)
void PlueckerConoid(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PLUECKER_CONOID)

    pasuli_calctype one_minus_v2 = 1 - v * v;
    pasuli_calctype rootOf = sqrt(one_minus_v2);
    P_X(u * rootOf);
    P_Y(u * v);
    P_Z(one_minus_v2);

    UD_X(rootOf);
    UD_Y(v);
    UD_Z_CONST(0);

    // Multiplied by sqrt(one_minus_v2)
    VD_X(-u * v);
    VD_Y(u * rootOf);
    VD_Z(-2 * v * rootOf);

    // Multiplied by sqrt(one_minus_v2) to avoid division (by 0)
    N_X(-2 * v * v * rootOf);
    N_Y(2 * v * one_minus_v2);
    N_Z(u);

    UUD_ALL(0);

    // Multiplied by sqrt(one_minus_v2)
    UVD_X(-v);
    UVD_Y(rootOf);
    UVD_Z(0);

    // Myultiplied by (sqrt(1-v*v)*(1-v*v));
    VVD_X(-u);
    VVD_Y(0);
    VVD_Z(-2 * rootOf * one_minus_v2);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPlueckerConoid = {
    PSLDD_ID(PLUECKER_CONOID)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_FULL_IMPL,
    -2, 2, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descPlueckerConoid =
    "name: Pluecker Conoid; \
ut:c; vt:c; \
us: -2; ue: 2; \
vs: -1; ve: 1; \
x: u*sqrt(1 - v*v); \
y: u*v; \
z: 1 - v*v; \
xu: sqrt(1-v*v); \
yu: v; \
zu: 0; \
xv: -u*v/(sqrt(1-v*v)); \
yv: u; \
zv: -2*v; \
xn: -2*v*v; \
yn: 2*v*(sqrt(1-v*v)); \
zn: u/(sqrt(1-v*v)); \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: -v/(sqrt(1-v*v)); \
yuv: 1; \
zuv: 0; \
xvv: -u/(sqrt(1-v*v)*(1-v*v)); \
yvv: 0; \
zvv: -2;";
#endif