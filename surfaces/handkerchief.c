
#include "handkerchief.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HANDKERCHIEF != 0)
void Handkerchief(pasuli_vartype u, pasuli_vartype v, pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HANDKERCHIEF)

    pasuli_calctype u_pow2 = u * u;
    pasuli_calctype v_pow2 = v * v;

    P_X(u);
    P_Y(v);
    P_Z((u_pow2 * u / 3) + u * v_pow2 * 2 * (u_pow2 - v_pow2));

    UD_X_CONST(1);
    UD_Y_CONST(0);
    UD_Z(u * (4 + u) + v_pow2);

    VD_X_CONST(0);
    VD_Y_CONST(1);
    VD_Z(v * (2 * u - 4));

    N_X(-PASULI_COND_COPY_UD_Z(u * (4 + u) + v_pow2));
    N_Y(-PASULI_COND_COPY_VD_Z(v * (2 * u - 4)));
    N_Z(1);

    UUD_X_CONST(0);
    UUD_Y_CONST(0);
    UUD_Z(4 + 2 * u);

    UVD_X_CONST(0);
    UVD_Y_CONST(0);
    UVD_Z(2 * v);

    VVD_X_CONST(0);
    VVD_Y_CONST(0);
    VVD_Z(2 * u - 4);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHandkerchief = {
    PSLDD_ID(HANDKERCHIEF)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_FULL_IMPL,
    -1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descHandkerchief =
    "name: Handkerchief; \
ut: c; vt: c; \
us: -1; ue: 1; \
vs: -1; ve: 1; \
x: u; \
y: v; \
z: u*u*u/3 + u*v*v + 2*(u*u - v*v); \
xu: 1; \
yu: 0; \
zu: u*(4+u)+v*v; \
xv: 0; \
yv: 1; \
zv: v*(2*u - 4); \
xn: -u*(4+u) - v*v; \
yn: 2*v*(2-u); \
zn: 1; \
xuu: 0; \
yuu: 0; \
zuu: 4+2*u; \
xuv: 0; \
yuv: 0; \
zuv: 2*v; \
xvv: 0; \
yvv: 0; \
zvv: 2*u-4;";
#endif