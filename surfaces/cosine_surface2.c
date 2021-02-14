
#include "cosine_surface2.h"
#include "surfaces_c_includes.h"

#if (USE_COSINE_SURFACE2 != 0)

void CosineSurface2(pasuli_vartype u, pasuli_vartype v, 
					double* constants, PaSuLiObject* pO) {

	PASULI_SET_TYPE_ID( COSINE_SURFACE2 )
	double cvu = cos(v + u);
	double cu = cos(u);
	double cv = cos(v);

	P_X( cu );
	P_Y( cv );
	P_Z( -cvu*cvu );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
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
PaSuLiDefDesc pslddCosineSurface2 = {
PSLDD_ID( COSINE_SURFACE2)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineSurface2 =
"name: Cosine Surface 2; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
x: cos(u); \
y: cos(v); \
z: -cos(u + v)^(2); \
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