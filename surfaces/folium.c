
#include "folium.h"
#include "surfaces_c_includes.h"

#if (USE_FOLIUM != 0)
void Folium(pasuli_vartype u, pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(FOLIUM)

	pasuli_calctype two_pi_3 = 2.0 * MY_PI / 3.0;

	pasuli_calctype cos_u_plus = cos(u + two_pi_3);
	pasuli_calctype cos_u_minus = cos(u - two_pi_3);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cosh_v = cosh(v);
	pasuli_calctype tanh_v = tanh(v);

	P_X(cos_u * ((2.0 * v) / MY_PI - tanh_v));
	P_Y(cos_u_plus / cosh_v);
	P_Z(cos_u_minus / cosh_v);

	pasuli_calctype sin_u = sin(u);

	UD_X((tanh_v - 2 * v) * sin_u / MY_PI);
	UD_Y(sin(u + two_pi_3) / cosh_v);
	UD_Z(cos(u + two_pi_3) * tanh_v);

	pasuli_calctype sinh_v = sinh(v);

	pasuli_calctype cosh_v2 = cosh_v * cosh_v;

	VD_X((2 - MY_PI / cosh_v2) * cos_u / MY_PI);
	VD_Y(-cos_u_minus * sinh_v / cosh_v2);
	VD_Z(sin(u + MY_PI / 3) * sinh_v / cosh_v2);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFolium = {
	PSLDD_ID(FOLIUM)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descFolium =
	"name: Folium;\
ut:c; vt:c;\
us:pi: -1; ue:pi: 1;\
vs:pi: -1; ve:pi: 1;\
x: cos(u)*(2*v/pi - tanh(v));\
y: cos(u + 2*pi/3)/cosh(v);\
z: cos(u - 2*pi/3)/cosh(v);\
xu: (tanh(v) - 2*v)*sin(u)/pi;\
yu: sin(u + 2*pi/3)/cosh(v);\
zu: cos(u + pi/3)*sinh(v)/cosh(v);\
xv: (2 - pi*sech(v)^2)*cos(u)/pi;\
yv: -cos(u + 2*pi/3)*sinh(v)/cosh(v)^2;\
zv: sin(u + pi/3)*sinh(v)/cosh(v)^2; ";
#endif