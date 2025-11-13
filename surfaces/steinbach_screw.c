
#include "steinbach_screw.h"
#include "surfaces_c_includes.h"

#if (USE_STEINBACH_SCREW != 0)

void SteinbachScrew(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(STEINBACH_SCREW)

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(v * cos_u);

    UD_X(cos_v);
    UD_Y(sin_v);
    UD_Z(-v * sin_u);

    VD_X(-u * sin_v);
    VD_Y(u * cos_v);
    VD_Z(cos_u);

    N_X(u * v * cos_v * sin_u + cos_u * sin_v);
    N_Y(u * v * sin_v * sin_u - cos_u * cos_v);
    N_Z(u);

    UUD_X_CONST(0);
    UUD_Y_CONST(0);
    UUD_Z(-v * cos_u);

    UVD_X(-sin_v);
    UVD_Y(cos_v);
    UVD_Z(-sin_u);

    VVD_X(-u * cos_v);
    VVD_Y(-u * sin_v);
    VVD_Z_CONST(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSteinbachScrew = {
    STEINBACH_SCREW,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_FULL_IMPL,
    -4, 4, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descSteinbachScrew =
    "name: Steinbach Screw;\
ut:c; vt:c;\
us: -4; ue: 4;\
vs:0; ve:pi:2;\
x: u*cos(v);\
y: u*sin(v);\
z: v*cos(u);\
xu: cos(v);\
yu: sin(v);\
zu: -v*sin(u);\
xv: -u*sin(v);\
yv: u*cos(v);\
zv: cos(u);\
xn: u*v*cos(v)*sin(u) + cos(u)*sin(v);\
yn: u*v*sin(u)*sin(v) - cos(u)*cos(v);\
zn: u;\
xuu: 0;\
yuu: 0;\
zuu: -v*cos(u);\
xuv: -sin(v);\
yuv: cos(v);\
zuv: -sin(u);\
xvv: -u*cos(v);\
yvv: -u*sin(v);\
zvv: 0;";
#endif