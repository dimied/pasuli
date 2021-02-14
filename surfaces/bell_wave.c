
#include "bell_wave.h"
#include "surfaces_c_includes.h"

#if (USE_BELL_WAVE != 0)
void BellWave(double u, double v,
			  double *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BELL_WAVE)

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double eav = (u * u + v * v);
	double seav = sqrt(eav);
	eav *= -a * a;

	P_X(u);
	P_Z(v);
	P_Y(cos(c * seav) * b * eav);

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
PaSuLiDefDesc pslddBellWave = {
PSLDD_ID( BELL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descBellWave =
"name: Bell Wave; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve: 12; \
c1:a: 1.5; c2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: cos(c*r)*b*exp(-(a*r)^(2)); \
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