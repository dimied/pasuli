

#include "../pasuli_macros.h"
#include "../pasuli_const.h"
#include "fruits.h"

#pragma warning(disable:4244)


#if(COMPILE_FRUITS != 0)

void KidneySurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KIDNEY_SURFACE )

	pasuli_vartype cv = cos(v);
	pasuli_vartype c3v = cos(3*v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype s3v = sin(3*v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	
	pasuli_vartype xy = (3*cv - c3v);

	P_X( cu*xy );
	P_Y( su*xy );
	P_Z( 3*sv - s3v );

	xy = (3*cv - c3v);
	UD_X( -su*xy );
	UD_Y( cu*xy );
	UD_Z_CONST( 0 );

	xy = (3*s3v - 3*sv);
	VD_X( cu*xy );
	VD_Y( su*xy );
	VD_Z( 3*cv - 3*c3v );

	xy = (3*cv - c3v)*(3*cv - 3*c3v);
	N_X( cu*xy );
	N_Y( -su*xy );
	N_Z( -(3*s3v - 3*sv)*(3*cv - c3v) );

	xy = (3*cv - c3v);
	UUD_X( -cu*xy );
	UUD_Y( -su*xy );
	UUD_Z( 0 );

	xy = (3*s3v - 3*sv);
	UVD_X( -su*xy );
	UVD_Y( cu*xy );
	UVD_Z( 0 );

	xy = (9*c3v -3*cv);
	VVD_X( cu*xy );
	VVD_Y( su*xy );
	VVD_Z( 9*s3v - 3*sv );
}
#endif


#if(COMPILE_FRUITS != 0)
void AppleSurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( APPLE_SURFACE )

	pasuli_vartype sin_v = sin(v);
	pasuli_vartype x_or_y_mul = 4 + 3.8*cos(v);

	P_X( cos(u)*x_or_y_mul );
	P_Y( sin(u)*x_or_y_mul );
	P_Z( (cos(v) + sin_v - 1)*(1 + sin_v)*log(1 - MY_PI*v/10.0) + 7.5*sin_v );

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




#if(COMPILE_FRUITS != 0)
void Apple2_Surface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( APPLE2_SURFACE )

	pasuli_vartype R1 = constants[0];
	pasuli_vartype xy = R1 + constants[1]*cos(v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv2 = 2.0*cos(v);
	pasuli_vartype sv2 = 2.0*sin(v);
	pasuli_vartype c5u = cos(5.0*u);

	P_X( cu*xy + pow(v/MY_PI, 20) );
	P_Y( su*xy + c5u*0.25 );
	P_Z( -2.3*log(1 - v*0.3157) + 3*sv2 + cv2 );

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





#if(COMPILE_FRUITS != 0)
void LemonSurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LEMON_SURFACE )

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype xy = sqrt(R*R - u*u) - r;

	P_X( xy*sv );
	P_Y( xy*cv );
	P_Z( u );

	UD_X( -sv/xy );
	UD_Y( -cv/xy );
	UD_Z_CONST( 1 );


	xy = sqrt(R*R - u*u) - r;
	VD_X( xy*cv );
	VD_Y( -(xy*sv) );
	VD_Z_CONST( 0 );

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




