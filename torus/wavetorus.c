
#include "wavetorus.h"
#include <math.h>

#define GET__C		pasuli_vartype R = constants[0]; \
					pasuli_vartype r = constants[1]; \
					pasuli_vartype a = constants[2]; \
					pasuli_vartype N = constants[3];

#define TORUS_POS	P_X( posxy*cu ); \
					P_Y( posxy*su ); \
					P_Z( posxyz*sv );

#define TORUS_UD	UD_X( -su ); \
					UD_Y( -cu ); \
					UD_Z( 0 );

#define TORUS_VD	VD_X( -r*sv*cu ); \
					VD_Y( -r*sv*su ); \
					VD_Z( -r*cv );

#define TORUS_N		N_X( cu*r*cv ); \
					N_Y( su*r*sv ); \
					N_Z( r*sv );

#define TORUS_UUD	UUD_X( -su ); \
					UUD_Y( -cu ); \
					UUD_Z( 0 );

#define TORUS_UVD	UVD_X( -su ); \
					UVD_Y( -cu ); \
					UVD_Z( 0 );

#define TORUS_VVD	VVD_X( -r*sv*cu ); \
					VVD_Y( -r*sv*su ); \
					VVD_Z( -r*cv );


#if(COMPILE_TORUS != 0)
void WaveTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WAVE_TORUS )

	GET__C

#if((PARTICLE_POS != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif
	pasuli_vartype posxyz = r + a*sin(N*u);
	pasuli_vartype posxy = cv*posxyz + R;

	TORUS_POS
	TORUS_UD
	TORUS_VD
	TORUS_N
	TORUS_UUD
	TORUS_UVD
	TORUS_VVD
}
#endif

#undef GET__C
#undef TORUS_POS
#undef TORUS_UD
#undef TORUS_VD
#undef TORUS_N
#undef TORUS_UUD
#undef TORUS_UVD
#undef TORUS_VVD


#include "torus_desc_inc.h"
#include "torus_const.h"


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddWaveTorus = {
PSLDD_ID( WAVE_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , torus_def_constants };
#endif

#if(COMPILE_DESC_TORUS != 0)
char* descWaveTorus =
"start; \
name: wave torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi : 2; \
vstart: 0; \
vend: pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:a: 1.0; \
c:4:n: 1.0; \
x: (R + cos(v)*(r + a*sin(n*u)))*cos(u); \
y: (R + cos(v)*(r + a sin(n*u)))*sin(u); \
z: (r + a*sin(n*u))*sin(v); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -R*sin(u) + cos(v)*(a*(n*cos(n*u)**cos(u) - sin(u)*sin(n*u)) -  r*sin(u)); \
yu: -R*cos(u) + cos(v)*(a*(n*cos(n*u)*sin(u) - cos(u)*sin(n*u)) -  r*cos(u)); \
zu: a*n*cos(n*u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -(r + a*sin(n*u))*sin(v)*cos(u); \
yv: -(r + a*sin(n*u))*sin(v)*sin(u); \
zv: (r + a*sin(n*u))*cos(v); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
xn: ;\
yn:X; \
yn: ; \
zn:X; \
zn: "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -cos(u)*(R + a*cos(v)*sin(n*u) + a*n*n*cos(v)*sin(n*u) + r*cos(v)) - 2*a*n*cos(v)*cos(n*u)*sin(u); \
yuu: -sin(u)*(R + a*cos(v)*sin(n*u) + a*n*n*cos(v)*sin(n*u) + r*cos(v)) -  2*a*n*cos(v)*cos(n*u)*cos(u); \
zuu: -a*n*n*sin(v)*sin(n*u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: (-a*n*cos(u)*cos(n*u) + sin(u)*(a*sin(n*u) + r))*sin(v); \
yuv: -(a*n*sin(u)*cos(n*u) + cos(u)*(a*sin(n*u) + r))*sin(v); \
zuv: a*n*cos(v)*cos(n*u); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -(r + a*sin(n*u))*cos(v)*cos(u); \
yvv: -(r + a*sin(n*u))*cos(v)*sin(u); \
zvv: (r + a*sin(n*u))*sin(v); "
#endif
"end;";
#endif
