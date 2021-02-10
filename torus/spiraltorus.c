
#include "torus_inc.h"

#if(COMPILE_TORUS != 0)
void SpiralTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPIRAL_TORUS )

	pasuli_vartype R1 = constants[0];
	pasuli_vartype R2 = constants[1];
	pasuli_vartype r = constants[2];
	pasuli_vartype N = constants[3];

	P_Y( r*sin(v) + R2*sin(N*u) );
	v = R1 + R2*cos(N*u) + r*cos(v);

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
PaSuLiDefDesc pslddSpiralTorus = {
PSLDD_ID( SPIRAL_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descSpiralTorus =
"start; \
name: SpiralTorus; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1: 1.0; \
c:2:R2: 1.0; \
c:3:r: 1.0; \
a:1:F: R1 + R2*cos(N*u) + r*cos(v); \
x: F*cos(u); \
y: r*sin(v) + R2*sin(N*u); \
z: F*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -((R1 + R2*cos(n*u) + r*cos(v))*sin(u) + R2*n*cos(u)*sin(n*u)); \
yu: R2*n*cos(n*u); \
zu: (R1 + R2*cos(n*u) + r*cos(v))*cos(u) - R2*n*sin(u)*sin(n*u); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*cos(u)*sin(v); \
yv: r*cos(v); \
zv: -r*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
yn:X; \
zn:X; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -cos(u)*(R1 + R2*cos(n*u)*(n*n+1) + r*cos(v)) + 2*R2*n*sin(u)*sin(n*u); \
yuu: -R2*n*n*sin(n*u); \
zuu: -sin(u)*(R1 + R2*cos(n*u)*(n*n+1) + r*cos(v)) - 2*R2*n*cos(u)*sin(n*u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: r*sin(u)*sin(v); \
yuv: 0; \
zuv: -r*cos(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -r*cos(u)*cos(v); \
yvv: -r*sin(v); \
zvv: -r*cos(v)*sin(u); "
#endif
"end;";
#endif