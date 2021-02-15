
#include "jeener_klein_surface.h"
#include "surfaces_c_includes.h"

#if (USE_JEENER_KLEIN_SURFACE != 0)
void JeenerKleinSurface(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(JEENER_KLEIN_SURFACE)

	double a = constants[0];
	double S = constants[1];
	double T = constants[2];

	a = sqrt(a);

	double W = (S + 1) * 0.25 * cos((S + 1) * u + MY_PI / T) + a;
	double Scos_u = S * cos(u);
	double Ssin_u = S * sin(u);
	double cos_Su = cos(S * u);
	double sin_Su = sin(S * u);
	double W_cos = W * cos((S - 1) * u * 0.5);
	double W_sin = W * sin((S - 1) * u * 0.5);

	P_X(Scos_u + cos_Su - W_sin * cos(v));
	P_Y(W * sin(v));
	P_Z(Ssin_u - sin_Su - W_cos * cos(v));

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
PaSuLiDefDesc pslddJeenerKleinSurface = {
PSLDD_ID( JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descJeenerKleinSurface =
	"name: Jeener Klein Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:S: 1.5; c2:T: 0.5; c3:a: 1.0; \
a1:W: ((S + 1)/4)*cos((S + 1)*u +pi/T) + sqrt(a); \
x: S*cos(u) + cos(S*u) - W*sin((S - 1)*u/2)*cos(v); \
y: W*sin(v); \
z: S*sin(u) - sin(S*u) - W*cos((S - 1)*u/2)*cos(v); \
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