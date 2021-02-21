
#include "spiral_wave.h"
#include "surfaces_c_includes.h"

#if (USE_SPIRAL_WAVE != 0)

void SpiralWave(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SPIRAL_WAVE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);

    P_X(v * cos_u);
    P_Y(v * sin_u);
    P_Z(a * cos(u * b + c * v));

    pasuli_calctype sin_ub_cv = sin(u * b + c * v);
    UD_X(-v * sin_u);
    UD_Y(v * cos_u);
    UD_Z(-a * b * sin_ub_cv);

    VD_X(cos_u);
    VD_Y(sin_u);
    VD_Z(-a * c * sin_ub_cv);

    N_X(a * (b * sin_u - c * v * cos_u) * sin_ub_cv);
    N_Y(-a * (b * cos_u + c * v * sin_u) * sin_ub_cv);
    N_Z(-v);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpiralWave = {
PSLDD_ID( SPIRAL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(3),
0, 2 , 0 , 20 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descSpiralWave =
    "name: Spiral Wave;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve: 20;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: v*cos(u);\
y: v*sin(u);\
z: a*cos(b*u + c*v);\
xu: -v*sin(u);\
yu: v*cos(u);\
zu: -a*b*sin(b*u + c*v);\
xv: cos(u);\
yv: sin(u);\
zv: -a*c*sin(b*u + c*v);\
xn: a*(b*sin(u) - c*v*cos(u))*sin(b*u+c*v);\
yn: -a*(b*cos(u) + c*v*sin(u))*sin(b*u+c*v);\
zn: -v;";
#endif