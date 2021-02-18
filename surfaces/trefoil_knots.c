
#include "trefoil_knots.h"
#include "surfaces_c_includes.h"

#if (USE_TREFOIL_KNOTS != 0)
void TrefoilKnots(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TREFOIL_KNOTS)

    double Bx;
    double By;
    double Bz;
    double r_cos_u3;
    double r_sin_u3;
    double R = constants[0];
    double r = constants[1];

    r_cos_u3 = cos(u / 3.0);
    r_sin_u3 = sin(u / 3.0);
    By = R + r * cos(u * 0.5);
    Bx = By * r_cos_u3;
    By = By * r_sin_u3;
    Bz = r + sin(u * 0.5);
    r_cos_u3 *= r;
    r_sin_u3 *= r;

    double vpi = cos(v - MY_PI);

    P_X(Bx + r_cos_u3 * vpi);
    P_Y(By + r_sin_u3 * vpi);
    P_Z(Bz + r * sin(v - MY_PI));

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

/*
#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots = {
    PSLDD_ID(TREFOIL_KNOTS)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI |
        PASULI_CONST_COUNT(2),
    0, 12, 0, 2, psldd_15_05_constants};
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots =
    "name: Trefoil Knots; \
ut:c; vt:c; \
us: 0; ue:pi: 12; \
vs: 0; ve:pi: 2; \
c1:R: 1.5; c2:r: 0.5; \
a1:Bx: (R + r*cos(u/2))*cos(u/3); \
a2:By: (R + r*cos(u/2))*sin(u/3); \
a3:Bz: r + sin(u/2); \
x: Bx + r*cos(u/3)*cos(v-pi); \
y: By + r*sin(u/3)*cos(v-pi); \
z: Bz + r*sin(v-pi); \
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