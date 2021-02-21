
#include "triple_cork_screw2.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_CORK_SCREW2 != 0)
void TripleCorkScrew2(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIPLE_CORK_SCREW2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype L = constants[2];
	pasuli_consttype N = constants[3];
	pasuli_consttype a = constants[4];
	pasuli_consttype b = constants[5];

	N *= MY_PI;
	a *= a;
	b *= b;

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype r_exp_bu = r * exp(-b * u * u);

	pasuli_calctype R_exp_au = R * exp(-a * u * u);
	pasuli_calctype cos_Nu = cos(u * N);
	pasuli_calctype sin_Nu = sin(u * N);

	P_X(r_exp_bu * cos_v + R_exp_au * cos_Nu);
	P_Y(r_exp_bu * sin_v + R_exp_au * sin_Nu);
	P_Z(L * u);

	r_exp_bu *= 2 * b * b * u;
	UD_X(-R_exp_au * (2 * a * a * u * cos_Nu + N * sin_Nu) - r_exp_bu * cos_v);
	UD_Y(R_exp_au * (2 * a * a * u * sin_Nu - N * cos_Nu) - r_exp_bu * sin_v);
	UD_Z(L);

	pasuli_calctype sign_value = PASULI_CALC_SIGN(r_exp_bu);
	VD_X(-sign_value * sin_v);
	VD_Y(sign_value * cos_v);
	VD_Z(0);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew2 = {
PSLDD_ID( TRIPLE_CORK_SCREW2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(6),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew2 =
	"name: Triple Cork Screw 2; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs:pi: -1; ve:pi: 1; \
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; \
c4:N: 1.0; c5:a: 1.0; c6:b: 1.0; \
a1:c: r*exp(-(b*b*u*u)); \
a2:d: R*exp(-(a*a*u*u)); \
x: c*cos(v) + d*cos(u*N*pi); \
y: c*sin(v) + d*sin(u*N*pi); \
z: L*u; \
xu: -R*exp(-(a*a*u*u))*(2*a*a*u*cos(N*pi*u) + N*pi*sin(N*pi*u)) - 2*b*b*r*u*cos(v)*exp(-(b*b*u*u)); \
yu: -R*exp(-(a*a*u*u))*(2*a*a*u*sin(N*pi*u) - N*pi*cos(N*pi*u)) - 2*b*b*r*u*sin(v)*exp(-(b*b*u*u)); \
zu: L; \
xv: -r*sin(v)*exp(-(b*b*u*u)); \
yv: r*cos(v)*exp(-(b*b*u*u)); \
zv: 0;";
#endif