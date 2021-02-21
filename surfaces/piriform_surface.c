
#include "piriform_surface.h"
#include "surfaces_c_includes.h"

#if (USE_PIRIFORM_SURFACE != 0)
void PiriformSurface(pasuli_vartype u, pasuli_vartype v,
					 pasuli_consttype *constants,
					 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PIRIFORM_SURFACE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype r = constants[2];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_v_plus_r = sin_v + r;
	pasuli_calctype factor = b * cos_v * sin_v_plus_r;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(a * sin_v_plus_r);

	UD_X(-PASULI_COND_COPY_POS_Y(factor * sin_u));
	UD_Y(PASULI_COND_COPY_POS_X(factor * cos_u));
	UD_Z(0);

	pasuli_calctype vd_factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
	vd_factor = -b * (r * sin(v) - vd_factor);
	VD_X(cos_u * vd_factor);
	VD_Y(sin_u * vd_factor);
	VD_Z(a * cos_v);

	vd_factor = a * b * cos_v * cos_v * (r + sin_v);
	N_X(vd_factor * cos_u);
	N_Y(vd_factor * sin_u);
	N_Z(b * b * cos_v * (2 * r * r * sin_v - 3 * r * cos(2 * v) + r * sin_v - sin(3 * v)) * 0.5);

	UUD_X(-PASULI_COND_COPY_POS_X(factor * cos_u));
	UUD_Y(-PASULI_COND_COPY_POS_Y(factor * sin_u));
	UUD_Z_CONST(0);

	factor = PASULI_TRIG_CALC_SUM_DIFFERENCE(cos_v, sin_v);
	factor = b * (r * sin_v - b * factor);

	UVD_X(sin_u * factor);
	UVD_Y(-cos_u * factor);
	UVD_Z_CONST(0);

	factor = -b * cos_v * (r + 4 * sin_v);
	VVD_X(cos_u * factor);
	VVD_Y(sin_u * factor);
	VVD_Z(-a * sin_v);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPiriformSurface = {
PSLDD_ID( PIRIFORM_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0, 2 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descPiriformSurface =
	"name:piriform Surface;\
ut:c; vt:c;\
us: 0; ue:pi: 2;\
vs:pi: -0.5; ve:pi: 0.5;\
c1:a: 1.5; c2:b: 0.5; c3:r: 1.0;\
a1:c: (r + sin(v));\
a2:d: b*cos(v)*c;\
x: d*cos(u);\
y: d*sin(u);\
z: a*c;\
xu: -b*cos(v)*(r+sin(v))*sin(u);\
yu: b*cos(v)*(r+sin(v))*cos(u);\
zu: 0;\
xv: -b*cos(u)*(r*sin(v) - (cos(v)^2 - sin(v)^2);\
yv: -b*sin(u)*(r*sin(v) - (cos(v)^2 - sin(v)^2);\
zv: a*cos(v);\
xn: a*b*cos(u)*cos(v)^2*(r + sin(v));\
yn: a*b*sin(u)*cos(v)^2*(r + sin(v));\
zn: b^2*cos(v)*(2*r^2*sin(v) - 3*r*cos(2*v) + r*sin(v) - sin(3*v))/2;\
xuu: -b*cos(v)*(r+sin(v))*cos(u);\
yuu: -b*cos(v)*(r+sin(v))*sin(u);\
zuu: 0;\
xuv: b*sin(u)*(r*sin(v) - b*(cos(v)^2 - sin(v)^2));\
yuv: -b*cos(u)*(r*sin(v) - b*(cos(v)^2 - sin(v)^2));\
zuv: 0;\
xvv: -b*cos(u)*(cos(v)*(r + 4*sin(v));\
yvv: -b*sin(u)*(cos(v)*(r + 4*sin(v));\
zvv: -a*sin(v);";
#endif