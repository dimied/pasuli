
#include "snails.h"
#include "shells_c_includes.h"

#if (USE_SNAILS != 0)
void Snails(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SNAILS)

	double cos_cu;
	double sin_cu;
	double R = constants[0];
	double a = constants[1];
	double b = constants[2];
	double c = constants[3];
	double h = constants[4];
	double K = constants[5];
	double w = constants[6];

	cos_cu = cos(c * u);
	sin_cu = sin(c * u);
	double hacv = h + a * cos(v);
	double ewu = exp(w * u);

	P_Z(ewu * (K + b * sin(v)));
	P_X(ewu * hacv * cos_cu);
	P_Y(R * ewu * hacv * sin_cu);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnails = {
	PSLDD_ID(SNAILS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_CALC_U_START | PASULI_CALC_U_END |
		PASULI_V_END_PI | PASULI_CONST_COUNT(9),
	0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
R \in R
a \in R
b \in R
c \in R
h \in R
k \in R
w \in R
u_min \in R
u_max \in R
x = exp(w u) (h + a cos(v)) cos(c u)
y = R exp(w u) (h + a cos(v)) sin(c u)
z = exp(w u) (k + b sin(v))

Die Konstanten a, b, c, h, k, und w bestimmen das Aussehen der Figur. 
Die Konstante R bestimmt die Drehrichtung der Spirale, 
R sollte nur die Werte -1 oder 1 annehmen.

u \in  [u_min, u_max]
v \in  [0, 2 pi]
*/
char *descSnails = "";
#endif