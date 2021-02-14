
#include "lemon_surface.h"
#include "fruits_c_includes.h"

#if (USE_LEMON_SURFACE != 0)
void LemonSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(LEMON_SURFACE)

    pasuli_vartype R = constants[0];
    pasuli_vartype r = constants[1];
    pasuli_vartype cv = cos(v);
    pasuli_vartype sv = sin(v);
    pasuli_vartype xy = sqrt(R * R - u * u) - r;

    P_X(xy * sv);
    P_Y(xy * cv);
    P_Z(u);

    UD_X(-sv / xy);
    UD_Y(-cv / xy);
    UD_Z_CONST(1);

    xy = sqrt(R * R - u * u) - r;
    VD_X(xy * cv);
    VD_Y(-(xy * sv));
    VD_Z_CONST(0);

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

/*
#if(COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddLemonSurface = {
PSLDD_ID( LEMON_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CALC_U_START|PASULI_CALC_U_END| \
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0,0, 0 , 2 , def_fruits_constants};
#endif
*/
#if (COMPILE_DESC_FRUITS != 0)
//f means formula
char *descLemonSurface =
    "name: Lemon Surface; \
cat: fruits; \
ut: c; \
vt: c; \
us: f : -sqrt(R*R-r*r); \
ue: f : sqrt(R*R-r*r); \
vs: 0; \
ve: pi : 2; \
c1:R: 2; \
c2:r: 1; \
x: (sqrt(R^2 - u^2) - r)*sin(v); \
y: (sqrt(R^2 - u^2) - r)*cos(v); \
z: u; "
#if (COMPILE_DESC_DERIV_U_FRUITS != 0)
    "xu: -u*sin(u)/(sqrt(R*R-u*u)); \
yu: -u_cos(v)/(sqrt(R*R-u*u)); \
zu: 1; "
#endif
#if (COMPILE_DESC_DERIV_V_FRUITS != 0)
    "xv: cos(v)*(sqrt(R*R-u*u)-r); \
yv: -sin(v)*(sqrt(R*R-u*u)-r); \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_FRUITS != 0)
    "xn: sin(v)*(sqrt(R*R-u*u)-r); \
yn: cos(v)*(sqrt(R*R-u*u)-r); \
zn: u-(r*u)/(sqrt(R*R-u*u)); "
#endif
#if (COMPILE_DESC_DERIV2_U_FRUITS != 0)
    "xuu: -R*R*sin(v)/(sqrt(R*R-u*u)); \
yuu: -R*R*cos(v)/(sqrt(R*R-u*u)); \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_FRUITS != 0)
    "xuv: -u*cos(v)/(sqrt(R*R-u*u)); \
yuv: u*sin(v)/(sqrt(R*R-u*u)); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_FRUITS != 0)
    "xvv: sin(v)*(sqrt(R*R-u*u) - r); \
yvv: cos(v)*(sqrt(R*R-u*u) - r); \
zvv: 0; "
#endif
    "end;";
#endif