
#include "bohemian_dome_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BOHEMIAN_DOME_SURFACE != 0)

void BohemianDomeSurface(pasuli_vartype u, pasuli_vartype v,
                         pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BOHEMIAN_DOME_SURFACE)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(a * cos_u);
    P_Y(b * cos_v + a * sin_u);
    P_Z(c * sin_v);

    UD_X(-a * sin_u);
    UD_Y(a * cos_u);
    UD_Z_CONST(0);

    VD_X_CONST(0);
    VD_Y(-b * sin_v);
    VD_Z(c * cos_v);

    N_X(a * c * cos_u * cos_v);
    N_Y(a * c * sin_u * cos_v);
    N_Z(a * b * sin_u * sin_v);
    
    UUD_X(-PASULI_COND_COPY_POS_X(a * cos_u));
    UUD_Y(-a * sin_u);
    UUD_Z_CONST(0);

    UVD_ALL(0);

    VVD_X_CONST(0);
    VVD_Y(-b * cos_v);
    VVD_Z(-PASULI_COND_COPY_POS_Z(c * sin_v));
}

#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBohemianDomeSurface = {
    BOHEMIAN_DOME_SURFACE,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI |
        PASULI_FULL_IMPL | PASULI_CONST_COUNT(3),
    0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descBohemianDomeSurface =
    "name: Bohemian Dome Surface;\
ut:c; vt:c;\
us:0; ue:pi:2; vs:0; ve:pi:2;\
c1:a:1; c2:b:1; c3:c:1;\
x: a*cos(u);\
y: b*cos(v) + a*sin(u);\
z: c*sin(v);\
xu: -a*sin(u);\
yu: a*cos(u);\
zu: 0;\
xv: 0;\
yv: -b*sin(v);\
zv: c*cos(v);\
xn: a*c*cos(u)*cos(v);\
yn: a*c*sin(u)*cos(v);\
zn: a*b*sin(u)*sin(v);\
xuu: -a*cos(u);\
yuu: -a*sin(u);\
zuu: 0;\
xuv: 0; yuv: 0; zuv: 0;\
xvv: 0;\
yvv: -b*cos(v);\
zvv: -c*sin(v);";
#endif