
#include "double_cone.h"
#include "surfaces_c_includes.h"

#if (USE_DOUBLE_CONE != 0)
void DoubleCone(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(DOUBLE_CONE)

    pasuli_calctype two_pi_div_3 = (2 * MY_PI) / 3.0;
    pasuli_calctype cos_u = cos(u);

    pasuli_calctype cos_u_plus = cos(u + two_pi_div_3);
    pasuli_calctype cos_u_minus = cos(u - two_pi_div_3);

    P_X(v * cos_u);
    P_Y((v - 1) * cos_u_plus);
    P_Z((1 - v) * cos_u_minus);

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_u_plus = sin(u + two_pi_div_3);
    pasuli_calctype sin_u_minus = sin(two_pi_div_3 - u);

    UD_X(-v * sin_u);
    UD_Y((1 - v) * sin_u_plus);
    UD_Z((1 - v) * sin_u_minus);

    VD_X(cos_u);
    VD_Y(cos_u_plus);
    VD_Z(-cos_u_minus);

    N_X((v - 1) * (cos_u_plus * sin_u_minus + cos_u_minus * sin_u_plus));
    N_Y(-(v * cos_u * sin_u_minus + v * cos_u_minus * sin_u + cos_u * sin_u_minus));
    N_Z(v * cos_u * sin_u_plus - v * cos_u_plus * sin_u - cos_u * sin_u_plus);

    UUD_X(-v * cos_u);
    UUD_Y((1 - v) * cos_u_plus);
    UUD_Z((v - 1) * cos_u_minus);

    UVD_X(-sin_u);
    UVD_Y(-sin_u_plus);
    UVD_Z(-sin_u_minus);

    VVD_ALL(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDoubleCone = {
    DOUBLE_CONE,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI,
    0, 2, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descDoubleCone =
    "name: Double Cone;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs: -1; ve: 1;\
x: v*cos(u);\
y: (v - 1)*cos(u + 2*pi/3);\
z: (1 - v)*cos(u - 2*pi/3);\
xu: -v*sin(u);\
yu: (1-v)*sin(u + 2*pi/3);\
zu: (1-v)*sin(2*pi/3 - u);\
xv: cos(u);\
yv: cos(u+2*pi/3);\
zv: -cos(u - 2*pi/3);\
xn: v*cos(2*pi/3 + u)*sin(2*pi/3 -u) + v*cos(2*pi/3 - u)*sin(2*pi/3 +u) - cos(2*pi/3 + u)*sin(2*pi/3 -u) - cos(2*pi/3 - u)*sin(2*pi/3 +u);\
yn: -v*cos(u)*sin(2*pi/3-u) - v*cos(2*pi/3 - u)*sin(u) - cos(u)*sin(2*pi/3-u);\
zn: v*cos(u)*sin(u + 2*pi/3) - v*cos(u + 2*pi/3)*sin(u) - cos(u)*sin(u + 2*pi/3);\
xuu: -v*cos(u);\
yuu: (1-v)*cos(2*pi/3 + u);\
zuu: (v-1)*cos(u - 2*pi/3);\
xuv: -sin(u);\
yuv: -sin(2*pi/3 + u);\
zuv: -sin(2*pi/3 - u);\
xvv: 0; yvv: 0; zvv: 0;";
#endif