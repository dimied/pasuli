
#include "snail_surface.h"
#include "shells_c_includes.h"

#if (USE_SNAIL_SURFACE != 0)
void SnailSurface(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SNAIL_SURFACE)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype u_cos_u = u * cos_u;
	pasuli_calctype u_sin_u = u * sin_u;

	P_X(u_sin_u * cos_v);
	P_Y(u_cos_u * cos_v);
	P_Z(-u * sin_v);

	UD_X((u_cos_u + sin_u) * cos_v);
	UD_Y((cos_u - u_sin_u) * cos_v);
	UD_Z(-sin_v);

	VD_X(-u_sin_u * sin_v);
	VD_Y(-u_cos_u * sin_v);
	VD_Z(-u * cos_v);

	// No common factor of u
	N_X(u_sin_u * cos_v * cos_v - cos_u);
	N_Y(u_cos_u * cos_v * cos_v - sin_u);
	N_Z(u * cos_v * sin_v);

	UUD_X(-u_sin_u * cos_v + 2 * cos_u * cos_v);
	UUD_Y(-u_cos_u * cos_v - 2 * sin_u * cos_v);
	UUD_Z(0);

	UVD_X(-u_cos_u * sin_v - sin_u * sin_v);
	UVD_Y(u_sin_u * sin_v - cos_u * sin_v);
	UVD_Z(-cos_v);

	VVD_X(-PASULI_COND_COPY_POS_X(-u_sin_u * cos_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(-u_cos_u * cos_v));
	VVD_Z(-PASULI_COND_COPY_POS_Z(u * sin_v));
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnailSurface = {
	SNAIL_SURFACE,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI | PASULI_CONST_COUNT(0),
	0, 2, -1, 1, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)

char *descSnailSurface = "name: Snail Surface;\
cat: shells;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:pi: -1; ve:pi:1;\
x: u*sin(u)*cos(v);\
y: u*cos(u)*cos(v);\
z: -u*sin(v);\
xu: u*cos(u)*cos(v)+cos(v)*sin(u);\
yu: -u*cos(v)*sin(u) + cos(u)*cos(v);\
zu: -sin(v);\
xv: -u*sin(u)*sin(v);\
yv: -u*cos(u)*sin(v);\
zv: -u*cos(v);\
xn: u*u*cos(v)^2*sin(u) - u*cos(u);\
yn: u*u*cos(v)^2*cos(u)+u*sin(u);\
zn: -u*u*cos(v)*sin(v);\
xuu: -u*cos(v)*sin(u) + 2*cos(u)*cos(v);\
yuu: -u*cos(v)*cos(u) - 2*sin(u)*cos(v);\
zuu: 0;\
xuv: -u*cos(u)*sin(v) - sin(u)*sin(v);\
yuv: u*sin(u)*sin(v) - cos(u)*sin(v);\
zuv: -cos(v);\
xvv: -u*cos(v)*sin(u);\
yvv: -u*cos(v)*cos(u);\
zvv: u*sin(v); ";
#endif
