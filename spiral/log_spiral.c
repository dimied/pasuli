
#include "log_spiral.h"
#include "spiral_c_includes.h"

#if (USE_LOG_SPIRAL != 0)
void LogSpiral(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LOG_SPIRAL)

	double a = constants[0];
	double H = constants[1];
	double x_u = exp(a * u) * cos(u);
	double eau_su = exp(a * u) * sin(u);

	P_X(x_u);
	P_Y(H * v);
	P_Z(eau_su);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddLogSpiral = {
	PSLDD_ID(LOG_SPIRAL)
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	0, 25, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descLogSpiral =
	"name: Log Spiral; \
cat: spiral; \
ut: c; vt: o; \
us: 0; ue: 25; \
vs: 0; ve: 1; \
c1:a: 1; c2:H: 1; \
x: exp(a*u)*cos(u); \
y: H*v; \
z: exp(a*u)*sin(u); "
#if (COMPILE_DESC_DERIV_U_SPIRAL != 0)
	"xu: exp(a*u)*(a*cos(u)-sin(u)); \
yu: 0; \
zu: exp(a*u)*(a*sin(u)+cos(u)); "
#endif
#if (COMPILE_DESC_DERIV_V_SPIRAL != 0)
	"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_SPIRAL != 0)
	"xn: -H*exp(a*u)*(a*sin(u)+cos(u)); \
yn: 0; \
zn: H*exp(a*u)*(a*cos(u)-sin(u)); "
#endif
	"xuu: exp(a*u)*(-2*a*sin(u)-cos(u)+a*a*cos(u)); \
yuu: 0; \
zuu: exp(a*u)*(2*a*cos(u)-sin(u)+a*a*sin(u)); "
	"xuv: 0; \
yuv: 0; \
zuv: 0; "
	"xvv: 0; \
yvv: 0; \
zvv: 0; "
	"end;";
#endif
