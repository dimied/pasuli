

#include "pasuli_defs.h"
#include "pasuli_macros.h"

void initConstAll( PaSuLiObject* pO, pasuli_consttype value ) {

	P_X( value );
	P_Y( value );
	P_Z( value );

	UD_X( value );
	UD_Y( value );
	UD_Z( value );

	VD_X( value );
	VD_Y( value );
	VD_Z( value );

	N_X( value );
	N_Y( value );
	N_Z( value );

	UUD_X( value );
	UUD_Y( value );
	UUD_Z( value );

	UVD_X( value );
	UVD_Y( value );
	UVD_Z( value );

	VVD_X( value );
	VVD_Y( value );
	VVD_Z( value );
}

