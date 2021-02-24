
#include "monkey_saddle2.h"
#include "surfaces_c_includes.h"

#if (USE_MONKEY_SADDLE2 != 0)
void MonkeySaddle2(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(MONKEY_SADDLE2)

    pasuli_consttype a = constants[0];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_3v = sin(3 * v);
    pasuli_calctype u2 = u * u;

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(a * u2 * u * sin_3v);

    UD_X(cos_v);
    UD_Y(sin_v);
    UD_Z(3 * a * u2 * sin_3v);

    // Ignore scaling by u
    pasuli_calctype factor = PASULI_CALC_SIGN(u);
    pasuli_calctype cos_3v = cos(3 * v);
    VD_X(-factor * sin_v);
    VD_Y(factor * cos_v);
    VD_Z(3 * a * factor * u2 * cos_3v);

    // Ignore scaling by u
    N_X(-3 * a * factor * u2 * (cos_v * sin_3v - sin_v * cos_3v));
    N_Y(-3 * a * factor * u2 * (cos_v * cos_3v + sin_v * sin_3v));
    N_Z(factor);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descMonkeySaddle2 =
    "name: Monkey Saddle 2;\
ut:u; vt:c;\
us:0; ue:1;\
vs:0; ve:pi:2;\
c1:a: 1;\
x: u*cos(v);\
y: u*sin(v);\
z: a*u^3*sin(3*v);\
xu: cos(v);\
yu: sin(v);\
zu: 3*a*u*u*sin(3*v);\
xv: -u*sin(v);\
yv: u*cos(v);\
zv: 3*a*u*u*u*cos(3*v);\
xn: -3*a*u^3*(cos(v)*sin(3*v)-sin(v)*cos(3*v));\
yn: -3*a*u^3*(cos(v)*cos(3*v)+sin(v)*sin(3*v));\
zn: u;";
#endif
