
#include "stiletto_surface.h"
#include "surfaces_c_includes.h"

#if (USE_STILETTO_SURFACE != 0)
void StilettoSurface(pasuli_vartype u, pasuli_vartype v,
					 pasuli_consttype *constants,
					 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(STILETTO_SURFACE)

	double cos_v = cos(v);
	double cossin_v2pi3 = cos(v + 2.0 * MY_PI / 3.0) * sin(v + 2.0 * MY_PI / 3.0);
	cossin_v2pi3 *= cossin_v2pi3;

	P_X((2.0 + cos(u)) * cos_v * cos_v * cos_v * sin(v));
	P_Y((2.0 + cos(u + 2.0 * MY_PI / 3.0)) * cossin_v2pi3);
	P_Z((-(2.0 + cos(u - 2.0 * MY_PI / 3.0))) * cossin_v2pi3);

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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddStilettoSurface = {
	PSLDD_ID(STILETTO_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
	0, 2, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descStilettoSurface =
	"name: Stiletto Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 1; \
x: (2+cos(u))*cos(v)*cos(v)*cos(v)*sin(v); \
y: (2+cos(u+2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
z: -(2+cos(u-2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
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
