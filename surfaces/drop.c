
#include "drop.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_DROP != 0)
void Drop(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DROP )

	double a = constants[0];
	double b = constants[1];

	double cu = cos(u);
	double su = sin(u);
	double ab_cos_u_sin_u = a*(b - cu)*su;
	double cv = cos(v);
	double sv = sin(v);

	P_X( ab_cos_u_sin_u*cv );
	P_Y( ab_cos_u_sin_u*sv );
	P_Z( cu );

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
PaSuLiDefDesc pslddDrop = {
PSLDD_ID( DROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if(COMPILE_DESC_SURFACES != 0)
char *descDrop =
"name: Drop; \
ut:c; vt:c; \
us: 0; ue:pi: 1; \
vs: 0; ve:pi: 2; \
c1:a: 1.5; \
c2:b: 0.5; \
x: a*(b - cos(u))*sin(u)*cos(v); \
y: a*(b - cos(u))*sin(u)*sin(v); \
z: cos(u); "
"xu: a*cos(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u)); \
yu: a*sin(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u)); \
zu: -sin(u); "
"xv: sin(u)*sin(v)*a*(cos(u)-b); \
yv: sin(u)*cos(v)*a*(b - cos(u)); \
zv: 0; "
"xn: a*(b - cos(u))*cos(v)*sin(u)*sin(u); \
yn: a*(b - cos(u))*sin(u)*sin(u)*sin(v); \
zn: sin(u)*a*a*(b-cos(u)*(1 - b*b + 3*b*cos(u)-2*cos(u)*cos(u))); "
"xuu: sin(u)*a*cos(v)*(4*cos(u)-b); \
yuu: sin(u)*a*sin(v)*(4*cos(u)-b); \
zuu: -cos(u); "
"xuv: sin(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u)); \
yuv: -cos(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u)); \
zuv: 0; "
"xvv: sin(u)*a*cos(v)*(cos(u)-b); \
yvv: sin(u)*a*sin(v)*(cos(u)-b); \
zvv: 0; "
"end;";
#endif