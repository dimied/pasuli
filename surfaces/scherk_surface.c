
#include "scherk_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_SCHERK_SURFACE != 0)
void ScherkSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SCHERK_SURFACE)

    pasuli_consttype c = constants[0];

    P_X(u);
    P_Y(v);
    P_Z(log(cos(c * u) / cos(c * v)) / c);

    pasuli_calctype tan_cu = tan(c * u);
    UD_X(1);
    UD_Y(0);
    UD_Z(-tan_cu);

    pasuli_calctype tan_cv = tan(c * v);
    VD_X(0);
    VD_Y(1);
    VD_Z(tan_cv);

    N_X(tan_cu);
    N_Y(-tan_cv);
    N_Z(1);

    // Ignore division by (cos(c*u)*cos(c*u))
    UUD_X_CONST(0);
    UUD_Y_CONST(0);
    UUD_Z(-c);

    UVD_ALL(0);

    // Ignore division by (cos(c*v)*cos(c*v))
    VVD_X_CONST(0);
    VVD_Y_CONST(0);
    VVD_Z(c);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddScherkSurface = {
    PSLDD_ID(SCHERK_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
    -1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descScherkSurface =
    "name: Scherk Surface;\
ut:c; vt:c;\
us:pi: -1; ue:pi: 1;\
vs:pi: -1; ve:pi: 1;\
c1:c:!=0: 1.5;\
x: u;\
y: v;\
z: log(cos(c*u)/cos(c*v))/c;\
xu: 1;\
yu: 0;\
zu: -sin(c*u)/cos(c*u);\
xv: 0;\
yv: 1;\
zv: sin(c*v)/cos(c*v);\
xn: sin(c*u)/cos(c*u);\
yn: -sin(c*v)/cos(c*v);\
zn: 1;\
xuu: 0;\
yuu: 0;\
zuu: -c/(cos(c*u)*cos(c*u));\
xuv: 0;\
yuv: 0;\
zuv: 0;\
xvv: 0;\
yvv: 0;\
zvv: c/(cos(c*v)*cos(c*v));";
#endif