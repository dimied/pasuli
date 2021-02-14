
#include "horn.h"
#include "surfaces_c_includes.h"

#if (USE_HORN != 0)
void Horn(pasuli_vartype u, pasuli_vartype v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HORN )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	b *= MY_PI;

	double au_cos_v = a + u*cos(v);

	P_X( au_cos_v*sin(b*u) );
	P_Y( au_cos_v*cos(b*u) + c*u );
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
PaSuLiDefDesc pslddHorn = {
PSLDD_ID( HORN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(3),
0, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descHorn =
"name: Horn; \
ut:c; vt:c; \
us: 0; ue: 1; \
vs:pi: -1; ve:pi: 1; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
x: (a + u*cos(v))*sin(b*pi*u); \
y: (a + u*cos(v))*cos(b*pi*u) + c*u; \
z: u*sin(v); "
"xu: b*pi*cos(b*pi*u)(a+u*cos(v)) + cos(v)*sin(b*pi*u); \
yu: c - b*pi*sin(b*pi*u)*(a+u*cos(v)) + cos(v)*cos(b*pi*u); \
zu: sin(v); "
"xv: -u*sin(v)*sin(b*pi*u); \
yv: -u*sin(v)*cos(b*pi*u); \
zv: u*cos(v); "
"xn: u*(b*pi*sin(b*pi*u)*cos(v)*(-a - u*cos(v)) +c*cos(v)+cos(b*pi*u)); \
yn: -u*(b*pi*cos(v)*cos(b*pi*u)*(a+u*cos(v)) + sin(b*pi*u)); \
zn: u*sin(v)*(-b*pi*(a+u*cos(v)) + c*sin(b*pi*u) ); "
"xuu: b*pi*(-b*pi*sin(b*pi*u)*(a + u*cos(v))) + 2*cos(v)*cos(b*pi*u); \
yuu: b*pi*(-b*pi*cos(b*pi*u)*(a + u*cos(v))) - 2*cos(v)*sin(b*pi*u); \
zuu: 0; "
"xuv: -sin(v)*(b*pi*u*cos(b*pi*u) + sin(b*pi*u)); \
yuv: sin(v)*(b*pi*u*sin(b*pi*u) - cos(b*pi*u)); \
zuv: cos(v); "
"xvv: -u*cos(v)*sin(b*pi*u); \
yvv: -u*cos(v)*cos(b*pi*u); \
zvv: -u*sin(v); "
"end;";
#endif