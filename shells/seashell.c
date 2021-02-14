
#include "seashell.h"
#include "shells_c_includes.h"

#if (USE_SEASHELL != 0)
void Seashell(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
			  {
	PASULI_SET_TYPE_ID(SEASHELL)

	double ah;
	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double turns = constants[3];
	double cos_u_pi_one;
	double cos_turns_v_pi;
	double sin_turns_v_pi;

	cos_u_pi_one = 1.0f + cos(u * MY_PI);

	ah = a * (1 - 0.5 * v);
	sin_turns_v_pi = turns * v * MY_PI;
	cos_turns_v_pi = cos(sin_turns_v_pi);
	sin_turns_v_pi = sin(sin_turns_v_pi);

	P_X(ah * cos_turns_v_pi * cos_u_pi_one + c * cos_turns_v_pi);
	P_Y(ah * sin_turns_v_pi * cos_u_pi_one + c * sin_turns_v_pi);
	P_Z(b * 0.5 * v + ah * sin(u * MY_PI));
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
char *descSeashell = "";
#endif