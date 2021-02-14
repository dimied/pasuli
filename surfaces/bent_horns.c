
#include "bent_horns.h"
#include "surfaces_c_includes.h"

#if (USE_BENT_HORNS != 0)
void BentHorns(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BENT_HORNS)

    double cos_v_minus_1 = cos(v) - 1.0;

    P_X((cos(u) + 2.0) * (v / 3.0 - sin(v)));
    P_Y((2.0 + cos(u + 2 * MY_PI / 3.0)) * cos_v_minus_1);
    P_Z((2.0 + cos(u - 2 * MY_PI / 3.0)) * cos_v_minus_1);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
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
PaSuLiDefDesc pslddBentHorns = {
    PSLDD_ID(BENT_HORNS)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
        PASULI_V_START_PI | PASULI_V_END_PI,
    -1, 1, -2, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descBentHorns =
    "name: Bent Horns; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -2; ve:pi: 2; \
x: (2 + cos(u))*(v/3 - sin(v)); \
y: (2 + cos(u + 2*pi/3))*(cos(v) - 1); \
z: (2 + cos(u - 2*pi/3))*(cos(v) - 1); \
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
