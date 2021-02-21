
#include "triaxial_teardrop.h"
#include "surfaces_c_includes.h"

#if (USE_TRIAXIAL_TEARDROP != 0)
void TriaxialTeardrop(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIAXIAL_TEARDROP)

	pasuli_calctype one_minus_cos_u = (1 - cos(u));
	pasuli_calctype cos_u_plus_2pi3 = cos(u + 2 * MY_PI / 3.0);
	pasuli_consttype cos_u_prepared = one_minus_cos_u * cos_u_plus_2pi3 * 0.5;

	pasuli_consttype pos_x_v = cos(v + 2 * MY_PI / 3.0);
	pasuli_consttype pos_y_v = cos(v - 2 * MY_PI / 3.0);

	P_X(cos_u_prepared * pos_x_v);
	P_Y(cos_u_prepared * pos_y_v);
	P_Z(cos(u - 2 * MY_PI / 3.0));

	pasuli_consttype ud_prepared = (-one_minus_cos_u * sin(u + 2 * MY_PI / 3.0) + sin(u) * cos_u_plus_2pi3) * 0.5;
	UD_X(pos_x_v * ud_prepared);
	UD_Y(pos_y_v * ud_prepared);
	UD_Z(sin(2 * MY_PI / 3.0 - v));

	// Skip scaling by (1 - cos(u)) * cos(u + 2 * MY_PI / 3.0)
	cos_u_prepared = PASULI_CALC_SIGN(cos_u_prepared);
	VD_X(-cos_u_prepared * sin(v + 2 * MY_PI / 3.0));
	VD_Y(cos_u_prepared * sin(2 * MY_PI / 3.0 - v));
	VD_Z(0);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTeardrop = {
	PSLDD_ID(TRIAXIAL_TEARDROP)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
	0, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTriaxialTeardrop =
	"name: Triaxial Teardrop;\
ut:c; vt:c;\
us: 0; ue:pi: 1;\
vs: 0; ve:pi: 2;\
x: (1 - cos(u))*cos(u + 2*pi/3)*cos(v + 2*pi/3)/2;\
y: (1 - cos(u))*cos(u + 2*pi/3)*cos(v - 2*pi/3)/2;\
z: cos(u - 2*pi/3);\
xu: cos(v + 2*pi/3)*(cos(u)*sin(u + 2*pi/3) + cos(u + 2*pi/3)*sin(u) - sin(u + 2*pi/3))/2;\
yu: cos(v - 2*pi/3)/2*(cos(u)*sin(u + 2*pi/3) + cos(u + 2*pi/3)*sin(u) - sin(u + 2*pi/3))/2;\
zu: sin(2*pi-u);\
xv: -(1 - cos(u))*cos(u + 2*pi/3)*sin(v + 2*pi/3);\
yv: (1 - cos(u))*cos(u + 2*pi/3)*sin(2*pi/3-v);\
zv: 0;";
#endif