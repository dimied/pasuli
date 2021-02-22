
#include "torus.h"
#include "torus_c_includes.h"

#if (USE_TORUS != 0)
void Torus(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype factor = R + r * cos_v;

	P_X(factor * cos_u);
	P_Y(factor * sin_u);
	P_Z(r * sin_v);

	// Ignore scaling by (R + r*cos(v))
	factor = PASULI_CALC_SIGN(factor);
	UD_X(-factor * sin_u);
	UD_Y(factor * cos_u);
	UD_Z_CONST(0);

	VD_X(-r * sin_v * cos_u);
	VD_Y(-r * sin_v * sin_u);
	VD_Z(r * cos_v);

	pasuli_calctype factor2 = factor*r;
	factor2 = PASULI_CALC_SIGN(factor2);
	// Ignore scaling by r*(R + r*cos(v))
	N_X(factor2 * cos_u * cos_v);
	N_Y(factor2 * sin_u * cos_v);
	N_Z(factor2 * sin_v);

	UUD_X(-factor * cos_u);
	UUD_Y(-factor * sin_u);
	UUD_Z(0);

	UVD_X(r * sin_v * sin_u);
	UVD_Y(-r * sin_v * cos_u);
	UVD_Z(0);

	VVD_X(-r * cos_v * cos_u);
	VVD_Y(-r * cos_v * sin_u);
	VVD_Z(-r * sin_v);
}
#endif

/*
#include "torus_const.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTorus = {
	PSLDD_ID(TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_U_END_PI | PASULI_V_END_PI | PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, torus_def_constants};
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descTorus =
	"name: Torus;\
cat: torus;\
ut: c; vt: c;\
us:0;  ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1.5; c2:r:0.5;\
x: (R+r*cos(v))*cos(u);\
y: (R+r*cos(v))*sin(u);\
z: r*sin(v);\
xu: -(R + r*cos(v))*sin(u) ;\
yu: (R + r*cos(v))*cos(u);\
zu: 0;\
xv: -r*sin(v)*cos(u);\
yv: -r*sin(v)*sin(u);\
zv: r*cos(v);\
xn: r*(R + r*cos(v))*cos(u)*cos(v);\
yn: r*(R + r*cos(v))*sin(u)*cos(v);\
zn: (R + r*cos(v))*r*sin(v);\
xuu: -(R + r*cos(v))*cos(u);\
yuu: -(R + r*cos(v))*sin(u);\
zuu: 0;\
xuv: r*sin(v)*sin(u);\
yuv: -r*sin(v)*cos(u);\
zuv: 0;\
xvv: -r*cos(v)*cos(u);\
yvv: -r*cos(v)*sin(u);\
zvv: -r*sin(v);";
#endif