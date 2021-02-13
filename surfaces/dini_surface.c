
#include "dini_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_DINI_SURFACE != 0)
void DiniSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DINI_SURFACE )

	double a = constants[0];
	double b = constants[1];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( a*cu*sv );
	P_Y( a*su*sv );
	P_Z( a*(cv + log(tan(v*0.5))) + b*u );

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
PaSuLiDefDesc pslddDiniSurface = {
PSLDD_ID( DINI_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 4 , 0.01f , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descDiniSurface =
"start; \
name: Dini Surface; \
ut:c; \
vt:c; \
us: 0; \
ue:pi: 4; \
vs: 0.01: \
ve: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: a*cos(u)*sin(v); \
y: a*sin(u)*sin(v); \
z: a*(cos(v) + ln(tan(v/2))) + b*u; \
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