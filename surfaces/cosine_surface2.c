
#include "cosine_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_COSINE_SURFACE2 != 0)

void CosineSurface2(pasuli_vartype u, pasuli_vartype v,
					double *constants, PaSuLiObject *pO)
{

	PASULI_SET_TYPE_ID(COSINE_SURFACE2)
	
	pasuli_calctype cos_uv = cos(v + u);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_v = cos(v);

	P_X(cos_u);
	P_Y(cos_v);
	P_Z(-cos_uv * cos_uv);

	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_uv = sin(v + u);

	pasuli_calctype cos_uv_sin_uv_2 = 2 * cos_uv * sin_uv;
	UD_X(-sin_u);
	UD_Y(0);
	UD_Z(cos_uv_sin_uv_2);

	pasuli_calctype sin_v = sin(v);
	VD_X(0);
	VD_Y(-sin_v);
	VD_Z(cos_uv_sin_uv_2);

	N_X(cos_uv_sin_uv_2 * sin_v);
	N_Y(cos_uv_sin_uv_2 * sin_u);
	N_Z(sin_u * sin_v);

	cos_uv_sin_uv_2 = 2 * cos_uv * cos_uv - 2 * sin_uv * sin_uv;

	UUD_X(-cos_u);
	UUD_Y_CONST(0);
	UUD_Z(cos_uv_sin_uv_2);

	UVD_X_CONST(0);
	UVD_Y_CONST(0);
	UVD_Z(cos_uv_sin_uv_2);

	VVD_X_CONST(0);
	VVD_Y(-cos_v);
	VVD_Z(cos_uv_sin_uv_2);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface2 = {
	COSINE_SURFACE2,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCosineSurface2 =
	"name: Cosine Surface 2;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
x: cos(u);\
y: cos(v);\
z: -cos(u + v)^(2);\
xu: -sin(u);\
yu: 0;\
zu: 2*cos(u+v)*sin(u+v);\
xv: 0;\
yv: -sin(v);\
zv: 2*cos(u+v)*sin(u+v);\
xn: 2*cos(u+v)*sin(u+v)*sin(v);\
yn: 2*cos(u+v)*sin(u+v)*sin(u);\
zn: sin(u)*sin(v);\
xuu: -cos(u);\
yuu: 0;\
zuu: 2*cos(u+v)^2 - 2*sin(u+v)^2;\
xuv: 0;\
yuv: 0;\
zuv: 2*cos(u+v)^2 - 2*sin(u+v)^2;\
xvv: 0;\
yvv: -cos_v;\
zvv: 2*cos(u+v)^2 - 2*sin(u+v)^2; ";
#endif