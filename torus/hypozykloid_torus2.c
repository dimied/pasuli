
#include "hypozykloid_torus2.h"
#include "torus_c_includes.h"

#if (USE_HYPOZYKLOID_TORUS_2 != 0)
void HypozykloidTorus2(pasuli_vartype u,
					   pasuli_vartype v,
					   pasuli_consttype *constants,
					   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPOZYKLOID_TORUS_2)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype h = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype R_minus_r = R - r;
	pasuli_calctype R_plus_r = R - r;

	pasuli_calctype factor = R1 + R_minus_r * sin_v - h * sin(R_minus_r * v / r);

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(R_minus_r * cos_v - h * cos(R_plus_r * v / r));

	// Ignore scaling by (R1 + (R - r)*sin(v) - h*sin(((R - r)/r)*v))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	factor = R_minus_r * cos_v - h * R_minus_r * cos(R_minus_r * v / r) / r;

	VD_X(cos_u * factor);
	VD_Y(sin_u * factor);
	VD_Z(-R_minus_r * sin_v + h * R_minus_r * sin(R_plus_r * v / r) / r);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddHypozykloidTorus2 = {
	HYPOZYKLOID_TORUS_2,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descHypozykloidTorus2 =
	"name: Hypozykloid Torus 2;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R1:1; c2:R: 1; c3:r:0.5; c4:h: 1;\
a1:F: (R1 + (R - r)*sin(v) - h*sin(((R - r)/r)*v));\
x: F*cos(u);\
y: F*sin(u);\
z: (R - r)*cos(v) - h*cos(((R + r)/r)*v);\
xu: -(R1 + (R - r)*sin(v) - h*sin(((R - r)/r)*v))*sin(u);\
yu: (R1 + (R - r)*sin(v) - h*sin(((R - r)/r)*v))*cos(u);\
zu: 0;\
xv: cos(u)*(-h*((R - r)/r)*cos(((R - r)/r)*v)+(R-r)*cos(v));\
yv: sin(u)*(-h*((R - r)/r)*cos(((R - r)/r)*v)+(R-r)*cos(v));\
zv: -(R - r)*sin(v) + h*(1 + R/r)*sin(((R + r)/r)*v);";
#endif
