
#include "torus_inc.h"

#if(COMPILE_TORUS != 0)
void TorusKnot(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TORUS_KNOT )

	pasuli_vartype R1 = constants[0];
	pasuli_vartype R2 = constants[1];
	pasuli_vartype r = constants[2];
	pasuli_vartype p = constants[3];
	pasuli_vartype q = constants[4];

	P_Y( r*sin(v) + R2*sin(p*u) );
	v = R1 + R2*cos(p*u) + r*sin(v);

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

	VD_X( -r*sv*cu );
	VD_Y( -r*sv*su );
	VD_Z( -r*cv );

#if(PARTICLE_N != 0)
	pO->n[0] = cu*r*cv;
	pO->n[1] = su*r*sv;
	pO->n[2] = r*sv;
#endif

#if(PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if(PARTICLE_UVD != 0)
	pO->uvd[0] = r*sv*su;
	pO->uvd[1] = -r*sv*cu;
	pO->uvd[2] = 0;
#endif
#if(PARTICLE_VVD != 0)
	pO->vvd[0] = -r*cv*cu;
	pO->vvd[1] = -r*cv*su;
	pO->vvd[2] = -r*sv;
#endif
}
#endif


#include "torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTorusKnot = {
PSLDD_ID( TORUS_KNOT )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(5),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descTorusKnot =
"name: Torus Knot; \
cat: torus; \
us: 0; \
ue:pi:2; \
vs: 0; \
ve: pi:2; \
c1:R1: 1.0; \
c2:R2: 1.0; \
c3:r: 1.0; \
c4:p: 1.0; \
c5:q: 1.0; \
a:1:F: (R1 + R2*cos(p*u) + r*cos(v)); \
x: F*cos(q*u); \
y: r*sin(v) + R2*sin(p*u); \
z: F*sin(q*u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -( q*sin(q*u)*(R1 +R2*cos(p*u) + r*cos(v)) + R2*p*cos(q*u)*sin(p*u) ); \
yu: R2*p*cos(p*u); \
zu: q*cos(q*u)*(R1 +R2*cos(p*u) + r*cos(v)) - R2*p*sin(q*u)*sin(p*u); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*cos(q*u)*sin(v); \
yv: r*cos(v); \
zv: -r*sin(v)*sin(q*u); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
yn:X; \
zn:X; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -cos(q*u)*(q*q*(R1 + R2*cos(p*u) + r*cos(v)) - p*p*R2*cos(p*u) ) + \
2*R2*p*q*sin(q*u)*sin(p*u) ; \
yuu: -R2*p*p*sin(p*u); \
zuu: -sin(q*u)*(q*q*(R1 + R2*cos(p*u) + r*cos(v)) + p*p*R2*cos(p*u)) - \
2*R2*p*q*cos(q*u)*sin(p*u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: q*r*sin(v)*sin(q*u); \
yuv: 0; \
zuv: -q*r*sin(v)*cos(q*u); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -r*cos(v)*cos(q*u); \
yvv: -r*sin(v); \
zvv: -r*cos(v)*sin(q*u); "
#endif
"end;";
#endif
