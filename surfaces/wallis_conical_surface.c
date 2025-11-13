
#include "wallis_conical_surface.h"
#include "surfaces_c_includes.h"

#if (USE_WALLIS_CONICAL_SURFACE != 0)

void WallisConicalSurface(pasuli_vartype u,
						  pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(WALLIS_CONICAL_SURFACE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype bb_cos_u = b * b * cos_u;

	pasuli_calctype common = sqrt(a * a - bb_cos_u * cos_u);
	P_Y(v * sin_u);
	P_X(v * cos_u);
	P_Z(c * common);

	UD_X(-v * cos_u);
	UD_Y(v * sin_u);
	UD_Z(b * b * c * cos_u * sin_u / common);

	VD_X(cos_u);
	VD_Y(sin_u);
	VD_Z_CONST(0);

	// Multiplied by (sqrt(a*a-b*b*cos(u)*cos(u)))
	N_X(-bb_cos_u * c * sin_u * sin_u);
	N_Y(bb_cos_u * c * cos_u * sin_u);
	N_Z(-v * common);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWallisConicalSurface = {
PSLDD_ID( WALLIS_CONICAL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
-1, 1 , 0 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descWallisConicalSurface =
	"name: Wallis Conical Surface;\
ut: c; vt:c;\
us: -1; ue: 1;\
vs:0; ve: 1;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: v*cos(u);\
y: v*sin(u);\
z: c*sqrt(a*a - b*b*cos(u)*cos(u));\
xu: -v*sin(u);\
yu: v*cos(u);\
zu: (b*b*c*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u)));\
xv: cos(u);\
yv: sin(u);\
zv: 0;\
xn: -(b*b*c*cos(u)*sin(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u)));\
yn: (b*b*c*cos(u)*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u)));\
zn: -v;";
#endif