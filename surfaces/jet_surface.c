
#include "jet_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_JET_SURFACE != 0)
void JetSurface(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(JET_SURFACE)

    double sin_u = sin(u) * (1 - cosh(u)) * 0.5;
    double cv = cos(v);
    double sv = sin(v);

    P_X(sin_u * cv);
    P_Y(sin_u * sv);
    P_Z(cosh(u));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
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
PaSuLiDefDesc pslddJetSurface = {
PSLDD_ID( JET_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descJetSurface =
"name: Jet Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 1; \
vs: 0; ve:pi: 2; \
x: (1 - cosh(u))*sin(u)*cos(v)/2; \
y: (1 - cosh(u))*sin(u)*sin(v)/2; \
z: cosh(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif