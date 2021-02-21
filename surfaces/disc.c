
#include "disc.h"
#include "surfaces_c_includes.h"

#if (USE_DISC != 0)

void Disc(pasuli_vartype u, pasuli_vartype v,
          pasuli_consttype *constants,
          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(DISC)

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);

    P_X(v * cos_u);
    P_Y(v * sin_u);
    P_Z(0);

    UD_X(-PASULI_COND_COPY_POS_Y(v * sin_u));
    UD_Y(PASULI_COND_COPY_POS_X(v * cos_u));
    UD_Z_CONST(0);

    VD_X(cos_u);
    VD_Y(sin_u);
    VD_Z_CONST(0);

    N_X_CONST(0);
    N_Y_CONST(0);
    N_Z(-v);

    UUD_X(-PASULI_COND_COPY_POS_X(v * cos_u));
    UUD_Y(-PASULI_COND_COPY_POS_Y(v * sin_u));
    UUD_Z_CONST(0);

    UVD_X(-sin_u);
    UVD_Y(cos_u);
    UVD_Z_CONST(0);

    VVD_ALL(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDisc = {
    PSLDD_ID(DISC)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI,
    0, 2, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descDisc =
    "name: Disc;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve: 1;\
x: v*cos(u);\
y: v*sin(u);\
z: 0;\
xu: -v*sin(u);\
yu: v*cos(u);\
zu: 0;\
xv: cos(u);\
yv: sin(u);\
zv: 0;\
xn: 0;\
yn: 0;\
zn: -v;\
xuu: -v*cos(u);\
yuu: -v*sin(u);\
zuu: 0;\
xuv: -sin(u);\
yuv: cos(u);\
zuv: 0;\
xvv: 0; yvv: 0; zvv: 0;";
#endif