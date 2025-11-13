
#include "bicorn_torus1.h"
#include "torus_c_includes.h"

#if (USE_BICORN_TORUS_1 != 0)
void BicornTorus1(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BICORN_TORUS_1)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype factor = R + r * cos_v * cos_v * (2 + cos_v) / (3 + sin_v * sin_v);

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Z(r * sin_v);

	pasuli_calctype sign_value = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	pasuli_calctype divisor = (3 + sin_v * sin_v);
	divisor *= divisor;

	factor = (16 - cos(3 * v) * 0.25 + 45 * cos_v * 0.25) * cos_v * sin_v;
	// Ignore r
	sign_value = PASULI_CALC_SIGN(r);
	VD_X(-sign_value * factor * cos_u / divisor);
	VD_Y(-sign_value * factor * sin_u / divisor);
	VD_Z(sign_value * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddBicornTorus1 = {
	BICORN_TORUS_1,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descBicornTorus1 =
	"name: Bicorn Torus 1;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1; c2:r: 1;\
x: (R + r*cos(v)^2*(2 + cos(v))/(3 + sin(v)^2))*cos(u);\
y: (R + r*cos(v)^2*(2 + cos(v))/(3 + sin(v)^2))*sin(u);\
z: r*sin(v);\
xu: -(R + r*cos(v)^2*(2 + cos(v))/(3 + sin(v)^2))*sin(u);\
yu: (R + r*cos(v)^2*(2 + cos(v))/(3 + sin(v)^2))*cos(u);\
zu: 0;\
xv: r*(16 - cos(3*v)/4 + 45*cos(v)/4)*cos(v)*sin(v)*cos(u)/(3+sin(v)^2)^2;\
yv: r*(16 - cos(3*v)/4 + 45*cos(v)/4)*cos(v)*sin(v)*sin(u)/(3+sin(v)^2)^2;\
zv: r*cos(v);";
#endif
