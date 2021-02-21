
#include "bicorn_torus2.h"
#include "torus_c_includes.h"

#if (USE_BICORN_TORUS_2 != 0)
void BicornTorus2(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BICORN_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype factor = R + r * sin(v);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype divisor = (3 + sin_v * sin_v);

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(r * cos_v * cos_v * (2 + cos_v) / divisor);

	// Ignore scaling by R + r * sin(v)
	pasuli_calctype sign_value = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	// Ignore scaling by r*cos(v)
	sign_value = PASULI_CALC_SIGN(r * cos_v);
	VD_X(sign_value * cos_u);
	VD_Y(sign_value * sin_u);
	VD_Z(-sign_value * (16 - cos(3 * v) * 0.25 + 45 * cos_v * 0.25) * sin_v / (divisor * divisor));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddBicornTorus2 = {
	PSLDD_ID(BICORN_TORUS_2)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descBicornTorus2 =
	"name: Bicorn Torus 2;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R:1; c2:r: 1;\
x: (R + r*sin(v))*cos(u);\
y: (R + r*sin(v))*sin(u);\
z: r*cos(v)^2*(2 + cos(v))/(3 + sin(v)^2);\
xu: -(R + r*sin(v))*sin(u);\
yu: (R + r*sin(v))*cos(u);\
zu: 0;\
xv: r*cos(u)*cos(v);\
yv: r*sin(u)*cos(v);\
zv: -r*(16 - cos(3*v)/4 + 45*cos(v)/4)*cos(v)*sin(v)/(3 + sin(v)^2)^2;";
#endif