
#include "piriform_surface.h"
#include "surfaces_c_includes.h"

#if (USE_PIRIFORM_SURFACE != 0)
void PiriformSurface(pasuli_vartype u, pasuli_vartype v,
					 pasuli_consttype *constants,
					 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PIRIFORM_SURFACE)

	double a = constants[0];
	double b = constants[1];
	double r = constants[2];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
	double xz = b * (v * (r + sv));

	P_X(xz * cu);
	P_Y(a * (r + sin(v)));
	P_Z(xz * su);

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
PaSuLiDefDesc pslddPiriformSurface = {
PSLDD_ID( PIRIFORM_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0, 2 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descPiriformSurface =
	"name:piriform Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs:pi: -0.5; ve:pi: 0.5; \
c1:a: 1.5; c2:b: 0.5; c3:r: 1.0; \
a1:c: (r + sin(v)); \
a2:d: b*(cos(v)*c; \
x: d*cos(u); \
y: d*sin(u); \
z: a*c; \
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