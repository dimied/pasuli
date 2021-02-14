
#include "cornucopia.h"
#include "shells_c_includes.h"

#if (USE_CORNUCOPIA != 0)
void Cornucopia(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CORNUCOPIA)

	double a = constants[0];
	double b = constants[1];

	double eav = exp(a * v);
	double ebv = exp(b * v);

	P_X(ebv * cos(v) + eav * cos(u) * cos(v));
	P_Y(ebv * sin(v) + eav * cos(u) * sin(v));
	P_Z(eav * sin(u));
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddCornucopia = {
	PSLDD_ID(CORNUCOPIA)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	-0.5f, 0.5f, 0, 2, 0};
#endif
/**
a \in R
b \in R

u \in [-pi , pi]
v \in [0 , 2pi]

x = e^{bv} cos(v) + e^{av} cos(u) cos(v)	
y = e^{bv} sin(v) + e^{av} cos(u) sin(v)
z = e^{av} sin(u)
*/
#if (COMPILE_DESC_SHELLS != 0)
char *descCornucopia = "";
#endif