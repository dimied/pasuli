
#include "stiletto_surface.h"
#include "surfaces_c_includes.h"

#if (USE_STILETTO_SURFACE != 0)
void StilettoSurface(pasuli_vartype u, pasuli_vartype v,
					 pasuli_consttype *constants,
					 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(STILETTO_SURFACE)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_u = cos(u);

	pasuli_calctype cos_v2 = cos(v + 2.0 * MY_PI / 3.0);
	pasuli_calctype sin_v2 = sin(v + 2.0 * MY_PI / 3.0);

	pasuli_calctype cossin_v2pi3 = cos_v2 * sin_v2;
	cossin_v2pi3 *= cossin_v2pi3;

	P_X((2.0 + cos_u) * cos_v * cos_v * cos_v * sin_v);
	P_Y((2.0 + cos(u + 2.0 * MY_PI / 3.0)) * cossin_v2pi3);
	P_Z(-(2.0 + cos(u - 2.0 * MY_PI / 3.0)) * cossin_v2pi3);

	pasuli_calctype sin_u = sin(u);

	pasuli_calctype cos_v6 = cos(u + MY_PI / 6);
	pasuli_calctype sin_v6 = sin(u + MY_PI / 6);
	pasuli_calctype factor = cos_v2 * cos_v2 * sin_v2 * sin_v2;

	UD_X(-cos_v * cos_v * cos_v * sin_u * sin_v);
	UD_Y(-factor * cos_v6);
	UD_Z(-factor * sin_v6);

	factor = (-cos(2 * v) + sqrt(3) * sin(2 * v)) * cos_v6 * sin_v6;
	VD_X(-cos_v * cos_v * (-1 + 4 * sin_v * sin_v) * (2 + cos_u));
	VD_Y((2.0 + cos(u + 2.0 * MY_PI / 3.0)));
	VD_Z(-(2.0 + cos(u - 2.0 * MY_PI / 3.0)));

	PASULI_CALC_NORMAL_FROM_UD_VD
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
xu: -cos(v)^3*sin(u)*sin(v); \
yu: -cos(v+pi/6)^2*sin(v+pi/6)^2*cos(u+pi/6); \
zu: -cos(v+pi/6)^2*sin(v+pi/6)^2*sin(u+pi/3); \
xv: -cos(v)^2*(-1+4*sin(v)^2)*(2+cos(u)); \
yv: (sin(u + pi/6)-2)*(-cos(2*v) + sqrt(3)*sin(2*v))*cos(v+pi/6)*sin(v+pi/6); \
zv: -(cos(u+pi/3) - 2)*(-cos(2*v) + sqrt(3)*sin(2*v))*cos(v+pi/6)*sin(v+pi/6);";
#endif
