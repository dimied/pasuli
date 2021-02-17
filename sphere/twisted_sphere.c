
#include "twisted_sphere.h"
#include "sphere_c_includes.h"

#if (USE_TWISTED_SPHERE != 0)
void TwistedSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_SPHERE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(a * cos_u * cos_v);
    P_Y(a * sin_v + b * u);
    P_Z(a * sin_u * cos_v);

    // Ignore scaling by cos_v
    UD_X(-a * sin_u);
    UD_Y(b);
    UD_Z(a * cos_u);

    VD_X(-a * cos_u * sin_v);
    VD_Y(a * cos_v);
    VD_Z(-a * sin_u * sin_v);

    // No scaling by a
    NORMAL_OP(pasuli_calctype cos_v_squared = cos_v * cos_v);
    N_X(-b * sin_u * sin_v - a * cos_u * cos_v_squared);
    N_Y(-a * sin_v * cos_v);
    N_Z(b * cos_u * sin_v - a * sin_u * cos_v_squared);

    // No scaling by cos_v
    UUD_X(-a * cos_u);
    UUD_Y_CONST(0);
    UUD_Z(-a * sin_u);
    
    // No scaling by sin_v
    UVD_X(a * sin_u);
    UVD_Y_CONST(0);
    UVD_Z(-a * cos_u);

    VVD_X(-a * cos_u * cos_v);
    VVD_Y(-a * sin_v);
    VVD_Z(-a * sin_u * cos_v);
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddTwistedSphere = {
    PSLDD_ID(TWISTED_SPHERE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI |
        PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
    0, 2, -1, 1, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descTwistedSphere =
    "name: twisted sphere; \
cat: sphere; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs:pi: -1; ve:pi: 1; \
c1:a: 1; c2:b: 1; \
x: a*cos(u)*cos(v); \
y: a*sin(v) + b*u; \
z: a*sin(u)*cos(v); \
xu: -a*sin(u)*cos(v); \
yu: b; \
zu: a*cos(u)*cos(v); \
xv: -a*cos(u)*sin(v); \
yv: a*cos(v); \
zv: -a*sin(u)*sin(v); \
xn: -a*(a*cos(u)*cos(v)*cos(v) + b*sin(u)*sin(v)); \
yn: -a*a*(cos(v)*sin(v)); \
zn: a*(b*cos(u)*sin(v) - a*cos(v)*cos(v)*sin(u)); \
xuu: -a*cos(u)*cos(v); \
yuu: 0; \
zuu: -a*cos(v)*sin(u); \
xuv: a*sin(u)*sin(v); \
yuv: 0; \
zuv: -a*cos(u)*sin(v); \
xvv: -a*cos(u)*cos(v); \
yvv: -a*sin(v); \
zvv: -a*cos(v)*sin(u); ";
#endif
