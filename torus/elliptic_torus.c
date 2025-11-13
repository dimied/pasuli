
#include "elliptic_torus.h"
#include "torus_c_includes.h"

#if (USE_ELLIPTIC_TORUS != 0)

void EllipticTorus(pasuli_vartype u,
				   pasuli_vartype v,
				   pasuli_consttype *constants,
				   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ELLIPTIC_TORUS)

	pasuli_consttype c = constants[0];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = cos_v + c;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(sin_v * cos_v);

	// Ignore scaling by (a + cos(v))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	VD_X(-cos_u * sin_v);
	VD_Y(-sin_u * sin_v);
	VD_Z(cos_v - sin_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEllipticTorus = {
PSLDD_ID( ELLIPTIC_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
0 , 2 , 0 , 2 , &torus_def_constants[2] };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descEllipticTorus =
	"name: Elliptic Torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:a: 1;\
x: (a + cos(v))*cos(u);\
y: (a + cos(v))*sin(u);\
z: sin(v) + cos(v);\
xu: -(a + cos(v))*sin(u);\
yu: (a + cos(v))*cos(u);\
zu: 0;\
xv: -cos(u)*sin(v);\
yv: -sin(u)*sin(v);\
zv: cos(v) - sin(v);";
#endif