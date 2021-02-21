
#include "jet_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_JET_SURFACE != 0)
void JetSurface(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(JET_SURFACE)

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cosh_u = cosh(u);
    pasuli_calctype pos_factor = sin_u * (1 - cosh_u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(pos_factor * cos_v * 0.5);
    P_Y(pos_factor * sin_v * 0.5);
    P_Z(cosh_u);

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sinh_u = sinh(u);

    pasuli_calctype factor = (cosh_u - 1) * cos_u + sin_u * sinh_u;
    // Skip division by 2
    UD_X(-factor * cos_v);
    UD_Y(-factor * sin_v);
    UD_Z(2 * sinh_u);

    // Skip division by 2
    VD_X(-PASULI_COND_COPY_POS_Y(pos_factor * sin_v));
    VD_Y(PASULI_COND_COPY_POS_X(pos_factor * cos_v));
    VD_Z_CONST(0);

    //cos(u)*cosh(u)^2*sin(u)/4 - (cos(u)*cosh(u)*sin(u))/2
    // + (cos(u)*sin(u))/4 + (sin(u)^2*cosh(u)*sinh(u))/4 - (sin(u)^2*sinh(u))/4
    //sin(u)*(cos(u)*(0.5 + cosh(u)*(0.5*cosh(u) - 1) + 0.5*sin(u)*sin(u)*(cosh(u)-1) )/2
    // Skip division by 2
    N_X(-pos_factor * sinh_u * cos_v);
    N_Y(-pos_factor * sinh_u * sin_v);
    N_Z(sin_u * (cos_u * (0.5 + cosh_u * (0.5 * cosh_u - 1)) - 0.5 * sin_u * pos_factor));
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJetSurface = {
    PSLDD_ID(JET_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
    0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descJetSurface =
    "name: Jet Surface;\
ut:c; vt:c;\
us: 0; ue:pi: 1;\
vs: 0; ve:pi: 2;\
x: (1 - cosh(u))*sin(u)*cos(v)/2;\
y: (1 - cosh(u))*sin(u)*sin(v)/2;\
z: cosh(u);\
xu: -((cosh(u) -1)*cos(u) + sin(u)*sinh(u))*cos(v)/2;\
yu: -((cosh(u) -1)*cos(u) + sin(u)*sinh(u))*sin(v)/2;\
zu: sinh(u);\
xv: -(1 - cosh(u))*sin(u)*sin(v)/2;\
yv: (1 - cosh(u))*sin(u)*cos(v)/2;\
zv: 0;\
xn: (cosh(u)-1)*sin(u)*sinh(u)*cos(v)/2;\
yn: (cosh(u)-1)*sin(u)*sinh(u)*sin(v)/2;\
zn: cos(u)*cosh(u)^2*sin(u)/4 - (cos(u)*cosh(u)*sin(u))/2 + (cos(u)*sin(u))/4 + (sin(u)^2*cosh(u)*sinh(u))/4 - (sin(u)^2*sinh(u))/4 ";
#endif