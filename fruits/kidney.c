

#include "fruits.h"
////
//#pragma warning(disable:4244)
#include "../pasuli_macros.h"
#include "../pasuli_const.h"


#if(COMPILE_FRUITS != 0)

/*
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
/*

void KidneySurface_UA(pasuli_vartype u, pasuli_vartype v, 
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

void KidneySurface_VA(pasuli_vartype u, pasuli_vartype v, 
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
*/
#endif
