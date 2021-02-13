
//#include "torus_inc.h"
#include "torus_common.h"

#define GET__C		pasuli_vartype R = constants[0]; \
					pasuli_vartype r = constants[1]; \
					pasuli_vartype a = constants[2];

#define TORUS_POS	POS_OP( posxy = cv*r_a_sin_u + R ); \
					P_X( posxy*cu ); \
					P_Y( posxy*su ); \
					P_Z( sv*r_a_sin_u );

#define TORUS_UD	UD_OP( udxy = r*cv*cu ); \
					UD_X( udxy*cu -  (R + cv*r_a_sin_u)*su ); \
					UD_Y( udxy*su +  (R + cv*r_a_sin_u)*cu ); \
					UD_Z( r*sv*cu );

#define TORUS_VD	VD_OP( vdxy = -sv*r_a_sin_u ); \
					VD_X( vdxy*cu ); \
					VD_Y( vdxy*su ); \
					VD_Z( cv*r_a_sin_u );


#if(USE_ANTISYMMETRIC_TORUS != 0)

void AntisymmetricTorus(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {

	PASULI_SET_TYPE_ID( ANTISYMMETRIC_TORUS )
	GET__C

	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype sv = sin(v);
	pasuli_vartype cv = cos(v);

	pasuli_vartype r_a_sin_u = (a + su)*r;
	POS_OP(pasuli_vartype posxy);
	UD_OP( pasuli_vartype udxy );
	VD_OP( pasuli_vartype vdxy );

	TORUS_POS

	TORUS_UD

	TORUS_VD

	TORUS_NORMAL_VARS_DEF
	TORUS_NORMAL

	pasuli_vartype xy = (R + cv*r_a_sin_u);

	UUD_X( r*cv*2*cu*su + xy*cu + r*cv*cu*su );
	UUD_Y( -r*cv*su*su + r*cv*cu*cu + r*cv*cu*cu - xy*su );
	UUD_Z( -r*sv*su );

	UVD_OP( pasuli_vartype uvdxy );

	UVD_OP( uvdxy = -r*sin(v)*(a + sin(u)) );
	UVD_X( uvdxy*cu );
	UVD_Y( uvdxy*su );
	UVD_Z( r*cos(v)*(a + sin(u)) );

	VVD_OP( pasuli_vartype vvdxy );

	VVD_OP( vvdxy = -r*sin(v)*(a + sin(u)) );
	VVD_X( vvdxy*cu );
	VVD_Y( vvdxy*su );
	VVD_Z( r*cos(v)*(a + sin(u)) );
}

#endif

#if(COMPILE_DEF_DESC_TORUS != 0)

#include "torus_const.h"

PaSuLiDefDesc pslddAntisymmetricTorus = {
PSLDD_ID( ANTISYMMETRIC_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_END_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , torus_def_constants };
#endif

#if(COMPILE_DESC_TORUS != 0)
char* descAntisymmetricTorus =
"start; \
name: Antisymmetric Torus; \
cat: torus; \
ut: c; \
vt: c; \
us: 0; \
ue: pi: 2; \
vs: 0; \
ve: pi: 2; \
c1:R: 1.5; \
c2:r: 0.5; \
c3:a: 1; \
x: (R + r*cos(v)*(a + sin(u)))*cos(u); \
y: (R + r*cos(v)*(a + sin(u)))*sin(u); \
z: r*sin(v)*(a + sin(u)); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: r*cos(v)*cos(u)*cos(u) -  (R + r*cos(v)*(a + sin(u)))*sin(u); \
yu: r*cos(v)*cos(u)*sin(u) +  (R + r*cos(v)*(a + sin(u)))*cos(u); \
zu: r*sin(v)*cos(u); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*sin(v)*(a + sin(u))*cos(u); \
yv: -r*sin(v)*(a + sin(u))*sin(u); \
zv: r*cos(v)*(a + sin(u)); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
xn: r*(R*a*cos(v) + R*cos(v)*sin(u) + 3*a*r*cos(v)*cos(v)*sin(u) + \
a*r*sin(u)*sin(v)*sin(v) + 2*r*(cos(v)*sin(u))^2) + \
r*(sin(u)*sin(v))^2 + a*a*r*cos(v)*cos(v))*cos(u); \
yn:X; \
yn: R*a*r*cps(v)*sin(u) + R*r*cos(v) - R*r*cos(u)*cos(u)*cos(v) - \
a*r*r*cos(u)*cos(u)-2*a*(r*cos(u)*cos(v))^2 - \
2*a*(r*cos(v))^2 + sin(u)*((a*r*cos(v))^2 - (r*cos(u))^2) + r*r*cos(v)*cos(v)*sin(u)^3; \
zn:X; \
zn: R*a*r*sin(v) + R*r*sin(u)*sin(v) + 2*a*r*r*cos(v)*sin(u)*sin(v) - \
a*a*r*r*cos(v)*sin(v) + r*r*cos(v)*sin(v)*sin(u)*sin(u); "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: r*cos(v)*2*cos(u)*sin(u) + \
(R + r*cos(v)*(a + sin(u)))*cos(u) + (r*cos(v)*cos(u))*sin(u); \
yuu -r*cos(v)*sin(u)*sin(u) + r*cos(v)*cos(u)*cos(u) + \
(r*cos(v)*cos(u))*cos(u) - (R + r*cos(v)*(a + sin(u)))*sin(u); \
zuu: -r*sin(v)*sin(u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: -r*sin(v)*(a + sin(u))*cos(u); \
yuv: -r*sin(v)*(a + sin(u))*sin(u); \
zuv: r*cos(v)*(a + sin(u)); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -r*cos(v)*(a + sin(u))*cos(u); \
yvv: -r*cos(v)*(a + sin(u))*sin(u); \
zvv: -r*sin(v)*(a + sin(u)); "
#endif
"end;";
#endif