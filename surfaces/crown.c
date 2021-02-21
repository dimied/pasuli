
#include "crown.h"
#include "surfaces_c_includes.h"

#if (USE_CROWN != 0)
void Crown(pasuli_vartype u, pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CROWN)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_sin_u = cos_u * sin_u;

	pasuli_calctype cos_u4_div_3 = cos(u + 4.0) / 3.0;
	//u = 0.5 * cos(u);

	pasuli_calctype cos_v = sin(v);
	pasuli_calctype sin_v = sin(v);
	double cos_sin_v = sin_v * cos_v;

	P_X(cos_u4_div_3);
	P_Y(cos_sin_u * cos_sin_v * cos_v + 0.3 * cos_u);
	P_Z(cos_sin_u * cos_sin_v);

	pasuli_calctype u2_difference = (cos_u * cos_u - sin_u * sin_u);
	UD_X(-sin(u + 4) / 3);
	UD_Y(u2_difference * cos_v * cos_v * sin_v - 0.5 * sin_u);
	UD_Z(u2_difference * cos_v * sin_v);

	VD_X(0);
	// cos_v*cos_v - 2*sin_v*sin_v = -3*sin_v*sin_v
	VD_Y(cos_u * cos_v * sin_u * (-3 * sin_v * sin_v));
	VD_Z(cos_u * sin_u * (cos_v * cos_v - sin_v * sin_v));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrown = {
	PSLDD_ID(CROWN)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCrown =
	"name: Crown;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
x: cos(u + 4)/3;\
y: cos(u)*sin(v)*cos(v)*sin(u)*cos(v) + 0.5*cos(u);\
z: cos(v)*sin(u)*cos(u)*sin(v);\
xu: -sin(u+4)/3;\
yu: cos(u)^2*cos(v)^2*sin(v) - cos(v)^2*sin(u)^2*sin(v) - 0.5*sin(u);\
zu: cos(u)^2*cos(v)*sin(v) - sin(u)^2*cos(v)*sin(v);\
xv: 0;\
yv: cos(u)*cos(v)^3*sin(u) - 2*cos(u)*cos(v)*sin(u)*sin(v)^2;\
zv: cos(u)*cos(v)^2*sin(u) - cos(u)*sin(u)*sin(v)^2; ";
#endif