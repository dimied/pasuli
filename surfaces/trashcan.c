
#include "trashcan.h"
#include "surfaces_c_includes.h"

#if (USE_TRASHCAN != 0)

void Trashcan(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRASHCAN)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	P_X((b + v) * cos_u);
	P_Y(v * sin_u);
	P_Z(a * v * v);

	UD_X(-(b + v) * sin_u);
	UD_Y(v * cos_u);
	UD_Z(0);

	VD_X(cos_u);
	VD_Y(sin_u);
	VD_Z(2 * a * v);

	N_X(2 * a * v * v * cos_u);
	N_Y(2 * a * (b + v) * v * sin_u);
	N_Z(-b * sin_u * sin_u - v);

	UUD_X(-(b + v) * cos_u);
	UUD_Y(-v * sin_u);
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
PaSuLiDefDesc pslddTrashcan = {
PSLDD_ID( TRASHCAN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTrashcan =
	"name: Trashcan;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve: 2;\
c1:a: 1.5; c2:b: 0.5;\
x: (b + v)*cos(u);\
y: v*sin(u);\
z: a*v*v;\
xu: -(b+v)*sin(u);\
yu: v*cos(u);\
zu: 0;\
xv: cos(u);\
yv: sin(u);\
zv: 2*a*v;\
xn: 2*a*v*v*cos(u);\
yn: 2*a*(b+v)*v*sin(u);\
zn: -b*sin(u)^2 - v;\
xuu: -(b+v)*cos(u);\
yuu: -v*sin(u);\
zuu: 0;\
xuv: -sin(u);\
yuv: cos(u);\
zuv: 0;\
xvv: 0;\
yvv: 0;\
zvv: 2*a;";
#endif