
#include "braided_torus.h"
#include "torus_c_includes.h"

#if (USE_BRAIDED_TORUS != 0)

void BraidedTorus(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BRAIDED_TORUS)

	pasuli_consttype a = constants[0];
	pasuli_consttype R = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_Nu = cos(N * u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_Nu = sin(N * u);

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype factor = R * (1 + a * cos_Nu);

	P_X(cos_u * (r * cos_v + factor));
	P_Y(sin_u * (r * cos_v + factor));
	P_Z(2.5 * (r * sin_v + a * sin_Nu));

	UD_X(-sin_u * (r * cos_v + R * (1 + a * (cos_Nu + N * sin_Nu))));
	UD_Y(cos_u * (r * cos_v + factor) - a * R * N * sin_u * sin_Nu);
	UD_Z(2.5 * a * N * cos_Nu);

	pasuli_calctype sign_value = PASULI_CALC_SIGN(r);
	VD_X(-sign_value * cos_u * sin_v);
	VD_Y(-sign_value * sin_u * sin_v);
	VD_Z(2.5 * sign_value * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddBraidedTorus = {
	BRAIDED_TORUS,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 8, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descBraidedTorus =
	"name: Braided Torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi: 8;\
vs:0; ve:pi:2;\
c1:a: 1; c2:R: 1; c3:r: 1; c4:n: 1;\
x: r*cos(v)*cos(u)+cos(u)*R*(1 + a*cos(n*u));\
y: r*cos(v)*sin(u) + sin(u)*R*(1 + a*cos(n*u));\
z: 2.5*(r*sin(v) + a*sin(n*u));\
xu: -r*cos(v)*sin(u) - sin(u)*R*(1 + a*(cos(n*u) + n*sin(n*u)));\
yu: r*cos(v)*cos(u)+cos(u)*R*(1 + a*cos(n*u)) -a*R*n*sin(u)*sin(n*u);\
zu: 2.5*a*n*cos(n*u);\
xv: -r*cos(u)*sin(v);\
yv: -r*sin(u)*sin(v);\
zv: 2.5*r*cos(v);";
#endif
