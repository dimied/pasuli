
#include "horn.h"
#include "surfaces_c_includes.h"

#if (USE_HORN != 0)
void Horn(pasuli_vartype u, pasuli_vartype v,
		  double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HORN)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];
	b *= MY_PI;

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype au_cos_v = a + u * cos_v;
	pasuli_calctype cos_bu = cos(b * u);
	pasuli_calctype sin_bu = sin(b * u);

	P_X(au_cos_v * sin_bu);
	P_Y(au_cos_v * cos_bu + c * u);
	P_Z(u * sin_v);

	UD_X(b * cos_bu * au_cos_v + cos_v * sin_bu);
	UD_Y(c - b * sin_bu * au_cos_v + cos_v * cos_bu);
	UD_Z(sin_v);

	VD_X(-u * sin_v * sin_bu);
	VD_Y(-u * sin_v * cos_bu);
	VD_Z(u * cos_v);

	N_X(u * (-b * sin_bu * cos_v * au_cos_v + c * cos_v + cos_bu));
	N_Y(-u * (b * cos_v * cos_bu * au_cos_v + sin_bu));
	N_Z(u * sin_v * (-b * au_cos_v + c * sin_bu));

	// Ignore b*pi
	UUD_X(-b * sin_bu * au_cos_v + 2 * cos_v * cos_bu);
	UUD_Y(-(b * cos_bu * au_cos_v + 2 * cos_v * sin_bu));
	UUD_Z(0);

	UVD_X(-sin_v * (b * u * cos_bu + sin_bu));
	UVD_Y(sin_v * (b * sin_bu - cos_bu));
	UVD_Z(cos_v);

	VVD_X(-u * cos_v * sin_bu);
	VVD_Y(-u * cos_v * cos_bu);
	VVD_Z(-u * sin_v);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHorn = {
PSLDD_ID( HORN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(3),
0, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descHorn =
	"name: Horn;\
ut:c; vt:c;\
us: 0; ue: 1;\
vs:pi: -1; ve:pi: 1;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: (a + u*cos(v))*sin(b*pi*u);\
y: (a + u*cos(v))*cos(b*pi*u) + c*u;\
z: u*sin(v);\
xu: b*pi*cos(b*pi*u)*(a+u*cos(v)) + cos(v)*sin(b*pi*u);\
yu: c - b*pi*sin(b*pi*u)*(a+u*cos(v)) + cos(v)*cos(b*pi*u);\
zu: sin(v);\
xv: -u*sin(v)*sin(b*pi*u);\
yv: -u*sin(v)*cos(b*pi*u);\
zv: u*cos(v);\
xn: u*(-b*pi*sin(b*pi*u)*cos(v)*(a + u*cos(v)) +c*cos(v) + cos(b*pi*u));\
yn: -u*(b*pi*cos(v)*cos(b*pi*u)*(a+u*cos(v)) + sin(b*pi*u));\
zn: u*sin(v)*(-b*pi*(a+u*cos(v)) + c*sin(b*pi*u));\
xuu: b*pi*(-b*pi*sin(b*pi*u)*(a + u*cos(v))) + 2*cos(v)*cos(b*pi*u);\
yuu: -b*pi*(b*pi*cos(b*pi*u)*(a + u*cos(v))) + 2*cos(v)*sin(b*pi*u);\
zuu: 0;\
xuv: -sin(v)*(b*pi*u*cos(b*pi*u) + sin(b*pi*u));\
yuv: sin(v)*(b*pi*u*sin(b*pi*u) - cos(b*pi*u));\
zuv: cos(v);\
xvv: -u*cos(v)*sin(b*pi*u);\
yvv: -u*cos(v)*cos(b*pi*u);\
zvv: -u*sin(v);  ";
#endif