
#include "cuspidal_edge.h"
#include "surfaces_c_includes.h"

#if (USE_CUSPIDAL_EDGE != 0)
void CuspidalEdge(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CUSPIDAL_EDGE)

    pasuli_calctype v2 = v * v;

    P_X(u);
    P_Y(v2);
    P_Z(v2 * v);

    UD_X_CONST(1);
    UD_Y_CONST(0);
    UD_Z_CONST(0);

    //Ignore scaling by v
    pasuli_calctype sign_value = PASULI_CALC_SIGN(v);
    VD_X_CONST(0);
    VD_Y(2 * sign_value);
    VD_Z(3 * sign_value * v);

    //Ignore scaling by v
    N_X(0);
    N_Y(-3 * sign_value * v);
    N_Z(2 * sign_value);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descCuspidalEdge =
    "name: Cuspidal Edge;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u;\
y: v^2;\
z: v^3;\
xu: 1;\
yu: 0;\
zu: 0;\
xv: 0;\
yv: 2*v;\
zv: 3*v*v;\
xn: 0;\
yn: -3*v*v;\
zn: 2*v;";
#endif