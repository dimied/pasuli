
#include "maeders_owl.h"
#include "../pasuli_macros.h"
#include <math.h>

#if(USE_MAEDERS_OWL != 0)
void MaedersOwl(pasuli_vartype u, pasuli_vartype v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( MAEDERS_OWL )

	double v2 = v*v;

	P_X( v*cos(u) - 0.5*v2*cos(2*u) );
	P_Y( -v*sin(u) - 0.5*v2*sin(2*u) );
	P_Z( (4*exp(3*log(v)*0.5)*cos(3*u*0.5)) / 3.0 );

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
PaSuLiDefDesc pslddMaedersOwl = {
PSLDD_ID( MAEDERS_OWL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 4 , 0.001f , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMaedersOwl =
"name: Maeders Owl; \
ut:c; vt:c; \
us: 0; ue:pi: 4; \
vs: 0.001; ve: 1; \
x: v*cos(u) - 0.5*v*v*cos(2*u); \
y: -v*sin(u) - 0.5*v*v*sin(2*u); \
z: 4*exp(1.5*log(v))*cos(3*u/2)/3; \
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
zvv: 0;";
#endif