
#include "pseudodevelopable_helicoid.h"
#include "surfaces_c_includes.h"

#if (USE_PSEUDODEVELOPABLE_HELICOID != 0)
void PseudodevelopableHelicoid(pasuli_vartype u,
                               pasuli_vartype v,
                               pasuli_consttype *constants,
                               PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PSEUDODEVELOPABLE_HELICOID)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];

    pasuli_calctype cos_v = cos(v);
    pasuli_calctype sin_v = sin(v);

    P_X(a * cos_v - u * sin_v);
    P_Y(a * sin_v + u * cos_v);
    P_Z(b * v);

    UD_X(-sin_v);
    UD_Y(cos_v);
    UD_Z(0);

    VD_X(-a * sin_v - u * cos_v);
    VD_Y(a * cos_v - u * sin_v);
    VD_Z(b);

    N_X(b * cos_v);
    N_Y(b * sin_v);
    N_Z(u);
}
#endif

#if (COMPILE_DESC_SURFACES != 0)
char *descPseudodevelopableHelicoid =
    "name: Pseudodevelopable Helicoid;\
ut:c; vt:o;\
us:-1.5; ue:0;\
vs:0; ve:pi:4;\
c1:a: 1; c2:b: 1;\
x: a*cos(v)-u*sin(v);\
y: a*sin(v)+u*cos(v);\
z: b*v;\
xu: -sin(v);\
yu: cos(v);\
zu: 0;\
xv: -a*sin(v)-u*cos(v);\
yv: a*cos(v)-u*sin(v);\
zv: b;\
xn: b*cos(v);\
yn: b*sin(v);\
zn: u;";
#endif
