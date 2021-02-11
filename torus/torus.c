
#include "torus_inc.h"

#if (USE_PASULI_TORUS_TORUS != 0)
void Torus(pasuli_vartype u, pasuli_vartype v,
		   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TORUS)

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];

	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u);
	pasuli_vartype cos_v = cos(v);
	pasuli_vartype sin_v = sin(v);
	pasuli_vartype rr_cos_v = R + r * cos_v;

	P_X(rr_cos_v * cos_u);
	P_Y(rr_cos_v * sin_u);
	P_Z(r * sin_v);

	UD_X(-rr_cos_v * sin_u);
	UD_Y(rr_cos_v * cos_u);
	UD_Z_CONST(0);

	VD_X(-r * sin_v * cos_u);
	VD_Y(-r * sin_v * sin_u);
	VD_Z(r * cos_v);

	N_X(rr_cos_v * r * cos_u * cos_v);
	N_Y(rr_cos_v * r * sin_u * sin_v);
	N_Z(rr_cos_v * r * sin_v);

	UUD_X(-rr_cos_v * cos(u));
	UUD_Y(-rr_cos_v * sin(u));
	UUD_Z(0);

	UVD_X(r * sin_v * sin_u);
	UVD_Y(-r * sin_v * cos_u);
	UVD_Z(0);

	VVD_X(-r * cos_v * cos_u);
	VVD_Y(-r * cos_v * sin_u);
	VVD_Z(-r * sin_v);
}
#endif

#include "torus_const.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTorus = {
	PSLDD_ID(TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_U_END_PI | PASULI_V_END_PI | PASULI_FULL_IMPL | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, torus_def_constants};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descTorus =
	"name: Torus; \
cat: torus; \
ut: c; \
vt: c; \
us:0;  \
ue:pi:2; \
vs:0; \
ve:pi:2; \
c1:R:1.5; \
c2:r:0.5; \
x: (R + r*cos(v))*cos(u); \
y: (R + r*cos(v))*sin(u); \
z: r*sin(v); \
xu: -(R + r*cos(v))*sin(u) ; \
yu: (R + r*cos(v))*cos(u); \
zu: 0; \
xv: -r*sin(v)*cos(u); \
yv: -r*sin(v)*sin(u); \
zv: r*cos(v); \
xn: r*(R + r*cos(v))*cos(u)*cos(v); \
yn: r*(R + r*cos(v))*sin(u)*cos(v); \
zn: (R + r*cos(v))*r*sin(v); \
xuu: -(R + r*cos(v))*cos(u); \
yuu: -(R + r*cos(v))*sin(u); \
zuu: 0; \
xuv: r*sin(v)*sin(u); \
yuv: -r*sin(v)*cos(u); \
zuv: 0; \
xvv: -r*cos(v)*cos(u); \
yvv: -r*cos(v)*sin(u); \
zvv: -r*sin(v);";
#endif