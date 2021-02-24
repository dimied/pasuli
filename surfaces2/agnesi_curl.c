
#include "agnesi_curl.h"
#include "surfaces_c_includes.h"

#if (USE_AGNESI_CURL != 0)
void AgnesiCurl(pasuli_vartype u,
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(AGNESI_CURL)

    pasuli_consttype T = constants[0];
    pasuli_consttype L = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = cos(v);
    pasuli_calctype T_plus_u = T + u;
    pasuli_calctype sqrtOf = sqrt((T - u) / T_plus_u);

    P_X(u * sin_v);
    P_Y(u * cos_v);
    P_Z(L * sqrtOf);

    pasuli_calctype ud_divisor = (sqrtOf * T_plus_u * T_plus_u);
    UD_X(sin_v);
    UD_Y(cos_v);
    UD_Z(-L * T / ud_divisor);

    VD_X(PASULI_COND_COPY_POS_Y(u * cos_v));
    VD_Y(-PASULI_COND_COPY_POS_X(u * sin_v));
    VD_Z(0);

    // Scale by (sqrt((T-u)/(T+u))*(T+u)^2) to avoid 2 divisions
    sqrtOf = L * T;
    // Ignore scale by u
    u = PASULI_CALC_SIGN(u);
    N_X(u * sqrtOf * sin_v);
    N_Y(u * sqrtOf * cos_v);
    N_Z(-u * ud_divisor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descAgnesiCurl =
    "name: Agnesi Curl;\
ut:c; vt:o;\
us:0; ue:T;\
vs:0; ve:pi:2;\
c1:T: 1; c2:L: 1;\
x: u*sin(v);\
y: u*cos(v);\
z: L*sqrt((T-u)/(T+u));\
xu: sin(v);\
yu: cos(v);\
zu: -L*T/(sqrt((T-u)/(T+u))*(T+u)^2);\
xv: u*cos(v);\
yv: -u*sin(v);\
zv: 0;\
xn: L*T*u*sin(v)/(sqrt((T-u)/(T+u))*(T+u)^2);\
yn: L*T*u*cos(v)/(sqrt((T-u)/(T+u))*(T+u)^2);\
zn: -u;";
#endif
