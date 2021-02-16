
#include "lemon_surface.h"
#include "fruits_c_includes.h"

#if (USE_LEMON_SURFACE != 0)
void LemonSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(LEMON_SURFACE)

    pasuli_calctype R = constants[0];
    pasuli_calctype r = constants[1];
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype rootOfR_u = sqrt(R * R - u * u);
    pasuli_calctype pos_factor = rootOfR_u - r;

    P_X(pos_factor * sin_v);
    P_Y(pos_factor * cos_v);
    P_Z(u);

    UD_X(-sin_v * u / rootOfR_u);
    UD_Y(-cos_v * u / rootOfR_u);
    UD_Z(1);

    VD_X(PASULI_COND_COPY_POS_Y(pos_factor * cos_v));
    VD_Y(-PASULI_COND_COPY_POS_X(pos_factor * sin_v));
    VD_Z(0);

    N_X(PASULI_COND_COPY_POS_X(sin_v * pos_factor));
    N_Y(PASULI_COND_COPY_POS_X(cos_v * pos_factor));
    N_Z(u - r * u / rootOfR_u);

    pasuli_calctype divisor = sqrt(pow(R * R - u * u, 3));
    UUD_X(-R * R * sin_v / divisor);
    UUD_Y(-R * R * cos_v / divisor);
    UUD_Z(0);

    UVD_X(-u * cos_v / rootOfR_u);
    UVD_Y(u * sin_v / rootOfR_u);
    UVD_Z(0);

    VVD_X(-PASULI_COND_COPY_POS_X(sin_v * pos_factor));
    VVD_Y(-PASULI_COND_COPY_POS_X(cos_v * pos_factor));
    VVD_Z(0);
}
#endif

#if (COMPILE_DESC_FRUITS != 0)
//f means formula
char *descLemonSurface =
    "name: Lemon Surface; \
cat: fruits; \
ut: c; vt: c; \
us:f: -sqrt(R*R-r*r); \
ue:f: sqrt(R*R-r*r); \
vs: 0; ve:pi: 2; \
c1:R: 2; c2:r: 1; \
x: (sqrt(R^2 - u^2) - r)*sin(v); \
y: (sqrt(R^2 - u^2) - r)*cos(v); \
z: u; \
xu: -u*sin(v)/(sqrt(R*R-u*u)); \
yu: -u*cos(v)/(sqrt(R*R-u*u)); \
zu: 1; \
xv: cos(v)*(sqrt(R*R-u*u)-r); \
yv: -sin(v)*(sqrt(R*R-u*u)-r); \
zv: 0; \
xn: sin(v)*(sqrt(R*R-u*u)-r); \
yn: cos(v)*(sqrt(R*R-u*u)-r); \
zn: u-(r*u)/(sqrt(R*R-u*u)); \
xuu: -R*R*sin(v)/(sqrt((R*R-u*u)^3)); \
yuu: -R*R*cos(v)/(sqrt((R*R-u*u)^3)); \
zuu: 0; \
xuv: -u*cos(v)/(sqrt(R*R-u*u)); \
yuv: u*sin(v)/(sqrt(R*R-u*u)); \
zuv: 0; \
xvv: -sin(v)*(sqrt(R*R-u*u) - r); \
yvv: -cos(v)*(sqrt(R*R-u*u) - r); \
zvv: 0; ";
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