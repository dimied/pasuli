
#include "triple_cork_screw1.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_CORK_SCREW1 != 0)

void TripleCorkScrew1(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIPLE_CORK_SCREW1)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype L = constants[2];
	pasuli_consttype N = constants[3];

	N *= MY_PI;

	pasuli_calctype cos_Nu = cos(u * N);
	pasuli_calctype sin_Nu = sin(u * N);
	pasuli_calctype one_minus_abs_u = (1 - fabs((double)u));

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(r * one_minus_abs_u * cos_v + R * one_minus_abs_u * cos_Nu);
	P_Y(r * one_minus_abs_u * sin_v + R * one_minus_abs_u * sin_Nu);
	P_Z(L * u);

	pasuli_calctype sign_value = PASULI_CALC_SIGN(u);
	pasuli_calctype xy_common = N * MY_PI * R * one_minus_abs_u;

	UD_X(-xy_common * sin_Nu - sign_value * (r * cos_v + R * cos_Nu));
	UD_Y(xy_common * cos_Nu - sign_value * (r * sin_v + R * sin_Nu));
	UD_Z(L);

	// Skip scaling by r*(1-|u|)
	sign_value = PASULI_CALC_SIGN(r * one_minus_abs_u);
	VD_X(-sign_value * sin_v);
	VD_Y(sign_value * cos_v);
	VD_Z(0);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew1 = {
PSLDD_ID( TRIPLE_CORK_SCREW1 )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew1 =
	"name: Triple Cork Screw 1;\
ut: c; vt: c;\
us: -1; ue: 1;\
vs:pi: -1; ve:pi: 1;\
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; c4:N: 1.0;\
x: r*(1 - |u|)*cos(v) + R*(1 - |u|)*cos(u*N*pi);\
y: r*(1 - |u|)*sin(v) + R*(1 - |u|)*sin(u*N*pi);\
z: L*u;\
xu: N*pi*R*(abs(u) - 1)*sin(N*pi*u) - sgn(u)*(r*cos(v) + R*cos(N*pi*u));\
yu: -N*pi*R*(abs(u) - 1)*cos(N*pi*u)- sgn(u)*(r*sin(v) + R*sin(N*pi*u));\
zu: L;\
xv: -r*(1 - |u|)*sin(v);\
yv: r*(1 - |u|)*cos(v);\
zv: 0;";
#endif