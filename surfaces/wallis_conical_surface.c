
#include "wallis_conical_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_WALLIS_CONICAL_SURFACE != 0)
void WallisConicalSurface(double u, double v, 
							double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WALLIS_CONICAL_SURFACE )

	double a2 = constants[0];
	double b2 = constants[1];
	double c = constants[2];
	double cu = cos(u);

	P_Y( v*sin(u) );
	P_X( v*cu );
	P_Z( c*sqrt(a2*a2 - b2*b2*cu*cu) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
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
#if(COMPILE_DESC_SURFACES != 0)
char *descWallisConicalSurface =
"name: Wallis Conical Surface; \
ut: c; \
vt:c; \
us: -1; \
ue: 1; \
vs: 0; \
ve: 1; \
c1:a: 1.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: v*cos(u); \
y: v*sin(u); \
z: c*sqrt(a*a - b*b*cos(u)*cos(u)); "
"xu: -v*sin(u); \
yu: v*cos(u); \
zu: (b*b*c*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); "
"xv: cos(u); yv: sin(u); zv: 0; "
"xn: -(b*b*c*cos(u)*sin(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); \
yn: (b*b*c*cos(u)*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); \
zn: -v; "
"xuu: -v*cos(u); \
yuu: -v*sin(u); \
zuu: (b*b*c*(a*a*(cos(u)*cos(u)-sin(u)*sin(u)) - b*b*(cos(u)^4)))/((a*a-b*b*cos(u)*cos(u))*sqrt(a*a-b*b*cos(u)*cos(u))); "
"xuv: -sin(u); \
yuv: cos(u); \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0;";
#endif