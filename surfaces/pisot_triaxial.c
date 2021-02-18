
#include "pisot_triaxial.h"
#include "surfaces_c_includes.h"

#if (USE_PISOT_TRIAXIAL != 0)

void PisotTriaxial(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PISOT_TRIAXIAL)

    P_X(0.655866 * cos(1.03002 + u) * (2 + cos(v)));
    P_Y(0.74878 * cos(1.40772 - u) * (2 + 0.868837 * cos(2.43773 + v)));
    P_Z(0.868837 * cos(2.43773 + u) * (2 + 0.495098 * cos(0.377696 - v)));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
//	double cv = cos(v);
//	double sv = sin(v);
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
PaSuLiDefDesc pslddPisotTriaxial = {
    PSLDD_ID(PISOT_TRIAXIAL)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_U_END_PI,
    0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descPisotTriaxial =
    "name: Pisot Triaxial; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
x: 0.655866*cos(1.03002 + u)*(2 + cos(v)); \
y: 0.74878*cos(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v)); \
z: 0.868837*cos(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v)); \
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
";
#endif