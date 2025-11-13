
#include "triaxial_tritorus.h"
#include "surfaces_c_includes.h"

#if (USE_TRIAXIAL_TRITORUS != 0)
void TriaxialTritorus(pasuli_vartype u, pasuli_vartype v,
					  double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIAXIAL_TRITORUS)

	pasuli_calctype two_pi_3 = (2.0 * MY_PI) / 3.0;
	pasuli_calctype four_pi_3 = (4.0 * MY_PI) / 3.0;
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype pos_x_factor_u = sin(u + two_pi_3);
	pasuli_calctype pos_x_factor_v = (1 + cos(v + two_pi_3));
	pasuli_calctype pos_y_factor_u = sin(u + four_pi_3);
	pasuli_calctype pos_y_factor_v = (1 + cos(v + four_pi_3));
	pasuli_calctype pos_z_factor = (1 + cos(v));

	P_X(pos_x_factor_u * pos_x_factor_v);
	P_Y(pos_y_factor_u * pos_y_factor_v);
	P_Z(sin_u * pos_z_factor);

	UD_X(cos(u + two_pi_3) * pos_x_factor_v);
	UD_Y(cos(u + four_pi_3) * pos_y_factor_v);
	UD_Z(cos(u) * pos_z_factor);

	VD_X(pos_x_factor_u * sin(v + two_pi_3));
	VD_Y(pos_y_factor_u * sin(v + four_pi_3));
	VD_Z(-sin_u * sin(v));

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTritorus = {
	TRIAXIAL_TRITORUS,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descTriaxialTritorus =
	"name: Triaxial Tritorus;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
x: sin(u + 2*pi/3)*(1 + cos(v + 2*pi/3));\
y: sin(u + 4*pi/3)*(1 + cos(v + 4*pi/3));\
z: sin(u)*(1 + cos(v));\
xu: cos(u + 2*pi/3)*(1 + cos(v + 2*pi/3));\
yu: cos(u + 4*pi/3)*(1 + cos(v + 4*pi/3));\
zu: cos(u)*(1 + cos(v));\
xv: -sin(u + 2*pi/3)*sin(v + 2*pi/3);\
yv: -sin(u + 4*pi/3)*sin(v + 4*pi/3);\
zv: -sin(u)*sin(v);";
#endif