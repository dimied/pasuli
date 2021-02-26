
#include "gauss_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_GAUSS_CYLINDER != 0)
void GaussCylinder(pasuli_vartype u, pasuli_vartype v,
				   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(GAUSS_CYLINDER)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];
	pasuli_consttype b = constants[2];

	pasuli_consttype bExp = v * a;
	bExp = b * exp(-(bExp * bExp));

	pasuli_consttype RplusBExp = R + bExp;

	pasuli_consttype cu = cos(u);
	pasuli_consttype su = sin(u);

	P_X(RplusBExp * cu);
	P_Y(v);
	P_Z(RplusBExp * su);

	UD_X(-RplusBExp * su);
	UD_Y_CONST(0);
	UD_Z(RplusBExp * cu);

	RplusBExp = -2 * a * a * v * bExp;

	VD_X(RplusBExp * cu);
	VD_Y_CONST(1);
	VD_Z(RplusBExp * su);

	RplusBExp = -(R + bExp);

	N_X(RplusBExp * cu);
	N_Y(-2 * a * a * v * bExp * (b + R * exp(v * v * a * a)));
	N_Z(RplusBExp * su);
}
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct gc_constants[] = {1.0, 1.0, 1.0};
PaSuLiDefDesc pslddGaussCylinder = {
	GAUSS_CYLINDER,
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(3),
	-1, 1, 0, 1, 0}; //gc_constants};
#endif
#if (COMPILE_DESC_CYLINDER != 0)
char *descGaussCylinder =
	"name: Gauss-Cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi:1;\
vs:0; ve: 1;\
c1:R: 1; c2:a: 1; c3:b: 1;\
x: (R + b*exp(-(a*a*v*v)))*cos(u);\
y: v;\
z: (R + b*exp(-(a*a*v*v)))*sin(u);\
xu: -sin(u)*(R+b*exp(-a*a*v*v));\
yu: 0;\
zu: cos(u)*(R+b*exp(-a*a*v*v));\
xv: -2*a*a*b*v*exp(-a*a*v*v)*cos(u);\
yv: 1;\
zv: -2*a*a*b*v*exp(-a*a*v*v)*sin(u);\
xn: -cos(u)*(R+b*exp(-a*a*v*v));\
yn: -2*a*a*b*v*exp(-2*a*a*v*v)*(b+R*exp(a*a*v*v));\
zn: -sin(u)*(R+b*exp(-a*a*v*v));\
xuu: -cos(u)*(R+b*exp(-a*a*v*v));\
yuu: 0;\
zuu -sin(u)*(R+b*exp(-a*a*v*v));\
xuv: 2*a*a*b*v*exp(-a*a*v*v)*sin(u);\
yuv: 0;\
zuv: -2*a*a*b*v*exp(-a*a*v*v)*cos(u);\
xvv: cos(u)*(2*a*a*b*exp(-a*a*v*v)*(2*a*a*v*v-1));\
yvv: 0;\
zvv sin(u)*(2*a*a*b*exp(-a*a*v*v)*(2*a*a*v*v-1)); ";
#endif