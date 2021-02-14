
#include "hyperbolic_spiral.h"
#include "spiral_c_includes.h"

#if (USE_HYPERBOLIC_SPIRAL != 0)
void HyperbolicSpiral(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPERBOLIC_SPIRAL)
	double cu;
	double su;

	if (u > 0.001f)
	{
		cu = cos(u) / u;
		su = sin(u) / u;
	}
	else
	{
		cu = 0;
		su = 1;
	}
	double c = constants[0];

	P_X(cu);
	P_Y(v * c);
	P_Z(su);
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
	"name: Hyperbolic Spiral; \
cat: spiral; \
ut: c; vt: o; \
us: 0; ue: 23; \
vs: 0; ve: 1; \
c1:H: 1.0; \
x: cos(u)/u; \
y: H*v; \
z: sin(u)/u; "
#if (COMPILE_DESC_DERIV_U_SPIRAL != 0)
	"xu: -(cos(u) + u*sin(u))/(u*u); \
yu: 0; \
zu: (u*cos(u)-sin(u))/(u*u); "
#endif
#if (COMPILE_DESC_DERIV_V_SPIRAL != 0)
	"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_SPIRAL != 0)
	"xn: H*(sin(u)-u*cos(u))/(u*u); \
yn: 0; \
zn: -H*(cos(u) + u*sin(u))/(u*u); "
#endif
	"xuu: (2*cos(u)+2*u*sin(u) - u*u*cos(u))/(u*u*u); \
yuu: 0; \
zuu: (2*sin(u) - 2*u*cos(u) - u*u*sin(u))/(u*u*u); "
	"xuv: 0; \
yuv: 0; \
zuv: 0; "
	"xvv: 0; \
yvv: 0; \
zvv: 0; "
	"end;";
#endif