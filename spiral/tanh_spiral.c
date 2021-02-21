
#include "tanh_spiral.h"
#include "spiral_c_includes.h"

#if (USE_TANH_SPIRAL != 0)
void TanhSpiral(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TANH_SPIRAL)

	pasuli_consttype a = constants[0];
	pasuli_consttype H = constants[1];

	pasuli_calctype cosh_2u = cosh(2 * u);
	pasuli_calctype sinh_2u = sinh(2 * u);
	pasuli_calctype cos_2au = cos(2 * a * u);
	pasuli_calctype sin_2u = sin(2 * u);
	pasuli_calctype divisor = cos_2au + cosh_2u;

	P_X(sinh_2u / divisor);
	P_Y(H * v);
	P_Z(sin_2u / divisor);

	pasuli_calctype sin_2au = sin(2 * a * u);
	pasuli_calctype cos_2u = cos(2 * u);
	// Rule: cosh(x)^2 - sinh(x)^2 = 1
	// No scaling by 2 and no division by ((cos(2*a*u) + cosh(2*u))^2)
	UD_X(a * sin_2au * sinh_2u + 1 + cos_2au * cosh_2u);
	UD_Y_CONST(0);
	UD_Z(a * sin_2au * sin_2u + cos_2au * cos_2u + cos_2u * cosh_2u - sin_2u * sinh_2u);

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	// Np scaling by 2*H and no division by ((cos(2*a*u) + cosh(2*u))^2)

	N_X(-(a * sin_2au * sin_2u + cos_2au * cos_2u + cos_2u * cosh_2u - sin_2u * sinh_2u));
	N_Y_CONST(0);
	N_Z(a * sin_2au * sinh_2u + 1 + cos_2au * cosh_2u);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddTanhSpiral = {
	PSLDD_ID(TANH_SPIRAL)
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1.5, 1.5, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descTanhSpiral =
	"name: Tanh Spiral;\
cat: spiral;\
ut: c; vt: o;\
us: -1.5; ue: 1.5;\
vs: 0; ve: 1;\
c1:a: 1; c2:H: 1;\
x: sinh(2*u)/(cos(2*a*u) + cosh(2*u));\
y: H*v;\
z: sin(2*u)/(cos(2*a*u) + cosh(2*u));\
xu: 2*(a*sin(2*a*u)*sinh(2*u)+(cosh(2*u)^2)-(sinh(2*u)^2)+cos(2*a*u)*cosh(2*u))/((cos(2*a*u) + cosh(2*u))^2);\
yu: 0;\
zu: 2*(a*sin(2*a*u)*sin(2*u)+(cos(2*a*u)*cos(2*u))+cos(2*u)*cosh(2*u)-sin(2*u)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^2);\
xv: 0;\
yv: H;\
zv: 0;\
xn: -H*2*(a*sin(2*a*u)*sin(2*u)+(cos(2*a*u)*cos(2*u))+cos(2*u)*cosh(2*u)-sin(2*u)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^2);\
yn: 0;\
zn: 2*H*(a*sin(2*a*u)*sinh(2*u)+(cosh(2*u)^2)-(sinh(2*u)^2)+cos(2*a*u)*cosh(2*u))/((cos(2*a*u) + cosh(2*u))^2); ";
#endif
