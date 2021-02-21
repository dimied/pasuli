
#include "snails.h"
#include "shells_c_includes.h"

#if (USE_SNAILS_SOMEWHERE)
void Snails(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SNAILS)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];
	pasuli_consttype b = constants[2];
	pasuli_consttype c = constants[3];
	pasuli_consttype h = constants[4];
	pasuli_consttype k = constants[5];
	pasuli_consttype w = constants[6];

	pasuli_calctype cos_cu = cos(c * u);
	pasuli_calctype sin_cu = sin(c * u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype h_a_cos_v = h + a * cos_v;
	pasuli_calctype exp_wu = exp(w * u);

	P_X(exp_wu * h_a_cos_v * cos_cu);
	P_Y(R * exp_wu * h_a_cos_v * sin_cu);
	P_Z(exp_wu * (k + b * sin_v));

	UD_X((-a * c * cos_v * sin_cu + a * cos_v * cos_cu - c * h * sin_cu + h * w * cos_cu) * exp_wu);
	UD_Y((a * c * cos_v * cos_cu + a * cos_v * sin_cu + c * h * cos_cu + h * w * sin_cu) * R * exp_wu);
	UD_Z((b * w * sin_v + k * w) * exp_wu);

	VD_X(-(a * cos_cu * sin_v) * exp_wu);
	VD_Y(-(a * sin_cu * sin_v) * R * exp_wu);
	VD_Z((b * cos_v) * exp_wu);

	PASULI_CALC_NORMAL_FROM_UD_VD
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
char *descSnails = "name: Cornucopia;\
cat: shells;\
ut: c; vt: c;\
us: 0; ue: 1;\
vs: 0; ve:pi: 2;\
c1:R: 1; c2:a: 1;\
c3:b: 1; c4:c: 1;\
c5:h: 1; c6:k: 1;\
c7:w: 1;\
x: e^(w*u)*(h+a*cos(v))*cos(c*u);\
y: R*e^(w*u)*(h+a*cos(v))*sin(c*u);\
z: e^(w*u)*(k + b*sin(v));\
xu: e^(u*w)*(-a*c*cos(v)*sin(c*u) + a*cos(v)*cos(c*u) - c*h*sin(c*u) + h*w*cos(c*u));\
yu: R*e^(u*w)*(a*c*cos(v)*cos(c*u) + a*cos(v)*sin(c*u) + c*h*cos(c*u) + h*w*sin(c*u));\
zu: e^(u*w)*(b*w*sin(v) + k*w);\
xv: -e^(u*w)*a*cos(c*u)*sin(v);\
yv: -e^(u*w)*a*sin(c*u)*R*sin(v);\
zv: e^(u*w)*b*cos(v); ";
#endif