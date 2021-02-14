
#include "dupin_cyclide.h"
#include "surfaces_c_includes.h"

#if (USE_DUPIN_CYCLIDE != 0)

void DupinCyclide(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DUPIN_CYCLIDE )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double d = constants[3];

	double b_sin_u = b*sin(u);
		u = cos(u);
	double b2_cos_u = b*b*u;
	double c_cos_u = c*u;
		u *= a;

	double bsin_v = b*sin(v);
	v = cos(v);
	double h = a - c_cos_u*v;

	P_X( (d*(c - u*v) + b2_cos_u)/h );
	P_Y( (b_sin_u*(a - d*v))/h );
	P_Z( (bsin_v*(c_cos_u - d))/h );


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
PaSuLiDefDesc pslddDupinCyclide = {
PSLDD_ID( DUPIN_CYCLIDE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descDupinCyclide =
"name: Dupin Cyclide; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; c4:d: 1.0; \
a:1:h: a - c*cos(u)*cos(v); \
x: (d*(c - a*cos(u)*cos(v)) + b*b*cos(u))/h; \
y: (b*sin(u)*(a - d*cos(v)))/h; \
z: b*sin(v)*(c*cos(u) - d)/h; \
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