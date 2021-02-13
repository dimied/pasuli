
#include "steinbach_screw.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_STEINBACH_SCREW != 0)
void SteinbachScrew(double u, double v,
                    double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(STEINBACH_SCREW)

    double cv = cos(v);
    double sv = sin(v);
    double cu = cos(u);

    P_X(u * cv);
    P_Y(u * sv);
    P_Z(v * cu);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double su = sin(u);
#endif

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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSteinbachScrew = {
    PSLDD_ID(STEINBACH_SCREW)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_FULL_IMPL,
    -4, 4, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descSteinbachScrew =
    "start; \
name: Steinbach Screw; \
ut:c; \
vt:c; \
us: -4; \
ue: 4; \
vs: 0; \
ve:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: v*cos(u); "
    "xu: cos(v); yu: sin(v); zu: -v*sin(u); "
    "xv: -u*sin(v); yv: u*cos(v); zv: cos(u); "
    "xn: u*v*cos(v)*sin(u) + cos(u)*sin(v); \
yn: u*v*sin(u)*sin(v) - cos(u)*cos(v); \
zn: u; "
    "xuu: 0; \
yuu: 0; \
zuu: -v*cos(u); "
    "xuv: -sin(v); \
yuv: cos(v); \
zuv: -sin(u); "
    "xvv: -u*cos(v); \
yvv: -u*sin(v); \
zvv: 0; "
    "end;";
#endif