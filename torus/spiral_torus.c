#include "spiral_torus.h"
#include "torus_c_includes.h"

#if (USE_SPIRAL_TORUS != 0)

void SpiralTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPIRAL_TORUS)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R2 = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_Nu = cos(N * u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_Nu = sin(N * u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = R1 + R2 * cos_Nu + r * cos_v;

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Y(r * sin_v + R2 * sin_Nu);

	factor = r * cos_v + R1 + R2 * cos_Nu;
	pasuli_calctype ud_factor = N * R2 * sin_Nu;
	UD_X(-ud_factor * cos_u - sin_u * factor);
	UD_Y(-ud_factor * sin_u + cos_u * factor);
	UD_Z(N * R2 * cos_Nu);

	// Ignore scaling by r
	r = PASULI_CALC_SIGN(r);
	VD_X(-r * sin_v * cos_u);
	VD_Y(-r * sin_v * sin_u);
	VD_Z(r * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddSpiralTorus = {
	PSLDD_ID(SPIRAL_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(3),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descSpiralTorus =
	"name: Spiral Torus;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R1:1; c2:R2:1; c3:r:1;\
a1:F: R1+R2*cos(N*u)+r*cos(v);\
x: F*cos(u);\
y: F*sin(u);\
z: r*sin(v)+R2*sin(N*u);\
xu: -N*R2*cos(u)*sin(N*u) - sin(u)*(r*cos(v)+R1+R2*cos(N*u));\
yu: -N*R2*sin(u)*sin(N*u) + cos(u)*(r*cos(v)+R1+R2*cos(N*u));\
zu: N*R2*cos(N*u);\
xv: -r*cos(u)*sin(v);\
yv: -r*sin(u)*sin(v);\
zv: r*cos(v);";
#endif