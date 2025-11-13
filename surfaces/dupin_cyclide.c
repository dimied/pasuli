
#include "dupin_cyclide.h"
#include "surfaces_c_includes.h"

#if (USE_DUPIN_CYCLIDE != 0)

void DupinCyclide(pasuli_vartype u, pasuli_vartype v,
				  double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(DUPIN_CYCLIDE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];
	pasuli_consttype d = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype b_sin_u = b * sin_u;

	pasuli_calctype b2_cos_u = b * b * cos_u;
	pasuli_calctype c_cos_u = c * cos_u;

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype b_sin_v = b * sin_v;

	pasuli_calctype h = a - c_cos_u * cos_v;

	P_X((d * (c - a * cos_u * cos_v) + b2_cos_u) / h);
	P_Y((b_sin_u * (a - d * cos_v)) / h);
	P_Z((b_sin_v * (c_cos_u - d)) / h);

	// Skip division by h^2
	UD_X((-a * b * b + d * a * a * cos_v - d * c * c * cos_v) * sin_u);
	UD_Y(b * (a - d * cos_v) * (a * cos_u - c * cos_v));
	UD_Z(b * c * (a - d * cos_v) * sin_u * sin_v);

	// Skip division by h^2
	VD_X((d*a*a - d*c*c - c*b*b*cos_u)*cos_u*sin_v);
	VD_Y(a*b*(-d + c*cos_u)*sin_u*sin_v);
	VD_Z(b*(-d + c*cos_u)*(a*cos_v - c*cos_u));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDupinCyclide = {
PSLDD_ID( DUPIN_CYCLIDE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descDupinCyclide =
	"name: Dupin Cyclide;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; c4:d: 1.0;\
a1:h: a - c*cos(u)*cos(v);\
x: (d*(c - a*cos(u)*cos(v)) + b*b*cos(u))/h;\
y: (b*sin(u)*(a - d*cos(v)))/h;\
z: b*sin(v)*(c*cos(u) - d)/h;\
xu: (-a*b^2 + d*a^2*cos(v) - d*c^2*cos(v))*sin(u)/h^2;\
yu: b*(a - d*cos(v))*(a*cos(u) - c*cos(v))/h^2;\
zu: b*c*(a-d*cos(v))*sin(u)*sin(v)/h^2;\
xv: (d*a^2 - d*c^2 - c*b^2*cos(u))*cos(u)*sin(v)/h^2;\
yv: a*b*(-d + c*cos(u))*sin(u)*sin(v)/h^2;\
zv: b*(-d + c*cos(u))*(a*cos(v) - c*cos(u))/h^2;";
#endif