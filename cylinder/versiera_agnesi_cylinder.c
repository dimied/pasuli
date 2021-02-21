
#include "versiera_agnesi_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_VERSIERA_AGNESI_CYLINDER != 0)
void VersieraAgnesiCylinder(pasuli_vartype u,
							pasuli_vartype v,
							pasuli_consttype *constants,
							PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(VERSIERA_AGNESI_CYLINDER)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];

	a *= 2.0; //attention

	pasuli_calctype v_q2_plus1 = (1 + v * v);
	pasuli_calctype R_plus_2a_divided = R + a / v_q2_plus1;
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	P_X(R_plus_2a_divided * cos_u);
	P_Y(a * v);
	P_Z(R_plus_2a_divided * sin_u);

	UD_X(-PASULI_COND_COPY_POS_Z(R_plus_2a_divided * sin_u));
	UD_Y_CONST(0);
	UD_Z(PASULI_COND_COPY_POS_X(R_plus_2a_divided * cos_u));

	R_plus_2a_divided = -2.0 * a * v / (v_q2_plus1 * v_q2_plus1);

	VD_X(R_plus_2a_divided * cos_u);
	VD_Y(a);
	VD_Z(R_plus_2a_divided * sin_u);

	NORMAL_OP(R_plus_2a_divided = -a * (a / v_q2_plus1 - R));

	N_X(R_plus_2a_divided * cos_u);
	N_Y(-2 * a * v * (R + a + R * v * v) / (v_q2_plus1 * v_q2_plus1 * v_q2_plus1));
	N_Z(R_plus_2a_divided * sin_u);
}
#endif

#if (COMPILE_DESC_CYLINDER != 0)
char *descVersieraAgnesiCylinder =
	"name: Versiera-Agnesi-Cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi: 1;\
vs: -3; ve: 3;\
c1:R: 1; c2:a: 1;\
x: (R + 2*a/(1 + v*v))*cos(u);\
y: 2*a*v;\
z: (R + 2*a/(1 + v*v))*sin(u);\
xu: -sin(u)*(R+2*a/(1+v*v));\
yu: 0;\
zu: cos(u)*(R+2*a/(1+v*v));\
xv: -4*a*v*cos(u)/((1+v*v)^2);\
yv: 2*a;\
zv: -4*a*v*sin(u)/((1+v*v)^2);\
xn: -2*a*(2*a/(1+v*v)-R)*cos(u);\
yn: -4*a*v*(R + 2*a + R*v*v)/((1+v*v)^3);\
xn: -2*a*(2*a/(1+v*v)-R)*sin(u);\
xuu : -cos(u) * (R + 2 * a * / (1 + v * v));\
yuu : 0;\
zuu : -sin(u) * (R + 2 * a * / (1 + v * v));\
xuv : 4 * a *v *sin(u) / ((1 + v * v) ^ 2);\
yuv : 0;\
zuv : -4 * a *v *cos(u) / ((1 + v * v) ^ 2);\
xvv : 4 * a * cos(u)*(4*v/(1 + v * v) - 1) / ((1 + v * v) ^ 2);\
yvv: 0;\
zvv: 4 * a * sin(u)*(4*v/(1 + v * v) - 1) / ((1 + v * v) ^ 2);";
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct vac_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddVACylinder = {
	PSLDD_ID(VERSIERA_AGNESI_CYLINDER)
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1, 1, -3, 4, 0}; //vac_constants};
#endif