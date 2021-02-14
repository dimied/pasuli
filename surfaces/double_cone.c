
#include "double_cone.h"
#include "surfaces_c_includes.h"

#if (USE_DOUBLE_CONE != 0)
void DoubleCone(double u, double v,
                double *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(DOUBLE_CONE)

    double two_pi_div_3 = (2 * MY_PI) / 3.0;

    P_X(v * cos(u));
    P_Y((v - 1) * cos(u + two_pi_div_3));
    P_Z((1 - v) * cos(u - two_pi_div_3));

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



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDoubleCone = {
PSLDD_ID( DOUBLE_CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDoubleCone =
"name: Double Cone; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: -1; ve: 1; \
x: v*cos(u); \
y: (v - 1)*cos(u + 2*pi/3); \
z: (1 - v)*cos(u - 2*pi/3); \
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