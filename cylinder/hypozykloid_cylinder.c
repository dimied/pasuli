
#include "hypozykloid_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_HYPOZYKLOID_CYLINDER != 0)
void HypozykloidCylinder(pasuli_vartype u, pasuli_vartype v,
						 pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPOZYKLOID_CYLINDER)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype h = constants[2];
	pasuli_consttype H = constants[3];
	//ATTENTION
	pasuli_calctype Rdiff = R - r;
	pasuli_calctype cosRdiff = cos(Rdiff * u / r);
	pasuli_calctype sinRdiff = sin(Rdiff * u / r);

	P_X(Rdiff * cos(u) + h * cosRdiff);
	P_Y(H * v);
	P_Z(Rdiff * sin(u) - h * sinRdiff);

	UD_X(h * Rdiff * sinRdiff / r - Rdiff * sin(u));
	UD_Y_CONST(0);
	UD_Z(-h * Rdiff * cosRdiff / r + Rdiff * cos(u));

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	N_X(H * (h * Rdiff * cosRdiff / r - Rdiff * cos(u)));
	N_Y_CONST(0);
	N_Z(H * (h * Rdiff * sinRdiff / r - Rdiff * sin(u)));

	PASULI_2ND_DERIVATIVES_START

	pasuli_calctype uudVal = (h * (Rdiff + R) + h * R * R / r);

	UUD_X(cosRdiff * uudVal / r - Rdiff * cos(u));
	UUD_Y_CONST(0);
	UUD_Z(sinRdiff * uudVal / r - Rdiff * sin(u));

	UVD_ALL(0);

	VVD_ALL(0);

	PASULI_2ND_DERIVATIVES_END
}
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
pasulidefdesc_ct hc_constants[] = {1.5, 1.0, 0.5, 1.0};
PaSuLiDefDesc pslddHypozykloidCylinder = {
	PSLDD_ID(HYPOZYKLOID_CYLINDER)
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(4),
	-1, 1, 0, 1, hc_constants};
#endif
#if (COMPILE_DESC_CYLINDER != 0)
char *descHypozykloidCylinder =
	"name: Hypozykloid-Cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi: 1;\
vs: 0; ve: 1;\
c1:R: 1.5; c2:r: 1.0;\
c3:h: 0.5; c4:H: 1.0;\
cond:r:not:0;\
x: (R - r)*cos(u) + h*cos(((R - r)/r)*u);\
y: H*v;\
z: (R - r)*sin(u) - h*sin(((R - r)/r)*u);\
xu: h*(R - r)*sin((R - r)*u/r)/r -(R - r)*sin(u);\
yu: 0;\
zu: -h*(R - r)*cos((R - r)*u/r)/r + (R - r)*cos(u);\
xv: 0;\
yv: H;\
zv: 0;\
xn: H*(h*(R - r)*cos((R - r)*u/r)/r - (R - r)*cos(u));\
yn: 0;\
zn: H*(h*(R - r)*sin((R - r)*u/r)/r -(R - r)*sin(u));\
xuu: 2*h*R*cos((R - r)*u/r)/r + 2*h*R*R*cos((R - r)*u/r)/(r*r) + h*cos((R - r)*u/r)/r - (R-r)*cos(u);\
yuu: 0;\
zuu: 2*h*R*sin((R - r)*u/r)/r + 2*h*R*R*sin((R - r)*u/r)/(r*r) + h*sin((R - r)*u/r)/r - (R-r)*sin(u);\
xuv: 0; yuv: 0; zuv 0;\
xvv: 0; yvv: 0; zvv 0; ";
#endif