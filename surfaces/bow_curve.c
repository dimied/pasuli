
#include "bow_curve.h"
#include "surfaces_c_includes.h"

#if (USE_BOW_CURVE != 0)

void BowCurve(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOW_CURVE)

    pasuli_consttype T = constants[0];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype T_cos_u = T * cos_u;
    pasuli_calctype T_sin_u = T * sin_u;
    pasuli_calctype sin_2v = sin(2 * v);
    pasuli_calctype cos_2v = cos(2 * v);
    pasuli_calctype T_sin_u_plus_2 = 2.0 + T_sin_u;

    P_X(T_sin_u_plus_2 * sin_2v);
    P_Y(T_sin_u_plus_2 * cos_2v);
    P_Z(T_cos_u + 3.0 * cos_2v);

    // Skips common factor T
    UD_X(cos_u * sin_2v);
    UD_Y(cos_u * cos_2v);
    UD_Z(-sin_u);

    VD_X(2 * T_sin_u * cos_2v + 4 * cos_2v);
    VD_Y(-(2 * T_sin_u * sin_2v + 4 * sin_2v));
    VD_Z(-3 * sin_v);

    // Ignore T
    N_X(-(2 * T_sin_u_plus_2 * sin_u * sin_2v + 3 * cos_u * cos_2v * sin_v));
    N_Y(-(2 * T_sin_u_plus_2 * sin_u * cos_2v - 3 * cos_u * sin_2v * sin_v));
    N_Z(-2 * (T_sin_u_plus_2 * cos_u));

    // Ignore T
    UUD_X(sin_u * sin_2v);
    UUD_Y(sin_u * cos_2v);
    UUD_Z(cos_u);

    // Ignore 2*T
    UVD_X(cos_u * cos_2v);
    UVD_Y(cos_u * sin_2v);
    UVD_Z(0);

    VVD_X(-4 * sin_2v * T_sin_u_plus_2);
    VVD_Y(-4 * cos_2v * T_sin_u_plus_2);
    VVD_Z(-3 * cos(v));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBowCurve = {
PSLDD_ID( BOW_CURVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBowCurve =
    "name: Bow Curve;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
c1:T: 1.5;\
x: (2 + T*sin(u))*sin(2*v);\
y: (2 + T*sin(u))*cos(2*v);\
z: T*cos(u) + 3*cos(v);\
xu: T*cos(u)*sin(2*v);\
yu: T*cos(u)*cos(2*v);\
zu: -T*sin(u);\
xv: 2*T*cos(2*v)*sin(u) + 4*cos(2*v);\
yv: -(2*T*sin(2*v)*sin(u) + 4*sin(2*v));\
zv: -3*sin(v);\
xn: -T*(2*T*sin(u)*sin(u)*sin(2*v) + 3*cos(u)*cos(2*v)*sin(v) + 4*sin(u)*sin(2*v));\
yn: -T*(2*T*sin(u)*sin(u)*cos(2*v) - 3*cos(u)*sin(2*v)*sin(v) + 4*sin(u)*cos(2*v));\
zn: -2*T*(T*cos(u)*sin(u) + 2*cos(u));\
xuu: -T*sin(u)*sin(2*v);\
yuu: -T*sin(u)*cos(2*v);\
zuu: -T*cos(u);\
xuv: 2*T*cos(u)*cos(2*v);\
yuv: -2*T*cos(u)*sin(2*v);\
zuv: 0;\
xvv: -4*sin(2*v)(T*sin(u) - 2);\
yvv: -4*cos(2*v)(T*sin(u) - 2);\
zvv: -3*cos(v);";
#endif