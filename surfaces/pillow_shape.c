
#include "pillow_shape.h"
#include "surfaces_c_includes.h"

#if (USE_PILLOW_SHAPE != 0)
void PillowShape(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PILLOW_SHAPE)

    double a = constants[0];

    P_X(cos(u));
    P_Y(cos(v));
    P_Z(a * sin(u) * sin(v));

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

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPillowShape = {
PSLDD_ID( PILLOW_SHAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_FULL_IMPL| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descPillowShape =
"name:pillow Shape; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 1; \
vs:pi: -1; \
ve:pi: 1; \
c1:a: 1.5; \
x: cos(u); \
y: cos(v); \
z: a*sin(u)*sin(v); "
"xu: -sin(u); \
yu: 0; \
zu: a*cos(u)*sin(v); "
"xv: 0; \
yv: -sin(v); \
zv: a*cos(v)*sin(u); "
"xn: a*cos(u)*sin(v)*sin(v); \
yn: a*cos(v)*sin(u)*sin(u); \
zn: sin(u)*sin(v); "
"xuu: -cos(u); \
yuu: 0; \
zuu: -a*sin(u)*sin(v); "
"xuv: 0; \
yuv: 0; \
zuv: a*cos(u)*cos(v); "
"xvv: 0; \
yvv: -cos(v); \
zvv: -a*sin(u)*sin(v); "
"";
#endif