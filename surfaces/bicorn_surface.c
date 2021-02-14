
#include "bicorn_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BICORN_SURFACE != 0)
void BicornSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BICORN_SURFACE)

    double cu = cos(u);
    double su = sin(u);

    double sv = sin(v);
    double cv = cos(v);

    double sin_v = sv * sv + 3.0;

    P_X(sv * cu);
    P_Y(v * v * (2.0 + v) / sin_v);
    P_Z(sv * su);

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
PaSuLiDefDesc pslddBicornSurface = {
PSLDD_ID( BICORN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBicornSurface =
"name: Bicorn Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 1; \
x: sin(v)*cos(u); \
y: sin(v)*sin(u); \
z: cos(v)*cos(v)*(2 + cos(v))/(3 + sin(v)*sin(v)); \
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