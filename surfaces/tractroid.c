
#include "tractroid.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_TRACTROID != 0)
void Tractroid(pasuli_vartype u, pasuli_vartype v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRACTROID )

	double sech_u = 1.0f / cosh(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( sech_u*cv );
	P_Y( sech_u*sv );
	P_Z( u - tanh(u) );

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
PaSuLiDefDesc pslddTractroid = {
PSLDD_ID( TRACTROID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 4 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTractroid =
"name: Tractroid; \
ut:c; vt:c; \
us: 0; ue: 4; \
vs: 0; ve:pi: 2; \
x: sech(u)*cos(v); \
y: sech(u)*sin(v); \
z: u - tanh(u); \
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