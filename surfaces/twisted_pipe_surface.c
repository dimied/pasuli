
#include "twisted_pipe_surface.h"
#include "surfaces_c_includes.h"

#if (USE_TWISTED_PIPE_SURFACE != 0)

void TwistedPipeSurface(pasuli_vartype u,
                        pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(TWISTED_PIPE_SURFACE)

    pasuli_calctype two_pi_3 = 2 * MY_PI / 3.0;

    pasuli_calctype h = sin(v);
    h = sqrt(1 + h * h);

    P_X((sin(v - two_pi_3) * (2.0 + cos(u - two_pi_3))) / h);
    P_Y((sin(v + two_pi_3) * (2.0 + cos(u + two_pi_3))) / h);
    P_Z((2.0 + cos(u)) * cos(v) / h);
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
    "name: Twisted pipe Surface;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
a1:h: sqrt(1 + sin(v)*sin(v));\
x: sin(v - 2*pi/3)*(2 + cos(u - 2*pi/3))/h;\
y: sin(v + 2*pi/3)*(2 + cos(u + 2*pi/3))/h;\
z: cos(v)*(2 + cos(u))/h;";
#endif