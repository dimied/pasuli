
#include "strangled_torus.h"
#include "torus_c_includes.h"

#if (USE_STRANGLED_TORUS != 0)
void StrangledTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(STRANGLED_TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype N = constants[2];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_nu_half = cos(N * u * 0.5);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = R + r * sin_v;

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Z(r * cos_v * cos_nu_half);

	pasuli_calctype sin_nu_half = sin(N * u * 0.5);

	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(-N * r * cos_v * sin_nu_half * 0.5);

	// Ignore scaling by r
	r = PASULI_CALC_SIGN(r);
	VD_X(r * cos_v * cos_u);
	VD_Y(r * cos_v * sin_u);
	VD_Z(-r * sin_v * cos_nu_half);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddStrangledTorus = {
	PSLDD_ID(STRANGLED_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(3),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descStrangledTorus =
	"name: Strangled Torus;\
cat: torus;\
ut: c; vt: c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
c1:R: 1; c2:r: 1; c3:n: 1;\
x: (R + r*sin(v))*cos(u);\
y: (R + r*sin(v))*sin(u);\
z: r*cos(v)*cos(n*u/2);\
xu: -(R + r*sin(v))*sin(u);\
yu: (R + r*sin(v))*cos(u);\
zu: -n*r*cos(v)*sin(n*u/2)/2;\
xv: r*cos(u)*cos(v);\
yv: r*sin(u)*cos(v);\
zv: -r*sin(v)*cos(n*u/2);";
#endif
