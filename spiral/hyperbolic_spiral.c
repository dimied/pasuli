
#include "hyperbolic_spiral.h"
#include "spiral_c_includes.h"

#if (USE_HYPERBOLIC_SPIRAL != 0)
void HyperbolicSpiral(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPERBOLIC_SPIRAL)

	pasuli_consttype H = constants[0];

	pasuli_calctype cos_u;
	pasuli_calctype sin_u;

	pasuli_calctype cos_u_div_u;
	pasuli_calctype sin_u_div_u;

	if (u > 0.001f)
	{
		cos_u = cos(u);
		sin_u = sin(u);

		cos_u_div_u = cos_u / u;
		sin_u_div_u = sin_u / u;
	}
	else
	{
		cos_u = 1;
		sin_u = 0;

		cos_u_div_u = 1000;
		sin_u_div_u = 1;
	}

	P_X(cos_u_div_u);
	P_Y(v * H);
	P_Z(sin_u_div_u);

	// No division by u^2
	UD_X(-(cos_u + u * sin_u));
	UD_Y_CONST(0);
	UD_Z(u * cos_u - sin_u);

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	// No multiplication by H and no division by u^2
	N_X(sin_u - u * cos_u);
	N_Y_CONST(0);
	N_Z(-(cos_u + u * sin_u));

	//No division by u^3
	UUD_X(2 * cos_u + 2 * u * sin_u - u * u * cos_u);
	UUD_Y_CONST(0);
	UUD_Z(2 * sin_u - 2 * u * cos_u - u * u * sin_u);

	UVD_ALL(0);
	VVD_ALL(0);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddHyperbolicSpiral = {
	PSLDD_ID(HYPERBOLIC_SPIRAL)
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(1),
	0, 23, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descHyperbolicSpiral =
	"name: Hyperbolic Spiral;\
cat: spiral;\
ut: c; vt: o;\
uc:not:0;\
us: 0; ue: 23;\
vs: 0; ve: 1;\
c1:H: 1;\
x: cos(u)/u;\
y: H*v;\
z: sin(u)/u;\
xu: -(cos(u) + u*sin(u))/(u*u);\
yu: 0;\
zu: (u*cos(u)-sin(u))/(u*u);\
xv: 0;\
yv: H;\
zv: 0;\
xn: H*(sin(u)-u*cos(u))/(u*u);\
yn: 0;\
zn: -H*(cos(u) + u*sin(u))/(u*u);\
xuu: (2*cos(u)+2*u*sin(u) - u*u*cos(u))/(u*u*u);\
yuu: 0;\
zuu: (2*sin(u) - 2*u*cos(u) - u*u*sin(u))/(u*u*u);\
xuv: 0; yuv: 0; zuv: 0;\
xvv: 0; yvv: 0; zvv: 0; ";
#endif