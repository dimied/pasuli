
#include "catalans_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_CATALANS_SURFACE != 0)
void CatalansSurface(pasuli_vartype u, pasuli_vartype v,
                     pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CATALANS_SURFACE)

    pasuli_calctype cosh_v = cosh(v);
    pasuli_calctype cosh_v_half = cosh(v * 0.5);
    pasuli_calctype sinh_v_half = sinh(v * 0.5);

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype sin_u_half = sin(u * 0.5);

    P_X(u - cosh_v * sin_u);
    P_Y(1 - cosh_v * cos_u);
    P_Z(-4 * sin_u_half * sinh_v_half);

    pasuli_calctype cos_u_half = cos(u * 0.5);

    UD_X(1 - cos_u * cosh_v);
    UD_Y(sin_u * cosh_v);
    UD_Z(-2 * cos_u_half * sinh_v_half);

    pasuli_calctype sinh_v = sinh(v);

    VD_X(-sin_u * sinh_v);
    VD_Y(-cos_u * sinh_v);
    VD_Z(-2 * cosh_v_half * sin_u_half);

    N_X(-2 * (sinh_v * sinh_v_half * cos_u * cos_u_half - cosh_v * cosh_v_half * sin_u * sin_u_half));
    N_Y(2 * (-cosh_v * cosh_v_half * cos_u * sin_u + sinh_v * sinh_v_half * sin_u * cos_u_half + cosh_v_half * sin_u_half));
    N_Z(sinh_v * (cosh_v - cos_u));

    UUD_X(cosh_v * sin_u);
    UUD_Y(cosh_v * cos_u);
    UUD_Z(sin_u_half * sinh_v_half);

    UVD_X(-sinh_v * cos_u);
    UVD_Y(sinh_v * sin_u);
    UVD_Z(-cosh_v_half * cos_u_half);

    VVD_X(-cosh_v * sin_u);
    VVD_Y(-cosh_v * cos_u);
    VVD_Z(-sinh_v_half * sin_u_half);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCatalansSurface = {
    PSLDD_ID(CATALANS_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED,
    -2, 2, -1.4f, 1.4f, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface =
    "name: Catalans Surface;\
ut:c; vt:c;\
us:pi: -2; ue:pi: 2;\
vs: -1.4; ve: 1.4;\
x: u - cosh(v)*sin(u);\
y: 1 - cosh(v)*cos(u);\
z: -4*sin(u/2)*sinh(v/2);\
xu: 1 - cos(u)*cosh(v);\
yu: cosh(v)*sin(u);\
zu: -2*cos(u/2)*sinh(v/2);\
xv: -sin(u)*sinh(v);\
yv: -cos(u)*sinh(v);\
zv: -2*cosh(v/2)*sin(u/2);\
xn: -2*(cos(u)*cos(u/2)*sinh(v)*sinh(v/2) - sin(u)*sin(u/2)*cosh(v)*cosh(v/2) );\
yn: 2*(-cos(u)*sin(u/2)*cosh(v)*cosh(v/2) + cos(u/2)*sin(u)*sinh(v)*sinh(v/2) + cosh(v/2)*sin(u/2) );\
zn: sinh(v)*(cosh(v) - cos(u));\
xuu: cosh(v)*sin(u);\
yuu: cosh(v)*cos(u);\
zuu: sin(u/2)*sinh(v/2);\
xuv: -sinh(v)*cos(u);\
yuv: sinh(v)*sin(u);\
zuv: -cos(u/2)*cosh(v/2);\
xvv: -cosh(v)*sin(u);\
yvv: -cosh(v)*cos(u);\
zvv: -sin(u/2)*sinh(v/2);";
#endif