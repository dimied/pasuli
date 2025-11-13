
#include "hyperboloid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_HYPERBOLOID != 0)
void Hyperboloid(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(HYPERBOLOID)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];

    pasuli_calctype cosh_v = cosh(v);
    pasuli_calctype sinh_v = sinh(v);
    pasuli_calctype cos_u = cos(u);
    pasuli_calctype a_cos_u = a * cos_u;
    pasuli_calctype sin_u = sin(u);
    pasuli_calctype a_sin_u = a * sin_u;

    P_X(a_cos_u * cosh_v);
    P_Y(a_sin_u * cosh_v);
    P_Z(b * sinh_v);

    UD_X(-PASULI_COND_COPY_POS_Y(a_sin_u * cosh_v));
    UD_Y(PASULI_COND_COPY_POS_X(a_cos_u * cosh_v));
    UD_Z_CONST(0);

    VD_X(a_cos_u * sinh_v);
    VD_Y(a_sin_u * sinh_v);
    VD_Z(b * cosh_v);

    pasuli_calctype common_factor = (a * cosh_v < 0) ? -1 : 1;
    N_X(common_factor * b * cos_u * cosh_v);
    N_Y(common_factor * b * sin_u * cosh_v);
    N_Z(-a * sinh_v);

    UUD_X(-PASULI_COND_COPY_POS_X(a_cos_u * cosh_v));
    UUD_Y(-PASULI_COND_COPY_POS_Y(a_sin_u * cosh_v));
    UUD_Z_CONST(0);

    common_factor = (a * sinh_v < 0) ? -1 : 1;
    UVD_X(-sin_u);
    UVD_Y(cos_u);
    UVD_Z_CONST(0);

    VVD_X(PASULI_COND_COPY_POS_X(a_cos_u * cosh_v));
    VVD_Y(PASULI_COND_COPY_POS_Y(a_sin_u * cosh_v));
    VVD_Z(PASULI_COND_COPY_POS_Z(b * sinh_v));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperboloid = {
PSLDD_ID( HYPERBOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descHyperboloid =
    "name: Hyperboloid;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs: -2; ve: 2;\
c1:a: 1.5; c2:b: 0.5;\
x: a*cosh(v)*cos(u);\
y: a*cosh(v)*sin(u);\
z: b*sinh(v);\
xu: -a*cosh(v)*sin(u);\
yu: a*cos(u)*cosh(v);\
zu: 0;\
xv: a*cos(u)*sinh(v);\
yv: a*sin(u)*sinh(v);\
zv: b*cosh(v);\
xn: a*b*cos(u)*cosh(v)*cosh(v);\
yn: a*b*sin(u)*cosh(v)*cosh(v);\
zn: -a*a*cosh(v)*sinh(v);\
xuu: -a*cos(u)*cosh(v);\
yuu: -a*sin(u)*cosh(v);\
zuu: 0;\
xuv: -a*sin(u)*sinh(v);\
yuv: a*cos(u)*sinh(v);\
zuv: 0;\
xvv: a*cos(u)*cosh(v);\
yvv: a*sin(u)*cosh(v);\
zvv: b*sinh(v);";
#endif