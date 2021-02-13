
#include "funnel.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_FUNNEL != 0)
void Funnel(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FUNNEL )

	double cv = cos(v);
	double sv = sin(v);

	P_X( u*cv );
	P_Y( u*sv );
	P_Z( log(u) );

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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFunnel = {
PSLDD_ID( FUNNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
0.01f, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFunnel =
"name: Funnel; \
ut:c; vt:c; \
us: 0.1; ue: 2; \
vs: 0; ve:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: log(u); \
xu: cos(v); yu: sin(v); zu: 1/u; \
xv: -u*sin(v); yv: u*cos(v); zv: 0; \
xn: -cos(v); \
yn: -sin(v); \
zn: u; \
xuu: 0; yuu: 0; zuu: -1/(u*u); \
xuv: -sin(v); yuv: cos(v); zuv: 0; \
xvv: -u*cos(v); yvv: -u*sin(v); zvv: 0;";
#endif