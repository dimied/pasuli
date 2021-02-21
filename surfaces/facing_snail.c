
#include "facing_snail.h"
#include "surfaces_c_includes.h"

#if (USE_FACING_SNAIL != 0)
void FacingSnail(pasuli_vartype u, pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(FACING_SNAIL)

	pasuli_consttype a = constants[0];

	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_v = cos(v);

	pasuli_calctype one_minus_av = (1 - a * v);

	P_X(cos_u * cos_v);
	P_Y(cos_u * sin_v);
	P_Z(one_minus_av * sin_u);

	UD_X(-cos_v * sin_u);
	UD_Y(-sin_v * sin_u);
	UD_Z(one_minus_av * cos_u);

	VD_X(-PASULI_COND_COPY_POS_Y(cos_u * sin_v));
	VD_Y(PASULI_COND_COPY_POS_X(cos_u * cos_v));
	VD_Z(-a * sin_u);

	N_X(-one_minus_av * cos_u * cos_u * cos_v + a * sin_u * sin_u * sin_v);
	N_Y(-one_minus_av * cos_u * cos_u * sin_v - a * sin_u * sin_u * cos_v);
	N_Z(-cos_u * sin_u);

	UUD_X(-PASULI_COND_COPY_POS_X(cos_u * cos_v));
	UUD_Y(-PASULI_COND_COPY_POS_Y(cos_u * sin_v));
	UUD_Z(-PASULI_COND_COPY_POS_Z(one_minus_av * sin_u));

	UVD_X(sin_u * sin_v);
	UVD_Y(-sin_u * cos_v);
	UVD_Z(-a * cos_u);

	VVD_X(-PASULI_COND_COPY_POS_X(cos_u * cos_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(cos_u * sin_v));
	VVD_Z_CONST(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFacingSnail = {
PSLDD_ID( FACING_SNAIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f, 0.5f , 0 , 6 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descFacingSnail =
	"name: Facing Snail;\
ut:c; vt:c;\
us:pi: -0.5; ue:pi: 0.5;\
vs: 0; ve:pi: 6;\
c1:a: 1.5;\
x: cos(v)*cos(u);\
y: sin(v)*cos(u);\
z: (1 - a*v)*sin(u);\
xu: -cos(v)*sin(u);\
yu: -sin(v)*sin(u);\
zu: (1-a*v)*cos(u);\
xv: -cos(u)*sin(v);\
yv: cos(u)*cos(v);\
zv: -a*sin(u);\
xn: (a*v - 1)*cos(u)^2*cos(v) + a*sin(u)^2*sin(v);\
yn: (a*v - 1)*cos(u)^2*sin(v) - a*sin(u)^2*cos(v);\
zn: -cos(u)*sin(u);\
xuu: -cos(u)*cos(v);\
yuu: -cos(u)*sin(v);\
zuu: (a*v-1)*sin(u);\
xuv: sin(u)*sin(v);\
yuv: -sin(u)*cos(v);\
zuv: -a*cos(u);\
xvv: -cos(u)*cos(v);\
yvv: -cos(u)*sin(v);\
zvv: 0; ";
#endif