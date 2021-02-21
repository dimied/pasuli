
#include "kidney_surface.h"
#include "fruits_c_includes.h"

#if (USE_KIDNEY_SURFACE != 0)
void KidneySurface(pasuli_vartype u, pasuli_vartype v,
				   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(KIDNEY_SURFACE)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_3v = cos(3 * v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_3v = sin(3 * v);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype common_factor = (3 * cos_v - cos_3v);

	P_X(cos_u * common_factor);
	P_Y(sin_u * common_factor);
	P_Z(3 * sin_v - sin_3v);

	UD_X(-PASULI_COND_COPY_POS_Y(sin_u * common_factor));
	UD_Y(PASULI_COND_COPY_POS_X(cos_u * common_factor));
	UD_Z(0);

	pasuli_calctype vd_factor = (3 * sin_3v - 3 * sin_v);
	VD_X(cos_u * vd_factor);
	VD_Y(sin_u * vd_factor);
	VD_Z(3 * cos_v - 3 * cos_3v);

	pasuli_calctype normal_factor = (9 * cos_v * cos_v - 12 * cos_v * cos_3v + 3 * cos_3v);
	N_X(cos_u * normal_factor);
	N_Y(sin_u * normal_factor);
	N_Z(9 * (cos_v * sin_v - cos_v * sin_3v) + 3 * (cos_3v * sin_3v - cos_3v * sin_v));

	UUD_X(-PASULI_COND_COPY_POS_X(cos_u * common_factor));
	UUD_Y(-PASULI_COND_COPY_POS_Y(sin_u * common_factor));
	UUD_Z(0);

	common_factor = (3 * sin_3v - 3 * sin_v);
	UVD_X(-sin_u * common_factor);
	UVD_Y(cos_u * common_factor);
	UVD_Z(0);

	common_factor = (9 * cos_3v - 3 * cos_v);
	VVD_X(cos_u * common_factor);
	VVD_Y(sin_u * common_factor);
	VVD_Z(9 * sin_3v - 3 * sin_v);
}

#endif

#if (COMPILE_DESC_FRUITS != 0)
char *descKidneySurface =
	"name: Kidney Surface;\
cat: fruits;\
ut: c; vt: c;\
us: 0; ue:pi: 2;\
vs:pi: -0.5; ve:pi: 0.5;\
x: cos(u)*(3*cos(v) - cos(3*v));\
y: sin(u)*(3*cos(v) - cos(3*v));\
z: 3*sin(v) - sin(3*v);\
xu: -sin(u)*(3*cos(v) - cos(3*v));\
yu: cos(u)*(3*cos(v) - cos(3*v));\
zu: 0;\
xv: 3*cos(u)*(sin(3*v) - sin(v));\
yv: 3*sin(u)*(sin(3*v) - sin(v));\
zv: 3*cos(v) - 3*cos(3*v);\
xn: cos(u)*(9*cos(v)^2 - 12*cos(v)*cos(3*v) + 3*cos(3*v));\
yn: sin(u)*(9*cos(v)^2 - 12*cos(v)*cos(3*v) + 3*cos(3*v));\
zn: 9*(cos(v)*sin(v) - cos(v)*sin(3*v)) + 3*(cos(3*v)*sin(3*v) - cos(3*v)*sin(v));\
xuu: -cos(u)*(3*cos(v) - cos(3*v));\
yuu: -sin(u)*(3*cos(v) - cos(3*v));\
zuu: 0;\
xuv: sin(u)*(3*sin(v) - 3*sin(3*v));\
yuv: cos(u)*(3*sin(3*v) - 3*sin(v));\
zuv: 0;\
xvv: cos(u)*(9*cos(3*v) -3*cos(v));\
yvv: sin(u)*(9*cos(3*v) -3*cos(v));\
zvv: 9*sin(3*v) - 3*sin(v); ";
#endif

#if (COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddKidneySurface = {
	PSLDD_ID(KIDNEY_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
	0, 2, -0.5f, 0.5, 0};
#endif