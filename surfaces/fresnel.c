
#include "fresnel.h"
#include "surfaces_c_includes.h"

#if (USE_FRESNEL != 0)
void Fresnel(double u, double v,
             double *constants,
             PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(FRESNEL)

    double a = constants[0];
    double b = constants[1];
    double c = constants[2];
    double csq = c * c;
    double cca = csq / a;
    double ccb = csq / b;
    double cos_u_sq;
    double sin_u;
    double divisor;
    a *= a;
    b *= b;

    cos_u_sq = cos(u);
    cos_u_sq *= cos_u_sq;
    sin_u = sin(u) * ccb;
    u = cos_u_sq / a + (1 - cos_u_sq) / b;
    cos_u_sq *= cca;

    divisor = sin(v);
    divisor *= divisor;
    divisor += csq * (1 - divisor) * u;

    P_X(cos_u_sq / divisor);
    P_Y((sin_u * cos(v)) / divisor);
    P_Z((c * sin(v)) / divisor);

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
PaSuLiDefDesc pslddFresnel = {
PSLDD_ID( FRESNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-1, 1 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descFresnel =
"name: Fresnel; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -0.5; ve:pi: 0.5; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
a:1:d: (sin(v)^(2)+c*c*cos(v)^(2)*(cos(u)^(2)/a*a + sin(u)^(2)/b*b)); \
x: (c*c/a)*(cos(u)^(2))/d; \
y: (c*c/b)*(sin(u)*cos(v))/d; \
z: c*(sin(v))/d; \
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