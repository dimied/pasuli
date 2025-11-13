
#include "sievert_surface.h"
#include "surfaces_c_includes.h"

#if (USE_SIEVERT_SURFACE != 0)

void SievertSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SIEVERT_SURFACE)

    pasuli_consttype C = constants[0];
    pasuli_calctype sqrt_C = sqrt(C);
    pasuli_calctype sqrt_Cplus1 = sqrt(C + 1);

    pasuli_calctype p = -u / (sqrt_Cplus1) + atan(sqrt_Cplus1 * tan(u));

    pasuli_calctype cos_u = cos(u);
    pasuli_calctype sin_v = sin(v);
    pasuli_calctype a = 2.0 / (C + 1 - C * sin_v * sin_v * cos_u * cos_u);

    pasuli_calctype sin_u = sin(u);
    pasuli_calctype r = a * sqrt((C + 1) * (1 + C * sin_u * sin_u)) * sin_v / sqrt_C;

    P_X(r * cos(p));
    P_Y(r * sin(p));
    P_Z((log(tan(v * 0.5)) + a * (C + 1) * cos(v)) / sqrt_C);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSievertSurface = {
PSLDD_ID( SIEVERT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f , 0.5f , 0.1f , 3 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descSievertSurface =
    "name: Sievert Surface;\
ut:c; vt:c;\
us:pi: -0.5; ue:pi: 0.5;\
vs: 0.1; ve:pi: 3;\
c1:C: 1.5;\
a1:p: -u/sqrt(C + 1) + atan(tan(u)*sqrt(C + 1));\
a2:a: 2/(C + 1 - C*sin(v)*sin(v)*cos(u)*cos(u));\
a3:r: a*sqrt((C + 1)*(1 + C*sin(u)*sin(u)))*sin(v)/sqrt(C);\
x: r*cos(p);\
y: r*sin(p);\
z: (ln(tan(v/2)) + a*(C + 1)*cos(v))/sqrt(C);";
#endif