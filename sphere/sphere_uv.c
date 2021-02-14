
#include "sphere_uv.h"
#include "sphere_c_includes.h"

#if (USE_SPHERE_UV != 0)
void SphereUV(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPHERE_UV)

	double uq = u * u;
	double vq = v * v;
	double uqp1 = u * u + 1.0;
	double u2 = u * 2.0;
	double vqp1 = v * v + 1.0;

	P_X((u2 * (1.0 - vq)) / (uqp1 * vqp1));
	P_Y((1.0 - uq) / (uqp1));
	P_Z((2.0 * v) / (uqp1 * vqp1));

	double uqp1q = uqp1 * uqp1;
	double divisor = vqp1 * uqp1q;

	UD_X(2 * (1 + uq * (1 - vq - uq * (1 + vq - uq * (1 - vq))) - vq) / (divisor * uqp1q));
	UD_Y(4 * u * (-1 - uq * (3 - uq * (3 - uq))) / (uqp1 * uqp1q * uqp1q));
	UD_Z(4 * v * (1 - vq) / (uqp1q * vqp1));

	double vqp1q = vqp1 * vqp1;

	VD_X(-8 * u * v * (1 + vq * (3 + vq * (3 + vq))) / (uqp1 * vqp1q * vqp1q * vqp1));
	VD_Y_CONST(0);
	VD_Z(4 * u * (1 - vq) / (uqp1 * vqp1q));

	divisor = uqp1q * vqp1q * uqp1;
	N_X(16 * uq * (vq - 1) / divisor);
	N_Y(8 * u * (-1 + uq - vq + uq * vq) / divisor);
	N_Z(32 * uq * v / divisor);

	divisor = uqp1q * uqp1 * vqp1;

	UUD_X(4 * u * (3 * (vq - 1) + uq * (1 - vq)) / divisor);
	UUD_Y(4 * (-1 + uq * (-1 + uq * (5 + uq * (20 + uq * (25 + uq * (14 + 3 * uq)))))) / (uqp1q * uqp1q * uqp1q * uqp1q));
	UUD_Z(8 * u * v * (uq - 3) / divisor);

	divisor = vqp1q * uqp1q;
	UVD_X(8 * v * (uq - 1) / divisor);
	UVD_Y_CONST(0);
	UVD_Z(4 * (1 - vq - uq + uq * vq) / divisor);

	divisor = uqp1 * vqp1q * vqp1;
	VVD_X(8 * u * (-1 + vq * (-5 + vq * (-4 + vq * (28 + vq * (98 + vq * (154 + vq * (140 + vq * (76 + vq * (23 + vq * 3))))))))) / (divisor * vqp1q * vqp1q * vqp1q * vqp1q));
	VVD_Y_CONST(0);
	VVD_Z(8 * u * v * (vq - 3) / divisor);
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereUV = {
	PSLDD_ID(SPHERE_UV)
			PASULI_FULL_IMPL |
		PASULI_U_CLOSED | PASULI_V_CLOSED,
	0, 10, -10, 10, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descSphereUV =
	"name: sphere uv; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: 10; \
vs: -10; \
ve: 10; \
x: 2*u*(1 - v*v)/((1 + u*u)*(1 + v*v)); \
y: (1 - u*u)/(1 + u*u); \
z: (4*u*v)/((1 + u*u)*(1 + v*v)); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: 2*(2*u*u*v*v - 2*u*u + (1 + u*u)*(1-v*v))/((1 + u*u)^2)*(1 + v*v)); \
yu: -4*u/(1+u*u)^2; \
zu: 4*v*(1 - u*u)/((1 + u*u)^2)*(1 + v*v)); "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: -8*u*v/((1 + u*u))*((1 + v*v))^2); \
yv: 0; \
zv: 4*u*(1-v*v)/((1 + u*u))*((1 + v*v))^2); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: 16*u*u(v*v - 1)/((1 + u*u)^3)*((1 + v*v))^2); \
yn: 8*u*(u*u*(1+v*v)-(1+v*v))/((1 + u*u)^3)*((1 + v*v))^2); \
zn: -32*u*u*v/((1 + u*u)^3)*((1 + v*v))^2); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: 4*u*(u*u*(1-v*v) + 3*(v*v-1))/((1 + u*u)^3)*(1 + v*v)); \
yuu: 4*(-1 + u*u*(-2 + u*u*(5 * u*u*(20 + u*u*(50 + u*u*(14 + 3*u*u))))))/((1 + u*u)^8); \
zuu: 8*u*v*(u*u - 3)/((1 + u*u)^3)*(1 + v*v)); "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: 8*v*(u*u - 1)/((1 + u*u)^2)*(1 + v*v)^2); \
yuv: 0; \
zuv: 4*(u*u*(v*v-1) - (v*v-1))/((1 + u*u)^2)*(1 + v*v)^2); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xvv: 8*u*(-1 + v*v*(-5 + v*v*(-4 + v*v*(28 + v*v*(98 + v*v*(154 + v*v*(140 + v*v*(76 + v*v*(23 + 3*v*v)))))))))/((1 + u*u))*(1 + v*v)^11); \
yvv: 0; \
zvv: 8*u*v*(v*v-3)/((1 + u*u))*(1 + v*v)^3); "
#endif
	"end;";
#endif