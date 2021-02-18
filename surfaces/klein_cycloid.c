
#include "klein_cycloid.h"
#include "surfaces_c_includes.h"

#if (USE_KLEIN_CYCLOID != 0)

void KleinCycloid(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(KLEIN_CYCLOID)

    double a = constants[0];
    double b = constants[1];
    double c = constants[2];

    double cos_ub = cos(u / b);
    double cos_uc_cos_ub = cos(u / c) * cos_ub;
    double sin_uc_cos_ub = sin(u / c) * cos_ub;
    u = sin(u / b);

    double sincos_v = sin(v) * cos(v);
    double acv = (a + cos(v));

    P_X(cos_uc_cos_ub * acv + u * sincos_v);
    P_Y(sin_uc_cos_ub * acv + u * sincos_v);
    P_Z(cos_ub * sincos_v - u * acv);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);
#endif

    UD_X(0);
    UD_Y(0);
    UD_Z(0);

    VD_X(0);
    VD_Y(0);
    VD_Z(0);

    N_X(0);
    N_Y(0);
    N_Z(0);

    UUD_X(0);
    UUD_Y(0);
    UUD_Z(0);

    UVD_X(0);
    UVD_Y(0);
    UVD_Z(0);

    VVD_X(0);
    VVD_Y(0);
    VVD_Z(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinCycloid = { //TODO TODO
    PSLDD_ID(KLEIN_CYCLOID)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI,
    0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descKleinCycloid =
    "name: Klein Cycloid; \
ut: c; vt: c; \
us: 0; ue:pi:c2:c3: 2; \
vs: 0; ve:pi: 4; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
x: cos(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
y: sin(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
z: -sin(u/b)*(a + cos(v)) + cos(u/b)*sin(v)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
";
#endif