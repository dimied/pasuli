
#include "torus_inc.h"

#if(COMPILE_TORUS != 0)
void BicornTorus1(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BICORN_TORUS_1 )

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];

	P_Y( r*sin(v) );
	v = cos(v);
	v = (R + r*v*v)*(2 + v)/(4.0 - v*v);

	P_X( cos(u)*v );
	P_Z( sin(u)*v );

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

