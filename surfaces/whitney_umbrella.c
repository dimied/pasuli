
#include "whitney_umbrella.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_WHITNEY_UMBRELLA != 0)
void WhitneyUmbrella(pasuli_vartype u, pasuli_vartype v,
                     pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(WHITNEY_UMBRELLA)

    P_X(u * v);
    P_Y(u);
    P_Z(v * v);

    UD_X(v);
    UD_Y_CONST(1);
    UD_Z_CONST(0);

    VD_X(u);
    VD_Y_CONST(0);
    VD_Z(2 * v);

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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWhitneyUmbrella = {
    PSLDD_ID(WHITNEY_UMBRELLA)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_FULL_IMPL,
    -1.5, 1.5, -1.5, 1.5, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descWhitneyUmbrella =
    "name: Whitney Umbrella; \
ut:c; \
vt:c; \
us: -1.5; \
ue: 1.5; \
vs: -1.5; \
ve: 1.5; \
x: u*v; \
y: u; \
z: v*v; "
    "xu: v; yu: 1; zu: 0; "
    "xv: u; yv: 0; zv: 2*v; "
    "xn: 2*v; \
yn: -2*v*v; \
zn: -u; "
    "xuu: 0; yuu: 0; zuu: 0; "
    "xuv: 1; yuv: 0; zuv: 0; "
    "xvv: 0; yvv: 0; zvv: 2; "
    "";
#endif