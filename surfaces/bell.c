
#include "bell.h"
#include "surfaces_c_includes.h"

#if (USE_BELL != 0)

void Bell(pasuli_vartype u, pasuli_vartype v,
          pasuli_consttype *constants,
          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BELL)

    double a = constants[0];
    double b = constants[1];

    double emv = b * exp(-(u * u + v * v) * a * a);

    P_X(u);
    P_Y(v);
    P_Z(emv);

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
PaSuLiDefDesc pslddBell = {
PSLDD_ID( BELL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBell =
    "name: Bell; \
ut:c; vt:c; \
us: -5; ue: 5; \
vs: -5; ve: 5; \
c1:a: 1.5; c2:b: 0.5; \
a1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: b*exp(-(a*r)^(2)); \
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