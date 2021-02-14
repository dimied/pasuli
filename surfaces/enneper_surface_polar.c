
#include "enneper_surface_polar.h"
#include "surfaces_c_includes.h"

#if (USE_ENNEPER_SURFACE_POLAR != 0)

void EnneperSurfacePolar(pasuli_vartype u, pasuli_vartype v,
						 pasuli_consttype *constants,
						 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ENNEPER_SURFACE_POLAR)

	double cu = cos(u);
	double su = sin(u);

	double s = v * cu;
	double t = v * su;

	P_X(s * (1 + t * t - (s * s) / 3.0));
	P_Y(t * (1 + s * s - (t * t) / 3.0));
	P_Z(s * s - t * t);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
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
PaSuLiDefDesc pslddEnneperSurfacePolar = {
	PSLDD_ID(ENNEPER_SURFACE_POLAR)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI,
	0, 2, 0, 2.5f, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurfacePolar =
	"name: Enneper Surface Polar; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve: 2.5; \
a:1:s: v*cos(u); \
a:2:t: v*sin(u); \
x: s - s^(3)/3 + s*t*t; \
y: t - t^(3)/3 + t*s*s; \
z: s*s - t*t; \
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