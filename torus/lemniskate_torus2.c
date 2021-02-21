
#include "lemniskate_torus2.h"
#include "torus_c_includes.h"

#if (USE_LEMNISKATE_TORUS_2 != 0)
void LemniskateTorus2(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LEMNISKATE_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u);
	pasuli_vartype cos_v = cos(v);
	pasuli_vartype sin_v = sin(v);

	pasuli_calctype factor = sin_v * sin_v + 1;

	P_Z(r * cos_v / factor);
	factor = R + r * cos_v * sin_v / factor;

	P_X(cos_u * factor);
	P_Y(sin_u * factor);

	// Ignore scaling by (R + r*sin(v)*cos(v)/(1 + sin(v)*sin(v)))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	// Scale by (1+sin(v)^2)^2
	// Ignore scaling by r
	r = PASULI_CALC_SIGN(r);
	factor = 3 * sin_v * sin_v - 1;
	VD_X(-r * cos_u * factor);
	VD_Y(-r * sin_u * factor);
	VD_Z(-r * (2 + cos_v * cos_v));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLemniskateTorus2 = {
PSLDD_ID(LEMNISKATE_TORUS_2)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descLemniskateTorus2 =
	"name: Lemniskate Torus 2;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R:1.5; c2:r:0.5;\
x: (R + r*sin(v)*cos(v)/(1 + sin(v)*sin(v)))*cos(u);\
y: (R + r*sin(v)*cos(v)/(1 + sin(v)*sin(v)))*sin(u);\
z: r*cos(v)/(1 + sin(v)*sin(v));\
xu: -(R + r*sin(v)*cos(v)/(1 + sin(v)*sin(v)))*sin(u);\
yu: (R + r*sin(v)*cos(v)/(1 + sin(v)*sin(v)))*cos(u);\
zu: 0;\
xv: -cos(u)*r*(3*sin(v)^2-1)/(1+sin(v)^2)^2;\
yv: -sin(u)*r*(3*sin(v)^2-1)/(1+sin(v)^2)^2;\
zv: -r*(2+cos(v)^2)/(1+sin(v)^2)^2;";
#endif
