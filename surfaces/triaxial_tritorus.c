
#include "triaxial_tritorus.h"
#include "surfaces_c_includes.h"

#if (USE_TRIAXIAL_TRITORUS != 0)
void TriaxialTritorus(pasuli_vartype u, pasuli_vartype v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIAXIAL_TRITORUS )

	double two_pi_3 = (2.0*MY_PI)/3.0;
	double four_pi_3 = (4.0*MY_PI)/3.0;

	P_X( sin(u)*(1 + cos(v)) );
	P_Y( sin(u + two_pi_3)*(1 + cos(v + two_pi_3)) );
	P_Z( sin(u + four_pi_3)*(1 + cos(v + four_pi_3)) );

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
PaSuLiDefDesc pslddTriaxialTritorus = {
PSLDD_ID( TRIAXIAL_TRITORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTritorus =
"name: Triaxial Tritorus; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
x: sin(u)*(1 + cos(v)); \
y: sin(u + 2*pi/3)*(1 + cos(v + 2*pi/3)); \
z: sin(u + 4*pi/3)*(1 + cos(v + 4*pi/3)); \
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