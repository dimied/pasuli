
#include "seashell.h"
#include "shells_c_includes.h"

#if (USE_SEASHELL != 0)
void Seashell(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SEASHELL)

	pasuli_consttype a_width = constants[0];
	pasuli_consttype b_height = constants[1];
	pasuli_consttype c_radius = constants[2];
	pasuli_consttype turns = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u_one = 1.0f + cos_u;

	pasuli_calctype a_h = a_width * (1 - 0.5 * v);
	pasuli_calctype n_v_pi = turns * v * MY_PI;
	pasuli_calctype cos_turns_v_pi = cos(n_v_pi);
	pasuli_calctype sin_turns_v_pi = sin(n_v_pi);

	P_X(a_h * cos_turns_v_pi * cos_u_one + c_radius * cos_turns_v_pi);
	P_Y(a_h * sin_turns_v_pi * cos_u_one + c_radius * sin_turns_v_pi);
	P_Z(b_height * 0.5 * v + a_h * sin_u);

	UD_X(-a_h * cos_turns_v_pi * sin_u);
	UD_Y(-a_h * sin_turns_v_pi * sin_u);
	UD_Z(-a_h * cos(u));

	pasuli_calctype vd_factor1 = 0.5 * a_width * n_v_pi - a_h * turns * MY_PI * cos_u - a_width * turns * MY_PI - c_radius * turns * MY_PI;
	pasuli_calctype vd_factor2 = cos_u_one * a_width * 0.5;
	VD_X(sin_turns_v_pi * vd_factor1 - cos_turns_v_pi * vd_factor2);
	VD_Y(-cos_turns_v_pi * vd_factor1 - sin_turns_v_pi * vd_factor2);
	VD_Z((b_height - a_width * sin_u) * 0.5);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif
#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSeashell = {
	PSLDD_ID(SEASHELL)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
a \in R : Width
b \in R : Height
c \in R: inner-radius
n \in R: number of turns

u \in [0 , 2]
v \in [0 , 2]

h = 1 - 0.5 v 	
x = a h cos(n v pi) (1 + cos(u pi)) + c cos(n v pi)
y = a h sin(n v pi) (1 + cos(u pi)) + c sin(n v pi)
z = b 0.5 v + a h sin(u pi)
*/
char *descSeashell = "name: Sea shell; \
cat: shells; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs: 0; ve: 2; \
c1:a: 1; c2:b: 1; \
c3:c: 1; c4:n: 1; \
a1:h: 1-0.5*v; \
x: a*h*cos(n*v*pi)*(1 + cos(u)) + c*cos(n*v*pi); \
y: a*h*sin(n*v*pi)*(1 + cos(u)) + c*sin(n*v*pi); \
z: b*0.5*v + a*h*sin(u); \
xu: -a*h*cos(n*pi*v)*sin(u); \
yu: -a*h*sin(n*pi*v)*sin(u); \
zu: -a*h*cos(u); \
xv: sin(n*pi*v)*(0.5*a*n*pi*v - a*h*n*pi*cos(u) - a*n*pi - c*n*pi) - cos(n*pi*v)*(cos(u)+1)*a*0.5; \
yv: cos(n*pi*v)*(-0.5*a*n*pi*v + a*h*n*pi*cos(u) + a*n*pi + c*n*pi) - sin(n*pi*v)*(cos(u)+1)*a*0.5; \
zv: 0.5*b - 0.5*a*sin(u); \
xuu: -a*h*cos(u)*cos(n*pi*v); \
yuu: -a*h*cos(u)*sin(n*pi*v); \
zuu: -a*h*sin(u); \
xuv: a*h*n*sin(u)*sin(n*pi*v) + 0.5*a*cos(n*pi*v)*sin(u); \
yuv: -a*h*n*sin(u)*cos(n*pi*v) + 0.5*a*sin(n*pi*v)*sin(u); \
zuv: -0.5*a*cos(u);";
#endif