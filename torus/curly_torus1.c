
#include "curly_torus1.h"
#include "torus_c_includes.h"

#if (USE_CURLY_TORUS_1 != 0)
void CurlyTorus1(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CURLY_TORUS_1)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R2 = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = R1 + r * cos_v;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(r * sin_v + R2 * sin(N * u));

	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(N * R2 * cos(N * u));

	// Ignore scaling by r
	factor = PASULI_CALC_SIGN(r);
	VD_X(-factor * sin_v * cos_u);
	VD_Y(-factor * sin_v * sin_u);
	VD_Z(factor * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#include "torus_desc.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCurlyTorus1 = {
	PSLDD_ID(CURLY_TORUS_1)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descCurlyTorus1 =
	"name: Curly Torus 1;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R1:1; c2:R2:1; c3:r:1; c4:n:1;\
x: (R1 + r*cos(v))*cos(u);\
y: (R1 + r*cos(v))*sin(u);\
z: r*sin(v) + R2*sin(n*u);\
xu: -(R1 + r*cos(v))*sin(u);\
yu: (R1 + r*cos(v))*cos(u);\
zu: n*R2*cos(n*u);\
xv: -r*cos(u)*sin(v);\
yv: -r*sin(u)*sin(v);\
zv: r*cos(v);";
#endif
