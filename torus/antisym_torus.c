
#include "torus_inc.h"

#define GET__C		pasuli_vartype R = constants[0]; \
					pasuli_vartype r = constants[1]; \
					pasuli_vartype a = constants[2];

#define TORUS_POS	POS_OP( posxy = cv*r_a_sin_u + R ); \
					P_X( posxy*cu ); \
					P_Y( posxy*su ); \
					P_Z( sv*r_a_sin_u );

#define TORUS_UD	UD_OP( udxy = r*cv*cu ); \
					UD_X( udxy*cu -  (R + cv*r_a_sin_u)*su ); \
					UD_Y( udxy*su +  (R + cv*r_a_sin_u)*cu ); \
					UD_Z( r*sv*cu );

#define TORUS_VD	VD_OP( vdxy = -sv*r_a_sin_u ); \
					VD_X( vdxy*cu ); \
					VD_Y( vdxy*su ); \
					VD_Z( cv*r_a_sin_u );


#if(USE_PASULI_TORUS_ANTISYM_TORUS != 0)

void AntisymmetricTorus(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {

	PASULI_SET_TYPE_ID( ANTISYMMETRIC_TORUS )
	GET__C

	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype sv = sin(v);
	pasuli_vartype cv = cos(v);

	pasuli_vartype r_a_sin_u = (a + su)*r;
	POS_OP(pasuli_vartype posxy);
	UD_OP( pasuli_vartype udxy );
	VD_OP( pasuli_vartype vdxy );

	TORUS_POS

	TORUS_UD

	TORUS_VD

	TORUS_NORMAL_VARS_DEF
	TORUS_NORMAL

	pasuli_vartype xy = (R + cv*r_a_sin_u);

	UUD_X( r*cv*2*cu*su + xy*cu + r*cv*cu*su );
	UUD_Y( -r*cv*su*su + r*cv*cu*cu + r*cv*cu*cu - xy*su );
	UUD_Z( -r*sv*su );

	UVD_OP( pasuli_vartype uvdxy );

	UVD_OP( uvdxy = -r*sin(v)*(a + sin(u)) );
	UVD_X( uvdxy*cu );
	UVD_Y( uvdxy*su );
	UVD_Z( r*cos(v)*(a + sin(u)) );

	VVD_OP( pasuli_vartype vvdxy );

	VVD_OP( vvdxy = -r*sin(v)*(a + sin(u)) );
	VVD_X( vvdxy*cu );
	VVD_Y( vvdxy*su );
	VVD_Z( r*cos(v)*(a + sin(u)) );
}

#endif

