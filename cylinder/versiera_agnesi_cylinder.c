
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

	pasuli_consttype vqp1 = (1 + v * v);
	pasuli_consttype xz = R + (a) / vqp1;
	pasuli_consttype cu = cos(u);
	pasuli_consttype su = sin(u);

	P_X(xz * cu);
	P_Y(a * v);
	P_Z(xz * su);

	UD_X(-su * xz);
	UD_Y_CONST(0);
	UD_Z(cu * xz);

	xz = -2.0 * a * v / (vqp1 * vqp1);
	VD_X(xz * cu);
	VD_Y_CONST(a);
	VD_Z(xz * su);

	xz = a * (-R - a / vqp1);
	N_X(xz * cu);
	N_Y(2 * a * v * (-R * vqp1 - a) / (vqp1 * vqp1 * vqp1));
	N_Z(xz * su);
}
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
#if (COMPILE_DESC_CYLINDER != 0)
char *descVACylinder =
	"name: Versiera-Agnesi-Cylinder; \
ut: c; vt: o; \
us:pi: -1; ue:pi: 1; \
vs: -3; ve: 3; \
c1:R: 1; c2:a: 1; \
x: (R + 2*a/(1 + v*v))*cos(u); \
y: 2*a*v; \
z: (R + 2*a/(1 + v*v))*sin(u); "
#if (COMPILE_DESC_DERIV_U_CYLINDER != 0)
	"xu: -sin(u)*(R+2*a/(1+v*v)); \
yu: 0; \
zu: cos(u)*(R+2*a/(1+v*v)); "
#endif
#if (COMPILE_DESC_DERIV_V_CYLINDER != 0)
	"xv: -4*a*v*cos(u)/((1+v*v)^2); \
yv: 2*a; \
zv: -4*a*v*sin(u)/((1+v*v)^2); "
#endif
#if (COMPILE_DESC_NORMAL_CYLINDER != 0)
	"xn: 2*a*cos(u)*(-R-2*a/((1+v*v))); \
yn: 4*a*v*(-R-2*a-R*v*v)/((1+v*v)^3); \
zn: 2*a*sin(u)*(-R-2*a/(1+v*v)); "
#endif
	"xuu: -cos(u)*(R+2*a*/(1+v*v)); \
yuu: 0; \
zuu: -sin(u)*(R+2*a*/(1+v*v)); "
	"xuv: 4*a*v*sin(u)/((1+v*v)^2); \
yuv: 0; \
zuv: -4*a*v*cos(u)/((1+v*v)^2); "
	"xvv: 4*a*(3*v*v-1)*cos(u)/((1+v*v)^3); \
yvv: ;\
zvv 4*a*(3*v*v-1)*sin(u)/((1+v*v)^3); "
	"end;";
#endif