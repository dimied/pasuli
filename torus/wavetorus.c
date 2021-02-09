
#include "torus_inc.h"

#define GET__C		pasuli_vartype R = constants[0]; \
					pasuli_vartype r = constants[1]; \
					pasuli_vartype a = constants[2]; \
					pasuli_vartype N = constants[3];

#define TORUS_POS	P_X( posxy*cu ); \
					P_Y( posxy*su ); \
					P_Z( posxyz*sv );

#define TORUS_UD	UD_X( -su ); \
					UD_Y( -cu ); \
					UD_Z( 0 );

#define TORUS_VD	VD_X( -r*sv*cu ); \
					VD_Y( -r*sv*su ); \
					VD_Z( -r*cv );

#define TORUS_N		N_X( cu*r*cv ); \
					N_Y( su*r*sv ); \
					N_Z( r*sv );

#define TORUS_UUD	UUD_X( -su ); \
					UUD_Y( -cu ); \
					UUD_Z( 0 );

#define TORUS_UVD	UVD_X( -su ); \
					UVD_Y( -cu ); \
					UVD_Z( 0 );

#define TORUS_VVD	VVD_X( -r*sv*cu ); \
					VVD_Y( -r*sv*su ); \
					VVD_Z( -r*cv );


#if(COMPILE_TORUS != 0)
void WaveTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WAVE_TORUS )

	GET__C

#if((PARTICLE_POS != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif
	pasuli_vartype posxyz = r + a*sin(N*u);
	pasuli_vartype posxy = cv*posxyz + R;

	TORUS_POS
	TORUS_UD
	TORUS_VD
	TORUS_N
	TORUS_UUD
	TORUS_UVD
	TORUS_VVD
}
#endif

#include "torus_undef.h"

