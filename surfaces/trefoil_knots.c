
#include "trefoil_knots.h"
#include "surfaces_c_includes.h"

#if (USE_TREFOIL_KNOTS != 0)
void TrefoilKnots(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TREFOIL_KNOTS)

    double R = constants[0];
    double r = constants[1];

    pasuli_calctype cos_u3 = cos(u / 3.0);
    pasuli_calctype sin_u3 = sin(u / 3.0);

    pasuli_calctype cos_u_half = cos(u * 0.5);
    pasuli_calctype sin_u_half = sin(u * 0.5);

    pasuli_calctype By = R + r * cos_u_half;
    pasuli_calctype Bx = By * cos_u3;

    By = By * sin_u3;

    pasuli_calctype Bz = r + sin_u_half;

    pasuli_calctype cos_v_minus_pi = cos(v - MY_PI);
    pasuli_calctype sin_v_minus_pi = sin(v - MY_PI);

    P_X(Bx + cos_u3 * r * cos_v_minus_pi);
    P_Y(By + sin_u3 * r * cos_v_minus_pi);
    P_Z(Bz + r * sin_v_minus_pi);

    pasuli_calctype cos_v = sin(v);
    pasuli_calctype sin_v = sin(v);

    UD_X(r * (cos_v * sin_u3 / 3.0 - cos_u3 * sin_u_half * 0.5 - cos_u_half * sin_u3 / 3.0) - R * sin_u3 / 3.0);
    UD_Y(r * (-cos_v * cos_u3 / 3.0 - sin_u3 * sin_u_half * 0.5 - cos_u_half * cos_u3 / 3.0) + R * cos_u3 / 3.0);
    UD_Z(cos_u_half * 0.5);

    VD_X(r * cos_u3 * sin_v);
    VD_Y(r * sin_v * sin_u3);
    VD_Z(-r * cos_v);

    PASULI_CALC_NORMAL_FROM_UD_VD
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
xu: r*(cos(v)*sin(u/3)/3 - cos(u/3)*sin(u/2)/2 - cos(u/2)*sin(u/3)/3) - R*sin(u/3)/3; \
yu: r*(-cos(v)*cos(u/3)/3 - sin(u/3)*sin(u/2)/2 + cos(u/3)*cos(u/2)/3) + R*cos(u/3)/3; \
zu: cos(u/2)/2; \
xv: r*cos(u/3)*sin(v); \
yv: r*sin(v)*sin(u/3); \
zv: -r*cos(v);";
#endif