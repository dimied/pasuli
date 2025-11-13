
#include "epizykloid_torus1.h"
#include "torus_c_includes.h"

#if (USE_EPIZYKLOID_TORUS_1 != 0)

void EpizykloidTorus1(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EPIZYKLOID_TORUS_1)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype h = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype R_plus_r = R + r;

	pasuli_calctype cos_R_plus_r = cos((R_plus_r * v) / r);
	pasuli_calctype sin_R_plus_r = sin((R_plus_r * v) / r);

	pasuli_calctype factor = h * cos_R_plus_r + R1 + R_plus_r * cos_v;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(R_plus_r * sin_v - h * sin_R_plus_r);

	// Ignore scaling
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	factor = h * R_plus_r * sin_R_plus_r / r - R_plus_r * sin_v;

	VD_X(factor * cos_u);
	VD_Y(factor * sin_u);
	VD_Z(R_plus_r * cos_v - h * R_plus_r * cos_R_plus_r / r);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEpizykloidTorus1 = {
	EPIZYKLOID_TORUS_1,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descEpizykloidTorus1 =
	"name: Epizykloid Torus 1;\
cat: torus;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R1:1; c2:R: 1; c3:r:0.5; c4:h: 1;\
x: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*cos(u);\
y: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*sin(u);\
z: (R + r)*sin(v) - h*sin(((R + r)/r)*v);\
xu: -(R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*sin(u);\
yu: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*cos(u);\
zu: 0;\
xv: cos(u)*(h*(1+R/r)*sin(((R + r)/r)*v)-(R+r)*sin(v));\
yv: sin(u)*(h*(1+R/r)*sin(((R + r)/r)*v)-(R+r)*sin(v));\
zv: (R + r)*cos(v) - h*(1 + R/r)*cos*(((R + r)/r)*v);";
#endif
