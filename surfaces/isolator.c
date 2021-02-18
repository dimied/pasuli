
#include "isolator.h"
#include "surfaces_c_includes.h"

#if (USE_ISOLATOR != 0)
void Isolator(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ISOLATOR)

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double fx = a + b * sin(c * u * 2.0 * MY_PI);

	P_X(u);
	P_Y(fx * sin(v));
	P_Z(fx * cos(v));

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
PaSuLiDefDesc pslddIsolator = {
PSLDD_ID( ISOLATOR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
1.5f, 9.5f , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descIsolator =
	"name: Isolator; \
ut:c; vt:c; \
us: 1.5; ue:pi: 9.5; \
vs: 0; ve:pi: 2; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
x: u; \
y: (a + b*sin(c*u*2*pi))*sin(v); \
z: (a + b*sin(c*u*2*pi))*cos(v); \
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
";
#endif