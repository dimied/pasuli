
#include "torus_inc.h"

#define GET__C		pasuli_vartype R = constants[0]; \
					pasuli_vartype r = constants[1];

#define TORUS_POS	P_X( rr_cos_v*cu ); \
					P_Y( rr_cos_v*su ); \
					P_Z( r*sv );

#define	TORUS_UD	UD_X( -rr_cos_v*su ); \
					UD_Y( -rr_cos_v*cu ); \
					UD_Z_CONST( 0 );

#define	TORUS_VD	VD_X( -r*sv*cu ); \
					VD_Y( -r*sv*su ); \
					VD_Z( -r*cv );

#define TORUS_N		N_X( rr_cos_v*cu*r*cv ); \
					N_Y( -rr_cos_v*su*r*sv ); \
					N_Z( rr_cos_v*r*sv );

#define	TORUS_UUD	UUD_X( -rr_cos_v*cos(u) ); \
					UUD_Y( -rr_cos_v*sin(u) ); \
					UUD_Z( 0 );

#define	TORUS_UVD	UVD_X( r*sv*su ); \
					UVD_Y( -r*sv*cu ); \
					UVD_Z( 0 );

#define	TORUS_VVD	VVD_X( -r*cv*cu ); \
					VVD_Y( -r*cv*su ); \
					VVD_Z( -r*sv );



#if(USE_PASULI_TORUS_TORUS != 0)
void Torus(pasuli_vartype u, pasuli_vartype v, 
		pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TORUS )

	GET__C
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype rr_cos_v = R + r*cv;

	TORUS_POS
	TORUS_UD
	TORUS_VD
	TORUS_N
	TORUS_UUD
	TORUS_UVD
	TORUS_VVD
}
#endif


#if(USE_PASULI_TORUS_TORUS_UA != 0)
void Torus_UA(pasuli_vartype* pU, pasuli_vartype v, int c,
		pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TORUS )

	pasuli_vartype u;
	GET__C

	pasuli_vartype cu;
	pasuli_vartype su;
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype rr_cos_v = R + r*cv;

	while(c > 0){
		u = *pU;
		cu = cos(u);
		su = sin(u);

		TORUS_POS
		TORUS_UD
		TORUS_VD
		TORUS_N
		TORUS_UUD
		TORUS_UVD
		TORUS_VVD
		--c;
	}
}
#endif



#if(USE_PASULI_TORUS_TORUS_VA != 0)
void Torus_VA(pasuli_vartype u, pasuli_vartype* pV, int c,
		pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TORUS )
	
	pasuli_vartype v;
	GET__C

	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv;
	pasuli_vartype sv;
	pasuli_vartype rr_cos_v;

	while(c>0) {

		v = *pV;
		cv = cos(v);
		sv = sin(v);
		rr_cos_v = R + r*cv;

		TORUS_POS
		TORUS_UD
		TORUS_VD
		TORUS_N
		TORUS_UUD
		TORUS_UVD
		TORUS_VVD
		--c;
	}
}
#endif



#if(COMPILE_TORUS != 0)
void Torus_UVA(pasuli_vartype* pUV, int c,
		pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TORUS )

	pasuli_vartype u,v;

	GET__C

	pasuli_vartype cu, su;
	pasuli_vartype cv, sv;
	pasuli_vartype rr_cos_v;

	while(c>0) {
		u = *pUV;
		++pUV;
		v = *pUV;
		++pUV;

		cu = cos(u);
		su = sin(u);
		cv = cos(v);
		sv = sin(v);
		rr_cos_v = R + r*cv;

		TORUS_POS
		TORUS_UD
		TORUS_VD
		TORUS_N
		TORUS_UUD
		TORUS_UVD
		TORUS_VVD
		--c;
	}
}
#endif

#include "torus_undef.h"

#include "torus_const.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTorus = {
PSLDD_ID( TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_END_PI|PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descTorus =
"start; \
name: Torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0  \
uend: pi: 2; \
vstart: 0; \
vend: pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
x: (R + r*cos(v))*cos(u) ; \
y: (R + r*cos(v))*sin(u) ; \
z: r*sin(v) ; "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -(R + r*cos(v))*sin(u) ; \
yu: (R + r*cos(v))*cos(u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*sin(v)*cos(u); \
yv: -r*sin(v)*sin(u); \
zv: r*cos(v); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: r*(R + r*cos(v))*cos(u)*cos(v); \
yn: r*(R + r*cos(v))*sin(u)*cos(v); \
zn: (R + r*cos(v))*r*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -(R + r*cos(v))*cos(u); \
yuu: -(R + r*cos(v))*sin(u); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: r*sin(v)*sin(u); \
yuv: -r*sin(v)*cos(u); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -r*cos(v)*cos(u); \
yvv: -r*cos(v)*sin(u); \
zvv: -r*sin(v); "
#endif
"end;";
#endif