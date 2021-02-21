
#include "triple_cork_screw3.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_CORK_SCREW3 != 0)

void TripleCorkScrew3(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIPLE_CORK_SCREW3)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype L = constants[2];
	pasuli_consttype N = constants[3];
	N *= MY_PI;

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype r_minus_abs_u = (1 - fabs((double)u)) * r;

	pasuli_calctype cos_u_pi_half = cos(u * 0.5 * MY_PI);
	pasuli_calctype cos_Nu = cos(u * N);
	pasuli_calctype sin_Nu = sin(N * u);

	P_X(r_minus_abs_u * cos_v + R * cos_u_pi_half * cos_Nu);
	P_Y(r_minus_abs_u * sin_v + R * cos_u_pi_half * sin_Nu);
	P_Z(L * u);

	R *= MY_PI;
	pasuli_calctype sign_value = PASULI_CALC_SIGN(u);
	pasuli_calctype sin_u_pi_half = sin(u * 0.5 * MY_PI);
	UD_X(R * (N * cos_u_pi_half * sin_Nu + cos_Nu * sin_u_pi_half * 0.5) - sign_value * cos_v);
	UD_Y(R * (N * cos_u_pi_half * cos_Nu - sin_Nu * sin_u_pi_half * 0.5) - sign_value * sin_v);
	UD_Z(L);

	sign_value = PASULI_CALC_SIGN(r_minus_abs_u);
	VD_X(-sign_value * sin_v);
	VD_Y(sign_value * cos_v);
	VD_Z(0);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew3 = {
PSLDD_ID( TRIPLE_CORK_SCREW3 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew3 =
	"name: Triple Cork Screw 3; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs:pi: -1; ve:pi: 1; \
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; c4:N: 1.0; \
a1:a: r*(1 - |u|); \
a2:b: R*cos(u*pi/2); \
x: a*cos(v) + b*cos(u*N*pi); \
y: a*sin(v) + b*sin(u*N*pi); \
z: L*u; \
xu: -pi*R*(N*cos(pi*u/2)*sin(N*pi*u) + cos(N*pi*u)*sin(pi*u/2)/2) -r*sgn(u)*cos(v); \
yu: pi*R*(N*cos(pi*u/2)*cos(N*pi*u) - sin(N*pi*u)*sin(pi*u/2)/2) -r*sgn(u)*sin(v); \
zu: L; \
xv: -r*(1 - |u|)*sin(v); \
yv: r*(1 - |u|)*cos(v); \
zv: 0;";
#endif