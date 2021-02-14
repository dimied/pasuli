
#include "tanh_spiral.h"
#include "spiral_c_includes.h"

#if (USE_TANH_SPIRAL != 0)
void TanhSpiral(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TANH_SPIRAL)

	double x_u;
	double z_u;
	double a = constants[0];
	double H = constants[1];

	if (u > 0)
	{
		u *= 2.0;
		z_u = cos(a * u) + cosh(u);
		x_u = sin(u) / z_u;
		z_u = sin(a * u) / z_u;
	}
	else
	{
		x_u = 0;
		z_u = 0;
	}

	P_X(x_u);
	P_Y(H * v);
	P_Z(z_u);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddTanhSpiral = {
	PSLDD_ID(TANH_SPIRAL)
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	-1.5, 1.5, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descTanhSpiral =
	"name: Tanh Spiral; \
cat: spiral; \
ut: c; \
vt: o; \
us: -1.5; \
ue: 1.5; \
vs: 0; \
ve: 1; \
c1:a: 1.0; \
c2:H: 1.0; \
x: sinh(2*u)/(cos(2*a*u) + cosh(2*u)); \
y: H*v; \
z: sin(2*u)/(cos(2*a*u) + cosh(2*u)); "
#if (COMPILE_DESC_DERIV_U_SPIRAL != 0)
	"xu: 2*(a*sin(2*a*u)*sinh(2*u)+(cosh(2*u)^2)-(sinh(2*u)^2)+cos(2*a*u)*cosh(2*u))/((cos(2*a*u) + cosh(2*u))^2); \
yu: 0; \
zu: 2*(a*sin(2*a*u)*sin(2*u)+(cos(2*a*u)*cos(2*u))+cos(2*u)*cosh(2*u)-sin(2*u)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^2); "
#endif
#if (COMPILE_DESC_DERIV_V_SPIRAL != 0)
	"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_SPIRAL != 0)
	"xn: -H*2*(a*sin(2*a*u)*sin(2*u)+(cos(2*a*u)*cos(2*u))+cos(2*u)*cosh(2*u)-sin(2*u)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^2); \
yn: 0; \
zn: 2*H*(a*sin(2*a*u)*sinh(2*u)+(cosh(2*u)^2)-(sinh(2*u)^2)+cos(2*a*u)*cosh(2*u))/((cos(2*a*u) + cosh(2*u))^2); "
#endif
	"xuu: 4*(2*a*cos(2*a*u)cosh(2*u)*sin(2*a+u)+\
2*a*cosh(2*u)^2*sin(2*a*u)-4*a*sin(2*a*u)*sinh(2*u)^2 +\
2*sinh(2*u)^3-cos(2*a*u)*cosh(2*u)*sinh(2*u) + \
a*a*cos(2*a*u)*cosh(2*u)*sinh(2*u)+\
a*a*cos(2*a*u)^2*sinh(2*u)+2*a*a*(sin(2*a*u)^2)*sinh(2*u)+\
(cos(2*a*u)^2)*sinh(2*u)\
-2*(cosh(2*u)^2)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^3); \
yuu: 0; \
zuu: 4*(2*a*cos(2*a*u)*cos(2*u)*sin(2*a*u)+\
2*a*cos(2*u)*cosh(2*u)*sin(2*a*u)-\
4*a*sin(2*a*u)*sin(2*u)*sinh(2*u)-\
2*cos(2*a*u)*cos(2*u)*sinh(2*u)-\
3*cos(2*a*u)*cosh(2*u)*sin(2*u)-\
2*cos(2*u)*cosh(2*u)*sinh(2*u)+\
a*a*cos(2*a*u)*cosh(2*u)*sin(2*u)+\
a*a*(cos(2*a*u)^2)*sin(2*u)+\
2*a*a*(sin(2*a*u)^2)*sin(2*u)-\
(cos(2*a*u)^2)*sin(2*u)-\
2*(cosh(2*u)^2)*sin(2*u)+\
2*sin(2*u)*(sinh(2*u)^2))/((cos(2*a*u) + cosh(2*u))^3); "
	"xuv: 0; \
yuv: 0; \
zuv: 0; "
	"xvv: 0; \
yvv: 0; \
zvv: 0; "
	"end;";
#endif
