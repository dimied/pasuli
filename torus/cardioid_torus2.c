
#include "cardioid_torus2.h"
#include "torus_c_includes.h"

#if (USE_CARDIOID_TORUS_2 != 0)

void CardioidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CARDIOID_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_2v = cos(2.0 * v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_2v = sin(2 * v);

	pasuli_calctype factor = R + r * (2 * sin_v - sin_2v);

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(r * (2.0 * cos_v - cos_2v));

	factor = PASULI_CALC_SIGN(factor);
	// Ignore scaling by (R + r*(2*sin(v) - sin(2*v)))
	UD_X(-factor * sin_u);
	UD_Y(-factor * cos_u);
	UD_Z(0);

	factor = cos_v - cos_2v;
	// Ignore scaling by 2*r
	pasuli_calctype sign_value = PASULI_CALC_SIGN(r);
	VD_X(sign_value * factor * cos_u);
	VD_Y(sign_value * factor * sin_u);
	VD_Z(sign_value * (sin_2v - sin_v));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCardioidTorus2 = {
	CARDIOID_TORUS_2,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descCardioidTorus2 =
	"name: Cardioid Torus 2;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1; c2:r: 1;\
x: (R + r*(2*sin(v) - sin(2*v)))*cos(u);\
y: (R + r*(2*sin(v) - sin(2*v)))*sin(u);\
z: r*(2*cos(v) - cos(2*v));\
xu: -(R + r*(2*sin(v) - sin(2*v)))*sin(u);\
yu: (R + r*(2*sin(v) - sin(2*v)))*cos(u);\
zu: 0;\
xv: 2*r*cos(u)*(cos(v) - cos(2*v));\
yv: 2*r*sin(u)*(cos(v) - cos(2*v));\
zv: -2*r*(sin(v) - sin(2*v));";
#endif
