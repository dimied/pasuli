
#include "spinning_top1.h"
#include "surfaces_c_includes.h"

#if (USE_SPINNING_TOP1 != 0)
void SpinningTop1(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SPINNING_TOP1)

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype abs_u = fabs(u);
    pasuli_calctype factor = abs_u - 1;
    pasuli_calctype factor2 = factor * factor;

    P_X(factor2 * cos_v);
    P_Y(factor2 * sin_v);
    P_Z(u);

    pasuli_calctype sign_value = PASULI_CALC_SIGN(u);
    UD_X(2 * cos_v * sign_value * factor);
    UD_Y(2 * sin_v * sign_value * factor);
    UD_Z(1);

    // Skip scaling by (abs(u)-1)^2
    sign_value = (factor2 > 0) ? 1 : 0;
    VD_X(-sign_value * sin_v);
    VD_Y(sign_value * cos_v);
    VD_Z(0);

    sign_value = PASULI_CALC_SIGN(u);
    N_X(-PASULI_COND_COPY_POS_X(factor2 * cos_v));
    N_Y(-PASULI_COND_COPY_POS_X(factor2 * sin_v));
    N_Z(2 * sign_value * (abs_u * (abs_u * (abs_u - 3) + 3) - 1));
}
#endif

// Schon vorhanden ???
#if (COMPILE_DESC_SURFACES != 0)
char *descSpinningTop1 =
    "name: Spinning Top 1;\
ut:c; vt:o;\
us:-1; ue:pi:1;\
vs:0; ve:pi:2;\
x: (abs(u)-1)^2*cos(v);\
y: (abs(u)-1)^2*sin(v);\
z: u;\
xu: 2*cos(v)*sgn(u)*(abs(u)-1);\
yu: 2*sin(v)*sgn(u)*(abs(u)-1);\
zu: 1;\
xv: -(abs(u)-1)^2*sin(v);\
yv: (abs(u)-1)^2*cos(v);\
zv: 0;\
xn: -(abs(u)-1)^2*cos(v);\
yn: -(abs(u)-1)^2*sin(v);\
zn: 2*sgn(u)*(abs(u)*(abs(u)*(abs(u)-3)+3)-1);";
#endif
