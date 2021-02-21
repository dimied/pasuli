
#include "snail.h"
#include "shells_c_includes.h"

#if (USE_SNAIL != 0)
void Snail(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SNAIL)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype h = exp(u / (6 * MY_PI));
	pasuli_calctype h_minus_1 = h - 1;
	pasuli_calctype eubpi = exp(u / (b * MY_PI));

	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_v = cos(v);

	// 2*cos(v/2) = 1 + cos(v) => cos(v/2)^2 = (1+cos(v))/2
	pasuli_calctype cos_half_v_sq = 0.5 + 0.5 * cos_v;

	P_X(a * (1 - h) * cos_u * cos_half_v_sq);
	P_Y(1 - eubpi + h_minus_1 * sin_v);
	P_Z(a * h_minus_1 * sin_u * cos_half_v_sq);

	pasuli_calctype six_pi = 6 * MY_PI;
	UD_X(h_minus_1 * cos_half_v_sq * sin_u - a * h * cos_u * cos_half_v_sq / six_pi);
	UD_Y(h * sin_v / six_pi - h / (b * MY_PI));
	UD_Z(h_minus_1 * cos_half_v_sq * cos_u - a * h * sin_u * cos_half_v_sq / six_pi);

	// sin(2*x) = 2*sin(x)*cos(x) 
	// => sin(0.5 * v) * cos(0.5 * v) = sin(v)*0.5
	VD_OP(pasuli_calctype vd_common = a * h_minus_1 * sin_v*0.5);
	VD_X(vd_common * cos_u);
	VD_Y(h_minus_1 * cos_v);
	VD_Z(-vd_common * sin_u);

	PASULI_CALC_NORMAL_FROM_UD_VD
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
char *descSnail = "name: Snail;\
cat: shells;\
ut: c; vt: c;\
us: 0; ue:pi: 6;\
vs: 0; ve:pi: 2;\
c1:a: 1; c2:b: 1;\
a1:h: e^(u/(6*pi));\
x: a*(1-h)*cos(u)*cos(0.5*v)*cos(0.5*v);\
y: 1 - e^(u/(b*pi)) - sin(v) + h*sin(v);\
z: a*(h-1)*sin(u)*cos(0.5*v)*cos(0.5*v);\
xu: a*h*cos(0.5*v)^2*sin(u) - a*cos(0.5*v)^2*sin(u) - a*h*cos(u)*cos(0.5*v)^2/(6*pi);\
yu: h*sin(v)/6*pi - h/(b*pi);\
zu: a*h*cos(0.5*v)^2*cos(u) - a*cos(0.5*v)^2*cos(u) - a*h*sin(u)*cos(0.5*v)^2/(6*pi);\
xv: a*(h-1)*cos(u)*sin(0.5*v)*cos(0.5*v);\
yv: (h-1)*cos(v);\
zv: a*(1-h)*sin(u)*sin(0.5*v)*cos(0.5*v); ";
#endif