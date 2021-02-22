
#include "piriform_torus2.h"
#include "torus_c_includes.h"

#if (USE_PIRIFORM_TORUS_2 != 0)
void PiriformTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PIRIFORM_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = r + sin_v;
	P_Z(factor);
	factor = R + cos_v * factor;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);

	// Ignore scaling by (R+cos(v)*(r+sin(v)))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
	factor -= r * sin_v;
	VD_X(cos_u * factor);
	VD_Y(sin_u * factor);
	VD_Z(cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddPiriformTorus2 = {
	PSLDD_ID(PIRIFORM_TORUS_2)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descPiriformTorus2 =
	"name: Piriform Torus 2;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R1:1; c2:R: 1;\
x: (R+cos(v)*(r+sin(v)))*cos(u);\
y: (R+cos(v)*(r+sin(v)))*sin(u);\
z: r+sin(v);\
xu: -(R+cos(v)*(r+sin(v)))*sin(u);\
yu: (R+cos(v)*(r+sin(v)))*cos(u);\
zu: 0;\
xv: cos(u)*(cos(v)^2-sin(v)^2-r*sin(v));\
yv: sin(u)*(cos(v)^2-sin(v)^2-r*sin(v));\
zv: cos(v);";
#endif
