
#include "lemniskate_torus1.h"
#include "torus_c_includes.h"

#if (USE_LEMNISKATE_TORUS_1 != 0)
void LemniskateTorus1(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LEMNISKATE_TORUS_1)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype divisor = sin_v * sin_v + 1;

	P_Z(r * cos_v * sin_v / divisor);

	divisor = R + r * cos_v / divisor;
	P_X(cos_u * divisor);
	P_Y(sin_u * divisor);

	// Ignore scaling by (R + r*cos(v)/(1 + sin(v)*sin(v)))
	divisor = PASULI_CALC_SIGN(divisor);
	UD_X(-divisor * sin_u);
	UD_Y(divisor * cos_u);
	UD_Z(0);

	// Multiplied by (1+sin(v)^2)^2
	// Ignore scale by r
	divisor = PASULI_CALC_SIGN(r);
	// Reusing cos_v !!!
	cos_v = (2 + cos_v * cos_v) * sin_v;
	VD_X(-divisor * cos_v * cos_u);
	VD_Y(-divisor * cos_v * sin_u);
	VD_Z(-divisor * (3 * sin_v * sin_v - 1));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLemniskateTorus1 = {
PSLDD_ID( LEMNISKATE_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descLemniskateTorus1 =
	"name: Lemniskate Torus 1;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R:1.5; c2:r:0.5;\
a1:F: r*cos(v)/(1 + sin(v)*sin(v));\
x: (R + F)*cos(u);\
y: (R + F)*sin(u);\
z: sin(v)*F;\
xu: -(R + r*cos(v)/(1 + sin(v)*sin(v)))*sin(u);\
yu: (R + r*cos(v)/(1 + sin(v)*sin(v)))*cos(u);\
zu: 0;\
xv: -cos(u)*r*(2+cos(v)^2)*sin(v)/(1+sin(v)^2)^2;\
yv: -sin(u)*r*(2+cos(v)^2)*sin(v)/(1+sin(v)^2)^2;\
zv: -r*(3*sin(v)^2-1)/(1+sin(v)^2)^2;";
#endif
