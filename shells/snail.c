
#include "snail.h"
#include "shells_c_includes.h"

#if (USE_SNAIL != 0)
void Snail(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SNAIL)

	double a = constants[0];
	double b = constants[1];

	double h = exp(u / (6 * MY_PI));
	double eubpi = exp(u / (b * MY_PI));

	double cos_half_v_sq = cos(v * 0.5f);
	cos_half_v_sq *= cos_half_v_sq;

	P_X(a * (1 - h) * cos(u) * cos_half_v_sq);
	P_Y(1 - eubpi + (h - 1) * sin(v));
	P_Z(a * (h - 1) * sin(u) * cos_half_v_sq);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnail = {
	PSLDD_ID(SNAIL)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(0),
	0, 6, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
u \in [0 , 6pi] 	
v \in [0 , 2pi]

h = e^{u/(6 pi)}
x = a (1 - h) cos(u) cos(0.5 v) cos(0.5 v)
y = 1 - e^{u/(b pi)} - sin(v) + h sin(v)
z = a (-1 + h) sin(u) cos(0.5 v) cos(0.5 v)
*/
char *descSnail = "";
#endif