
#include "limpet_torus.h"
#include "torus_c_includes.h"

#if (USE_LIMPET_TORUS != 0)

void LimpetTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LIMPET_TORUS)

	pasuli_calctype sqrt2 = sqrt(2.0);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype sqrt2_plus_cos_v = sqrt2 + cos_v;
	pasuli_calctype sqrt2_plus_sin_v = sqrt2 + sin_v;

	P_X(cos_u / sqrt2_plus_sin_v);
	P_Y(sin_u / sqrt2_plus_sin_v);
	P_Z(1.0 / sqrt2_plus_cos_v);

	// Multiplied by (sqrt(2) + sin(v)), it's always positive
	UD_X(-sin_u);
	UD_Y(cos_u);
	UD_Z(0);

	// MUltiplied by (sqrt(2) + sin(v))^2*(sqrt(2) + cos(v))^2
	pasuli_calctype factor = cos_v * sqrt2_plus_cos_v * sqrt2_plus_cos_v;
	VD_X(-cos_u * factor);
	VD_Y(-sin_u * factor);

	VD_Z(sin_v * sqrt2_plus_sin_v * sqrt2_plus_sin_v);

	//(sqrt(2) + sin(v))^3*(sqrt(2) + cos(v))^2
	// Attention! cos_v reused
	cos_v = sin_v * sqrt2_plus_sin_v * sqrt2_plus_sin_v;
	N_X(cos_u * cos_v);
	N_Y(sin_u * cos_v);
	N_Z(factor);
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLimpetTorus = {
	LIMPET_TORUS,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI,
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descLimpetTorus =
	"name: Limpet Torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
x: cos(u)/(sqrt(2) + sin(v));\
y: sin(u)/(sqrt(2) + sin(v));\
z: 1/(sqrt(2) + cos(v));\
xu: -sin(u)/(sqrt(2) + sin(v));\
yu: cos(u)/(sqrt(2) + sin(v));\
zu: 0;\
xv: -cos(u)*cos(v)/(sqrt(2) + sin(v))^2;\
yv: -sin(u)*cos(v)/(sqrt(2) + sin(v))^2;\
zv: sin(v)/(sqrt(2) + cos(v))^2;\
xn: cos(u)*sin(v)/((sqrt(2) + cos(v))^2*(sqrt(2) + sin(v)));\
yn: sin(u)*sin(v)/((sqrt(2) + cos(v))^2*(sqrt(2) + sin(v)));\
zn: cos(v)/(sqrt(2) + sin(v))^3;";
#endif