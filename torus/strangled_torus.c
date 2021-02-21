
#include "strangled_torus.h"
#include "torus_c_includes.h"

#if(USE_STRANGLED_TORUS != 0)
void StrangledTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( STRANGLED_TORUS )

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];
	pasuli_vartype N = constants[2];

	P_Y( cos(N*u*0.5)*cos(v) );
	v = R + r*sin(v);
	P_X( cos(u)*v );
	P_Z( sin(u)*v );

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


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddStrangledTorus = {
PSLDD_ID( STRANGLED_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descStrangledTorus =
"name: Strangled Torus;\
cat: torus;\
ut: c; vt: c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
c1:R: 1; c2:r: 1; c3:n: 1;\
x: (R + r*sin(v))*cos(u);\
y: r*cos(v)*cos(n*u/2);\
z: (R + r*sin(v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0;\
yu: 0;\
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0;\
yv: 0;\
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0;\
yn: 0;\
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0;\
yuu: 0;\
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0;\
yuv: 0;\
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0;\
yvv: 0;\
zvv: 0; "
#endif
"";
#endif
