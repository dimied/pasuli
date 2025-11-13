

#include "cylinder.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_CYLINDER != 0)
void Cylinder(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CYLINDER)

	pasuli_consttype r = constants[0];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	P_X(r * cos_u);
	P_Y(r * sin_u);
	P_Z(v);

	UD_X(-PASULI_COND_COPY_POS_Y(r * sin_u));
	UD_Y(PASULI_COND_COPY_POS_X(r * cos_u));
	UD_Z_CONST(0);

	VD_X_CONST(0);
	VD_Y_CONST(0);
	VD_Z_CONST(1);

	N_X(PASULI_COND_COPY_POS_X(r * cos_u));
	N_Y(PASULI_COND_COPY_POS_Y(r * sin_u));
	N_Z_CONST(0);

	PASULI_2ND_DERIVATIVES_START

	UUD_X(-PASULI_COND_COPY_POS_X(r * cos_u));
	UUD_Y(-PASULI_COND_COPY_POS_X(r * sin_u));
	UUD_Z(0);

	UVD_ALL(0);
	VVD_ALL(0);

	PASULI_2ND_DERIVATIVES_END
}
#endif

/*
#if (COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct c_constants[] = {1};
PaSuLiDefDesc pslddCylinder = {
	CYLINDER,
			PASULI_U_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(1),
	-1, 1, 0, 1, (pasulidefdesc_ct *)0}; //c_constants};
#endif
*/
#if (COMPILE_DESC_CYLINDER != 0)
char *descCylinder =
	"name: Cylinder;\
cat: cylinder;\
ut: c; vt: o;\
us:pi: -1; ue:pi:1;\
vs:0; ve: 1;\
c1:r: 1;\
x: r*cos(u);\
y: r*sin(u);\
z: v;\
xu: -r*sin(u);\
yu: r*cos(u);\
zu: 0;\
xv: 0;\
yv: 0;\
zv: 1;\
xn: r*cos(u);\
yn: r*sin(u);\
zn: 0;\
xuu: -r*cos(u);\
yuu: -r*sin(u);\
zuu: 0;\
xuv: 0; yuv: 0; zuv: 0;\
xvv: 0; yvv: 0; zvv: 0; ";
#endif