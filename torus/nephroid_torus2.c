
#include "nephroid_torus2.h"
#include "torus_c_includes.h"

#if (USE_NEPHROID_TORUS_2 != 0)
void NephroidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(NEPHROID_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_3v = cos(3.0 * v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_3v = sin(3.0 * v);

	pasuli_calctype factor = R + r * (3.0 * sin_v - sin_3v);

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Z(r * (3 * cos_v - cos_3v));

	// Ignore scaling by (R+r*(3*sin(v)-sin(3*v)))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-sin_u * factor);
	UD_Y(cos_u * factor);
	UD_Z(0);

	factor = cos_v - cos_3v;
	// Ignore scaling by 3*r
	// Attention, reusing cos_v
	cos_v = PASULI_CALC_SIGN(r);
	VD_X(cos_v * cos_u * factor);
	VD_Y(cos_v * sin_u * factor);
	VD_Z(sin_3v - sin_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddNephroidTorus2 = {
PSLDD_ID( NEPHROID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descNephroidTorus2 =
	"name: Nephroid Torus 2;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R:1.5; c2:r:0.5;\
x: (R+r*(3*sin(v)-sin(3*v)))*cos(u);\
y: (R+r*(3*sin(v)-sin(3*v)))*sin(u);\
z: r*(3*cos(v)-cos(3*v));\
xu: -(R+r*(3*sin(v)-sin(3*v)))*sin(u);\
yu: (R+r*(3*sin(v)-sin(3*v)))*cos(u);\
zu: 0;\
xv: 3*r*cos(u)*(cos(v)-cos(3*v));\
yv: 3*r*sin(u)*(cos(v)-cos(3*v));\
zv: 3*r*(sin(3*v)-sin(v));";
#endif
