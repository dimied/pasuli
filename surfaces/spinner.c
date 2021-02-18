
#include "spinner.h"
#include "surfaces_c_includes.h"

#if (USE_SPINNER != 0)
void Spinner(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SPINNER)

    double x_or_z = fabs(u) - 1.0;
    x_or_z *= x_or_z;
    double cv = cos(v);
    double sv = sin(v);

    P_X(x_or_z * cv);
    P_Y(u);
    P_Z(x_or_z * sv);

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
y: u; \
z: (|u| - 1)^(2)*sin(v); \
xu: 0; \
yu: 1; \
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