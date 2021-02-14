
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

	pasuli_consttype vq = v * v;
	pasuli_consttype vqp1 = (vq + 1);
	pasuli_consttype vsq = (a * (vq - 1)) / (vq + 1);

	pasuli_consttype su = sin(u);
	pasuli_consttype cu = cos(u);
	pasuli_consttype xz = vsq + R;

	P_X(xz * cu);
	P_Y(vsq * v);
	P_Z(xz * su);

	UD_X(-PASULI_COND_COPY_POS_Z(xz * su));
	UD_Y_CONST(0);
	UD_Z(PASULI_COND_COPY_POS_X(xz * cu));

	pasuli_consttype vqp1q = vqp1 * vqp1;

	//TODO
	pasuli_consttype vd = (4 * a * v) / (vqp1q);
	VD_X(vd * cu);
	VD_Y(a * (2 * vq * (1 - vq) / (vqp1q) + (3 * vq - 1) / vqp1));
	VD_Z(vd * su);

	vd = vqp1q * vqp1;
	xz = a * (R * (1 - vq * (3 - vq * (5 - vq))) + a * (-1.0 + vq * (5 - vq * (3 - vq)))) / (vd);
	N_X(xz * cu);
	N_Y(4 * a * v * (R - a + vq * (R + a)) / vd);
	N_Z(xz * su);
}
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
#if (COMPILE_DESC_CYLINDER != 0)
char *descStrophoideCylinder =
	"name: Strophoide-Cylinder; \
ut: c; vt: o; \
us:pi: -1; ue:pi : 1; \
vs: -2; ve: 2; \
c1:R: 1; c2:a: 1; \
x: (R + a*(v*v - 1)/(v*v + 1))*cos(u); \
y: a*v*(v*v - 1)/(v*v + 1); \
z: (R + a*(v*v - 1)/(v*v + 1))*sin(u); "
#if (COMPILE_DESC_DERIV_U_CYLINDER != 0)
	"xu: sin(u)*(a-R-(R+a)*v*v)/(1+v*v); \
yu: 0; \
zu: cos(u)*(R-a+(R+a)*v*v)/(1+v*v); "
#endif
#if (COMPILE_DESC_DERIV_V_CYLINDER != 0)
	"xv: 4*a*v*cos(u)*(1+v*v*(3+v*v*(3+v*v)))/((1+v*v)^5); \
yv: a*(-1+v*v*v*v*(11+v*v*(24+v*v*(21+v*v*(8+v*v)))))/((1+v*v)^6); \
zv: 4*a*v*sin(u)*(1+v*v*(3+v*v*(3+v*v)))/((1+v*v)^5); "
#endif
#if (COMPILE_DESC_NORMAL_CYLINDER != 0)
	"xn: a*cos(u)*(R-a-v*v*((3*R-5*a) - v*v*((5*R-3*a)-(R+a)*v*v)))/((1+v*v)^3); \
yn: 4*a*v*(R-a+v*v*(R+a))/((1+v*v)^3); \
zn: a*sin(u)*(R-a-v*v*((3*R-5*a) - v*v*((5*R-3*a)-(R+a)*v*v)))/((1+v*v)^3); "
#endif
	"xuu: cos(u)*(a-R - v*v*(R+a))/(1+v*v); \
yuu: 0; \
zuu: sin(u)*(a-R - v*v*(R+a))/(1+v*v); "
	"xuv: 4*a*v*(-1-v*v*(3 + v*v*(3 + v*v)))*sin(u)/((1+v*v)^5); \
yuv: 0; \
zuv: 4*a*v*(1+v*v*(3 + v*v*(3 + v*v)))*cos(u)/((1+v*v)^5); "
	"xvv: 4*a*cos(u)*(1+v*v*(5+v*v*(4-v*v*(28+v*v*(98+v*v*(154 + v*v*(140+v*v*(76+v*v*(23+3*v*v)))))))))/((1+v*v)^11); \
yvv: 4*a*v*(3+v*v*(14+v*v*(25+v*v*(20+v*v*(5-v*v*(2 + v*v))))))/((1+v*v)^8); \
zvv 4*a*sin(u)*(1+v*v*(5+v*v*(4-v*v*(28+v*v*(98+v*v*(154 + v*v*(140+v*v*(76+v*v*(23+3*v*v)))))))))/((1+v*v)^11); "
	"end;";
#endif