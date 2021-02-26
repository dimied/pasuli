
#include "geronolemniskate_torus1.h"
#include "torus_c_includes.h"

#if (USE_GERONO_LEMNISKATE_TORUS_1 != 0)

void GeronoLemniskateTorus1(pasuli_vartype u,
							pasuli_vartype v,
							pasuli_consttype *constants,
							PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(GERONO_LEMNISKATE_TORUS_1)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = r * sin_v;

	P_Z(factor * cos_v);
	factor += R;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);

	// Ignore scaling by (R + r*sin(v))
	factor = PASULI_CALC_SIGN(factor);

	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	// Ignore scaling by r
	factor = PASULI_CALC_SIGN(r);
	VD_X(factor * cos_v * cos_u);
	VD_Y(factor * cos_v * sin_u);

	// Warning! we reuse cos_u
	cos_u = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
	VD_Z(factor * cos_u);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddGeronoLemniskateTorus1 = {
	GERONO_LEMNISKATE_TORUS_1,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descGeronoLemniskateTorus1 =
	"name: Gerono Lemniskate Torus 1;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1; c2:r:1;\
x: (R + r*sin(v))*cos(u);\
y: (R + r*sin(v))*sin(u);\
z: r*sin(v)*cos(v);\
xu: -(R + r*sin(v))*sin(u);\
yu: (R + r*sin(v))*cos(u);\
zu: 0;\
xv: r*cos(u)*cos(v);\
yv: r*sin(u)*cos(v);\
zv: r*(cos(v)^2-sin(v)^2);";
#endif
