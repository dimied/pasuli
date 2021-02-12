
#include "torus_inc.h"


#if(USE_TWISTED_EIGHT_TORUS != 0)
void TwistedEightTorus(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TWISTED_EIGHT_TORUS )

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];

	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype sv = sin(v);
	u *= 0.5f;
	pasuli_vartype cos_u2 = cos(u);
	u = sin(u);

	pasuli_vartype sin_v = sin(v);
	v *= 2.0;
	v = sin(v);						//v stands for sin(2*v)

	P_Z( r*(u*sin_v + cos_u2*v) );

	v = (R + r*(cos_u2*sin_v - u*v));

	P_X( v*cu );
	P_Y( v*su );		//u stands for sin(u/2)


	P_X( cu );
	P_Y( su );
	P_Z( r*sv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cv = cos(v);
#endif

	UD_X( -su );
	UD_Y( -cu );
	UD_Z( 0 );

	VD_X( -r*sv*cu );
	VD_Y( -r*sv*su );
	VD_Z( -r*cv );

#if(PARTICLE_N != 0)
	pO->n[0] = cu*r*cv;
	pO->n[1] = su*r*sv;
	pO->n[2] = r*sv;
#endif

#if(PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if(PARTICLE_UVD != 0)
	pO->uvd[0] = r*sv*su;
	pO->uvd[1] = -r*sv*cu;
	pO->uvd[2] = 0;
#endif
#if(PARTICLE_VVD != 0)
	pO->vvd[0] = -r*cv*cu;
	pO->vvd[1] = -r*cv*su;
	pO->vvd[2] = -r*sv;
#endif
}
#endif