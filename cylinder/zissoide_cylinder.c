
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

	pasuli_consttype vq = v * v;
	pasuli_consttype vqp1 = (vq + 1);
	pasuli_consttype vsq = (a * v * v) / vqp1;
	pasuli_consttype su = sin(u);
	pasuli_consttype cu = cos(u);
	pasuli_consttype xz = vsq + R;

	P_X(xz * cu);
	P_Y(vsq * v);
	P_Z(xz * su);

	xz = (R + a * vq / vqp1);
	UD_X(-su * xz);
	UD_Y_CONST(0);
	UD_Z(xz * cu);

	pasuli_consttype vqp1q = vqp1 * vqp1;
	xz = 2 * a * v / (vqp1q);
	VD_X(cu * xz);
	VD_Y((a * vq * (3 * vqp1q - vq)) / (vqp1q));
	VD_Z(su * xz);

	vqp1q *= vqp1;
	xz = a * vq * (-R * (3 + vq * (4 + vq)) - a * vq * (3 + vq)) / vqp1q;
	N_X(xz * cu);
	N_Y(2 * a * v * (R + vq * (R + a)) / vqp1q);
	N_Z(xz * su);
}
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct zc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddZissoideCylinder = {
	PSLDD_ID(ZISSOIDE_CYLINDER)
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1, 1, -5, 5, 0}; //zc_constants};
#endif
#if (COMPILE_DESC_CYLINDER != 0)
char *descZissoideCylinder =
	"name: Zissoide-Cylinder; \
ut: c; vt: o; \
us:pi: -1; ue:pi: 1; \
vs: -5; ve: 5; \
c1:R: 1; c2:a: 1; \
x: (R + a*v*v/(1 + v*v))*cos(u); \
y: a*v^(3)/(1 + v*v); \
z: (R + a*v*v/(1 + v*v))*sin(u); "
#if (COMPILE_DESC_DERIV_U_CYLINDER != 0)
	"xu: -sin(u)*(R+a*v*v/(1+v*v)); \
yu: 0; \
zu: cos(u)*(R+a*v*v/(1+v*v)); "
#endif
#if (COMPILE_DESC_DERIV_V_CYLINDER != 0)
	"xv: 2*a*v*cos(u)/((1+v*v)^2); \
yv: a*v*v*(3+v*v*(4+v*v))/((1+v*v)^3); \
zv: 2*a*v*sin(u)/((1+v*v)^2); "
#endif
#if (COMPILE_DESC_NORMAL_CYLINDER != 0)
	"xn: -cos(u)*a*v*v*(3*R+v*v*((4*R+3*a) + v*v*(R+a)))/((1+v*v)^3); \
yn: 2*a*v*(R+v*v*(R+a))/((1+v*v)^3); \
zn: -sin(u)*a*v*v*(3*R+v*v*((4*R+3*a) + v*v*(R+a)))/((1+v*v)^3); "
#endif
	"xuu: -(R+(a*v*v)/(1+v*v))*cos(u); \
yuu: 0; \
zuu: -(R+(a*v*v)/(1+v*v))*sin(u); "
	"xuv: -2*a*v*sin(u)/((1+v*v)^2); \
yuv: 0\
zuv 2*a*v*cos(u)/((1+v*v)^2); "
	"xvv: 2*a*cos(u)*(1-v*v*v*v*(6 + v*v*(8+3*v*v))))/((1+v*v)^6); \
yvv: /((1+v*v)^3); \
zvv: 2*a*sin(u)*(1-v*v*v*v*(6 + v*v*(8+3*v*v))))/((1+v*v)^6); "
	"end;";
#endif