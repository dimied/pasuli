
#include "scherk_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_SCHERK_SURFACE != 0)
void ScherkSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SCHERK_SURFACE)

    double c = constants[0];

    P_X(u);
    P_Y(v);
    P_Z(log(cos(c * u) / cos(c * v)) / c);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);
#endif

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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddScherkSurface = {
PSLDD_ID( SCHERK_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descScherkSurface =
"name: Scherk Surface; \
ut:c; vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:c:!=0: 1.5; \
x: u; \
y: v; \
z: log(cos(c*u)/cos(c*v))/c; "
"xu: 1; yu: 0; zu: -sin(c*u)/cos(c*u); "
"xv: 0; yv: 1; zv: sin(c*v)/cos(c*v); "
"xn: sin(c*u)/cos(c*u); \
yn: -sin(c*v)/cos(c*v); \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: -c/(cos(c*u)*cos(c*u)); "
"xuv: 0; yuv: 0; zuv: 0; "
"xvv: 0; yvv: 0; zvv: c/(cos(c*v)*cos(c*v)); "
"end;";
#endif