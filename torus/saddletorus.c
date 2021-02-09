
#include "torus_inc.h"

#if(COMPILE_TORUS != 0)
void SaddleTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SADDLE_TORUS )

	pasuli_vartype K = constants[0];

	P_X( K*(1+u)*cos(v) );
	P_Y( K*(1-u)*sin(v) );
	P_Z( u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X( -su );
	UD_Y( -cu );
	UD_Z( 0 );

	VD_X( -K*sv*cu );
	VD_Y( -K*sv*su );
	VD_Z( -K*cv );

#if(PARTICLE_N != 0)
	pO->n[0] = cu*K*cv;
	pO->n[1] = su*K*sv;
	pO->n[2] = K*sv;
#endif

#if(PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if(PARTICLE_UVD != 0)
	pO->uvd[0] = K*sv*su;
	pO->uvd[1] = -K*sv*cu;
	pO->uvd[2] = 0;
#endif
#if(PARTICLE_VVD != 0)
	pO->vvd[0] = -cv*cu;
	pO->vvd[1] = -cv*su;
	pO->vvd[2] = -sv;
#endif
}
#endif

