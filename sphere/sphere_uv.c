
#include "sphere_uv.h"
#include "sphere_c_includes.h"

#if (USE_SPHERE_UV != 0)
void SphereUV(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPHERE_UV)

	pasuli_calctype u_squared = u * u;
	pasuli_calctype v_squared = v * v;
	pasuli_calctype u_squared_plus_1 = u * u + 1.0;
	pasuli_calctype u2 = u * 2.0;
	pasuli_calctype v_squared_plus_1 = v * v + 1.0;

	P_X((u2 * (1.0 - v_squared)) / (u_squared_plus_1 * v_squared_plus_1));
	P_Y((1.0 - u_squared) / (u_squared_plus_1));
	P_Z((4.0 * u * v) / (u_squared_plus_1 * v_squared_plus_1));

	pasuli_calctype uqp1q = u_squared_plus_1 * u_squared_plus_1;
	pasuli_calctype divisor = v_squared_plus_1 * uqp1q;

	// No division by common factor (1+u*u)^2
	UD_X(2 * (u_squared * v_squared - u_squared - v_squared + 1) / v_squared_plus_1);
	UD_Y(-4 * u);
	UD_Z(4 * v * (1 - u_squared) / v_squared_plus_1);

	// No division by common factor ((1 + u*u)*(1 + v*v)^2)
	VD_X(-8 * u * v);
	VD_Y_CONST(0);
	VD_Z(4 * u * (1 - v_squared));

	// No division by factor ((1 + u*u)^3*(1 + v*v)^2) and multiplication by 8
	N_X(2 * u_squared * (v_squared - 1));
	N_Y(u * (u_squared * v_squared + u_squared - v_squared - 1));
	N_Z(4 * u_squared * v);

	/* Not validated yet
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
	*/
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
ut: c; vt: c; \
us: 0; ue: 10; \
vs: -10; ve: 10; \
x: 2*u*(1 - v*v)/((1 + u*u)*(1 + v*v)); \
y: (1 - u*u)/(1 + u*u); \
z: (4*u*v)/((1 + u*u)*(1 + v*v)); \
xu: 2*(u^2*v^2 - u^2 - v^2 + 1) / ((1 + u*u)^2*(1 + v*v)); \
yu: -4*u/(1+u*u)^2; \
zu: 4*v*(1 - u*u)/((1 + u*u)^2*(1 + v*v)); \
xv: -8*u*v/((1 + u*u)*(1 + v*v)^2); \
yv: 0; \
zv: 4*u*(1-v*v)/((1 + u*u)*(1 + v*v)^2); \
xn: 16*u*u(v*v - 1)/((1 + u*u)^3*(1 + v*v)^2); \
yn: 8*u*(u^2*v^2 + u^2 - v^2 - 1)/((1 + u*u)^3*(1 + v*v)^2); \
zn: -32*u*u*v/((1 + u*u)^3*(1 + v*v)^2); ";
#endif