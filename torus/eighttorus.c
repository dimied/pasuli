

#include "torus_inc.h"


#if(COMPILE_TORUS != 0)
void EightTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( EIGHT_TORUS )

	pasuli_vartype cos_u;
	pasuli_vartype sin_u;				//-->u=sin(u)/2;
	pasuli_vartype sin_v;				//-->v=sin(2*v)
	pasuli_vartype c = constants[0];

	cos_u = cos(u);
	sin_u = sin(u);

	sin_v = sin(v);
	v = sin(2.0*v);
	
	P_Y( sin_u*sin_v + cos_u*0.5*v );
	v = (c + sin_v*cos_u - v*sin_u*0.5);

	P_X( cos_u*v );
	P_Z( sin_u*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X( -su );
	UD_Y( -cu );
	UD_Z( 0 );

	VD_X( -c*sv*cu );
	VD_Y( -c*sv*su );
	VD_Z( -c*cv );

#if(PARTICLE_N != 0)
	pO->n[0] = cu*c*cv;
	pO->n[1] = su*c*sv;
	pO->n[2] = c*sv;
#endif

#if(PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if(PARTICLE_UVD != 0)
	pO->uvd[0] = c*sv*su;
	pO->uvd[1] = -c*sv*cu;
	pO->uvd[2] = 0;
#endif
#if(PARTICLE_VVD != 0)
	pO->vvd[0] = -c*cv*cu;
	pO->vvd[1] = -c*cv*su;
	pO->vvd[2] = -c*sv;
#endif
}
#endif


