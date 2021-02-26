
#include "log_spiral.h"
#include "spiral_c_includes.h"

#if (USE_LOG_SPIRAL != 0)
void LogSpiral(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LOG_SPIRAL)

	pasuli_consttype a = constants[0];
	pasuli_consttype H = constants[1];

	pasuli_calctype exp_au = exp(a * u);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	//pasuli_calctype exp_au_cos_u = exp_au * cos_u;
	//pasuli_calctype exp_au_sin_u = exp_au * sin_u;

	P_X(exp_au * cos_u);
	P_Y(H * v);
	P_Z(exp_au * sin_u);

	// No scaling by exp(a*u)
	UD_X(a * cos_u - sin_u);
	UD_Y_CONST(0);
	UD_Z(a * sin_u + cos_u);

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	// No scaling by H*exp(a*u)
	N_X(-(a * sin_u + cos_u));
	N_Y_CONST(0);
	N_Z(a * cos_u - sin_u);

	// No scaling by exp(a*u)
	UUD_X(a * a * cos_u - 2 * a * sin_u - cos_u);
	UUD_Y_CONST(0);
	UUD_Z(a * a * sin_u + 2 * a * cos_u - sin_u);

	UVD_ALL(0);
	VVD_ALL(0);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddLogSpiral = {
	LOG_SPIRAL,
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	0, 25, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descLogSpiral =
	"name: Log Spiral;\
cat: spiral;\
ut: c; vt: o;\
us:0; ue: 25;\
vs:0; ve: 1;\
c1:a: 1; c2:H: 1;\
x: exp(a*u)*cos(u);\
y: H*v;\
z: exp(a*u)*sin(u);\
xu: exp(a*u)*(a*cos(u)-sin(u));\
yu: 0;\
zu: exp(a*u)*(a*sin(u)+cos(u));\
xv: 0;\
yv: H;\
zv: 0;\
xn: -H*exp(a*u)*(a*sin(u)+cos(u));\
yn: 0;\
zn: H*exp(a*u)*(a*cos(u)-sin(u));\
xuu: exp(a*u)*(-2*a*sin(u)-cos(u)+a*a*cos(u));\
yuu: 0;\
zuu: exp(a*u)*(2*a*cos(u)-sin(u)+a*a*sin(u));\
xuv: 0; yuv: 0; zuv: 0;\
xvv: 0; yvv: 0; zvv: 0; ";
#endif
