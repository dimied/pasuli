
#include "soucoupid.h"
#include "surfaces_c_includes.h"

#if (USE_SOUCOUPOID != 0)

void Soucoupoid(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SOUCOUPOID)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_u2 = sin_u * sin_u;
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(cos_u * cos_v);
	P_Y(cos_u * sin_v);
	P_Z(sin_u2 * sin_u);

	UD_X(-cos_v * sin_u);
	UD_Y(-sin_v * sin_u);
	UD_Z(3 * cos_u * sin_u2);

	VD_X(-cos_u * sin_v);
	VD_Y(cos_u * cos_v);
	VD_Z(0);

	// we divide by cos(u)*sin(u)
	pasuli_calctype factor;
	PASULI_CALC_FACTOR(factor, cos_u * sin_u);

	N_X(-factor * 3 * cos_v * cos_u * sin_u);
	N_Y(-factor * 3 * sin_v * cos_u * sin_u);
	N_Z(-factor);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSoucoupoid = {
	PSLDD_ID(SOUCOUPOID)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_END_PI,
	-1, 1, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descSoucoupoid =
	"name: Soucoupoid;\
ut:c; vt:c;\
us:pi: -1; ue:pi: 1;\
vs: 0; ve:pi: 1;\
x: cos(u)*cos(v);\
y: cos(u)*sin(v);\
z: (sin(u))^(3);\
xu: -cos(v)*sin(u);\
yu: -sin(v)*sin(u);\
zu: 3*cos(u)*sin(u)^2;\
xv: -cos(u)*sin(v);\
yv: cos(u)*cos(v);\
zv: 0;\
xn: -3*cos(u)^2*cos(v)*sin(u)^2;\
yn: -3*cos(u)^2*sin(v)*sin(u)^2;\
zn: -cos(u)*sin(u);\
xuu: -cos(u)*cos(v);\
yuu: -cos(u)*sin(v);\
zuu: 6*cos(u)^2*sin(u) - 3*sin(u)^3;\
xuv: sin(u)*sin(v);\
yuv: -sin(u)*cos(v);\
zuv: 0;\
xvv: -cos(u)*cos(v);\
yvv: -cos(u)*sin(v);\
zvv: 0;";
#endif