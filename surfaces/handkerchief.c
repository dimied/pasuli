
#include "handkerchief.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HANDKERCHIEF != 0)
void Handkerchief(pasuli_vartype u, pasuli_vartype v, pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HANDKERCHIEF)

    double u2 = u * u;
    double v2 = v * v;

    P_X(u);
    P_Y(v);
    P_Z((u2 * u / 3) + u * v2 * 2 * (u2 - v2));

    UD_X_CONST(1);
    UD_Y_CONST(0);
    UD_Z(0);

    VD_X_CONST(0);
    VD_Y_CONST(1);
    VD_Z(0);

    N_X(0);
    N_Y(0);
    N_Z(0);

    UUD_X(0);
    UUD_Y(0);
    UUD_Z(0);

    UVD_X(0);
    UVD_Y(0);
    UVD_Z(0);

    VVD_X(0);
    VVD_Y(0);
    VVD_Z(0);
}
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHandkerchief = {
PSLDD_ID( HANDKERCHIEF )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHandkerchief =
"name: Handkerchief; \
ut: c; \
vt: c; \
us: -1; \
ue: 1; \
vs: -1; \
ve: 1; \
x: u; \
y: v; \
z: u*u*u/3 + u*v*v + 2*(u*u - v*v); "
"xu: 1; \
yu: 0; \
zu: u*(4+u)+v*v; "
"xv: 0; \
yv: 1; \
zv: v*(2*u - 4); "
"xn: -u*(4+u) - v*v; \
yn: 2*v*(2-u); \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 4+2*u; "
"xuv: 0; \
yuv: 0; \
zuv: 2*v; "
"xvv: 0; \
yvv: 0; \
zvv: 2*u-4; "
"end;";
#endif