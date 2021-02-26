
#include "tranguloid_trefoil.h"
#include "surfaces_c_includes.h"

#if (USE_TRANGULOID_TREFOIL != 0)
void TranguloidTrefoil(pasuli_vartype u, pasuli_vartype v,
					   pasuli_consttype *constants,
					   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRANGULOID_TREFOIL)

	pasuli_calctype sin_3u = sin(3.0 * u);
	pasuli_calctype sin_2u = sin(2.0 * u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_2u = cos(2.0 * u);

	pasuli_calctype cos_v_plus_2 = 2.0 + cos(v);
	pasuli_calctype cos_v_plus_2PI = (2 + cos(v + 2 * MY_PI / 3.0));

	P_X(2 * sin_3u / cos_v_plus_2);
	P_Y(2 * (sin_u + 2 * sin_2u) / cos_v_plus_2PI);
	P_Z((cos_u - 2 * cos_2u) * cos_v_plus_2 * cos_v_plus_2PI * 0.25);

	pasuli_calctype cos_3u = cos(3.0 * u);
	pasuli_calctype sin_v_pi3 = sin(v + MY_PI / 3.0);
	pasuli_calctype sin_2v = sin(2.0 * v);
	pasuli_calctype cos_2v = cos(2.0 * v);

	UD_X(6 * cos_3u / cos_v_plus_2);
	UD_Y(-2 * (cos_u + 4 * cos_2u) / cos_v_plus_2PI);
	UD_Z((-2 * cos_2u + cos_u) * (2 * sin_v_pi3 - 0.5 * (sin_2v + sqrt(3) * cos_2v)) * 0.25);

	pasuli_calctype sin_v = sin(v);
	pasuli_calctype sin_v_pi6 = sin(v + MY_PI / 6.0);

	VD_X(2 * sin_v * sin_3u / (cos_v_plus_2 * cos_v_plus_2));
	VD_Y(2 * (1 + 4 * cos_u) * cos_v_plus_2PI * sin_u / (sin_v_pi6 * sin_v_pi6));
	VD_Z((-2 + sin_v_pi6) * (cos_v_plus_2) * (sin_u - 4 * sin_2u) * 0.25);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTranguloidTrefoil = {
	TRANGULOID_TREFOIL,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTranguloidTrefoil =
	"name: Tranguloid Trefoil;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
x: 2*sin(3*u)/(2 + cos(v));\
y: 2*(sin(u) + 2*sin(2*u))/(2 + cos(v + 2*pi/3));\
z: (cos(u) - 2*cos(2*u))*(2 + cos(v))*(2 + cos(v + 2*pi/3))/4;\
xu: 6*cos(3*u)/(2+cos(v));\
yu: -(2*cos(u)+8*cos(2*u))/(sin(v+pi/6) - 2);\
zu: (-2*cos(2*u) + cos(u))*(2*sin(v+pi/3) - sin(2*v)/2 + sqrt(3)*cos(2*v)/2) /4;\
xv: 2*sin(v)*sin(3*u)/(2+cos(v))^2;\
yv: 2*(1+4*cos(u))*cos(v+pi/6)*sin(u)/(sin(v+pi/6) - 2)^2;\
zv: (-2+sin(v+pi/6))*(2+cos(v))*(-4*sin(2*u) + sin(u))/4;";
#endif