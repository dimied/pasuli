
#include "triple_cork_screw3.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_CORK_SCREW3 != 0)

void TripleCorkScrew3(pasuli_vartype u, pasuli_vartype v, 
						double* constants, 
						PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIPLE_CORK_SCREW3 )

	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];
	N *= MY_PI;

	double Lu = L*u;
	double z_u = R*cos(u*0.5*MY_PI);
	double y_u = cos(u*N)*z_u;
	z_u *= sin(N*u);
	u = (1 - fabs((double)u))*r;

	P_X( Lu );
	P_Y( u*cos(v) + y_u );
	P_Z( u*sin(v) + z_u );

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
PaSuLiDefDesc pslddTripleCorkScrew3 = {
PSLDD_ID( TRIPLE_CORK_SCREW3 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew3 =
"name: Triple Cork Screw 3; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs:pi: -1; ve:pi: 1; \
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; c4:N: 1.0; \
a1:a: r*(1 - |u|); \
a2:b: R*cos(u*pi/2); \
x: L*u; \
y: a*cos(v) + b*cos(u*N*pi); \
z: a*sin(v) + b*sin(u*N*pi); \
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