
#include "kappa_surface.h"
#include "surfaces_c_includes.h"

#if (USE_KAPPA_SURFACE != 0)
void KappaSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(KAPPA_SURFACE)

	pasuli_consttype a = constants[0];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype tan_v = tan(v);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype a_cos_v = a * cos_v;

	P_X(a_cos_v * cos_u);
	P_Y(a_cos_v * sin_u);
	P_Z(-(a_cos_v / tan_v));

	UD_X(-PASULI_COND_COPY_POS_Y(a_cos_v * sin_u));
	UD_Y(PASULI_COND_COPY_POS_X(a_cos_v * cos_u));
	UD_Z_CONST(0);

	pasuli_calctype sin_v = sin(v);
	pasuli_calctype a_sin_v = a * sin_v;
	VD_X(-a_sin_v * cos_u);
	VD_Y(-a_sin_v * sin_u);
	VD_Z(a / (cos_v * tan_v * tan_v) + a * cos_v);

	pasuli_calctype factor = a*a;
	factor = PASULI_CALC_SIGN(a * a);
	pasuli_calctype common_factor = cos_v * cos_v + atan(v) * atan(v);
	N_X(factor * cos_u * common_factor);
	N_Y(factor * sin_u * common_factor);
	N_Z(factor * cos_v * sin_v);

	UUD_X(-PASULI_COND_COPY_POS_X(a_cos_v * cos_u));
	UUD_Y(-PASULI_COND_COPY_POS_Y(a_cos_v * sin_u));
	UUD_Z_CONST(0);

	UVD_X(a_sin_v * sin_u);
	UVD_Y(-a_sin_v * cos_u);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(a_cos_v * cos_u));
	VVD_Y(-PASULI_COND_COPY_POS_Y(a_cos_v * sin_u));
	VVD_Z(a * (cos_v / tan_v - 2 / (sin_v * sin_v * sin_v)));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKappaSurface = {
PSLDD_ID( KAPPA_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
0, 2 , 0.25f , 0.5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descKappaSurface =
	"name: Kappa Surface;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs: 0.25; ve:pi: 0.5;\
c1:a: 1.5;\
a1:r: a*cos(v);\
x: r*cos(u);\
y: r*sin(u);\
z: -r/tan(v);\
xu: -a*cos(v)*sin(u);\
yu: a*cos(v)*cos(u);\
zu: 0;\
xv: -a*sin(v)*cos(u);\
yv: -a*sin(v)*sin(u);\
zv: a/(cos(v)*tan(v)^2) + a*sin(v)/tan(v);\
xn: a^2*cos(u)*(cos(v)^2 + 1/tan(v)^2);\
yn: a^2*sin(u)*(cos(v)^2 + 1/tan(v)^2);\
zn: a^2*cos(v)*sin(v);\
xuu: -a*cos(u)*cos(v);\
yuu: -a*sin(u)*cos(v);\
zuu: 0;\
xuv: a*sin(u)*sin(v);\
yuv: -a*cos(u)*sin(v);\
zuv: 0;\
xvv: -a*cos(u)*cos(v);\
yvv: -a*sin(u)*cos(v);\
zvv: a*cos(v)/tan(v) - 2*a/sin(v)^3; ";
#endif