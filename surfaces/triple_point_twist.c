
#include "triple_point_twist.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_POINT_TWIST != 0)

void TriplePointTwist(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIPLE_POINT_TWIST)

	pasuli_consttype c = constants[0];

	pasuli_calctype v2 = v * v;
	pasuli_calctype v3 = v2 * v;

	P_X(u);
	P_Y(v3 + c * v);
	P_Z(u * v + v2 * v3 + c * v3);

	UD_X(1);
	UD_Y(0);
	UD_Z(v);

	VD_X(0);
	VD_Y(c + 3 * v2);
	VD_Z(3 * c * v2 + u + 5 * v2 * v2);

	N_X(-v * (c + 3 * v2));
	N_Y(-PASULI_COND_COPY_VD_Z(3 * c * v2 + u + 5 * v2 * v2));
	N_Z(PASULI_COND_COPY_VD_Y(c + 3 * v2));

	UUD_ALL(0);

	UVD_X_CONST(0);
	UVD_Y_CONST(0);
	UVD_Z_CONST(1);

	VVD_X_CONST(0);
	VVD_Y(6 * v);
	VVD_Z(v * (6 * c + 20 * v2));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriplePointTwist = {
PSLDD_ID( TRIPLE_POINT_TWIST )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-2, 1.7f , -1.5f , 1.5f , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTriplePointTwist =
	"name: Triple point Twist; \
ut:c; vt:c; \
us: -2; ue: 1.7; \
vs: -1.5; ve: 1.5; \
c1:c: 1.5; \
x: u; \
y: v^3+c*v; \
z: u*v+v^5+c*v^3; \
xu: 1; \
yu: 0; \
zu: v; \
xv: 0; \
yv: c+3*v*v; \
zv: 3*c*v*v+u+5*v^4; \
xn: -c*v-3*v^3; \
yn: -3*c*v^2-u-5*v^4; \
zn: c+3*v^2; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 1; \
xvv: 0; \
yvv: 6*v; \
zvv: 6*c*v+20*v^3;";
#endif