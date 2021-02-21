
#include "maeders_owl.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_MAEDERS_OWL != 0)
void MaedersOwl(pasuli_vartype u, pasuli_vartype v,
				double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(MAEDERS_OWL)

	pasuli_calctype v2 = v * v;
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_2u = cos(2 * u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_2u = sin(2 * u);
	pasuli_calctype exp_v = exp(1.5 * log(v));

	P_X(v * cos_u - 0.5 * v2 * cos_2u);
	P_Y(-v * sin_u - 0.5 * v2 * sin_2u);
	P_Z(4 * exp_v * cos(1.5 * u) / 3.0);

	UD_X(v * (v * sin_2u - sin_u));
	UD_Y(-v * (v * cos_2u - cos_u));
	UD_Z(-3 * sin(1.5 * u) * exp_v);

	VD_X(-v * cos_2u + cos_u);
	VD_Y(-v * sin_2u - sin_u);
	VD_Z(-3 * cos(1.5 * u) * exp_v / v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMaedersOwl = {
	PSLDD_ID(MAEDERS_OWL)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI,
	0, 4, 0.001f, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descMaedersOwl =
	"name: Maeders Owl;\
ut:c; vt:c;\
us: 0; ue:pi: 4;\
vs: 0.001; ve: 1;\
x: v*cos(u) - 0.5*v*v*cos(2*u);\
y: -v*sin(u) - 0.5*v*v*sin(2*u);\
z: 4*exp(1.5*log(v))*cos(3*u/2)/3;\
xu: v^2*sin(2*u) - v*sin(u);\
yu: -v^2*cos(2*u) - v*cos(u);\
zu: -3*sin(3*u/2)*exp(1.5*log(v));\
xv: -v*cos(2*u) + cos(u);\
yv: -v*sin(2*u) - sin(u);\
zv: -3*cos(3*u/2)*exp(1.5*log(v))/v;";
#endif