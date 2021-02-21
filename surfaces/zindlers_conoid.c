
#include "zindlers_conoid.h"
#include "surfaces_c_includes.h"

#if (USE_ZINDLERS_CONOID != 0)
void ZindlersConoid(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ZINDLERS_CONOID)

    pasuli_consttype a = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(a * tan(2.0 * v));

    UD_X(cos_v);
    UD_Y(sin_v);
    UD_Z(0);

    // Multiplied by cos(2*v)^2
    pasuli_calctype factor = cos(2 * v);
    factor *= factor;

    VD_X(-u * sin_v * factor);
    VD_Y(u * cos_v * factor);
    VD_Z(2 * a);

    // Multiplied by cos(2*v)^2
    N_X(2 * a * sin_v);
    N_Y(-2 * a * cos_v);
    N_Z(u * factor);
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
#if (COMPILE_DESC_SURFACES != 0)
char *descZindlersConoid =
    "name: Zindlers Conoid; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs: -0.75; ve: 0.75; \
c1:a: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: a*tan(2*v); \
xu: cos(v); \
yu: sin(v); \
zu: 0; \
xv: -u*sin(v); \
yv: u*cos(v); \
zv: 2*a/cos(2*v)^2; \
xn: 2*a*sin(v)/cos(2*v)^2; \
yn: -2*a*cos(v)/cos(2*v)^2; \
zn: u;";
#endif
