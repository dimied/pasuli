
#include "bonan_jeener_klein_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BONAN_JEENER_KLEIN_SURFACE != 0)

void BonanJeenerKleinSurface(double u, double v,
							 double *constants,
							 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BONAN_JEENER_KLEIN_SURFACE)

	double M = constants[0];
	double T = constants[1];
	double cv = cos(v);
	double sv = sin(v);

	double W = sin((M - 1) * u) + T;
	double M_cos_u_Mu = M * cos(u) - cos(M * u);
	double M_sin_u_Mu = M * sin(u) - sin(M * u);
	u = (M + 1) * u * 0.5;
	double MMW_sin_u2 = (((M - 1) * W) / M) * sin(u);
	u = (((M - 1) * W) / M) * cos(u);

	P_Y(W * sv);
	P_X(M_cos_u_Mu - cv * MMW_sin_u2);
	P_Z(M_sin_u_Mu - cv * u);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
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
PaSuLiDefDesc pslddBonanJeenerKleinSurface = {
PSLDD_ID( BONAN_JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBonanJeenerKleinSurface =
	"name: Bonan Jeener Klein Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:M: 1.5; c2:T: 0.5; \
a:1:W: sin((M - 1)*u) + T; \
x: M*cos(u) - cos(M*u) - ((M - 1)/M)*W*sin((M + 1)*u/2)*cos(v); \
y: W*sin(v); \
z: M*sin(u) - sin(M*u) + ((M - 1)/M)*W*cos((M + 1)*u/2)*cos(v); \
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
