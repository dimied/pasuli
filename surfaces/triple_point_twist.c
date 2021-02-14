
#include "triple_point_twist.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_POINT_TWIST != 0)
void TriplePointTwist(double u, double v,
					  double *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIPLE_POINT_TWIST)

	double c = constants[0];

	double v2 = v * v;
	double v3 = v2 * v;

	P_X(u);
	P_Y(v3 + c * v);
	P_Z(u * v + v2 * v3 + c * v3);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X(0);
	UD_Y(0);
	UD_Z(0);

	VD_X(0);
	VD_Y(0);
	VD_Z(0);

	N_X(0);
	N_Y(0);
	N_Z(0);

	UUD_X(0);
	UUD_Y(0);
	UUD_Z(0);

	UVD_X(0);
	UVD_Y(0);
	UVD_Z(0);

	VVD_X(0);
	VVD_Y(0);
	VVD_Z(0);
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
#if(COMPILE_DESC_SURFACES != 0)
char *descTriplePointTwist =
"name: Triple point Twist; \
ut:c; vt:c; \
us: -2; ue: 1.7; \
vs: -1.5; ve: 1.5; \
c1:c: 1.5; \
x: u; \
y: v^(3) + c*v; \
z: u*v + v^(5) + c*v^(3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif