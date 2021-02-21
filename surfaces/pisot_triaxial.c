
#include "pisot_triaxial.h"
#include "surfaces_c_includes.h"

#if (USE_PISOT_TRIAXIAL != 0)

void PisotTriaxial(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PISOT_TRIAXIAL)

    pasuli_calctype cos_v = cos(v);

    P_X(0.655866 * cos(1.03002 + u) * (2 + cos_v));
    P_Y(0.74878 * cos(1.40772 - u) * (2 + 0.868837 * cos(2.43773 + v)));
    P_Z(0.868837 * cos(2.43773 + u) * (2 + 0.495098 * cos(0.377696 - v)));

    UD_X(-0.655866 * sin(1.03002 + u) * (2 + cos_v));
    UD_Y(-0.74878 * sin(1.40772 - u) * (2 + 0.868837 * cos(2.43773 + v)));
    UD_Z(-0.868837 * sin(2.43773 + u) * (2 + 0.495098 * cos(0.377696 - v)));

    VD_X(-0.655866*cos(1.03002 + u)*sin(v));
    VD_Y(-0.650568*cos(1.40772 - u)*sin(2.43773 + v));
    VD_Z(-0.430159*cos(2.43773 + u)*sin(0.377696-v));

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPisotTriaxial = {
    PSLDD_ID(PISOT_TRIAXIAL)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_U_END_PI,
    0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descPisotTriaxial =
    "name: Pisot Triaxial;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
x: 0.655866*cos(1.03002 + u)*(2 + cos(v));\
y: 0.74878*cos(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v));\
z: 0.868837*cos(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v));\
xu: -0.655866*sin(1.03002 + u)*(2 + cos(v));\
yu: -0.74878*sin(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v));\
zu: -0.868837*sin(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v));\
xv: -0.655866*cos(1.03002 + u)*sin(v);\
yv: -0.650568*cos(1.40772 - u)*sin(2.43773 + v);\
zv: -0.430159*cos(2.43773 + u)*sin(v-0.377696);";
#endif