
#include "twisted_eight_torus.h"
#include "torus_c_includes.h"

#if (USE_TWISTED_EIGHT_TORUS != 0)
void TwistedEightTorus(pasuli_vartype u,
					   pasuli_vartype v,
					   pasuli_consttype *constants,
					   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TWISTED_EIGHT_TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_vartype cos_u = cos(u);
	pasuli_vartype cos_u_half = cos(u * 0.5);
	pasuli_vartype sin_u = sin(u);
	pasuli_vartype sin_u_half = sin(u * 0.5);

	pasuli_vartype sin_v = sin(v);
	pasuli_vartype sin_2v = sin(2 * v);

	pasuli_calctype factor = R + r * (cos_u_half * sin_v - sin_u_half * sin_2v);

	pasuli_calctype pos_x = factor * cos_u;
	pasuli_calctype pos_y = factor * sin_u;

	P_X(pos_x);
	P_Y(pos_y);
	P_Z(r * (sin_u_half * sin_v + cos_u_half * sin_2v));

	pasuli_calctype ud_factor = cos_u_half * sin_2v + sin_u_half * sin_v;
	UD_X(-cos_u * r * ud_factor * 0.5 - pos_y);
	UD_Y(-sin_u * r * ud_factor * 0.5 + pos_x);
	UD_Z(r * (cos_u_half * sin_v - sin_u_half * sin_2v) * 0.5);

	pasuli_vartype cos_v = cos(v);
	pasuli_vartype cos_2v = cos(2 * v);

	factor = cos_v * cos_u_half - 2 * cos_2v * sin_u_half;
	// Ignore scaling by r
	r = PASULI_CALC_SIGN(r);
	VD_X(r * cos_u * factor);
	VD_Y(r * sin_u * factor);
	VD_Z(r * (cos_v * sin_u_half + 2 * cos_u_half * cos_2v));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTwistedEightTorus = {
PSLDD_ID( TWISTED_EIGHT_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descTwistedEightTorus =
	"name: Twisted Torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R: 1.5; c2:r: 0.5;\
x: (R+r*(cos(u/2)*sin(v)-sin(u/2)*sin(2*v)))*cos(u);\
y: (R+r*(cos(u/2)*sin(v)-sin(u/2)*sin(2*v)))*sin(u);\
z: r*(sin(u/2)*sin(v) + cos(u/2)*sin(2*v));\
xu: -cos(u)*r*(cos(u/2)*sin(2*v)+sin(u/2)*sin(v))/2-(R+r*(cos(u/2)*sin(v)-sin(u/2)*sin(2*v)))*sin(u);\
yu: -sin(u)*r*(cos(u/2)*sin(2*v)+sin(u/2)*sin(v))/2+(R+r*(cos(u/2)*sin(v)-sin(u/2)*sin(2*v)))*cos(u);\
zu: r*(cos(u/2)*sin(v) - sin(u/2)*sin(2*v))/2;\
xv: r*cos(u)*(cos(v)*cos(u/2)-2*cos(2*v)*sin(u/2));\
yv: r*sin(u)*(cos(v)*cos(u/2)-2*cos(2*v)*sin(u/2));\
zv: r*(cos(v)*sin(u/2)+2*cos(u/2)*cos(2*v));";
#endif