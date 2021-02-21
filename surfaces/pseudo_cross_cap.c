
#include "pseudo_cross_cap.h"
#include "surfaces_c_includes.h"

#if (USE_PSEUDO_CROSS_CAP != 0)

void PseudoCrossCap(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PSEUDO_CROSS_CAP)

	pasuli_calctype one_minus_usq = 1.0 - u * u;

	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_2v = sin(2 * v);
	P_X(one_minus_usq * sin_v);
	P_Y(one_minus_usq * sin_2v);
	P_Z(u);

	UD_X(-2 * u * sin_v);
	UD_Y(-2 * u * sin_2v);
	UD_Z(1);

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_2v = cos(2 * v);

	VD_X(one_minus_usq * cos_v);
	VD_Y(2 * one_minus_usq * cos_2v);
	VD_Z(0);

	pasuli_calctype factor;
	PASULI_CALC_FACTOR(factor, one_minus_usq);

	N_X(-2 * factor * cos_2v);
	N_Y(factor * cos_v);
	N_Z(2 * u * factor * (cos_v * sin_2v - 2 * cos_2v * sin_v));

	UUD_X(-2 * sin_v);
	UUD_Y(-2 * sin_2v);
	UUD_Z_CONST(0);

	UVD_X(-2 * u * cos_v);
	UVD_Y(-4 * u * cos_2v);
	UVD_Z_CONST(0);

	VVD_X(-one_minus_usq * sin_v);
	VVD_Y(-4 * one_minus_usq * sin_2v);
	VVD_Z_CONST(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPseudoCrossCap = {
	PSLDD_ID(PSEUDO_CROSS_CAP)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descPseudoCrossCap =
	"name: Pseudo Cross Cap;\
ut:c; vt:c;\
us: -1; ue: 1;\
vs:pi: -1; ve:pi: 1;\
x: (1 - u*u)*sin(v);\
y: (1 - u*u)*sin(2*v);\
z: u;\
xu: -2*u*sin(v);\
yu: -2*u*sin(2*v);\
zu: 1;\
xv: (1 - u*u)*cos(v);\
yv: 2*(1 - u*u)*cos(2*v);\
zv: 0;\
xn: -2*(1-u^2)*cos(2*v);\
yn: (1-u^2)*cos(v);\
zn: 2*u*(1-u^2)*(cos(v)*sin(2*v) -2*cos(2*v)*sin(v));\
xuu: -2*sin(v);\
yuu: -2*sin(2*v);\
zuu: 0;\
xuv: -2*u*cos(v);\
yuv: -4*u*cos(2*v);\
zuv: 0;\
xvv: -(1-u^2)*sin(v);\
yvv: -4*(1-u^2)*sin(2*v);\
zvv: 0;";
#endif