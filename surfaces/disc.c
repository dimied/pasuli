
#include "disc.h"
#include "surfaces_c_includes.h"

#if (USE_DISC != 0)

void Disc(double u, double v,
          double *constants,
          PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(DISC)

    double cu = cos(u);
    double su = sin(u);

    P_X(v * cu);
    P_Y(0);
    P_Z(v * su);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cv = cos(v);
    double sv = sin(v);
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
PaSuLiDefDesc pslddDisc = {
    PSLDD_ID(DISC)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI,
    0, 2, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descDisc =
    "name: Disc; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve: 1; \
x: v*cos(u); \
y: 0; \
z: v*sin(u); \
xu: 0; \
yu: 0; \
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
end;";
#endif