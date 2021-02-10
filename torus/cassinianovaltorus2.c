
#include "torus_inc.h"

#if(COMPILE_TORUS != 0)
void CassinianOvalTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CASSINIAN_OVAL_TORUS_2 )

	pasuli_vartype R = constants[0];
	pasuli_vartype a = constants[1];
	pasuli_vartype b = constants[2];
	a *= a;
	b *= b;
	b *= b;

	pasuli_vartype M = a*cos(2.0*v);
	M += sqrt(b + M*M - a*a);
	M = sqrt(M);

	P_Y( M*cos(v) );
	v = R + M*sin(v);

	P_X( v*cos(u) );
	P_Z( v*sin(u) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X( -su );
	UD_Y( -cu );
	UD_Z( 0 );

	VD_X( -sv*cu );
	VD_Y( -sv*su );
	VD_Z( -cv );

#if(PARTICLE_N != 0)
	pO->n[0] = cu*cv;
	pO->n[1] = su*sv;
	pO->n[2] = sv;
#endif

#if(PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if(PARTICLE_UVD != 0)
	pO->uvd[0] = sv*su;
	pO->uvd[1] = -sv*cu;
	pO->uvd[2] = 0;
#endif
#if(PARTICLE_VVD != 0)
	pO->vvd[0] = -cv*cu;
	pO->vvd[1] = -cv*su;
	pO->vvd[2] = -sv;
#endif
}
#endif


#include "torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCassinianOvalTorus2 = {
PSLDD_ID( CASSINIAN_OVAL_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descCassinianOvalTorus2 =
"start; \
name: Cassinian Oval Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.0; \
c:2:a: 1.0; \
c:3:b: 1.0; \
a:1:M: 2*a*a*cos(2*v) + 2*sqrt((-a^{4} + b^{4}) + a^{4}*cos(2*v)^{2}); \
x: (R + sqrt(M/2)*sin(v))*cos(u); \
y: sqrt(M/2)*cos(v); \
z: (R + sqrt(M/2)*sin(v))*sin(u); "
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
