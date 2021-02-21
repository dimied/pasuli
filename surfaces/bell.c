
#include "bell.h"
#include "surfaces_c_includes.h"

#if (USE_BELL != 0)

void Bell(pasuli_vartype u, pasuli_vartype v,
          pasuli_consttype *constants,
          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BELL)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];

    pasuli_consttype b_exp_auv = b * exp(-(u * u + v * v) * a * a);

    P_X(u);
    P_Y(v);
    P_Z(b_exp_auv);

    pasuli_consttype aa_2 = 2 * a * a;
    UD_X_CONST(1);
    UD_Y_CONST(0);
    UD_Z(-aa_2 * b_exp_auv * u);

    VD_X_CONST(0);
    VD_Y_CONST(1);
    VD_Z(-aa_2 * b_exp_auv * v);

    N_X(-PASULI_COND_COPY_UD_Z(-aa_2 * b_exp_auv * u));
    N_Y(-PASULI_COND_COPY_VD_Z(-aa_2 * b_exp_auv * v));
    N_Z_CONST(1);

    // Ignore factor exp(-(a*r)^(2))*2*a*a
    UUD_X_CONST(0);
    UUD_Y_CONST(0);
    UUD_Z(aa_2 * b * u * u - b);

    // Ignore factor 4*exp(-(a*r)^(2))*a^2
    UVD_X_CONST(0);
    UVD_Y_CONST(0);
    UVD_Z(aa_2 * b * u * v);

    // Ignore factor exp(-(a*r)^(2))*2*a*a
    VVD_X_CONST(0);
    VVD_Y_CONST(0);
    VVD_Z(aa_2 * b * v * v - b);
    /*
xuv: 0;\
yuv: 0;\
zuv: 4*exp(-(a*r)^(2))*a^4*b*u*v;\
*/
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
    "name: Bell;\
ut:c; vt:c;\
us: -5; ue: 5;\
vs: -5; ve: 5;\
c1:a: 1.5; c2:b: 0.5;\
a1:r: sqrt(u*u + v*v);\
x: u;\
y: v;\
z: b*exp(-(a*r)^(2));\
xu: 1;\
yu: 0;\
zu: -2*a*a*b*u*exp(-(a*r)^(2));\
xv: 0;\
yv: 1;\
zv: -2*a*a*b*v*exp(-(a*r)^(2));\
xn: 2*a*a*b*u*exp(-(a*r)^(2));\
yn: 2*a*a*b*v*exp(-(a*r)^(2));\
zn: 1;\
xuu: 0;\
yuu: 0;\
zuu: 2*exp(-(a*r)^(2))*(2*a^4*b*u^2 - a^2*b);\
xuv: 0;\
yuv: 0;\
zuv: 4*exp(-(a*r)^(2))*a^4*b*u*v;\
xvv: 0;\
yvv: 0;\
zvv: 2*exp(-(a*r)^(2))*(2*a^4*b*v^2 - a^2*b); ";
#endif