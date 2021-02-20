
#include "spring1.h"
#include "surfaces_c_includes.h"

#if (USE_SPRING1 != 0)

void Spring1(pasuli_vartype u,
			 pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPRING1)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype L = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype R_r_cos_v = R + r * cos_v;

	P_X(R_r_cos_v * cos_u);
	P_Y(R_r_cos_v * sin_u);
	P_Z(r * (sin_v + (L * u) / MY_PI));

	UD_X(-PASULI_COND_COPY_POS_Y(R_r_cos_v * sin_u));
	UD_Y(PASULI_COND_COPY_POS_X(R_r_cos_v * cos_u));
	UD_Z(L * r / MY_PI);

	VD_X(-r * cos_u * sin_v);
	VD_Y(-r * sin_u * sin_v);
	VD_Z(r * cos_v);

	pasuli_calctype factor = PASULI_CALC_SIGN(r);

	// Ignore r
	N_X(-factor * (L * r * sin_u * sin_v / MY_PI + cos_u * cos_v * (r * cos_v + R)));
	N_Y(factor * (L * r * cos_u * sin_v / MY_PI + sin_u * cos_v * (r * cos_v + R)));
	N_Z(factor * sin_v * (r * cos_v + R));

	UUD_X(-PASULI_COND_COPY_POS_X(R_r_cos_v * cos_u));
	UUD_Y(-PASULI_COND_COPY_POS_Y(R_r_cos_v * sin_u));
	UUD_Z(0);

	UVD_X(r * sin_u * sin_v);
	UVD_Y(-r * cos_u * sin_v);
	UVD_Z(0);

	VVD_X(-factor * cos_u * cos_v);
	VVD_Y(-factor * sin_u * cos_v);
	VVD_Z(-factor * sin_v);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring1 = {
PSLDD_ID( SPRING1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4)|PASULI_CALC_U_END,//MUL_BY_CONST(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descSpring1 =
	"name: Spring 1; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; c4:N: 1.0; \
x: (R + r*cos(v))*cos(u); \
y: (R + r*cos(v))*sin(u); \
z: r*(sin(v) + L*u/pi); \
xu: -(R + r*cos(v))*sin(u); \
yu: (R + r*cos(v))*cos(u); \
zu: L*r/pi; \
xv: -r*cos(u)*sin(v); \
yv: -r*sin(u)*sin(v); \
zv: r*cos(v); \
xn: L*r^2*sin(u)*sin(v)/pi + r*cos(u)*(cos(v)*(r*cos(v) + R)); \
yn: -L*r^2*cos(u)*sin(v)/pi + r*sin(u)*(cos(v)*(r*cos(v) + R)); \
zn: r*(sin(v)*(r*cos(v) + R)); \
xuu: -(R + r*cos(v))*cos(u); \
yuu: -(R + r*cos(v))*sin(u); \
zuu: 0; \
xuv: r*sin(u)*sin(v); \
yuv: -r*cos(u)*sin(v); \
zuv: 0; \
xvv: -r*cos(u)*cos(v); \
yvv: -r*sin(u)*cos(v); \
zvv: -r*sin(v);";
#endif
