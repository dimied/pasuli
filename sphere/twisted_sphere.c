
#include "twisted_sphere.h"
#include "sphere_c_includes.h"

#if (USE_TWISTED_SPHERE != 0)
void TwistedSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_SPHERE)

    double a = constants[0];
    double b = constants[1];
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);

    P_X(a * cu * cv);
    P_Y(a * sv + b * u);
    P_Z(a * su * cv);

    UD_X(-a * su * cv);
    UD_Y(b);
    UD_Z(a * cu * cv);

    VD_X(-a * cu * sv);
    VD_Y(a * cv);
    VD_Z(-a * su * sv);

    N_X(-b * a * su * sv - a * a * cv * cv * cu);
    N_Y(a * a * sv * cv);
    N_Z(b * a * cu * sv - a * su * cv * cv);

    UUD_X(-a * cu * cv);
    UUD_Y_CONST(0);
    UUD_Z(-a * cv * su);

    UVD_X(a * su * sv);
    UVD_Y_CONST(0);
    UVD_Z(-a * cu * sv);

    VVD_X(-a * cu * cv);
    VVD_Y(-a * sv);
    VVD_Z(-a * su * cv);
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
ut: c; \
vt: c; \
us: 0; \
ue: pi : 2; \
vs: pi : -1; \
ve: pi : 1; \
c1:a: 1.0; \
c2:b: 1.0; \
x: a*cos(u)*cos(v); \
y: a*sin(v) + b*u; \
z: a*sin(u)*cos(v); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
    "xu: -a*sin(u)*cos(v); \
yu: b; \
zu: a*cos(u)*cos(v); "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
    "xv: -a*cos(u)*sin(v); \
yv: a*cos(v); \
zv: -a*sin(u)*sin(v); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
    "xn: -a*(a*cos(u)*cos(v)*cos(v) + b*sin(u)*sin(v)); \
yn: -a*a*(cos(v)*sin(v)); \
zn: a*(b*cos(u)*sin(v) - a*cos(v)*cos(v)*sin(u)); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
    "xuu: -a*cos(u)*cos(v); \
yuu: 0; \
zuu: -a*cos(v)*sin(u); "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
    "xuv: a*sin(u)*sin(v); \
yuv: 0; \
zuv: -a*cos(u)*sin(v); "
#endif
#if (COMPILE_DESC_DERIV2_V_SPHERE != 0)
    "xvv: -a*cos(u)*cos(v); \
yvv: -a*sin(v); \
zvv: -a*cos(v)*sin(u); "
#endif
    "end;";
#endif
