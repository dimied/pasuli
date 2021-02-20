
#include "spinner.h"
#include "surfaces_c_includes.h"

#if (USE_SPINNER != 0)

void Spinner(pasuli_vartype u,
             pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SPINNER)

    pasuli_calctype u_sign = PASULI_CALC_SIGN(u);

    pasuli_calctype factor = fabs(u) - 1.0;
    factor *= factor;

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(factor * cos_v);
    P_Y(factor * sin_v);
    P_Z(u);

    UD_X(2 * u_sign * factor * cos_v);
    UD_Y(2 * u_sign * factor * sin_v);
    UD_Z(1);

    // Don't scale by (|u| - 1)^(2)
    u_sign = PASULI_CALC_SIGN(factor);

    VD_X(-u_sign * sin_v);
    VD_Y(u_sign * cos_v);
    VD_Z(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpinner = {
PSLDD_ID( SPINNER )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descSpinner =
    "name: Spinner; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs: 0; ve:pi: 2; \
x: (|u| - 1)^(2)*cos(v); \
y: (|u| - 1)^(2)*sin(v); \
z: u; \
xu: 2*u*(|u|-1)*cos(v)/|u|; \
yu: 2*u*(|u|-1)*sin(v)/|u|; \
zu: 1; \
xv: -(|u| - 1)^(2)*sin(v); \
yv: (|u| - 1)^(2)*cos(v); \
zv: 0;";
#endif