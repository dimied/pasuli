
#include "trefoil_knots2.h"
#include "surfaces_c_includes.h"

#if (USE_TREFOIL_KNOTS2 != 0)

void TrefoilKnots2(pasuli_vartype u,
				   pasuli_vartype v,
				   pasuli_consttype *constants,
				   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TREFOIL_KNOTS2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype a = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype r_cos_v = r * cos_v;
	pasuli_calctype r_sin_v = r * sin_v;

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_Nu = cos(N * u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_Nu = sin(N * u);

	pasuli_calctype factor = 1 + a * cos_Nu;

	P_X(r_cos_v * cos_u + R * cos_u * factor);
	P_Y(r_cos_v * sin_u + R * sin_u * factor);
	P_Z(r_sin_v + a * sin_Nu);

	factor = R * factor + r_cos_v;
	// Attention
	sin_Nu *= a * N * R;

	UD_X(-sin_u * factor - cos_u * sin_Nu);
	UD_Y(cos_u * factor - sin_u * sin_Nu);
	UD_Z(a * N * cos_Nu);

	factor = PASULI_CALC_SIGN(r);
	// Don't scale by r
	VD_X(-factor * sin_v * cos_u);
	VD_Y(-factor * sin_v * sin_u);
	VD_Z(factor * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots2 = {
PSLDD_ID( TREFOIL_KNOTS2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0, 4 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots2 =
	"name: Trefoil Knots 2;\
ut:c; vt:c;\
us: 0; ue:pi: 4;\
vs: 0; ve:pi: 2;\
c1:R: 1.5; c2:r: 0.5; c3:a: 1.0; c4:N: 1.0;\
x: r*cos(v)*cos(u) + R*cos(u)*(1 + a*cos(N*u));\
y: r*cos(v)*sin(u) + R*sin(u)*(1 + a*cos(N*u));\
z: r*sin(v) + a*sin(N*u);\
xu: -sin(u)*(R*(a*cos(N*u) + 1) + r*cos(v)) - a*N*R*cos(u)*sin(N*u);\
yu: cos(u)*(R*(a*cos(N*u) + 1) + r*cos(v)) - a*N*R*sin(u)*sin(N*u);\
zu: a*N*cos(N*u);\
xv: -r*cos(u)*sin(v);\
yv: -r*sin(u)*sin(v);\
zv: r*cos(v);";
#endif