
#include "ruled_rotor_cylindroid.h"
#include "surfaces_c_includes.h"

#if (USE_RULED_ROTOR_CYLINDROID != 0)
void RuledRotorCylindroid(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(RULED_ROTOR_CYLINDROID)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype n = constants[2];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_nu = cos(n * u);
    pasuli_calctype sin_nu = sin(n * u);
    pasuli_calctype factor = a + b * sin_nu;

    P_X(factor * cos_u - v * sin_u);
    P_Y(factor * sin_u + v * cos_u);
    P_Z(b * cos_nu);

    pasuli_calctype factor2 = b * n * cos_nu - v;
    UD_X(-sin_u * factor + cos_u * factor2);
    UD_Y(cos_u * factor + sin_u * factor2);
    UD_Z(-b * n * sin_nu);

    VD_X(-sin_u);
    VD_Y(cos_u);
    VD_Z(0);

    factor = b * n * sin_nu;
    N_X(cos_u * factor);
    N_Y(sin_u * factor);
    N_Z(b * n * cos_nu - v);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRuledRotorCylindroid =
    "name: Ruled Rotor Cylindroid;\
ut:c; vt:o;\
us:0; ue:pi:2;\
vs:0; ve: 2;\
c1:1:a: 1; c2:b: 1; c3:n: 1;\
x: (a+b*sin(n*u))*cos(u)-v*sin(u);\
y: (a+b*sin(n*u))*sin(u)+v*cos(u);\
z: b*cos(n*u);\
xu: -sin(u)*(a+b*sin(n*u)) + cos(u)*(b*n*cos(n*u)-v);\
yu: cos(u)*(a+b*sin(n*u)) + sin(u)*(b*n*cos(n*u)-v);\
zu: -b*n*sin(n*u);\
xv: -sin(u);\
yv: cos(u);\
zv: 0;\
xn: b*n*cos(u)*sin(n*u);\
yn: b*n*sin(u)*sin(n*u);\
zn: b*n*cos(n*u)-v;";
#endif
