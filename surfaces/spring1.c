
#include "spring1.h"
#include "surfaces_c_includes.h"

#if (USE_SPRING1 != 0)
void Spring1(pasuli_vartype u, pasuli_vartype v, 
			  double* constants, 
			  PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPRING1 )

	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	u = (L*u)/MY_PI;
	double Rrcv = v = R + r*cv;

	P_X( Rrcv*cu );
	P_Y( Rrcv*su );
	P_Z( r*sin(v + u) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
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
PaSuLiDefDesc pslddSpring1 = {
PSLDD_ID( SPRING1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4)|PASULI_CALC_U_END,//MUL_BY_CONST(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring1 =
"name: Spring 1; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; c4:N: 1.0; \
x: (R + r*cos(v))*cos(u); \
y: (R + r*cos(v))*sin(u); \
z: r*(sin(v) + L*u/pi); \
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
";
#endif
