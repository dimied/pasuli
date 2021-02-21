
#include "drop.h"
#include "surfaces_c_includes.h"

#if (USE_DROP != 0)
void Drop(pasuli_vartype u, pasuli_vartype v,
		  double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(DROP)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype b_cos_u_sin_u = (b - cos_u) * sin_u;
	pasuli_calctype ab_cos_u_sin_u = a * b_cos_u_sin_u;
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(ab_cos_u_sin_u * cos_v);
	P_Y(ab_cos_u_sin_u * sin_v);
	P_Z(cos_u);

	pasuli_calctype ud_common = b * cos(u) + 1 - 2 * cos(2 * u);
	UD_X(a * cos_v * ud_common);
	UD_Y(a * sin_v * ud_common);
	UD_Z(-sin_u);

	VD_X(-PASULI_COND_COPY_POS_Y(ab_cos_u_sin_u * sin_v));
	VD_Y(PASULI_COND_COPY_POS_X(ab_cos_u_sin_u * cos_v));
	VD_Z_CONST(0);

	pasuli_calctype normal_factor = (a < 0) ? -1 : 1;

	N_X(normal_factor * b_cos_u_sin_u * cos_v * sin_u);
	N_Y(normal_factor * b_cos_u_sin_u * sin_v * sin_u);
	// sin(u)*a*a*(b*b*cos(u) - 2*b*cos(u)^2 + b*sin(u)^2 + cos(u)^3 - cos(u)*sin(u)^2 )
	// sin(u)*a*a*(b*b*cos(u) - 2*b*cos(u)^2 + b*(1-cos(u)^2) + cos(u)^3 - cos(u)*sin(u)^2 )
	// sin(u)*a*a*(b*b*cos(u) - 3*b*cos(u)^2 + b + cos(u)^3 - cos(u)*sin(u)^2 )
	// sin(u)*a*a*(b*b*cos(u) - 3*b*cos(u)^2 + b + cos(u)*(1-sin(u)^2) - cos(u)*sin(u)^2 )
	// sin(u)*a*a*(b*b*cos(u) - 3*b*cos(u)^2 + b + cos(u)-cos(u)sin(u)^2 - cos(u)*sin(u)^2 )
	// sin(u)*a*a*(b*b*cos(u) - 3*b*cos(u)^2 + b + cos(u)-2*cos(u)sin(u)^2 )
	N_Z(normal_factor * a * sin_u * (b * b * cos_u - 3 * b * cos_u * cos_u + b + cos_u - 2 * cos_u * sin_u * sin_u));

	UUD_X(a * sin_u * cos_v * (4 * cos_u - b));
	UUD_Y(a * sin_u * sin_v * (4 * cos_u - b));
	UUD_Z(-cos_u);

	ud_common = 1 - b * cos_u - 2 * sin_u * sin_u;
	UVD_X(sin_v * a * ud_common);
	UVD_Y(-cos_v * a * ud_common);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(ab_cos_u_sin_u * cos_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(ab_cos_u_sin_u * sin_v));
	VVD_Z_CONST(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDrop = {
PSLDD_ID( DROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descDrop =
	"name: Drop;\
ut:c; vt:c;\
us: 0; ue:pi: 1;\
vs: 0; ve:pi: 2;\
c1:a: 1.5;\
c2:b: 0.5;\
x: a*(b - cos(u))*sin(u)*cos(v);\
y: a*(b - cos(u))*sin(u)*sin(v);\
z: cos(u);\
xu: a*cos(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u));\
yu: a*sin(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u));\
zu: -sin(u);\
xv: sin(u)*sin(v)*a*(cos(u)-b);\
yv: sin(u)*cos(v)*a*(b - cos(u));\
zv: 0;\
xn: a*(b - cos(u))*cos(v)*sin(u)*sin(u);\
yn: a*(b - cos(u))*sin(v)*sin(u)*sin(u);\
zn: sin(u)*a*a*(b*b*cos(u) - 2*b*cos(u)^2 + b*sin(u)^2 + cos(u)^3 - cos(u)*sin(u)^2 );\
xuu: sin(u)*a*cos(v)*(4*cos(u)-b);\
yuu: sin(u)*a*sin(v)*(4*cos(u)-b);\
zuu: -cos(u);\
xuv: sin(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u));\
yuv: -cos(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u));\
zuv: 0;\
xvv: sin(u)*a*cos(v)*(cos(u)-b);\
yvv: sin(u)*a*sin(v)*(cos(u)-b);\
zvv: 0; ";
#endif