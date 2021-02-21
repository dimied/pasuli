
#include "astroid_torus.h"
#include "torus_c_includes.h"

#if (USE_ASTROID_TORUS != 0)

void AstroidTorus(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ASTROID_TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype factor = R + cos_v * cos_v * cos_v;

	P_X(cos_u * factor);
	P_Y(sin_u * factor);
	P_Y(r * sin_v * sin_v * sin_v);

	pasuli_calctype sign_value = PASULI_CALC_SIGN(factor);
	// Don't scale (R + r*cos(v)^3)
	UD_X(-sin_u * sign_value);
	UD_Y(cos_u * sign_value);
	UD_Z(0);

	sign_value = PASULI_CALC_SIGN(cos_v * sin_v * r);
	// Don't scale by 3*cos(v)*sin(v)*r
	VD_X(-sign_value * cos_u * cos_v);
	VD_Y(-sign_value * sin_u * cos_v);
	VD_Z(sign_value * sin_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddAstroidTorus = {
	PSLDD_ID(ASTROID_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descAstroidTorus =
	"name: Astroid Torus; \
cat: torus; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:R: 1; c2:r: 1; \
a1:F: (R + r*cos(v)^3); \
x: F*cos(u);\
y: F*sin(u);\
z: r*sin(v)^3;\
xu: -sin(u)*(R + r*cos(v)^3);\
yu: cos(u)*(R + r*cos(v)^3);\
zu: 0;\
xv: -3*r*cos(u)*cos(v)^2*sin(v);\
yv: -3*r*sin(u)*cos(v)^2*sin(v);\
zv: 3*r*cos(v)*sin(v)^2;";
#endif