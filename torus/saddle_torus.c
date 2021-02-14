
#include "saddle_torus.h"
#include "torus_c_includes.h"

#if(USE_SADDLE_TORUS != 0)
void SaddleTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SADDLE_TORUS )

	pasuli_vartype K = constants[0];

	P_X( K*(1+u)*cos(v) );
	P_Y( K*(1-u)*sin(v) );
	P_Z( u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X( -su );
	UD_Y( -cu );
	UD_Z( 0 );

	VD_X( -K*sv*cu );
	VD_Y( -K*sv*su );
	VD_Z( -K*cv );

#if(PARTICLE_N != 0)
	pO->n[0] = cu*K*cv;
	pO->n[1] = su*K*sv;
	pO->n[2] = K*sv;
#endif

#if(PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if(PARTICLE_UVD != 0)
	pO->uvd[0] = K*sv*su;
	pO->uvd[1] = -K*sv*cu;
	pO->uvd[2] = 0;
#endif
#if(PARTICLE_VVD != 0)
	pO->vvd[0] = -cv*cu;
	pO->vvd[1] = -cv*su;
	pO->vvd[2] = -sv;
#endif
}
#endif


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddSaddleTorus = {
PSLDD_ID( SADDLE_TORUS )	
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI,
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descSaddleTorus =
"name: Saddle Torus; \
cat: torus; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
a:1:F: 1-cos(x)*cos(x) - cos(x + 2 pi/3)*cos(x + 2 pi/3); \
x: (2 + cos(u))*cos(v); \
y: (2 + cos(u + 2*pi/3))*cos(v + 2*pi/3); \
z: (2 + sign(F(u))*sqrt(abs(F(u))))*sign(F(v))*sqrt(abs(F(v))); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif