
#include "pluecker_conoid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_PLUECKER_CONOID != 0)
void PlueckerConoid(double u, double v,
                    double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PLUECKER_CONOID)

    double xz = 1 - v * v;
    P_X(u * sqrt(xz));
    P_Y(u * v);
    P_Z(xz);

    UD_X(0);
    UD_Y(0);
    UD_Z(0);

    VD_X(0);
    VD_Y(0);
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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPlueckerConoid = {
    PSLDD_ID(PLUECKER_CONOID)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_FULL_IMPL,
    -2, 2, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descPlueckerConoid =
    "start; \
name: Pluecker Conoid; \
ut:c; \
vt:c; \
us: -2; \
ue: 2; \
vs: -1; \
ve: 1; \
x: u*sqrt(1 - v*v); \
y: u*v; \
z: 1 - v*v; "
    "xu: sqrt(1-v*v); \
yu: v; \
zu: 0; "
    "xv: -u*v/(sqrt(1-v*v)); \
yv: u; \
zv: -2*v; "
    "xn: -2*v*v; \
yn: 2*v*(sqrt(1-v*v)); \
zn: u/(sqrt(1-v*v)); "
    "xuu: 0; \
yuu: 0; \
zuu: 0; "
    "xuv: -v/(sqrt(1-v*v)); \
yuv: 1; \
zuv: 0; "
    "xvv: -u/(sqrt(1-v*v)*(1-v*v)); \
yvv: 0; \
zvv: -2; "
    "end;";
#endif