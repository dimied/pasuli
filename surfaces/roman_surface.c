
#include "roman_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_ROMAN_SURFACE != 0)
void RomanSurface(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(ROMAN_SURFACE);

    double u_sqrt = sqrt(1 - u * u);
    double cv = cos(v);
    double sv = sin(v);

    P_X(2 * u * cv * u_sqrt);
    P_Y(2 * u * sv * u_sqrt);
    P_Z(1 - 2 * u * u * cv * cv);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
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
PaSuLiDefDesc pslddRomanSurface = {
    PSLDD_ID(ROMAN_SURFACE)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_FULL_IMPL,
    0, 1, 0, 2, 0};
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descRomanSurface =
    "name: Roman Surface; \
ut:c; \
vt:c; \
us: 0; \
ue: 1; \
vs: 0; \
ve:pi: 2; \
x: 2*u*cos(v)*sqrt(1 - u*u); \
y: 2*u*sin(v)*sqrt(1 - u*u); \
z: 1 - 2*u*u*cos(v)*cos(v); "
    "xu: 2*(1-2*u*u)*cos(v)/(sqrt(1-u*u)); \
yu: 2*(1-2*u*u)*sin(v)/(sqrt(1-u*u)); \
zu: -4*u*cos(v)*cos(v); "
    "xv: -2*u*sqrt(1-u*u)*sin(v); \
yv: 2*u*sqrt(1-u*u)*cos(v); \
zv: 4*u*u*cos(v)*sin(v); "
    "xn: ((8*u*u*(1-u*u*(1+sin(v)*sin(v))))*cos(v))/(sqrt(1-u*u)); \
yn: 8*((u*u*cos(v))^2)*sin(v)/(sqrt(1-u*u)); \
zn: 4*u(1-2*u*u); "
    "xuu: 2*u*(2*u*u-3)*cos(v)/(sqrt(1-u*u)*(1-u*u)); \
yuu: 2*u*(2*u*u-3)*sin(v)/(sqrt(1-u*u)*(1-u*u)); \
zuu: -4*cos(v)*cos(v); \
xuv: 2*sin(v)*(2*u*u-1)/(sqrt(1-u*u)); \
yuv: 2*cos(v)*(1-2*u*u)/(sqrt(1-u*u)); \
zuv: 8*u*cos(v)*sin(v); \
xvv: -2*u*(sqrt(1-u*u))*cos(v); \
yvv: -2*u*(sqrt(1-u*u))*sin(v); \
zvv: 4*u*u*(2*cos(v)*cos(v) - 1); \
";
#endif