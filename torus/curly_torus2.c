
#include "curly_torus1.h"
#include "torus_c_includes.h"

#if (USE_CURLY_TORUS_2 != 0)
void CurlyTorus2(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CURLY_TORUS_2)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R2 = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u);
	pasuli_vartype cos_v = cos(v);
	pasuli_vartype sin_v = sin(v);

	pasuli_calctype factor = r * cos_v + R1 + R2 * cos(N * u);

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(r * sin_v);

	pasuli_vartype sin_Nu = sin(N * u);

	UD_X(-factor * sin_u - N * R2 * cos_u * sin_Nu);
	UD_Y(factor * cos_u - N * R2 * sin_u * sin_Nu);
	UD_Z(0);

	// Ignore scaling by r
	factor = PASULI_CALC_SIGN(r);
	VD_X(-factor * sin_v * cos_u);
	VD_Y(-factor * sin_v * sin_u);
	VD_Z(factor * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCurlyTorus2 = {
	CURLY_TORUS_2,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descCurlyTorus2 =
	"name: Curly Torus 2;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R1:1; c2:R2:1; c3:r:1; c4:n:1;\
a1:F: (R1 + R2*cos(n*u) + r*cos(v));\
x: F*cos(u);\
y: F*sin(u);\
z: r*sin(v);\
xu: -(R1 + R2*cos(n*u) + r*cos(v))*sin(u) - n*R2*cos(u)*sin(n*u);\
yu: (R1 + R2*cos(n*u) + r*cos(v))*cos(u) - n*R2*sin(u)*sin(n*u);\
zu: 0;\
xv: -r*cos(u)*sin(v);\
yv: -r*sin(u)*sin(v);\
zv: r*cos(v);";
#endif
