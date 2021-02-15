
#include "twisted_pipe_surface.h"
#include "surfaces_c_includes.h"

#if (USE_TWISTED_PIPE_SURFACE != 0)
void TwistedPipeSurface(pasuli_vartype u, pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_PIPE_SURFACE)

    double two_pi_3 = 2 * MY_PI / 3.0;

    double y_u = 2.0 + cos(u - two_pi_3);
    double z_u = 2.0 + cos(u + two_pi_3);
    u = 2.0 + cos(u);

    double h = sin(v);
    h = sqrt(1 + h * h);

    P_X((u * cos(v)) / h);
    P_Y((sin(v - two_pi_3) * y_u) / h);
    P_Z((sin(v + two_pi_3) * z_u) / h);

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
PaSuLiDefDesc pslddTwistedPipeSurface = {
    PSLDD_ID(TWISTED_PIPE_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
    0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTwistedPipeSurface =
    "name: Twistedpipe Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
a1:h: sqrt(1 + sin(v)*sin(v)); \
x: cos(v)*(2 + cos(u))/h; \
y: sin(v - 2*pi/3)*(2 + cos(u - 2*pi/3))/h; \
z: sin(v + 2*pi/3)*(2 + cos(u + 2*pi/3))/h; \
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