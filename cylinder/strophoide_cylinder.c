
#include "strophoide_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_STROPHOIDE_CYLINDER != 0)
void StrophoideCylinder(pasuli_vartype u,
						pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(STROPHOIDE_CYLINDER)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];

	pasuli_calctype v_q2 = v * v;
	pasuli_calctype v_q2_plus1 = (v_q2 + 1);
	pasuli_calctype vsq = (a * (v_q2 - 1)) / (v_q2 + 1);

	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype multiplier = vsq + R;

	P_X(multiplier * cos_u);
	P_Y(vsq * v);
	P_Z(multiplier * sin_u);

	UD_X(-PASULI_COND_COPY_POS_Z(multiplier * sin_u));
	UD_Y(0);
	UD_Z(PASULI_COND_COPY_POS_X(multiplier * cos_u));

	VD_OP(pasuli_calctype vdTemp = a * v * v * ((1 - v_q2) / v_q2_plus1 + 1));
	VD_X(cos_u * vdTemp);
	VD_Y(a * (2 * v_q2 * (1 - v_q2) / v_q2_plus1 + 2 * v_q2 - 1) / v_q2_plus1);
	VD_Z(sin_u * vdTemp);

	PASULI_CALC_NORMAL_FROM_UD_VD

	/*
	vd = vqp1q * v_q2_plus1;
	multiplier = a * (R * (1 - v_q2 * (3 - v_q2 * (5 - v_q2))) + a * (-1.0 + v_q2 * (5 - v_q2 * (3 - v_q2)))) / (vd);
	N_X(multiplier * cos_u);
	N_Y(4 * a * v * (R - a + v_q2 * (R + a)) / vd);
	N_Z(multiplier * sin_u);
	*/
}
#endif

#if (COMPILE_DESC_CYLINDER != 0)
char *descStrophoideCylinder =
	"name: Strophoide-Cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi: 1;\
vs: -2; ve: 2;\
c1:R: 1; c2:a: 1;\
x: (R + a*(v*v - 1)/(v*v + 1))*cos(u);\
y: a*v*(v*v - 1)/(v*v + 1);\
z: (R + a*(v*v - 1)/(v*v + 1))*sin(u);\
xu: sin(u)*(a*(1-v*v)/(1+v*v) -R);\
yu: 0;\
zu: cos(u)*(R+a*(v*v-1)/(1+v*v));\
xv: 2*a*v*cos(u)*( (1 - v*v)/(1+v*v) + 1 )/(1+v*v);\
yv: a * (  2*(v*v - v*v*v*v)/(1+v*v) + 2*v*v   - 1)/(1+v*v);\
zv: 2*a*v*sin(u)*( (1 - v*v)/(1+v*v) + 1 )/(1+v*v);\
xn: ?;\
yn: ?;\
zn: ?;";
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct sc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddStrophoideCylinder = {
	PSLDD_ID(STROPHOIDE_CYLINDER)
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1, 1, -2, 2, 0}; //sc_constants};
#endif