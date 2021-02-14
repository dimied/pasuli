
#include "sine_cone.h"
#include "surfaces_c_includes.h"

#if (USE_SINE_CONE != 0)

void SineCone(double u, double v, 
			  double* constants, 
			  PaSuLiObject* pO) {

	double K = constants[0];
	double N = constants[1];

	P_X( u*cos(v) );
	P_Y( K*u*cos(N*v) );
	P_Z( u*sin(v) );

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

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineCone = {
PSLDD_ID( 0 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
-10, 10 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descSineCone =
"name: Sine Cone; \
ut:c; vt:c; \
us: -10; ue: 10; \
vs:pi: -1; ve:pi: 1; \
c1:k: 1.5; c2:N: 0.5; \
x: u*cos(v); \
y: k*u*cos(N*v); \
z: u*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif