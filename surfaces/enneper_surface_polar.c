
#include "enneper_surface_polar.h"
#include "surfaces_c_includes.h"

#if (USE_ENNEPER_SURFACE_POLAR != 0)

void EnneperSurfacePolar(pasuli_vartype u, pasuli_vartype v,
						 pasuli_consttype *constants,
						 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ENNEPER_SURFACE_POLAR)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype s = v * cos_u;
	pasuli_calctype t = v * sin_u;

	P_X(s * (1 + t * t - (s * s) / 3.0));
	P_Y(t * (1 + s * s - (t * t) / 3.0));
	P_Z(s * s - t * t);

	pasuli_calctype cos_3u = cos(3 * u);
	pasuli_calctype sin_3u = sin(3 * u);

	UD_X(v * (v * v * sin_3u - sin_u));
	UD_Y(v * (v * v * cos_3u + cos_u));
	UD_Z(-2 * v * v * sin(2 * u));

	VD_X(-v * v * cos_3u + cos_u);
	VD_Y(v * v * sin_3u + sin_u);
	VD_Z(2 * v * cos(2 * u));

	PASULI_CALC_NORMAL_FROM_UD_VD
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
a1:s: v*cos(u); \
a2:t: v*sin(u); \
x: s - s^(3)/3 + s*t*t; \
y: t - t^(3)/3 + t*s*s; \
z: s*s - t*t; \
xu: v*(v*v*sin(3*u) - sin(u)); \
yu: v*(v*v*cos(3*u) + cos(u)); \
zu: -2*v^2*sin(2*u); \
xv: -v^2*cos(3*u) + cos(u); \
yv: v^2*sin(3*u) + sin(u); \
zv: 2*v*cos(2*u);";
#endif