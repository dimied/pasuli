
#include "torus_knot.h"
#include "torus_c_includes.h"

#if (USE_TORUS_KNOT != 0)

void TorusKnot(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TORUS_KNOT)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R2 = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype p = constants[3];
	pasuli_consttype q = constants[4];

	pasuli_calctype cos_qu = cos(q * u);
	pasuli_calctype cos_pu = cos(p * u);

	pasuli_calctype sin_qu = sin(q * u);
	pasuli_calctype sin_pu = sin(p * u);

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype factor = R1 + R2 * cos_pu + r * cos_v;

	P_X(factor * cos_qu);
	P_Y(factor * sin_qu);
	P_Z(r * sin_v + R2 * sin_pu);

	pasuli_calctype ud_factor = -p * R2 * sin_pu;
	UD_X(ud_factor * cos_qu - sin_qu * q * factor);
	UD_Y(ud_factor * sin_qu + cos_qu * q * factor);
	UD_Z(p * R2 * cos_pu);

	r = PASULI_CALC_SIGN(r);
	VD_X(-r * sin_v * cos_qu);
	VD_Y(-r * sin_v * sin_qu);
	VD_Z(r * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTorusKnot = {
	PSLDD_ID(TORUS_KNOT)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(5),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descTorusKnot =
	"name: Torus Knot;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R1:1; c2:R2:1; c3:r:1; c4:p:1; c5:q:1;\
a1:F: (R1 + R2*cos(p*u) + r*cos(v));\
x: F*cos(q*u);\
y: F*sin(q*u);\
z: r*sin(v) + R2*sin(p*u);\
xu: -p*R2*cos(q*u)*sin(p*u)-sin(q*u)*q*(r*cos(v)+R1+R2*cos(p*u));\
yu: -p*R2*sin(q*u)*sin(p*u)+cos(q*u)*q*(r*cos(v)+R1+R2*cos(p*u));\
zu: p*R2*cos(p*u);\
xv: -r*cos(q*u)*sin(v);\
yv: -r*sin(q*u)*sin(v);\
zv: r*cos(v);";
#endif