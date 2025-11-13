
#include "lemniskate_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_LEMNISKATE_CYLINDER != 0)

void LemniskateCylinder(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LEMNISKATE_CYLINDER)

	pasuli_consttype r = constants[0];
	pasuli_consttype H = constants[1];

	pasuli_consttype sin_u = sin(u);
	pasuli_consttype cos_u = cos(u);
	pasuli_consttype sin_u_pow2 = sin_u * sin_u;
	pasuli_consttype divisor = sin_u_pow2 + 1.0;

	P_X(r * cos_u / divisor);
	P_Y(H * v);
	P_Z(r * sin_u * cos_u / divisor);

	pasuli_consttype x_u_q = divisor * divisor;
	pasuli_consttype cos_u_pow2 = cos_u * cos_u;

	UD_X(-r * sin_u * (1 + 2 * cos_u_pow2 / divisor) / divisor);
	UD_Y_CONST(0);
	UD_Z(r * ((cos_u_pow2 - sin_u_pow2) / divisor - 2 * cos_u_pow2 * sin_u_pow2 / x_u_q));

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	N_X(-H * PASULI_COND_COPY_UD_Z(r * ((cos_u_pow2 - sin_u_pow2) / divisor - 2 * cos_u_pow2 * sin_u_pow2 / x_u_q)));
	N_Y(0);
	N_Z(H * PASULI_COND_COPY_UD_X(-r * sin_u * (1 + 2 * cos_u_pow2 / divisor) / divisor));
}
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct lc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddLemniskateCylinder = {
	LEMNISKATE_CYLINDER,
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1, 1, 0, 1, 0}; //lc_constants};
#endif
#if (COMPILE_DESC_CYLINDER != 0)
char *descLemniskateCylinder =
	"name: Lemniskate-Cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi:1;\
vs:0; ve: 1;\
c1:r: 1.0; c2:H: 1.0;\
x: r*cos(u)/(1 + sin(u)^2);\
y: H*v;\
z: r*sin(u)*cos(u)/(1 + sin(u)^2);\
xu: -r*sin(u)*(1 + 2*cos(u)^2 / (sin(u)^2 + 1))/(sin(u)^2 + 1);\
yu: 0;\
zu: r*( cos(u)^(2)/(sin(u)^2 + 1) - sin(u)^(2)/(sin(u)^(2) + 1) - 2*cos(u)^(2)*sin(u)^(2)/(sin(u)^(2) + 1)^(2) );\
xv: 0;\
yv: H;\
zv: 0;\
xn: -H* (r*( cos(u)^(2)/(sin(u)^2 + 1) - sin(u)^(2)/(sin(u)^(2) + 1) - 2*cos(u)^(2)*sin(u)^(2)/(sin(u)^(2) + 1)^(2) ));\
yn: 0;\
zn: H*(-r*sin(u)*(1 + 2*cos(u)^2 / (sin(u)^2 + 1))/(sin(u)^2 + 1));\
xuu : ?;\
yuu : 0;\
zuu : ?;\
xuv : 0; yuv : 0; zuv 0;\
xvv : 0; yvv : 0; zvv 0;";
#endif