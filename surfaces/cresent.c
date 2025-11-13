
#include "cresent.h"
#include "surfaces_c_includes.h"

#if (USE_CRESENT != 0)
void Cresent(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants, PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(CRESENT)

    pasuli_consttype a = constants[0];
    pasuli_consttype b = constants[1];
    pasuli_consttype c = constants[2];

    pasuli_calctype cos_bu = cos(b * u);
    pasuli_calctype sin_bu = sin(b * u);

    pasuli_calctype sin_bv = sin(b * v);
    pasuli_calctype cos_cv = cos(c * v);
    pasuli_calctype sin_cv = sin(c * v);

    pasuli_calctype a_sinsin = a + sin_bu * sin_bv;

    P_X(a_sinsin * sin_cv);
    P_Y(a_sinsin * cos_cv);
    P_Z(cos_bu * sin_bv + v * 4.0 / MY_PI - 2.0);

    UD_X(b * cos_bu * sin_bv * sin_cv);
    UD_Y(b * cos_bu * sin_bv * cos_cv);
    UD_Z(-b * sin_bu * sin_bv);

    pasuli_calctype cos_bv = cos(b * v);

    VD_X(a * c * cos_cv + b * cos_bv * sin_bu * sin_cv + c * cos_cv * sin_bu * sin_bv);
    VD_Y(b * cos_bv * sin_bu * cos_cv - a * c * sin_cv - c * sin_cv * sin_bu * sin_bv);
    VD_Z(b * cos_bu * cos_bv + 4 / MY_PI);

    PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCresent = {
    CRESENT,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_CONST_COUNT(3),
    0, 1, 0, 1, psldd_15_05_constants};
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descCresent =
    "name: Cresent;\
ut:c; vt:c;\
us:0; ue:pi:1;\
vs:0; ve:pi:1;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: (a + sin(b*u)*sin(b*v))*sin(c*v);\
y: (a + sin(b*u)*sin(b*v))*cos(c*v);\
z: cos(b*u)*sin(b*v) + 4*v/pi - 2;\
xu: b*cos(b*u)*sin(b*v)*sin(c*v);\
yu: b*cos(b*u)*sin(b*v)*cos(c*v);\
zu: -b*sin(b*u)*sin(b*v);\
xv: a*c*cos(c*v) + b*cos(b*v)*sin(b*u)*sin(c*v) + c*cos(c*v)*sin(b*u)*sin(b*v);\
yv: -a*c*sin(c*v) + b*cos(b*v)*sin(b*u)*cos(c*v) -  c*sin(c*v)*sin(b*u)*sin(b*v);\
zv: b*cos(b*u)*cos(b*v) + 4/PI; ";
#endif