
#include "shoe_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_SHOE_SURFACE != 0)
void ShoeSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SHOE_SURFACE )

	P_X( u );
	P_Y( v );
	P_Z( (u*u*u)*0.5 - (v*v)*0.5 );

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
PaSuLiDefDesc pslddShoeSurface = {
PSLDD_ID( SHOE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descShoeSurface =
"name: Shoe Surface; \
ut:c; vt:c; \
us: -2; ue: 2; \
vs: -2; ve: 2; \
x: u; \
y: v; \
z: u*u*u/3 - v*v/2; "
"xu: 1; \
yu: 0; \
zu: u*u; "
"xv: 0; \
yv: 1; \
zv: -v; "
"xn: -u*u; \
yn: v; \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 2*u; "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: -1;";
#endif