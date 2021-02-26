
#include "apple2_surface.h"
#include "fruits_c_includes.h"

#if (USE_APPLE2_SURFACE != 0)
void Apple2_Surface(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(APPLE2_SURFACE)

	pasuli_calctype R1 = constants[0];
	pasuli_calctype r = constants[1];
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype pos_factor = R1 + r * cos_v;
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v2 = 2.0 * cos_v;
	pasuli_calctype sin_v = 2.0 * sin(v);
	pasuli_calctype cos_5u = cos(5.0 * u);

	P_X(cos_u * pos_factor + pow(v / MY_PI, 20));
	P_Y(sin_u * pos_factor + cos_5u * 0.25);
	P_Z(-2.3 * log(1 - v * 0.3157) + 3 * sin_v + cos_v2);

	pasuli_calctype sin_5u = sin(5.0 * u);

	UD_X(-sin_u * pos_factor);
	UD_Y(cos_u * pos_factor + 1.25 * sin_5u);
	UD_Z(0);

	VD_X(20.0 * pow(v / MY_PI, 19) / MY_PI - r * cos_u * sin_v);
	VD_Y(-r * sin_u * sin_v);
	pasuli_calctype divisor = 1 - 0.3157 * v;

	if (fabs(divisor) < 0.0001)
	{
		divisor = 0.72611 / 0.0001;
	}
	else
	{
		divisor = 0.72611 / divisor;
	}
	VD_Z(6 * cos_v - 2 * sin_v + divisor);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DESC_FRUITS != 0)
char *descAppleSurface2 =
	"name: Apple Surface (V2);\
ut: c; vt: c;\
us:pi: -1; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
c1:R: 1.5; c2:r: 0.5;\
x: cos(u)*(R + r*cos(v)) + (v/pi)^(20);\
y: sin(u)*(R + r*cos(v)) + 0.25*cos(5*u);\
z: -2.3*log(1 - v*0.3157) + 6*sin(v) + 2*cos(v);\
xu: -sin(u)*(R + r*cos(v));\
yu: cos(u)*(R + r*cos(v)) - 1.25*sin(5*u);\
zu: 0;\
xv: 20*(v^19)/(pi^20) - r*cos(u)*sin(v);\
yv: -r*sin(u)*sin(v);\
zv: 6*cos(v)-2*sin(v) + (0.72611)/(1-0.3157*v);\
xn: ?;\
yn: ?;\
zn: ?;\
xuu: -cos(u)*(R + cos(v));\
yuu: -sin(u)*(R+r*cos(v)) - 6.25*cos(5*u);\
zuu: 0;\
xuv: r*sin(u)*sin(v);\
yuv: -r*cos(u)*sin(v);\
zuv: 0;\
xvv: -r*cos(u)*cos(v) + 380*(v^18)/(pi^20);\
yvv: -r*cos(v)*sin(u);\
zvv: (0.229233)/((1-0.3157v)^2) - 6*sin(v) - 2*cos(v); ";

#endif

/*
#if(COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddApple2_Surface = {
PSLDD_ID( APPLE2_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1, -1, 1 , def_fruits_constants};
#endif
*/