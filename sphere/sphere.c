
#include "../pasuli_const.h"
#include "sphere.h"
#include <math.h>

#if(PASULI_COMPILER	== PASULI_COMPILER_MSVC)
#pragma warning(disable:4005)	//WE KNOW THAT WE REDEFINE FOLLOWING DEFs
#endif
/*
#define PASULIOBJECT_POS		COMPILE_POS_SPHERE
#define PASULIOBJECT_UD			COMPILE_DERIV_U_SPHERE
#define PASULIOBJECT_VD			COMPILE_DERIV_V_SPHERE
#define PASULIOBJECT_N			COMPILE_NORMAL_SPHERE
#define PASULIOBJECT_UUD		COMPILE_DERIV2_U_SPHERE
#define PASULIOBJECT_VVD		COMPILE_DERIV2_V_SPHERE
#define PASULIOBJECT_UVD		COMPILE_DERIV_UV_SPHERE
*/

#include "../pasuli_macros.h"

#if(PASULI_COMPILER	== PASULI_COMPILER_MSVC)
#pragma warning(disable:4244)
#endif


#if(COMPILE_SPHERE != 0)
void Sphere(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPHERE )

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( cu*sv );
	P_Y( su*sv );
	P_Z( cv );

	UD_X( -PASULI_COND_COPY_POS_Y( su*sv ) );
	UD_Y( PASULI_COND_COPY_POS_X( cu*sv ) );
	UD_Z_CONST( 0 );

	VD_X( cu*cv );
	VD_Y( su*cv );
	VD_Z( -sv );

	N_X( -sv*sv*cu );
	N_Y( -sv*sv*su );
	N_Z( -sv*cv );

	UUD_X( -cu*sv );
	UUD_Y( -su*sv );
	UUD_Z_CONST( 0 );

	UVD_X( -su*cv );
	UVD_Y( cu*cv );
	UVD_Z_CONST( 0 );

	VVD_X( -PASULI_COND_COPY_POS_X( cu*sv ) );
	VVD_Y( -PASULI_COND_COPY_POS_Y( su*sv ) );
	VVD_Z( -cv );
}
#endif



#if(COMPILE_SPHERE != 0)
void Ellipsoid(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ELLIPSOID )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( a*cu*sv );
	P_Y( b*su*sv );
	P_Z( c*cv );

	UD_X( -a*su*sv );
	UD_Y( b*cu*sv );
	UD_Z_CONST( 0 );

	VD_X( a*cu*cv );
	VD_Y( b*su*cv );
	VD_Z( -c*sv );

	N_X( -b*c*sv*sv*cu );
	N_Y( -a*c*sv*sv*su );
	N_Z( -a*b*sv*cv);

	UUD_X( -PASULI_COND_COPY_POS_X(a*cu*sv) );
	UUD_Y( -PASULI_COND_COPY_POS_Y(b*su*sv) );
	UUD_Z_CONST( 0 );

	UVD_X( -a*su*cv );
	UVD_Y( b*cu*cv );
	UVD_Z_CONST( 0 );

	VVD_X( -a*cu*sv );
	VVD_Y( -b*su*sv );
	VVD_Z( -c*cv );
}
#endif



#if(COMPILE_SPHERE != 0)
void SphereV(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPHERE_V )

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( cu*cv );
	P_Y( sv );
	P_Z( su*cv );

	UD_X( -PASULI_COND_COPY_POS_Z(su*cv) );
	UD_Y_CONST( 0 );
	UD_Z( PASULI_COND_COPY_POS_X(cu*cv) );

	VD_X( -cu*sv );
	VD_Y( cv );
	VD_Z( -su*sv );

	N_X( -cu*cv*cv );
	N_Y( -sv*cv );
	N_Z( -su*cv*cv );

	UUD_X( -PASULI_COND_COPY_POS_X(cu*cv) );
	UUD_Y_CONST( 0 );
	UUD_Z( -PASULI_COND_COPY_POS_Z(su*cv) );

	UVD_X( su*sv );
	UVD_Y_CONST( 0 );
	UVD_Z( -cu*sv );

	VVD_X( -PASULI_COND_COPY_POS_X(cu*cv) );
	VVD_Y( -sv );
	VVD_Z( -PASULI_COND_COPY_POS_Z(su*cv) );
}
#endif



#if(COMPILE_SPHERE != 0)
void OpenSphere(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( OPEN_SPHERE )

	double uq = u*u;
	double vq = v*v;
	double divisor = 1 + uq + vq;

	P_X( (2.0*u)/divisor );
	P_Y( (uq + vq - 1)/divisor );
	P_Z( (2.0*v)/divisor );

	double divq = divisor*divisor;

	UD_X(2*(1 - uq + vq)/(divq*divisor) );
	UD_Y( (4*u)/divq );
	UD_Z( -4*u*v/ divq );

	VD_X( PASULI_COND_COPY_UD_Z( -4*u*v/ divq ) );
	VD_Y( 4*v/divq );
	VD_Z(2*(1 - vq*vq + uq*(2 + uq))/(divq*divisor) );

	double div3 = divq*divisor;
	N_X( 8*u/(div3) );
	N_Y( 4*(vq + uq - 1)/(div3) );
	N_Z( 8*v/(div3) );

	UUD_X( 4*u*(uq - 3*(1 + vq))/(div3) );
	UUD_Y( 4*(1 - 3*uq + vq)/div3 );
	UUD_Z( 4*v*(-1 + 3*uq - vq)/div3 );

	UVD_X( 4*v*(-1 + 3*uq - vq)/div3 );
	UVD_Y( -16*u*v/div3 );
	UVD_Z( 4*u*(3*vq - uq - 1)/div3 );

	VVD_X( 4*u*(3*vq - uq - 1)/div3 );
	VVD_Y( 4*(1 + uq - 3*vq)/div3 );
	VVD_Z( 4*v*(vq - 3*(1 + uq))/div3 );
}
#endif




#if(COMPILE_SPHERE != 0)
void SphereUV(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPHERE_UV )

	double uq = u*u;
	double vq = v*v;
	double uqp1 = u*u + 1.0;
	double u2 = u*2.0;
	double vqp1 = v*v + 1.0;

	P_X( (u2*(1.0 - vq))/(uqp1*vqp1) );
	P_Y( (1.0 - uq)/(uqp1) );
	P_Z( (2.0*v)/(uqp1*vqp1) );

	double uqp1q = uqp1*uqp1;
	double divisor = vqp1*uqp1q;

	UD_X( 2*(1+ uq*(1 - vq - uq*(1 + vq - uq*(1 - vq))) - vq )/(divisor*uqp1q) );
	UD_Y( 4*u*(-1 - uq*(3 - uq*(3 - uq)))/(uqp1*uqp1q*uqp1q) );
	UD_Z( 4*v*(1 - vq)/(uqp1q*vqp1) );

	double vqp1q = vqp1*vqp1;

	VD_X( -8*u*v*(1 + vq*(3 + vq*(3 + vq)) )/(uqp1*vqp1q*vqp1q*vqp1) );
	VD_Y_CONST( 0 );
	VD_Z( 4*u*(1 - vq)/(uqp1*vqp1q) );

	divisor = uqp1q*vqp1q*uqp1;
	N_X( 16*uq*(vq - 1)/divisor );
	N_Y( 8*u*(-1 + uq - vq + uq*vq)/divisor );
	N_Z( 32*uq*v/divisor );

	divisor = uqp1q*uqp1*vqp1;

	UUD_X( 4*u*(3*(vq - 1) + uq*(1 - vq))/divisor );
	UUD_Y( 4*(-1 + uq*(-1 +uq*(5 + uq*(20 + uq*(25 + uq*(14 + 3*uq))))))/(uqp1q*uqp1q*uqp1q*uqp1q) );
	UUD_Z( 8*u*v*(uq - 3)/divisor );

	divisor = vqp1q*uqp1q;
	UVD_X( 8*v*(uq - 1)/divisor );
	UVD_Y_CONST( 0 );
	UVD_Z( 4*(1 - vq - uq + uq*vq)/divisor );

	divisor = uqp1*vqp1q*vqp1;
	VVD_X( 8*u*(-1 + vq*(-5 + vq*(-4 + vq*(28 + vq*(98 + vq*(154 + vq*(140 + vq*(76 + vq*(23 + vq*3)))))))))/(divisor*vqp1q*vqp1q*vqp1q*vqp1q) );
	VVD_Y_CONST( 0 );
	VVD_Z( 8*u*v*(vq - 3)/divisor );
}
#endif



#if(COMPILE_SPHERE != 0)
void TwistedSphere(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TWISTED_SPHERE )

	double a = constants[0];
	double b = constants[1];
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( a*cu*cv );
	P_Y( a*sv + b*u );
	P_Z( a*su*cv );

	UD_X( -a*su*cv );
	UD_Y( b );
	UD_Z( a*cu*cv );

	VD_X( -a*cu*sv );
	VD_Y( a*cv );
	VD_Z( -a*su*sv );


	N_X( -b*a*su*sv - a*a*cv*cv*cu );
	N_Y( a*a*sv*cv );
	N_Z( b*a*cu*sv - a*su*cv*cv );

	UUD_X( -a*cu*cv );
	UUD_Y_CONST( 0 );
	UUD_Z( -a*cv*su );

	UVD_X( a*su*sv );
	UVD_Y_CONST( 0 );
	UVD_Z( -a*cu*sv );

	VVD_X( -a*cu*cv );
	VVD_Y( -a*sv );
	VVD_Z( -a*su*cv );
}
#endif



#if(COMPILE_SPHERE != 0)
void WaveSphere(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WAVE_SPHERE )

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
	double ccu = cos(cu);
	double scu = sin(cu);
	double u_scu = u*scu;
	double u_ccu = u*ccu;

	P_X( u_ccu*cv );
	P_Y( u_ccu*sv );
	P_Z( u_scu );

	double xy = (ccu + u_scu*su);
	UD_X( cv*xy );
	UD_Y( sv*xy );
	UD_Z( scu - u_ccu*su );

	VD_X( -u_ccu*sv );
	VD_Y( u_ccu*cv );
	VD_Z_CONST( 0 );

	xy = u*(-scu + u_ccu*su)*ccu;
	N_X( cv*xy );
	N_Y( sv*xy );
	N_Z( u_ccu*(ccu + u*scu*su) );

	xy = u_scu*cu + u*ccu*su*su + 2*scu*su;
	UUD_X( cv*xy );
	UUD_Y( sv*xy );
	UUD_Z( u_ccu*cu + u_scu*su*su + 2*ccu*su );

	xy = (ccu + u_scu*su);
	UVD_X( -sv*xy );
	UVD_Y( cv*xy );
	UVD_Z_CONST( 0 );

	VVD_X( -u_ccu*cv );
	VVD_Y( u_ccu*sv );
	VVD_Z_CONST( 0 );
}
#endif



#if(COMPILE_SPHERE != 0)
void PseudoSphere(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PSEUDOSPHERE )

	double cu = cos(u);
	double su = sin(u);
	double sv = sin(v);
	double cv = cos(v);

	P_X( cu*sv );
	P_Y( su*sv );
	P_Z( cv + log(tan(v*0.5)) );

	UD_X( -su*sv );
	UD_Y( cu*sv );
	UD_Z_CONST( 0 );

	double xyz = -sv + 0.5/(cos(0.5*v)*cos(0.5*v)*tan(v*0.5));
	VD_X( cu*cv );
	VD_Y( su*cv );
	VD_Z( xyz );

	N_X( xyz*cu*sv);
	N_Y( xyz*su*sv);
	N_Z( -sv*cv );

	UUD_X( -PASULI_COND_COPY_POS_X( cu*sv ) );
	UUD_Y( -PASULI_COND_COPY_POS_Y( su*sv ) );
	UUD_Z_CONST( 0 );

	UVD_X( -cv*su );	//same as -VD_Y
	UVD_Y( cu*cv );		//same as VD_X
	UVD_Z_CONST( 0 );

	xyz = 0.5/(cos(0.5*v)*cos(0.5*v)*tan(v*0.5));
	VVD_X( -PASULI_COND_COPY_POS_X( cu*sv ) );
	VVD_Y( -PASULI_COND_COPY_POS_Y( su*sv ) );
	VVD_Z( -cv - xyz*xyz + xyz*tan(0.5*v) );
}
#endif

///////////////////////////////////////////////


pasulidefdesc_ct sphere_def_constants[] = {1.5, 1.0, 1.0};

#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphere = {
PSLDD_ID( SPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(0),
0, 2, 0, 1, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descSphere = 
"start; \
name: sphere; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 1; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -sin(u)*sin(v); \
yu: cos(u)*sin(v); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -cos(u)*sin(v)*sin(v); \
yn: -sin(u)*sin(v)*sin(v); \
zn: -sin(v)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu:  0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -sin(u)*cos(v); \
yuv: cos(u)*cos(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv:  -cos(v); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddEllipsoid = {
PSLDD_ID( ELLIPSOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
0, 2, 0, 1, sphere_def_constants };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descEllipsoid = 
"start; \
name: ellipsoid; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: pi : 2; \
vs: 0; \
ve: pi : 1; \
c1:a: 1.5; \
c2:b: 1.0; \
c3:c: 1.0; \
x: a*cos(u)*sin(v); \
y: b*sin(u)*sin(v); \
z: c*cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -a*sin(u)*sin(v); \
yu: b*cos(u)*sin(v); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: a*cos(u)*cos(v); \
yv: b*sin(u)*cos(v); \
zv: -c*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -b*c*sin(v)*sin(v)*cos(u); \
yn: -a*c*sin(v)*sin(v)*sin(u); \
zn: -a*b*sin(v)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -a*cos(u)*sin(v); \
yuu: -b*sin(u)*sin(v); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -a*sin(u)*cos(v); \
yuv: b*cos(u)*cos(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xvv: -a*cos(u)*sin(v); \
yvv: -b*sin(u)*sin(v); \
zvv: -c*cos(v); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereV = {
PSLDD_ID( SPHERE_V)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(0),
0, 1, -1, 1, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descSphereV =
"start; \
name: sphere v; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: pi : 1; \
vs: pi : -1; \
ve: pi : 1; \
x: cos(u)*cos(v); \
y: sin(v); \
z: sin(u)*cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -sin(u)*cos(v); \
yu: 0; \
zu: cos(u)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -cos(u)*sin(v); \
yv: cos(v); \
zv: -sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -cos(u)*cos(v)*cos(v); \
yn: -sin(v)*cos(v); \
zn: -sin(u)*cos(v)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -cos(u)*cos(v); \
yuu: 0; \
zuu: -sin(u)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: sin(u)*sin(v); \
yuv: 0; \
zuv: -cos(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -cos(u)*cos(v); \
yvv: -sin(v); \
zvv: -cos(v)*sin(u); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddOpenSphere = {
PSLDD_ID( OPEN_SPHERE )
PASULI_FULL_IMPL|PASULI_U_CLOSED|PASULI_V_CLOSED,
-10, 10, -10, 10, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descOpenSphere = 
"start; \
name: open sphere; \
cat: sphere; \
ut: o; \
vt: o; \
us: -10; \
ue: 10; \
vs: -10; \
ve: 10; \
x: 2*u/(1 + u*u + v*v); \
y: (u*u + v*v - 1)/(1 + u*u + v*v); \
z: 2*v/(1 + u*u + v*v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: 2*(1 - u*u + v*v)/((1 + u*u + v*v)^2); \
yu: 4*u/((1 + u*u + v*v)^2); \
zu: -4*u*v/((1 + u*u + v*v)^2); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -4*u*v/((1 + u*u + v*v)^2); \
yv: 4*v/((1 + u*u + v*v)^2); \
zv: 2*(1+u*u - v*v)/((1 + u*u + v*v)^2); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: 8*u/((1 + u*u + v*v)^3); \
yn: 4*(-1 + u*u + v*v)/((1 + u*u + v*v)^3); \
zn: 8*v/((1 + u*u + v*v)^3); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: 4*u*(u*u - 3*(1+v*v))/((1 + u*u + v*v)^3); \
yuu: 4*(1+v*v-3*u*u)/((1 + u*u + v*v)^3); \
zuu: 4*v*(3*u*u - (1+v*v))/((1 + u*u + v*v)^3); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: 4*v*(3*u*u - (1+v*v))/((1 + u*u + v*v)^3); \
yuv: -(16*u*v)/((1 + u*u + v*v)^3); \
zuv: 4*u*(3*v*v - (1+u*u))/((1 + u*u + v*v)^3); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xvv: 4*u*(3*v*v - (1+u*u))/((1 + u*u + v*v)^3); \
yvv: 4*(1+u*u-3*v*v)/((1 + u*u + v*v)^3); \
zvv: 4*v*(v*v - 3*(1+u*u))/((1 + u*u + v*v)^3); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereUV = {
PSLDD_ID( SPHERE_UV )
PASULI_FULL_IMPL|PASULI_U_CLOSED|PASULI_V_CLOSED,
0, 10, -10, 10, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descSphereUV = 
"start; \
name: sphere uv; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: 10; \
vs: -10; \
ve: 10; \
x: 2*u*(1 - v*v)/((1 + u*u)*(1 + v*v)); \
y: (1 - u*u)/(1 + u*u); \
z: (4*u*v)/((1 + u*u)*(1 + v*v)); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: 2*(2*u*u*v*v - 2*u*u + (1 + u*u)*(1-v*v))/((1 + u*u)^2)*(1 + v*v)); \
yu: -4*u/(1+u*u)^2; \
zu: 4*v*(1 - u*u)/((1 + u*u)^2)*(1 + v*v)); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -8*u*v/((1 + u*u))*((1 + v*v))^2); \
yv: 0; \
zv: 4*u*(1-v*v)/((1 + u*u))*((1 + v*v))^2); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: 16*u*u(v*v - 1)/((1 + u*u)^3)*((1 + v*v))^2); \
yn: 8*u*(u*u*(1+v*v)-(1+v*v))/((1 + u*u)^3)*((1 + v*v))^2); \
zn: -32*u*u*v/((1 + u*u)^3)*((1 + v*v))^2); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: 4*u*(u*u*(1-v*v) + 3*(v*v-1))/((1 + u*u)^3)*(1 + v*v)); \
yuu: 4*(-1 + u*u*(-2 + u*u*(5 * u*u*(20 + u*u*(50 + u*u*(14 + 3*u*u))))))/((1 + u*u)^8); \
zuu: 8*u*v*(u*u - 3)/((1 + u*u)^3)*(1 + v*v)); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: 8*v*(u*u - 1)/((1 + u*u)^2)*(1 + v*v)^2); \
yuv: 0; \
zuv: 4*(u*u*(v*v-1) - (v*v-1))/((1 + u*u)^2)*(1 + v*v)^2); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xvv: 8*u*(-1 + v*v*(-5 + v*v*(-4 + v*v*(28 + v*v*(98 + v*v*(154 + v*v*(140 + v*v*(76 + v*v*(23 + 3*v*v)))))))))/((1 + u*u))*(1 + v*v)^11); \
yvv: 0; \
zvv: 8*u*v*(v*v-3)/((1 + u*u))*(1 + v*v)^3); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddTwistedSphere = {
PSLDD_ID( TWISTED_SPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0, 2, -1, 1, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descTwistedSphere =
"start; \
name: twisted sphere; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: pi : 2; \
vs: pi : -1; \
ve: pi : 1; \
c1:a: 1.0; \
c2:b: 1.0; \
x: a*cos(u)*cos(v); \
y: a*sin(v) + b*u; \
z: a*sin(u)*cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -a*sin(u)*cos(v); \
yu: b; \
zu: a*cos(u)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -a*cos(u)*sin(v); \
yv: a*cos(v); \
zv: -a*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -a*(a*cos(u)*cos(v)*cos(v) + b*sin(u)*sin(v)); \
yn: -a*a*(cos(v)*sin(v)); \
zn: a*(b*cos(u)*sin(v) - a*cos(v)*cos(v)*sin(u)); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -a*cos(u)*cos(v); \
yuu: 0; \
zuu: -a*cos(v)*sin(u); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: a*sin(u)*sin(v); \
yuv: 0; \
zuv: -a*cos(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -a*cos(u)*cos(v); \
yvv: -a*sin(v); \
zvv: -a*cos(v)*sin(u); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddWaveSphere = {
PSLDD_ID( WAVE_SPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI| \
PASULI_FULL_IMPL,
0, 14, 0, 2, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descWaveSphere = 
"start; \
name: wave sphere; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: 14; \
vs: 0; \
ve: pi : 2; \
x: u*cos(cos(u))*cos(v); \
y: u*cos(cos(u))*sin(v); \
z: u*sin(cos(u)); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
yu: sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
zu: sin(cos(u)) - u*cos(cos(u))*sin(u); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -u*cos(cos(u))*sin(v); \
yv: u*cos(v)*cos(cos(u)); \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: u*cos(cos(u))(u*cos(cos(u)*sin(u)-sin(cos(u))))*cos(v); \
yn: u*cos(cos(u))(u*cos(cos(u)*sin(u)-sin(cos(u))))*sin(v); \
zn: u*(cos(cos(u))^2 + u*cos(cos(u))*sin(u)*sin(cos(u))); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: cos(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u))); \
yuu: sin(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u))); \
zuu: -(cos(cos(u))*(2*sin(u) + u*cos(u)) + u*sin(cos(u))*sin(u)*sin(u)); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
yuv: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -u*cos(cos(u))*cos(v); \
yvv: -u*sin(v)*cos(cos(u)); \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddPseudoSphere = {
PSLDD_ID( PSEUDOSPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL,
-1, 1, 0.1f, 3.1f, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descPseudoSphere = 
"start; \
name: pseudo sphere; \
cat: sphere; \
ut: c; \
vt: c; \
us: pi : -1; \
ue: pi : 1; \
vs: 0.1; \
ve: 3.10; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v) + log(tan(v/2)); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -sin(v)*sin(u) ; \
yu: sin(v)*cos(u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*cos(u)*sin(v); \
yn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*sin(u)*sin(v); \
zn: -cos(v)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -cos(v)*sin(u); \
yuv: cos(u)*cos(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv: -cos(v) - (1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))^2 + 1/(2*cos(0.5*v)*cos(0.5*v)); "
#endif
"end;";
#endif