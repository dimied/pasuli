
#include "triaxial_hexatorus.h"
#include "surfaces_c_includes.h"

#if (USE_TRIAXIAL_HEXATORUS != 0)

void TriaxialHexatorus(pasuli_vartype u,
                       pasuli_vartype v,
                       pasuli_consttype *constants,
                       PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TRIAXIAL_HEXATORUS)

    pasuli_calctype two_pi_3 = (2 * MY_PI) / 3.0;
    pasuli_calctype sqrt2 = sqrt(2.0);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype div_pos_x = (sqrt2 + cos(v + two_pi_3));
    pasuli_calctype div_pos_y = (sqrt2 + cos(v - two_pi_3));
    pasuli_calctype div_pos_z = (sqrt2 + cos(v));

    pasuli_calctype pos_x_u = sin(u + two_pi_3);
    pasuli_calctype pos_y_u = cos(u - two_pi_3);

    P_X(pos_x_u / div_pos_x);
    P_Y(pos_y_u / div_pos_y);
    P_Z(sin_u / div_pos_z);

    UD_X(cos(u + two_pi_3) / div_pos_x);
    UD_Y(-sin(u - two_pi_3) / div_pos_y);
    UD_Z(cos(u) / div_pos_z);

    VD_X(pos_x_u * sin(v + two_pi_3) / (div_pos_x * div_pos_x));
    VD_Y(-pos_y_u * sin(two_pi_3 - v) / (div_pos_y * div_pos_y));
    VD_Z(sin_u * sin(v) / (div_pos_z * div_pos_z));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialHexatorus = {
    PSLDD_ID(TRIAXIAL_HEXATORUS)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_U_END_PI,
    0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTriaxialHexatorus =
    "name: Triaxial Hexatorus; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
x: sin(u + 2*pi/3)/(sqrt(2) + cos(v + 2*pi/3)); \
y: cos(u - 2*pi/3)/(sqrt(2) + cos(v - 2*pi/3)); \
z: sin(u)/(sqrt(2) + cos(v)); \
xu: cos(u + 2*pi/3)/(sqrt(2) + cos(v + 2*pi/3)); \
yu: -sin(u - 2*pi/3)/(sqrt(2) + cos(v - 2*pi/3)); \
zu: cos(u)/(sqrt(2) + cos(v)); \
xv: sin(u + 2*pi/3)*sin(v + 2*pi/3)/(sqrt(2) + cos(v + 2*pi/3))^2; \
yv: -cos(u - 2*pi/3)*sin(2*pi/3-v)/(sqrt(2) + cos(v - 2*pi/3))^2; \
zv: sin(u)*sin(v)/(sqrt(2) + cos(v))^2;";
#endif