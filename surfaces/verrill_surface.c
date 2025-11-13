
#include "verrill_surface.h"
#include "surfaces_c_includes.h"

#if (USE_VERRILL_SURFACE != 0)
void VerrillSurface(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(VERRILL_SURFACE)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_3v = cos(3.0 * v);
	pasuli_calctype u2 = u * u;
	pasuli_calctype u_pow3_2 = 2.0 * u * u2;
	pasuli_calctype common = u_pow3_2 * cos_3v / 3.0;

	P_X(-2 * u * cos_v + 2 * cos_v / u - common);
	P_Y(6 * u * sin_v - 2 * sin_v / u - common);
	P_Z(4.0 * log(u));

	common = u2 * cos_3v;
	// Multiply by u^2 and divide by 2
	UD_X(u2 * (-common - cos_v) - cos_v);
	UD_Y(u2 * (-common + 3 * sin_v) + sin_v);
	UD_Z(4 * u);

	common = u_pow3_2 * sin(3 * v);
	// Multiply by u
	VD_X(u * (common + 2 * sin_v) - 2 * sin_v);
	VD_Y(u * (common + 6 * cos_v) - 2 * cos_v);
	VD_Z(0);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddVerrillSurface = {
	VERRILL_SURFACE,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI,
	0.5, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descVerrillSurface =
	"name: Verrill Surface;\
ut:c; vt:c;\
us: 0.5; ue: 1;\
vs:0; ve:pi:2;\
x: -2*u*cos(v) + (2*cos(v)/u) - 2*u^(3)*cos(3*v)/3;\
y: 6*u*sin(v) - 2*sin(v)/u - 2*u^(3)*cos(3*v)/3;\
z: 4*log(u);\
xu: -2*u^2*cos(3*v) - 2*cos(v)/u^2 - 2*cos(v);\
yu: -2*u^2*cos(3*v) + 2*sin(v)/u^2 + 6*sin(v);\
zu: 4/u;\
xv: 2*u^3*sin(3*v) + 2*u*sin(v) - 2*sin(v)/u;\
yv: 2*u^3*sin(3*v) + 6*u*cos(v) - 2*cos(v)/u;\
zv: 0;";
#endif