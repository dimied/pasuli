
#include "paper_bag.h"
#include "surfaces_c_includes.h"

#if (USE_PAPER_BAG != 0)
void PaperBag(pasuli_vartype u, pasuli_vartype v,
			  double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PAPER_BAG)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u = cos(u);

	P_X(v * cos_u);
	P_Y((v + u * b) * sin_u);
	P_Z(a * v * v);

	UD_X(-v * sin_u);
	UD_Y((v + b * u) * cos_u + b * sin_u);
	UD_Z_CONST(0);

	VD_X(cos_u);
	VD_Y(sin_u);
	VD_Z(2 * a * v);

	N_X(2 * (a * b * v * (u * cos_u + sin_u) + a * v * v * cos_u));
	N_Y(2 * a * v * v * sin_u);
	N_Z(-b * u * cos_u * cos_u - b * cos_u * sin_u - v);

	UUD_X(-v * cos_u);
	UUD_Y(-b * u * sin_u + 2 * b * cos_u - v * sin_u);
	UUD_Z_CONST(0);

	UVD_X(-sin_u);
	UVD_Y(cos_u);
	UVD_Z_CONST(0);

	VVD_X_CONST(0);
	VVD_Y_CONST(0);
	VVD_Z(2 * a);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPaperBag = {
PSLDD_ID( PAPER_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descPaperBag =
	"name: Paper Bag; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve: 2; \
c1:a: 1.5; c2:b: 0.5; \
x: v*cos(u); \
y: (v + b*u)*sin(u); \
z: a*v*v; \
xu: -v*sin(u); \
yu: (v+b*u)*cos(u) + b*sin(u); \
zu: 0; \
xv: cos(u); \
yv: sin(u); \
zv: 2*a*v; \
xn: 2*a*b*u*v*cos(u) + 2*a*b*v*sin(u) + 2*a*v*v*cos(u); \
yn: 2*a*v*v*sin(u); \
zn: -b*u*cos(u)^2 - b*cos(u)*sin(u) - v; \
xuu: -v*cos(u); \
yuu: -b*u*sin(u) + 2*b*cos(u) - v*sin(u); \
zuu: 0; \
xuv: -sin(u); \
yuv: cos(u); \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 2*a;  ";
#endif