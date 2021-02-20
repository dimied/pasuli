
#include "tractroid.h"
#include "surfaces_c_includes.h"

#if (USE_TRACTROID != 0)

void Tractroid(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRACTROID)

	pasuli_calctype cosh_u = cosh(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(cos_v / cosh_u);
	P_Y(sin_v / cosh_u);
	P_Z(u - tanh(u));

	pasuli_calctype sinh_u = sinh(u);
	// Muplitplied by cosh(u)^2
	UD_X(-cos_v * sinh_u);
	UD_Y(-sin_v * sinh_u);
	UD_Z(cosh_u * cosh_u - 1);

	// Muplitplied by cosh(u), it's always positive
	VD_X(-sin_v);
	VD_Y(cos_v);
	VD_Z(0);

	pasuli_calctype summand = 1 - cosh_u * cosh_u;
	// Muplitplied by cosh(u)^3
	N_X(cos_v * summand);
	N_Y(sin_v * summand);
	N_Z(-sinh_u);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTractroid = {
	PSLDD_ID(TRACTROID)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI,
	0, 4, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTractroid =
	"name: Tractroid; \
ut:c; vt:c; \
us: 0; ue: 4; \
vs: 0; ve:pi: 2; \
x: sech(u)*cos(v); \
y: sech(u)*sin(v); \
z: u - tanh(u); \
xu: -cos(v)*sinh(u)/cosh(u)^2; \
yu: -sin(v)*sinh(u)/cosh(u)^2; \
zu: 1 - 1/cosh(u)^2; \
xv: -sin(v)/cosh(u); \
yv: cos(v)/cosh(u); \
zv: 0; \
xn: -cos(v)/cosh(u) + cos(v)/cosh(u)^3; \
yn: -sin(v)/cosh(u) + sin(v)/cosh(u)^3; \
zn: -sinh(u)/cosh(u)^3;";
#endif