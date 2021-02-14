
#include "guimard_surface.h"
#include "surfaces_c_includes.h"

#if (USE_GUIMARD_SURFACE != 0)
void GuimardSurface(double u, double v,
					double *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(GUIMARD_SURFACE)

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double cv = cos(v);
	double sv = sin(v);

	P_X(((1 - u) * a + b * u) * cv);
	P_Y(b * u * sv);
	P_Z(c * u * sv * sv);

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
PaSuLiDefDesc pslddGuimardSurface = {
PSLDD_ID( GUIMARD_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descGuimardSurface =
	"name: Guimard Surface; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs: -1; ve: 1; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
x: ((1 - u)*a + u*b)*cos(v); \
y: b*u*sin(v); \
z: c*u*sin(v)*sin(v); \
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
