
#include "paraboloid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_PARABOLOID != 0)
void Paraboloid(pasuli_vartype u, pasuli_vartype v,
				double *constants, PaSuLiObject *pO)
{

	PASULI_SET_TYPE_ID(PARABOLOID)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype a_cos_u = a * cos(u);
	pasuli_calctype a_sin_u = a * sin(u);

	P_X(a_cos_u * v);
	P_Y(a_sin_u * v);
	P_Z(b * v * v);

	UD_X(-PASULI_COND_COPY_POS_Y(a_sin_u * v));
	UD_Y(PASULI_COND_COPY_POS_X(a_cos_u * v));
	UD_Z_CONST(0);

	VD_X(a_cos_u);
	VD_Y(a_sin_u);
	VD_Z(2 * b * v);

	N_X(2 * b * v * v * a_cos_u);
	N_Y(2 * b * v * v * a_sin_u);
	N_Z(-a * a * v);

	UUD_X(-PASULI_COND_COPY_POS_X(a_cos_u * v));
	UUD_Y(-PASULI_COND_COPY_POS_Y(a_sin_u * v));
	UUD_Z_CONST(0);

	UVD_X(-a_sin_u);
	UVD_Y(a_cos_u);
	UVD_Z_CONST(0);

	VVD_X_CONST(0);
	VVD_Y_CONST(0);
	VVD_Z(2 * b);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddParaboloid = {
PSLDD_ID( PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI| \
PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descParaboloid =
	"name: Paraboloid;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:0; ve: 2;\
c1:a: 1.5; c2:b: 0.5;\
x: a*v*cos(u);\
y: a*v*sin(u);\
z: b*v*v;\
xu: -a*v*sin(u);\
yu: a*v*cos(u);\
zu: 0;\
xv: a*cos(u);\
yv: a*sin(u);\
zv: 2*b*v;\
xn: 2*a*b*v*v*cos(u);\
yn: 2*a*b*v*v*sin(u);\
zn: -a*a*v;\
xuu: -a*v*cos(u);\
yuu: -a*v*sin(u);\
zuu: 0;\
xuv: -a*sin(u);\
yuv: a*cos(u);\
zuv: 0;\
xvv: 0; yvv: 0; zvv: 2*b;";
#endif