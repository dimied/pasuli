
#include "pluecker_conoid2.h"
#include "surfaces_c_includes.h"

#if (USE_PLUECKER_CONOID2 != 0)
void PlueckerConoid2(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PLUECKER_CONOID2)

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype sin_2v = sin(v);

    P_X(u * cos_v);
    P_Y(u * sin_v);
    P_Z(sin_2v);

    UD_X(cos_v);
    UD_Y(sin_v);
    UD_Z(0);

    pasuli_calctype cos_2v = cos(2 * v);
    VD_X(-u * sin_v);
    VD_Y(u * cos_v);
    VD_Z(2 * cos_2v);

    N_X(2 * cos_2v * sin_v);
    N_Y(-2 * cos_2v * cos_v);
    N_Z(u);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPlueckerConoid2 =
    "name: Pluecker's Conoid 2;\
ut:u; vt:c;\
us:0; ue:2;\
vs:0; ve:pi:2;\
x: u*cos(v);\
y: u*sin(v);\
z: sin(2*v);\
xu: cos(v);\
yu: sin(v);\
zu: 0;\
xv: -u*sin(v);\
yv: u*cos(v);\
zv: 2*cos(2*v);\
xn: 2*cos(2*v)*sin(v);\
yn: -2*cos(2*v)*cos(v);\
zn: u;";
#endif
