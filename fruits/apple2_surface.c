
#include "apple2_surface.h"
#include "fruits_c_includes.h"

#if (USE_APPLE2_SURFACE != 0)
void Apple2_Surface(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(APPLE2_SURFACE)

	pasuli_vartype R1 = constants[0];
	pasuli_vartype xy = R1 + constants[1] * cos(v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv2 = 2.0 * cos(v);
	pasuli_vartype sv2 = 2.0 * sin(v);
	pasuli_vartype c5u = cos(5.0 * u);

	P_X(cu * xy + pow(v / MY_PI, 20));
	P_Y(su * xy + c5u * 0.25);
	P_Z(-2.3 * log(1 - v * 0.3157) + 3 * sv2 + cv2);

	UD_X(0);
	UD_Y(0);
	UD_Z(0);

	VD_X(0);
	VD_Y(0);
	VD_Z(0);

	N_X(0);
	N_Y(0);
	N_Z(0);

	UUD_X(0);
	UUD_Y(0);
	UUD_Z(0);

	UVD_X(0);
	UVD_Y(0);
	UVD_Z(0);

	VVD_X(0);
	VVD_Y(0);
	VVD_Z(0);
}
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
#if (COMPILE_DESC_FRUITS != 0)
char *descApple2_Surface =
	"name: Apple Surface (V2); \
ut: c; vt: c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
c1:R: 1.5; c2:r: 0.5; \
x: cos(u)*(R + r*cos(v)) + (v/pi)^(20); \
y: sin(u)*(R + r*cos(v)) + 0.25*cos(5*u); \
z: -2.3*log(1 - v*0.3157) + 6*sin(v) + 2*cos(v); "
#if (COMPILE_DESC_DERIV_U_FRUITS != 0)
	"xu: -sin(u)*(R + r*cos(v)); \
yu: cos(u)*(R + r*cos(v)) - 1.25*sin(5*u); \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_FRUITS != 0)
	"xv: 20*(v^19)/(pi^20) - r*cos(u)*sin(v); \
yv: -r*sin(u)*sin(v); \
zv: 6*cos(v)-2*sin(v) + (0.72611)/(1-0.3157*v); "
#endif
#if (COMPILE_DESC_NORMAL_FRUITS != 0)
	"xn: cos(u)*(R*(6*cos(v)-2*sin(v)+(1/(1.3772 - 0.434783*v)) \
-2*r*cos(v)*sin(v))+6*r*cos(v)*cos(v) + \
(r*cos(v))/(1.3772-0.434783*v)) + \
sin(5*u)*(-7.5*cos(v) + 1/(0.347826*v-1.10176) + 2.5*sin(v)); \
yn: sin(u)*(cos(v)*(6*(R+r*cos(v)) + (0.72611*r)/(1-0.3157*v)) + (0.72611*R)/(1-0.3157*v) - 2*R*sin(v)); \
zn: sin(v)*(R*r-1.25r*cos(u)*sin(5*u) + r*r*cos(v)) + (v^19)*(-20*cos(u)*(cos(u)+cos(v)) + 25*sin(5*u))/(pi^20); "
#endif
#if (COMPILE_DESC_DERIV2_U_FRUITS != 0)
	"xuu: -cos(u)*(R + cos(v)); \
yuu: -sin(u)*(R+r*cos(v)) - 6.25*cos(5*u); \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_FRUITS != 0)
	"xuv: r*sin(u)*sin(v); \
yuv: -r*cos(u)*sin(v); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_FRUITS != 0)
	"xvv: -r*cos(u)*cos(v) + 380*(v^18)/(pi^20); \
yvv: -r*cos(v)*sin(u); \
zvv: (0.229233)/((1-0.3157v)^2) - 6*sin(v) - 2*cos(v); "
#endif
	"end;";
#endif