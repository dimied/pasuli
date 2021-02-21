
#include "bell_polar.h"
#include "surfaces_c_includes.h"

#if (USE_BELL_POLAR != 0)
void BellPolar(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BELL_POLAR)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype exp_av = exp(-2 * a * a * v * v);
    pasuli_calctype b_exp_av = b * exp_av;

    P_X(v * cos_u);
    P_Y(v * sin_u);
    //v = sqrt(v*cos(u)*v*cos(u) + v*sin(u)*v*sin(u)) = sqrt(v*v) = v
    P_Z(b_exp_av);

    UD_X(-PASULI_COND_COPY_POS_Y(v * sin_u));
    UD_Y(PASULI_COND_COPY_POS_X(v * cos_u));
    UD_Z_CONST(0);

    pasuli_calctype aav4 = 4*a*a*v;
    VD_X(cos_u);
    VD_Y(sin_u);
    VD_Z(-aav4 * b_exp_av);

    // No scaling by v
    N_X(-aav4*cos_u*b_exp_av);
    N_Y(-aav4*sin_u*b_exp_av);
    N_Z(-1);

    UUD_X(-PASULI_COND_COPY_POS_X(v*cos_u));
    UUD_Y(-PASULI_COND_COPY_POS_X(v*sin_u));
    UUD_Z_CONST(0);

    UVD_X(-sin_u);
    UVD_X(cos_u);
    UVD_X_CONST(0);

    // No scaling by 4*a^2*exp(-2*a*a*v*v)
    VVD_X_CONST(0);
    VVD_Y_CONST(0);
    VVD_Z(4*a*a*v*v);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellPolar = {
PSLDD_ID( BELL_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBellPolar =
    "name: Bell Polar;\
ut: c; vt: c;\
us: 0; ue:pi: 2;\
vs: 0; ve: 12;\
c1:a: 1.5; c2:b: 0.5;\
a1:r: sqrt(2*v*v);\
x: v*cos(u);\
y: v*sin(u);\
z: b*exp(-(a*r)^(2));\
xu: -v*sin(u);\
yu: v*cos(u);\
zu: 0;\
xv: cos(u);\
yv: sin(u);\
zv: -4*a^(2)*b*v*exp(-2*a*a*v*v);\
xn: -4*a^(2)*b*v*v*cos(u)*exp(-2*a*a*v*v);\
yn: -4*a^(2)*b*v*v*sin(u)*exp(-2*a*a*v*v);\
zn: -v;\
xuu: -v*cos(u);\
yuu: -v*sin(u);\
zuu: 0;\
xuv: -sin(u);\
yuv: cos(u);\
zuv: 0;\
xvv: 0;\
yvv: 0;\
zvv: 16*a^(4)*b*v^(2)*exp(-2*a*a*v*v) - 4*a^(2)*b*exp(-2*a*a*v*v)";
#endif