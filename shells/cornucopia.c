
#include "cornucopia.h"
#include "shells_c_includes.h"

#if (USE_CORNUCOPIA != 0)
void Cornucopia(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CORNUCOPIA)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype exp_av = exp(a * v);
	pasuli_calctype exp_bv = exp(b * v);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(exp_bv * cos_v + exp_av * cos_u * cos_v);
	P_Y(exp_bv * sin_v + exp_av * cos_u * sin_v);
	P_Z(exp_av * sin_u);

	// We ignore the common factor e^(a*v)
	UD_X(-cos_v * sin_u);
	UD_Y(sin_v * sin_u);
	UD_Z(cos_u);

	VD_X(a * exp_av * cos_u * cos_v + b * exp_bv * cos_v - exp_bv * sin_v - exp_av * cos_u * sin_v);
	VD_Y(a * exp_av * cos_u * sin_v + b * exp_bv * sin_v - exp_bv * cos_v - exp_av * cos_u * cos_v);
	VD_Z(a * exp_av * sin_u);

	// We ignore the common factor e^(a*v)
	N_X(-a * exp_av * sin_v - b * exp_bv * cos_u * sin_v - exp_bv * cos_u * cos_v - exp_av * cos_u * cos_u * cos_v);
	N_Y(-a * exp_av * cos_v - b * exp_bv * cos_u * cos_v - exp_bv * cos_u * sin_v - exp_av * cos_u * cos_u * sin_v);
	N_Z(-exp_bv * sin_u - exp_av * cos_u * sin_u);
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

#if (COMPILE_DESC_SHELLS != 0)
char *descCornucopia = "name: Cornucopia;\
cat: shells;\
ut: c; vt: c;\
us:pi:-1; ue:pi:1;\
vs: 0; ve:pi: 2;\
c1:a: 1; c2:b: 1;\
x: e^(b*v)*cos(v) + e^(a*v)*cos(u)*cos(v);\
y: e^(b*v)*sin(v) + e^(a*v)*cos(u)*sin(v);\
z: e^(a*v)*sin(u);\
xu: -e^(a*v)*cos(v)*sin(u);\
yu: -e^(a*v)*sin(v)*sin(u);\
zu: e^(a*v)*cos(u);\
xv: a*e^(a*v)*cos(u)*cos(v) + b*e^(b*v)*cos(v) - e^(b*v)*sin(v) - e^(a*v)*cos(u)*sin(v);\
yv: a*e^(a*v)*cos(u)*sin(v) + b*e^(b*v)*sin(v) - e^(b*v)*cos(v) - e^(a*v)*cos(u)*cos(v);\
zv: a*e^(a*v)*sin(u);\
xn: -a*e^(2*a*v)*sin(v) - b*e^(a*v+b*v)*cos(u)*sin(v) - e^(a*v+b*v)*cos(u)*cos(v) - e^(2*a*v)*cos(u)^(2)*cos(v);\
yn: a*e^(2*a*v)*cos(v) + b*e^(a*v+b*v)*cos(u)*cos(v) - e^(a*v+b*v)*cos(u)*sin(v) - e^(2*a*v)*cos(u)^(2)*sin(v);\
zn: -e^(a*v+b*v)*sin(u) - e^(2*a*v)*cos(u)*sin(u);\
xuu: -e^(a*v)*cos(u)*cos(v);\
yuu: -e^(a*v)*cos(u)*sin(v);\
zuu: -e^(a*v)*sin(u);\
xuv: -a*e^(a*v)*cos(v)*sin(u) + e^(a*v)*sin(u)*sin(v);\
yuv: -a*e^(a*v)*sin(v)*sin(u) - e^(a*v)*sin(u)*cos(v);\
zuv: a*e^(a*v)*cos(u);\
xvv: a*a*e^(a*v)*cos(u)*cos(v) - 2*a*e^(a*v)*cos(u)*sin(v) + b*b*e^(b*v)*cos(v) - 2*b*e^(b*v)*sin(v) - e^(b*v)*cos(v) - e^(a*v)*cos(u)*cos(v);\
yvv: a*a*e^(a*v)*cos(u)*sin(v) + 2*a*e^(a*v)*cos(u)*cos(v) + b*b*e^(b*v)*sin(v) + 2*b*e^(b*v)*cos(v) - e^(b*v)*sin(v) - e^(a*v)*cos(u)*sin(v);\
zvv: a*a*e^(a*v)*sin(u); ";
#endif