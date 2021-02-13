
#include "catalans_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_CATALANS_SURFACE != 0)
void CatalansSurface(double u, double v,
                     double *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CATALANS_SURFACE)

    double chv = cosh(v);
    double cu = cos(u);
    double su = sin(u);

    P_X(u - chv * sin(u));
    P_Y(1 - cos(u) * chv);
    P_Z(-4.0f * sin(u * 0.5) * sinh(v * 0.5));

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
PaSuLiDefDesc pslddCatalansSurface = {
PSLDD_ID( CATALANS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-2, 2 , -1.4f , 1.4f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface =
"name: Catalans Surface; \
ut:c; vt:c; \
us:pi: -2; ue:pi: 2; \
vs: -1.4; ve: 1.4; \
x: u - cosh(v)*sin(u); \
y: 1 - cosh(v)*cos(u); \
z: -4*sin(u/2)*sinh(v/2); \
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
zvv: 0;";
#endif