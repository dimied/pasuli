
#include "tricuspoid_torus2.h"
#include "torus_c_includes.h"

#if (USE_TRICUSPOID_TORUS_2 != 0)
void TricuspoidTorus2(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRICUSPOID_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_2v = cos(2.0 * v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_2v = sin(2.0 * v);

	pasuli_calctype factor = R + r * (2 * sin_v - sin_2v);

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Z(r * (2 * cos_v + cos_2v));

	// Ignore scaling by (R+r*(2*sin(v)-sin(2*v)))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	factor = cos_v - cos_2v;
	// Ignore scaling by 2*r
	r = PASULI_CALC_SIGN(r);
	VD_X(r * factor * cos_u);
	VD_Y(r * factor * sin_u);
	VD_Z(-r * (sin_v + sin_2v));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTricuspoidTorus2 = {
PSLDD_ID( TRICUSPOID_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descTricuspoidTorus2 =
	"name: Tricuspoid Torus 2;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1.5; c2:r:0.5;\
x: (R+r*(2*sin(v)-sin(2*v)))*cos(u);\
y: (R+r*(2*sin(v)-sin(2*v)))*sin(u);\
z: r*(2*cos(v)+cos(2*v));\
xu: -(R+r*(2*sin(v)-sin(2*v)))*sin(u);\
yu: (R+r*(2*sin(v)-sin(2*v)))*cos(u);\
zu: 0;\
xv: 2*r*cos(u)*(cos(v)-cos(2*v));\
yv: 2*r*sin(u)*(cos(v)-cos(2*v));\
zv: -2*r*(sin(v)+sin(2*v));";
#endif
