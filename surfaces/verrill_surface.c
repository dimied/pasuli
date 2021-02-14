
#include "verrill_surface.h"
#include "surfaces_c_includes.h"

#if (USE_VERRILL_SURFACE != 0)
void VerrillSurface(double u, double v,
					double *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(VERRILL_SURFACE)

	double cv2 = 2.0 * cos(v);
	double cv3 = (cos(3.0 * v) * -(2.0 * u * u * u)) / 3.0;
	double sv2 = 2.0 * sin(v);

	P_X(cv2 / u - cv2 + cv3);
	P_Y(3.0 * sv2 - sv2 / u + cv3);
	P_Z(4.0 * log(u));

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
PaSuLiDefDesc pslddVerrillSurface = {
	PSLDD_ID(VERRILL_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI,
	0.5, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descVerrillSurface =
	"name: Verrill Surface; \
ut:c; vt:c; \
us: 0.5; ue: 1; \
vs: 0; ve:pi: 2; \
x: -2*u*cos(v) + (2*cos(v)/u) - 2*u^(3)*cos(3*v)/3; \
y: 6*u*sin(v) - 2*sin(v)/u - 2*u^(3)*cos(3*v)/3; \
z: 4*log(u); \
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