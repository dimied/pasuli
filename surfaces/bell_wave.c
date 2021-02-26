
#include "bell_wave.h"
#include "surfaces_c_includes.h"

#if (USE_BELL_WAVE != 0)
void BellWave(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BELL_WAVE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype exp_auv = (u * u + v * v);
	pasuli_calctype sqrt_v2_u2 = sqrt(exp_auv);
	exp_auv = exp(-a * a * exp_auv);

	pasuli_calctype cos_c_sqrt = cos(c * sqrt_v2_u2);

	P_X(u);
	P_Z(v);
	P_Y(cos_c_sqrt * b * exp_auv);

	// We multiply sqrt_v2_u2
	pasuli_calctype sin_c_sqrt = sin(c * sqrt_v2_u2);
	UD_X(sqrt_v2_u2);
	UD_Y_CONST(0);
	UD_Z(-exp_auv * (2 * a * a * u * cos_c_sqrt * sqrt_v2_u2 + b * c * u * sin_c_sqrt));

	// We multiply sqrt_v2_u2
	VD_X_CONST(0);
	VD_Y(sqrt_v2_u2);
	VD_Z(-exp_auv * (2 * a * a * v * cos_c_sqrt * sqrt_v2_u2 + b * c * v * sin_c_sqrt));

	// We multiply sqrt_v2_u2
	N_X(-PASULI_COND_COPY_UD_Z(-exp_auv * (2 * a * a * u * cos_c_sqrt * sqrt_v2_u2 + b * c * u * sin_c_sqrt)));
	N_Y(-PASULI_COND_COPY_VD_Z(-exp_auv * (2 * a * a * u * cos_c_sqrt * sqrt_v2_u2 + b * c * u * sin_c_sqrt)));
	N_Z(sqrt_v2_u2);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellWave = {
PSLDD_ID( BELL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBellWave =
	"name: Bell Wave;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:0; ve: 12;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1;\
a1:r: sqrt(u*u + v*v);\
x: u;\
y: v;\
z: cos(c*r)*b*exp(-(a*r)^(2));\
xu: 1;\
yu: 0;\
zu: -exp(-(a*r)^(2))*(2*a^2*b*u*cos(c*r) + b*c*u*sin(c*r)/r);\
xv: 0;\
yv: 1;\
zv: -exp(-(a*r)^(2))*(2*a^2*b*v*cos(c*r) + b*c*v*sin(c*r)/r);\
xn: exp(-(a*r)^(2))*(2*a^2*b*u*cos(c*r) + b*c*u*sin(c*r)/r);\
yn: exp(-(a*r)^(2))*(2*a^2*b*v*cos(c*r) + b*c*v*sin(c*r)/r);\
zn: 1; ";
#endif