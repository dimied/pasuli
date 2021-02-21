
#include "hole_discus.h"
#include "surfaces_c_includes.h"

#if (USE_HOLE_DISCUS != 0)
void HoleDiscus(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HOLE_DISCUS)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_v_plus_a = sin_v + a;
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_u = sin(u);

    P_X(sin_u / sin_v_plus_a);
    P_Y(cos_u / sin_v_plus_a);
    P_Z(cos_v / b);

    // Skip division by (a + sin(v))
    UD_X(cos_u);
    UD_Y(-sin_u);
    UD_Z(0);

    pasuli_calctype divisor = sin_v_plus_a * sin_v_plus_a;
    VD_X(-sin_u * cos_v / divisor);
    VD_Y(-cos_u * cos_v / divisor);
    VD_Z(-sin_v / b);

    // Skip division by (a + sin(v))
    N_X(sin_u * sin_v / b);
    N_Y(cos_u * sin_v / b);
    N_Z(-cos_v / divisor);

    // Skip division by (a + sin(v))
    UUD_X(-sin_u);
    UUD_Y(-cos_u);
    UUD_Z(0);

    // Skip division by (a + sin(v))^2
    UVD_X(-cos_u * cos_v);
    UVD_Y(sin_u * cos_v);
    UVD_Z(0);

    pasuli_calctype uud_factor = (1 + cos_v * cos_v + a * sin_v);

    VVD_X(sin_u * uud_factor / (divisor * sin_v_plus_a));
    VVD_Y(cos_u * uud_factor / (divisor * sin_v_plus_a));
    VVD_Z(-cos_v / b);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDiscus = {
PSLDD_ID( HOLE_DISCUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descHoleDiscus =
    "name: Hole Discus;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
c1:a: 1.5; c2:b: 0.5;\
x: sin(u)/(a + sin(v));\
y: cos(u)/(a + sin(v));\
z: cos(v)/b;\
xu: cos(u)/(a + sin(v));\
yu: -sin(u)/(a + sin(v));\
zu: 0;\
xv: -sin(u)*cos(v)/(a + sin(v))^2;\
yv: -cos(u)*cos(v)/(a + sin(v))^2;\
zv: -sin(v)/b;\
xn: sin(u)*sin(v)/(b*(a+sin(v)));\
yn: cos(u)*sin(v)/(b*(a+sin(v)));\
zn: -cos(v)/((a+sin(v))^3);\
xuu: -sin(u)/(a + sin(v));\
yuu: -cos(u)/(a + sin(v));\
zuu: 0;\
xuv: -cos(u)*cos(v)/(a + sin(v))^2;\
yuv: sin(u)*cos(v)/(a + sin(v))^2;\
zuv: 0;\
xvv: sin(u)*(1 + cos(v)^2 + a*sin(v))/(a + sin(v))^3;\
yvv: cos(u)*(1 + cos(v)^2 + a*sin(v))/(a + sin(v))^3;\
zvv: -cos(v)/b; ";
#endif