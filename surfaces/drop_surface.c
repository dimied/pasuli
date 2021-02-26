
#include "drop_surface.h"
#include "surfaces_c_includes.h"

#if (USE_DROP_SURFACE != 0)
void DropSurface(pasuli_vartype u, pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(DROP_SURFACE)

	pasuli_consttype a = constants[0];

	pasuli_calctype sin_ua = sin(u - a);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(cos_u * cos_v);
	P_Y(cos_u * sin_v);
	P_Z(sin_ua);

	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_ua = cos(a -u);

	UD_X(-sin_u*cos_v);
	UD_Y(-sin_u*sin_v);
	UD_Z(cos_ua);

	VD_X(-PASULI_COND_COPY_POS_Y(cos_u*sin_v));
	VD_Y(PASULI_COND_COPY_POS_X(cos_u*cos_v));
	VD_Z_CONST(0);

	N_X(-cos_u*cos_v*cos_ua);
	N_Y(-cos_u*cos_ua*sin_v);
	N_Z(-cos_u*sin_u);

	UUD_X(-PASULI_COND_COPY_POS_X(cos_u*cos_v));
	UUD_Y(-PASULI_COND_COPY_POS_Y(cos_u*sin_v));
	UUD_Z(-sin_ua);

	UVD_X(sin_u*sin_v);
	UVD_Y(-sin_u*cos_v);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(cos_u*cos_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(cos_u*sin_v));
	VVD_Z_CONST(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDropSurface = {
PSLDD_ID( DROP_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5, 0.5 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descDropSurface =
	"name: Drop Surface;\
ut:c; vt:c;\
us:pi: -0.5; ue:pi: 0.5;\
vs:0; ve:pi:2;\
c1:a: 1.5;\
x: cos(v)*cos(u);\
y: sin(v)*cos(u);\
z: sin(u - a);\
xu: -sin(u)*cos(v);\
yu: -sin(u)*sin(v);\
zu: cos(a-u);\
xv: -cos(u)*sin(v);\
yv: cos(u)*cos(v);\
zv: 0;\
xn: -cos(u)*cos(v)*cos(a-u);\
yn: -cos(u)*cos(a-u)*sin(v);\
zn: -cos(u)*sin(u);\
xuu: -cos(u)*cos(v);\
yuu: -cos(u)*sin(v);\
zuu: -sin(u-a);\
xuv: sin(u)*sin(v);\
yuv: -sin(u)*cos(v);\
zuv: 0;\
xvv: -cos(u)*cos(v);\
yvv: -cos(u)*sin(v);\
zvv: 0; ";
#endif