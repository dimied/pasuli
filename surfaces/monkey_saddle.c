
#include "monkey_saddle.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_MONKEY_SADDLE != 0)
void MonkeySaddle(double u, double v,
                  double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MONKEY_SADDLE)

    P_X(u);
    P_Y(v);
    P_Z(u * u * u - 3 * u * v * v);

    UD_X(1);
    UD_Y(0);
    UD_Z(3 * u * u - 3 * v * v);

    VD_X(0);
    VD_Y(1);
    VD_Z(-6 * u * v);

    N_X(2 * v * v - 2 * u * u);
    N_Y(-6 * u * v);
    N_Z(1);

    UUD_X(0);
    UUD_Y(0);
    UUD_Z(6 * u);

    UVD_X(0);
    UVD_Y(0);
    UVD_Z(-6 * v);

    VVD_X(0);
    VVD_Y(0);
    VVD_Z(-6 * u);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMonkeySaddle = {
    PSLDD_ID(MONKEY_SADDLE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_FULL_IMPL,
    -1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descMonkeySaddle =
    "name: Monkey Saddle; \
ut:c; \
vt:c; \
us: -1; \
ue: 1; \
vs: -1; \
ve: 1; \
x: u; \
y: v; \
z: u*u*u - 3*u*v*v; "
    "xu: 1; \
yu: 0; \
zu: 3*(u*u - v*v); "
    "xv: 0; \
yv: 1; \
zv: -6*u*v; "
    "xn: 3*(v*v - u*u); \
yn: 6*u*v; \
zn: 1; "
    "xuu: 0; \
yuu: 0; \
zuu: 6*u; "
    "xuv: 0; \
yuv: 0; \
zuv: -6*v; "
    "xvv: 0; \
yvv: 0; \
zvv: -6*u; "
    "end;";
#endif