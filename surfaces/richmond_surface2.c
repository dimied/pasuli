
#include "richmond_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_RICHMOND_SURFACE2 != 0)
void RichmondSurface2(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(RICHMOND_SURFACE2)

    pasuli_calctype u2 = u * u;
    pasuli_calctype v2 = v * v;
    pasuli_calctype divisor = u2 + v2;

    P_X(u2 * u / 3 - u * v2 + u / divisor);
    P_Y(v2 * v / 3 - v * u2 - v / divisor);
    P_Z(2 * u);

    pasuli_calctype factor = divisor * divisor;
    // Multiplied by (u^2+v^2)^2
    UD_X((v2 - u2 + factor * (u2 - v2)));
    UD_Y(2 * u * v * (factor - 1));
    UD_Z(2 * factor);

    // Multiplied by (u^2+v^2)^2
    VD_X(-2 * u * v * (factor + 1));
    VD_Y(v2 - u2 + factor * (v2 - u2));
    VD_Z(0);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface2 =
    "name: Richmond Surface 2;\
ut:c; vt:o;\
us:-1; ue:1;\
vs:-1; ve:1;\
x: u^3/3-u*v^2+u/(u^2+v^2);\
y: v^3/3-v*u^2-v/(u^2+v^2);\
z: 2*u;\
xu: (v^2-u^2+(u^2+v^2)^2*(u^2-v^2))/(u^2+v^2)^2;\
yu: 2*u*v*((u^2+v^2)^2-1)/(u^2+v^2)^2;\
zu: 2;\
xv: -2*u*v*(1+(u^2+v^2)^2)/(u^2+v^2)^2;\
yv: (v^2-u^2+(u^2+v^2)^2*(v^2-u^2))/(u^2+v^2)^2;\
zv: 0;";
#endif
