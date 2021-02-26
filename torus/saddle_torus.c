
#include "saddle_torus.h"
#include "torus_c_includes.h"

#if (USE_SADDLE_TORUS != 0)
void SaddleTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SADDLE_TORUS)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype cos_u_plus_2pi3 = cos(u + 2 * MY_PI / 3.0);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype cos_v_plus_2pi3 = cos(v + 2 * MY_PI / 3.0);
	pasuli_calctype sin_v = sin(v);

	P_X((2 + cos_u) * cos_v);
	P_Y((2 + cos_u_plus_2pi3) * cos_v_plus_2pi3);

	pasuli_calctype F = sin_u * sin_u - cos_u_plus_2pi3 * cos_u_plus_2pi3;
	pasuli_calctype value_for_u = PASULI_CALC_SIGN(F);
	value_for_u = value_for_u * sqrt(fabs(F)) + 2;
	// Now for v
	F = sin_v * sin_v - cos_v_plus_2pi3 * cos_v_plus_2pi3;
	pasuli_calctype value_for_v = PASULI_CALC_SIGN(F);

	P_Z(value_for_u * value_for_v * sqrt(fabs(F)));
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
#include "../pasuli_const.h"
PaSuLiDefDesc pslddSaddleTorus = DEFINE_DEF_DESC(
	SADDLE_TORUS,
	PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI,
	0, 2, 0, 2, 0);
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descSaddleTorus =
	"name: Saddle Torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
a1:F: 1-cos(x)*cos(x) - cos(x + 2 pi/3)*cos(x + 2 pi/3);\
x: (2 + cos(u))*cos(v);\
y: (2 + cos(u + 2*pi/3))*cos(v + 2*pi/3);\
z: (2 + sign(F(u))*sqrt(abs(F(u))))*sign(F(v))*sqrt(abs(F(v))); ";
#endif