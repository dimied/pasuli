
#include "torus_inc.h"

#if(COMPILE_TORUS != 0)
void HypozykloidTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPOZYKLOID_TORUS_2 )

	pasuli_vartype R1 = constants[0];
	pasuli_vartype R = constants[1];
	pasuli_vartype r = constants[2];
	pasuli_vartype h = constants[3];
	R += r;
	pasuli_vartype rrr_sin_v = R1 + (R)*sin(v);

	P_Y( (R)*cos(v) - h*cos(((R)*v)/r) );
	v = h*sin(((R)*v)/r);

	P_X( rrr_sin_v - cos(u)*v );
	P_Z( rrr_sin_v - sin(u)*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
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


