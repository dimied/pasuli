
#include "klein_cycloid.h"
#include "surfaces_c_includes.h"

#if (USE_KLEIN_CYCLOID != 0)

void KleinCycloid(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KLEIN_CYCLOID)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype cos_ub = cos(u / b);
    pasuli_calctype cos_uc = cos(u / c);
    pasuli_calctype sin_uc = sin(u / c);
    pasuli_calctype sin_ub = sin(u / b);

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sincos_v = sin(v) * cos_v;
    pasuli_calctype a_plus_cos_v = (a + cos_v);

    P_X(cos_uc * cos_ub * a_plus_cos_v + sin_ub * sincos_v);
    P_Y(sin_uc * cos_ub * a_plus_cos_v + sin_ub * sincos_v);
    P_Z(cos_ub * sincos_v - sin_ub * a_plus_cos_v);
}
#endif

/*
#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinCycloid = { //TODO TODO
    KLEIN_CYCLOID,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI,
    0, 2, 0, 2, 0};
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descKleinCycloid =
    "name: Klein Cycloid;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi: 4;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: cos(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v);\
y: sin(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v);\
z: -sin(u/b)*(a + cos(v)) + cos(u/b)*sin(v)*cos(v); ";
#endif