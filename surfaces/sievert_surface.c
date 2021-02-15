
#include "sievert_surface.h"
#include "surfaces_c_includes.h"

#if (USE_SIEVERT_SURFACE != 0)

void SievertSurface(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(SIEVERT_SURFACE)

    double C = constants[0];
    double sqrtC = sqrt(C);
    double sqrtC1 = sqrt(C + 1);

    double r_u = sin(u);
    r_u = sqrt((C + 1) * (1 + C * r_u * r_u)) / sqrtC;
    double sin_p = -u / (sqrtC1) + atan(sqrtC1 * tan(u));
    double cos_p = cos(sin_p);
    sin_p = sin(sin_p);
    u = cos(u);
    u *= u;

    double sin_v = sin(v);
    double a = 2.0 / (C + 1 - C * sin_v * sin_v * u);
    sin_v = sin(v) * r_u * a;

    P_X(sin_v * cos_p);
    P_Y(sin_v * sin_p);
    P_Z((log(tan(v * 0.5)) + a * (C + 1) * cos(v)) / sqrtC);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
    double cu = cos(u);
    double su = sin(u);
    double cv = cos(v);
    double sv = sin(v);
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
    "name: Sievert Surface; \
ut:c; vt:c; \
us:pi: -0.5; ue:pi: 0.5; \
vs: 0.1; ve:pi: 3; \
c1:C: 1.5; \
a1:p: -u/sqrt(C + 1) + atan(tan(u)*sqrt(C + 1)); \
a2:a: 2/(C + 1 - C*sin(v)*sin(v)*cos(u)*cos(u)); \
a3:r: a*sqrt((C + 1)*(1 + C*sin(u)*sin(u)))*sin(v)/sqrt(C); \
x: r*cos(p); \
y: r*sin(p); \
z: (ln(tan(v/2)) + a*(C + 1)*cos(v))/sqrt(C); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif