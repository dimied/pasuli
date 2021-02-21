
#include "eight_torus.h"
#include "torus_c_includes.h"

#if (USE_EIGHT_TORUS != 0)

void EightTorus(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EIGHT_TORUS)

	pasuli_consttype c = constants[0];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	//pasuli_calctype sv = sin(v);

	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_2v = sin(2.0 * v);

	pasuli_calctype factor = (c + sin_v * cos_u - sin_2v * sin_u * 0.5);

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Z(sin_u * sin_v + cos_u * sin_2v * 0.5);

	pasuli_calctype cos_sin_difference = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_u, sin_u);

	UD_X(-((c + 2 * cos_u * sin_v) * sin_u + sin_2v * cos_sin_difference * 0.5));
	UD_Y((c - sin_u * sin_2v) * cos_u + sin_2v * cos_sin_difference);
	UD_Z(cos_u * sin_v - sin_u * sin_2v * 0.5);

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_2v = cos(2.0 * v);
	factor = (cos_u * cos_v - cos_2v * sin_u);

	VD_X(cos_u * factor);
	VD_Y(sin_u * factor);
	VD_Z(cos_u * cos_2v + cos_v * sin_u);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEightTorus = {
PSLDD_ID( EIGHT_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI|\
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1 , 1 , -1 , 1 , &torus_def_constants[2] };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descEightTorus =
	"name: Eight Torus;\
cat: torus;\
ut: c; vt: c;\
us: pi: -1; ue:pi: 1;\
vs: pi: -1; ve:pi: 1;\
c1:c: 1;\
x: cos(u)*(c + sin(v)*cos(u) - sin(2*v)*sin(u)/2);\
y: sin(u)*(c + sin(v)*cos(u) - sin(2*v)*sin(u)/2);\
z: sin(u)*sin(v) + cos(u)*sin(2*v)/2;\
xu: -(c*sin(u) + sin(2*v)*(cos(u)^2 - sin(u)^2)/2 + 2*cos(u)*sin(u)*sin(v));\
yu: c*cos(u) + sin(v)*(cos(u)^2 - sin(u)^2) - cos(u)*sin(u)*sin(2*v);\
zu: cos(u)*sin(v) - sin(u)*sin(2*v)/2;\
xv: cos(u)^2*cos(v) - cos(u)*cos(2*v)*sin(u);\
yv: cos(u)*cos(v)*sin(u) - cos(2*v)*sin(u)^2;\
zv: cos(u)*cos(2*v) + cos(v)*sin(u);";
#endif