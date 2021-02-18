
#include "funnel.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_FUNNEL != 0)
void Funnel(pasuli_vartype u, pasuli_vartype v,
			double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(FUNNEL)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype log_u = log(u);

	P_X(u * cos_v);
	P_Y(u * sin_v);
	P_Z(log_u);

	UD_X(cos_v);
	UD_Y(sin_v);
	pasuli_calctype z_value = (fabs(u) < 0.0001) ? 1 / 0.0001 : 1 / u;
	UD_Z(z_value);

	VD_X(-PASULI_COND_COPY_POS_Y(u * sin_v));
	VD_Y(PASULI_COND_COPY_POS_X(u * cos_v));
	VD_Z(0);

	N_X(-cos_v);
	N_Y(-sin_v);
	N_Z(u);

	// No scaling by (1/u)^2
	UUD_X_CONST(0);
	UUD_Y_CONST(0);
	UUD_Z(-1);

	UVD_X(-sin_v);
	UVD_Y(cos_v);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(u * cos_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(u * sin_v));
	VVD_Z_CONST(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFunnel = {
	PSLDD_ID(FUNNEL)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_FULL_IMPL,
	0.01f, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descFunnel =
	"name: Funnel; \
ut:c; vt:c; \
us: 0.1; ue: 2; \
vs: 0; ve:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: log(u); \
xu: cos(v); yu: sin(v); zu: 1/u; \
xv: -u*sin(v); yv: u*cos(v); zv: 0; \
xn: -cos(v); \
yn: -sin(v); \
zn: u; \
xuu: 0; \
yuu: 0; \
zuu: -1/(u*u); \
xuv: -sin(v); \
yuv: cos(v); \
zuv: 0; \
xvv: -u*cos(v); \
yvv: -u*sin(v); \
zvv: 0; ";
#endif