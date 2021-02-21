
#include "gear_torus.h"
#include "torus_c_includes.h"

#if (USE_GEAR_TORUS != 0)

void GearTorus(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(GEAR_TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];
	pasuli_consttype b = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype b_sin_Nv = b * sin(N * v);

	pasuli_calctype r = a + tanh(b_sin_Nv) / b;
	pasuli_calctype factor = R + r * cos_v;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(r * sin_v);

	// Ignore scaling
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z(0);

	pasuli_calctype cos_Nv = cos(N * v);
	pasuli_calctype scale = cosh(b_sin_Nv);
	scale *= scale;

	factor = N * cos_v * cos_Nv - scale * r * sin_v;
	// Scale by cosh(b*sin(n*v))^2
	VD_X(cos_u * factor);
	VD_Y(sin_u * factor);
	VD_Z(r * scale * cos_v + N * cos_Nv * sin_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#include "torus_desc.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddGearTorus = {
	PSLDD_ID(GEAR_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_FULL_IMPL | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descGearTorus =
	"name: GearTorus;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R:1; c2:a:1; c3:b:1; c4:N:1;\
a1:r: a+tanh(b*sin(n*v))/b;\
x: (R + r*cos(v))*cos(u);\
y: (R + r*cos(v))*sin(u);\
z: r*sin(v);\
xu: -(R + (a + tanh(b*sin(n*v))/b)*cos(v))*sin(u);\
yu: (R + (a + tanh(b*sin(n*v))/b)*cos(v))*cos(u);\
zu: 0;\
xv: cos(u)*((n*cos(v)*cos(n*v))/cosh(b*sin(n*v))^2-(a + tanh(b*sin(n*v))/b)*sin(v));\
yv: sin(u)*((n*cos(v)*cos(n*v))/cosh(b*sin(n*v))^2-(a + tanh(b*sin(n*v))/b)*sin(v));\
zv: (a + tanh(b*sin(n*v))/b)*cos(v) + n*cos(n*v)*sin(v)/cosh(b*sin(n*v))^2;";
#endif
