
#include "paraboloid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_PARABOLOID != 0)
void Paraboloid(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PARABOLOID )

	double a = constants[0];
	double b = constants[1];
    
	double acu = a*cos(u);
	double asu = a*sin(u);

	P_X( acu*v );
	P_Y( asu*v );
	P_Z( b*v*v );

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
PaSuLiDefDesc pslddParaboloid = {
PSLDD_ID( PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI| \
PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descParaboloid =
"start; \
name: Paraboloid; \
ut:c; \
vt:c; \
us:pi: -1; \
ue:pi: 1; \
vs: 0; \
ve: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: a*v*cos(u); \
y: a*v*sin(u); \
z: b*v*v; "
"xu: -a*v*sin(u); \
yu: a*v*cos(u); \
zu: 0; "
"xv: a*cos(u); \
yv: a*sin(u); \
zv: 2*b*v; "
"xn: 2*a*b*v*v*cos(u); \
yn: 2*a*b*v*v*sin(u); \
zn: -a*a*v; "
"xuu: -a*v*cos(u); \
yuu: -a*v*sin(u); \
zuu: 0; "
"xuv: -a*sin(u); yuv: a*cos(u); zuv: 0; "
"xvv: 0; yvv: 0; zvv: 2*b; "
"end;";
#endif