
#include "bent_horns.h"
#include "surfaces_c_includes.h"

#if (USE_BENT_HORNS != 0)
void BentHorns(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BENT_HORNS)

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_v_minus_1 = cos_v - 1.0;

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype cos_u_plus = cos(u + 2 * MY_PI / 3.0);
    pasuli_calctype cos_u_minus = cos(u - 2 * MY_PI / 3.0);

    P_X((cos_u + 2.0) * (v / 3.0 - sin_v));
    P_Y((2.0 + cos_u_plus) * cos_v_minus_1);
    P_Z((2.0 + cos_u_minus) * cos_v_minus_1);

    UD_OP(pasuli_calctype sin_u = sin(u));
    UD_OP(pasuli_calctype sin_u_plus = sin(u + 2 * MY_PI / 3.0));
    UD_OP(pasuli_calctype sin_u_minus = sin(u - 2 * MY_PI / 3.0));

    UD_X(sin_u * (sin_v - v / 3));
    UD_Y(-sin_u_plus * cos_v_minus_1);
    UD_Z(sin_u_minus * cos_v_minus_1);

    VD_X((cos_u - 3 * cos_u * cos_v - 6 * cos_v + 2) / 3);
    VD_Y(-sin_v * (2 + cos_u_plus));
    VD_Z(-sin_v * (2 + cos_u_minus));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBentHorns = {
    BENT_HORNS,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI,
    -1, 1, -2, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descBentHorns =
    "name: Bent Horns;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:pi: -2; ve:pi:2;\
x: (2 + cos(u))*(v/3 - sin(v));\
y: (2 + cos(u + 2*pi/3))*(cos(v) - 1);\
z: (2 + cos(u - 2*pi/3))*(cos(v) - 1);\
xu: sin(u)*(sin(v) - v/3);\
yu: sin(u + 2*pi/3)*(1-cos(v));\
zu: sin(u - 2*pi/3)*(cos(v)-1);\
xv: cos(u)/3 - cos(u)*cos(v) - 2*cos(v) + 2/3;\
yv: -sin(v)*(2+cos(u + 2*pi/3));\
zv: -sin(v)*(2+cos(u - 2*pi/3)); ";
#endif
