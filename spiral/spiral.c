
#include "../pasuli_const.h"
#include "../pasuli_macros.h"
#include "spiral.h"
#include <math.h>

#pragma warning(disable:4244)


#if(COMPILE_SPIRAL != 0)
void ArchimedicSpiral(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ARCHIMEDIC_SPIRAL )

	P_X( u*cos(u) );
	P_Y( v*(*constants) );
	P_Z( sin(u) );
}
#endif

#if(COMPILE_SPIRAL != 0)
void HyperbolicSpiral(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPERBOLIC_SPIRAL )
	double cu;
	double su;

	if(u > 0.001f) {
		cu = cos(u)/u;
		su = sin(u)/u;
	} else {
		cu = 0;
		su = 1;
	}

	P_X( cu );
	P_Y( v*(*constants) );
	P_Z( su );
}
#endif


#if(COMPILE_SPIRAL != 0)
void FermatSpiral(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FERMAT_SPIRAL )

	P_X( sqrt(u)*cos(u) );
	P_Y( v*(*constants) );
	P_Z( sqrt(u)*sin(u) );
}
#endif



#if(COMPILE_SPIRAL != 0)
void TanhSpiral(double u, double v, 
			   double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TANH_SPIRAL )

	double x_u;
	double z_u;
	double a = constants[0];
	double H = constants[1];

		if(u > 0) {
			u *= 2.0;
			z_u = cos(a*u) + cosh(u);
			x_u = sin(u)/z_u;
			z_u = sin(a*u)/z_u;

		} else {
			x_u = 0;
			z_u = 0;
		}

	P_X( x_u );
	P_Y( H*v );
	P_Z( z_u );
}
#endif



#if(COMPILE_SPIRAL != 0)
void LogSpiral(double u, double v, 
			   double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LOG_SPIRAL )

	double a = constants[0];
	double H = constants[1];
	double x_u = exp(a*u)*cos(u);
	double eau_su = exp(a*u)*sin(u);

	P_X( x_u );
	P_Y( H*v );
	P_Z( eau_su );
}
#endif


#if(COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddArchimedicSpiral = {
PSLDD_ID( ARCHIMEDIC_SPIRAL )
PASULI_U_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(1),
0,23, 0,1, 0 };
#endif
#if(COMPILE_DESC_SPIRAL != 0)
char *descArchimedicSpiral = 
"start; \
name: Archimedic Spiral; \
cat: spiral; \
utype: closed; \
vtype: open; \
ustart: 0; \
uend: 23; \
vstart: 0; \
vend: 1; \
c:1: H: 1.0; \
x: u*cos(u); \
y: H*v; \
z: u*sin(u); "
#if(COMPILE_DESC_DERIV_U_SPIRAL != 0)
"xu: cos(u) - u*sin(u); \
yu: 0; \
zu: sin(u) + u*cos(u); "
#endif
#if(COMPILE_DESC_DERIV_V_SPIRAL != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPIRAL != 0)
"xn: -H*(sin(u) + u*cos(u)); \
yn: 0; \
zn: H*(cos(u) - u*sin(u)); "
#endif
"xuu: -2*sin(u) - u*cos(u); \
yuu: 0; \
zuu: 2*cos(u) - u*sin(u); "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddHyperbolicSpiral = {
PSLDD_ID( HYPERBOLIC_SPIRAL )
PASULI_U_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(1),
0,23, 0,1, 0 };
#endif
#if(COMPILE_DESC_SPIRAL != 0)
char *descHyperbolicSpiral = 
"start; \
name: Hyperbolic Spiral; \
cat: spiral; \
utype: closed; \
vtype: open; \
ustart: 0; \
uend: 23; \
vstart: 0; \
vend: 1; \
c:1:H: 1.0; \
x: cos(u)/u; \
y: H*v; \
z: sin(u)/u; "
#if(COMPILE_DESC_DERIV_U_SPIRAL != 0)
"xu: -(cos(u) + u*sin(u))/(u*u); \
yu: 0; \
zu: (u*cos(u)-sin(u))/(u*u); "
#endif
#if(COMPILE_DESC_DERIV_V_SPIRAL != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPIRAL != 0)
"xn: H*(sin(u)-u*cos(u))/(u*u); \
yn: 0; \
zn: -H*(cos(u) + u*sin(u))/(u*u); "
#endif
"xuu: (2*cos(u)+2*u*sin(u) - u*u*cos(u))/(u*u*u); \
yuu: 0; \
zuu: (2*sin(u) - 2*u*cos(u) - u*u*sin(u))/(u*u*u); "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddFermatSpiral = {
PSLDD_ID( FERMAT_SPIRAL )
PASULI_U_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(1),
0,10, 0,1, 0 };
#endif
#if(COMPILE_DESC_SPIRAL != 0)
char *descFermatSpiral = 
"start; \
name: Fermat Spiral; \
cat: spiral; \
utype: closed; \
vtype: open; \
ustart: 0; \
uend: 10; \
vstart: 0; \
vend: 1; \
c:1:H: 1.0; \
x: sqrt(u)*cos(u); \
y: H*v; \
z: sqrt(u)*sin(u); "
#if(COMPILE_DESC_DERIV_U_SPIRAL != 0)
"xu: (0.5*cos(u) - u*sin(u))/sqrt(u); \
yu: 0; \
zu: (0.5*sin(u) + u*cos(u))/sqrt(u); "
#endif
#if(COMPILE_DESC_DERIV_V_SPIRAL != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPIRAL != 0)
"xn: -H*(0.5*sin(u)+u*cos(u))/sqrt(u); \
yn: 0; \
zn: H*(0.5*cos(u) - u*sin(u))/sqrt(u); "
#endif
"xuu: -(0.25*cos(u) + u*sin(u) + u*u*cos(u))/(u*sqrt(u)); \
yuu: 0; \
zuu: -(0.25*sin(u) - u*cos(u) + u*u*sin(u))/(u*sqrt(u)); "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddTanhSpiral = {
PSLDD_ID( TANH_SPIRAL )
PASULI_U_CLOSED|PASULI_FULL_IMPL| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1.5 , 1.5 , 0, 1, 0 };
#endif
#if(COMPILE_DESC_SPIRAL != 0)
char *descTanhSpiral = 
"start; \
name: Tanh Spiral; \
cat: spiral; \
utype: closed; \
vtype: open; \
ustart: -1.5; \
uend: 1.5; \
vstart: 0; \
vend: 1; \
c:1:a: 1.0; \
c:2:H: 1.0; \
x: sinh(2*u)/(cos(2*a*u) + cosh(2*u)); \
y: H*v; \
z: sin(2*u)/(cos(2*a*u) + cosh(2*u)); "
#if(COMPILE_DESC_DERIV_U_SPIRAL != 0)
"xu: 2*(a*sin(2*a*u)*sinh(2*u)+(cosh(2*u)^2)-(sinh(2*u)^2)+cos(2*a*u)*cosh(2*u))/((cos(2*a*u) + cosh(2*u))^2); \
yu: 0; \
zu: 2*(a*sin(2*a*u)*sin(2*u)+(cos(2*a*u)*cos(2*u))+cos(2*u)*cosh(2*u)-sin(2*u)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^2); "
#endif
#if(COMPILE_DESC_DERIV_V_SPIRAL != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPIRAL != 0)
"xn: -H*2*(a*sin(2*a*u)*sin(2*u)+(cos(2*a*u)*cos(2*u))+cos(2*u)*cosh(2*u)-sin(2*u)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^2); \
yn: 0; \
zn: 2*H*(a*sin(2*a*u)*sinh(2*u)+(cosh(2*u)^2)-(sinh(2*u)^2)+cos(2*a*u)*cosh(2*u))/((cos(2*a*u) + cosh(2*u))^2); "
#endif
"xuu: 4*(2*a*cos(2*a*u)cosh(2*u)*sin(2*a+u)+\
2*a*cosh(2*u)^2*sin(2*a*u)-4*a*sin(2*a*u)*sinh(2*u)^2 +\
2*sinh(2*u)^3-cos(2*a*u)*cosh(2*u)*sinh(2*u) + \
a*a*cos(2*a*u)*cosh(2*u)*sinh(2*u)+\
a*a*cos(2*a*u)^2*sinh(2*u)+2*a*a*(sin(2*a*u)^2)*sinh(2*u)+\
(cos(2*a*u)^2)*sinh(2*u)\
-2*(cosh(2*u)^2)*sinh(2*u))/((cos(2*a*u) + cosh(2*u))^3); \
yuu: 0; \
zuu: 4*(2*a*cos(2*a*u)*cos(2*u)*sin(2*a*u)+\
2*a*cos(2*u)*cosh(2*u)*sin(2*a*u)-\
4*a*sin(2*a*u)*sin(2*u)*sinh(2*u)-\
2*cos(2*a*u)*cos(2*u)*sinh(2*u)-\
3*cos(2*a*u)*cosh(2*u)*sin(2*u)-\
2*cos(2*u)*cosh(2*u)*sinh(2*u)+\
a*a*cos(2*a*u)*cosh(2*u)*sin(2*u)+\
a*a*(cos(2*a*u)^2)*sin(2*u)+\
2*a*a*(sin(2*a*u)^2)*sin(2*u)-\
(cos(2*a*u)^2)*sin(2*u)-\
2*(cosh(2*u)^2)*sin(2*u)+\
2*sin(2*u)*(sinh(2*u)^2))/((cos(2*a*u) + cosh(2*u))^3); "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddLogSpiral = {
PSLDD_ID( LOG_SPIRAL )
PASULI_U_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0,25 , 0,1, 0 };
#endif
#if(COMPILE_DESC_SPIRAL != 0)
char *descLogSpiral = 
"start; \
name: Log Spiral; \
cat: spiral; \
utype: closed; \
vtype: open; \
ustart: 0; \
uend: 25; \
vstart: 0; \
vend: 1; \
c:1: a: 1.0; \
c:2: H: 1.0; \
x: exp(a*u)*cos(u); \
y: H*v; \
z: exp(a*u)*sin(u); "
#if(COMPILE_DESC_DERIV_U_SPIRAL != 0)
"xu: exp(a*u)*(a*cos(u)-sin(u)); \
yu: 0; \
zu: exp(a*u)*(a*sin(u)+cos(u)); "
#endif
#if(COMPILE_DESC_DERIV_V_SPIRAL != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPIRAL != 0)
"xn: -H*exp(a*u)*(a*sin(u)+cos(u)); \
yn: 0; \
zn: H*exp(a*u)*(a*cos(u)-sin(u)); "
#endif
"xuu: exp(a*u)*(-2*a*sin(u)-cos(u)+a*a*cos(u)); \
yuu: 0; \
zuu: exp(a*u)*(2*a*cos(u)-sin(u)+a*a*sin(u)); "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif
