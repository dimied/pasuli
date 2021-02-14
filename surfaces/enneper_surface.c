
#include "enneper_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_ENNEPER_SURFACE != 0)
void EnneperSurface(pasuli_vartype u, pasuli_vartype v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ENNEPER_SURFACE )

	double u_pow2 = u*u;
	double v_pow2 = v*v;

	P_X( u - (u_pow2*u/3) + u*v_pow2 );
	P_Y( v - (v_pow2*v/3) + v*u_pow2 );
	P_Z( u_pow2 - v_pow2 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

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

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurface = {
PSLDD_ID( ENNEPER_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface =
"name: Enneper Surface; \
ut: c; vt: c; \
us: -2; ue: 2; \
vs: -2; ve: 2; \
x: u - (u*u*u/3) + u*v*v; \
y: v - (v*v*v/3) + u*u*v; \
z: u*u - v*v; "
"xu: 1 - u*u + v*v; \
yu: 2*u*v; \
zu: 2*u; "
"xv: 2*u*v; \
yv: 1 + u*u - v*v; \
zv: -2*v; "
"xn: -2*u*(1+u*u+v*v); \
yn: 2*v*(1+u*u+v*v); \
zn: 1-((u*u + v*v)^2); "
"xuu: -2*u; \
yuu: 2*v; \
zuu: 2; "
"xuv: 2*v; \
yuv: 2*u; \
zuv: 0; "
"xvv: 2*u; \
yvv: -2*v; \
zvv: -2; ";
#endif