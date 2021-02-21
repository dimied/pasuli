
#include "egg.h"
#include "surfaces_c_includes.h"

#if (USE_EGG != 0)
void Egg(pasuli_vartype u, pasuli_vartype v,
		 pasuli_consttype *constants,
		 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EGG)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype sqrt_uab = sqrt(u * (u - a) * (u - b));
	pasuli_calctype pos_factor = c * sqrt_uab;

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(pos_factor * sin_v);
	P_Y(pos_factor * cos_v);
	P_Z(u);

	pasuli_calctype ud_common = c * (u * (a + b - 2 * u) - (a - u) * (b - u));
	// Scale by 2*sqrt(u*(a-u)*(b-u)) to avoid division
	UD_X(-ud_common * sin_v);
	UD_Y(ud_common * cos_v);
	UD_Z(2 * sqrt(u * (a - u) * (b - u)));

	// Skip multiplication by sqrt(u * (u - a) * (u - b))
	VD_X(c * cos_v);
	VD_Y(-c * sin_v);
	VD_Z_CONST(0);

	// Avoid one multiplication by c
	pasuli_calctype normal_factor = (c < 0) ? -1 : 1;

	N_X(normal_factor * sqrt_uab * sin_v);
	N_Y(normal_factor * sqrt_uab * cos_v);
	N_Z(normal_factor * (-a * b + a + b - u * u * 1.5) * c);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0) //TODO TODO
PaSuLiDefDesc pslddEgg = {
	PSLDD_ID(EGG)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_CONST_COUNT(3) |
		PASULI_CALC_U_END,
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descEgg =
	"name: Egg;\
ut: c; vt: c;\
us: 0; ue: c1: 1;\
vs: 0; ve:pi: 2;\
c1:a: 0.5; c2:b: 0.5; c3:c: 1.0;\
cond:a:<=:c;\
x: c*sqrt(u*(u - a)*(u - b))*sin(v);\
y: c*sqrt(u*(u - a)*(u - b))*cos(v);\
z: u;\
xu: -c*(u*(a+b - 2*u) - (a-u)*(b-u))*sin(v)/2*sqrt(u*(a-u)*(b-u));\
yu: -c*(u*(a+b - 2*u) - (a-u)*(b-u))*cos(v)/2*sqrt(u*(a-u)*(b-u));\
zu: 1;\
xv: c*sqrt(u*(u - a)*(u - b))*cos(v);\
yv: -c*sqrt(u*(u - a)*(u - b))*sin(v);\
zv: 0;\
xn: c*sqrt(u*(u - a)*(u - b))*sin(v);\
yn: c*sqrt(u*(u - a)*(u - b))*cos(v);\
zn: -a*b*c^2/2 + a*c^2 + b*c^2 - 3*c^2*u^2/2;";
#endif