
#include "zissoide_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_ZISSOIDE_CYLINDER != 0)

void ZissoideCylinder(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ZISSOIDE_CYLINDER)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];

	pasuli_calctype v_q2 = v * v;
	pasuli_calctype v_q2_plus1 = (v_q2 + 1);

	pasuli_calctype a_v2 = a * v_q2;
	pasuli_calctype a_v2_divided = a_v2 / v_q2_plus1;
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype pos_factor = a_v2_divided + R;

	P_X(pos_factor * cos_u);
	P_Y(a_v2 * v / v_q2_plus1);
	P_Z(pos_factor * sin_u);

	UD_X(-PASULI_COND_COPY_POS_Z(pos_factor * sin_u));
	UD_Y(0);
	UD_Z(PASULI_COND_COPY_POS_X(pos_factor * cos_u));

	pasuli_calctype vqp1q = v_q2_plus1 * v_q2_plus1;
	pos_factor = 2 * a * v;

	VD_X(cos_u * pos_factor / vqp1q);
	VD_Y((a * v_q2 * (3 + v_q2)) / (vqp1q));
	VD_Z(sin_u * pos_factor / vqp1q);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_CYLINDER != 0)
char *descZissoideCylinder =
	"name: Zissoide-Cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi:1;\
vs: -5; ve: 5;\
c1:R: 1; c2:a: 1;\
x: (R + a*v*v/(1 + v*v))*cos(u);\
y: a*v^(3)/(1 + v*v);\
z: (R + a*v*v/(1 + v*v))*sin(u);\
xu: -sin(u)*(R+a*v*v/(1+v*v));\
yu: 0;\
zu: cos(u)*(R+a*v*v/(1+v*v));\
xv: 2*a*v*cos(u)/((1+v*v)^2);\
yv: a*v*v*(v*v + 3)/((1+v*v)^2);\
zv: 2*a*v*sin(u)/((1+v*v)^2);\
xn: ?;\
yn: ?;\
zn: ?;\
xuu: -(R+(a*v*v)/(1+v*v))*cos(u);\
yuu: 0;\
zuu: -(R+(a*v*v)/(1+v*v))*sin(u);\
xuv: -2*a*v*sin(u)/((1+v*v)^2);\
yuv: 0;\
zuv 2*a*v*cos(u)/((1+v*v)^2);\
xvv: 2*a*cos(u)*(4*v^4*/(v*v + 1)^2 - 5*v*v/(v*v + 1) +1) /(v*v + 1);\
yvv: 2*a*v(4*v^4/(v*v+1)^2 + - 7*v*v/(v*v+1) + 3)/(v*v+1);\
zvv: 2*a*cos(u)*(4*v^4*/(v*v + 1)^2 - 5*v*v/(v*v + 1) +1) /(v*v + 1); ";
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct zc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddZissoideCylinder = {
	ZISSOIDE_CYLINDER,
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1, 1, -5, 5, 0}; //zc_constants};
#endif