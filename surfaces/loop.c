
#include "loop.h"
#include "surfaces_c_includes.h"

#if (USE_LOOP != 0)
void Loop(pasuli_vartype u, pasuli_vartype v,
		  pasuli_consttype *constants,
		  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LOOP)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_u = cos(u);

	P_X(sin_v * cos_u);
	P_Y(2.0 * cos_v);
	P_Z(4.0 * sin_v * cos_v);

	pasuli_calctype sin_u = sin(u);

	UD_X(-sin_u * sin_v);
	UD_Y_CONST(0);
	UD_Z_CONST(0);

	VD_X(cos_u * cos_v);
	VD_Y(-2 * sin_v);
	VD_Z(4 * (2 * cos_v * cos_v - 1));

	// skip scaling by 2
	N_X_CONST(0);
	//N_Y(2*(cos_v*cos_v*sin_u*sin_v - sin_u*sin_v*sin_v*sin_v));
	N_Y(2 * sin_u * sin_v * (2 * cos_v * cos_v - 1));
	N_Z(sin_u * sin_v * sin_v);

	UUD_X(-cos_u * sin_v);
	UUD_Y_CONST(0);
	UUD_Z_CONST(0);

	UVD_X(-cos_v * sin_u);
	UVD_Y_CONST(0);
	UVD_Z_CONST(0);

	VVD_X(-cos_u * sin_v);
	VVD_Y(2 * cos_v);
	VVD_Z(-16 * cos_v * sin_v);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLoop = {
	LOOP,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descLoop =
	"name: Loop;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
x: sin(v)*cos(u);\
y: 2*cos(v);\
z: 4*sin(v)*cos(v);\
xu: -sin(u)*sin(v);\
yu: 0;\
zu: 0;\
xv: cos(u)*cos(v);\
yv: -2*sin(v);\
zv: 4*(cos(v)^2 - sin(v)^2);\
xn: 0;\
yn: 4*(cos(v)^2*sin(u)*sin(v) - sin(u)*sin(v)^3);\
zn: 2*sin(u)*sin(v)^2;\
xuu: -cos(u)*sin(v);\
yuu: 0;\
zuu: 0;\
xuv: -cos(v)*sin(u);\
yuv: 0;\
zuv: 0;\
xvv: -cos(u)*sin(v);\
yvv: -2*cos(v);\
zvv: -16*cos(v)*sin(v);";
#endif