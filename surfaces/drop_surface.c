
#include "drop_surface.h"
#include "surfaces_c_includes.h"

#if (USE_DROP_SURFACE != 0)
void DropSurface(double u, double v,
				 double *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(DROP_SURFACE)

	double a = constants[0];

	double sin_ua = sin(u - a);
	double cu = cos(u);

	P_X(cu * cos(v));
	P_Y(cu * sin(v));
	P_Z(sin_ua);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
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
PaSuLiDefDesc pslddDropSurface = {
PSLDD_ID( DROP_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5, 0.5 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descDropSurface =
	"name: Drop Surface; \
ut:c; vt:c; \
us:pi: -0.5; ue:pi: 0.5; \
vs: 0; ve:pi: 2; \
c1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: sin(u - a); \
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