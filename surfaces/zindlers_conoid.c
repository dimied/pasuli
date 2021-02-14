
#include "zindlers_conoid.h"
#include "surfaces_c_includes.h"

#if (USE_ZINDLERS_CONOID != 0)
void ZindlersConoid(double u, double v,
                    double *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ZINDLERS_CONOID)

    double a = constants[0];

    P_X(u * cos(v));
    P_Y(u * sin(v));
    P_Z(a * tan(2.0 * v));

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
PaSuLiDefDesc pslddZindlersConoid = {
PSLDD_ID( ZINDLERS_CONOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -0.75f , 0.75f , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descZindlersConoid =
"name: Zindlers Conoid; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs: -0.75; ve: 0.75; \
c1:a: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: a*tan(2*v); \
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
