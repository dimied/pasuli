#include "astroidal_ellipsoid.h"
#include "surfaces_c_includes.h"

#if (USE_ASTROIDAL_ELLIPSOID != 0)
void AstroidalEllipsoid(pasuli_vartype u,
                        pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ASTROIDAL_ELLIPSOID)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    pasuli_calctype cos_u_pow3 = PASULI_TRIG_COS_POW3(cos_u, v);
    pasuli_calctype sin_u_pow3 = PASULI_TRIG_SIN_POW3(sin_u, v);

    pasuli_calctype cos_v_pow3 = PASULI_TRIG_COS_POW3(cos_v, v);
    pasuli_calctype sin_v_pow3 = PASULI_TRIG_SIN_POW3(sin_v, v);

    P_X(a * cos_u_pow3 * cos_v_pow3);
    P_Y(b * sin_u_pow3 * cos_v_pow3);
    P_Z(c * sin_v_pow3);

    // Ignore scaling by 3*cos(u)*cos(v)^3*sin(u);
    pasuli_calctype factor = cos_u * cos_v_pow3 * sin_u;
    factor = PASULI_CALC_SIGN(factor);
    UD_X(-a * factor * cos_u);
    UD_Y(b * factor * sin_u);
    UD_Z(0);

    // Ignore scaling by 3*cos(v)*sin(v)
    factor = cos_v * sin_v;
    factor = PASULI_CALC_SIGN(factor);
    VD_X(-a * factor * cos_u_pow3 * cos_v);
    VD_Y(-b * factor * sin_u_pow3 * cos_v);
    VD_Z(c * factor * sin_v);

    // Ignore common scaling by 9*cos(u)*cos(v)^4*sin(u)*sin(v)
    factor = cos_u * sin_u * sin_v * cos_v * cos_v; // cos(v)^4 always positive
    factor = PASULI_CALC_SIGN(factor);
    N_X(b * c * factor * sin_u * sin_v);
    N_Y(a * c * factor * cos_u * sin_v);
    N_Z(a * b * factor * cos_u * cos_v * sin_u);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descAstroidalEllipsoid =
    "name: Astroidal Ellipsoid;\
ut:c; vt:c;\
us:pi:-0.5; ue:pi:0.5;\
vs:pi:-1; ve:pi:1;\
c1:a: 1; c2:b: 1; c3:c: 1;\
x: a*cos(u)^3*cos(v)^3;\
y: b*sin(u)^3*cos(v)^3;\
z: c*sin(v)^3;\
xu: -3*a*cos(u)^2*cos(v)^3*sin(u);\
yu: 3*b*cos(u)*cos(v)^3*sin(u)^2;\
zu: 0;\
xv: -3*a*cos(u)^3*cos(v)^2*sin(v);\
yv: -3*b*sin(u)^3*cos(v)^2*sin(v);\
zv: 3*c*cos(v)*sin(v)^2;\
xn: 9*b*c*cos(u)*cos(v)^4*sin(u)^2*sin(v)^2;\
yn: 9*a*c*cos(u)^2*cos(v)^4*sin(u)*sin(v)^2;\
zn: 9*a*b*cos(u)^2*cos(v)^5*sin(u)^2*sin(v);";
#endif