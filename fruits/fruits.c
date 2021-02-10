

#include "../pasuli_macros.h"
#include "../pasuli_const.h"
#include "fruits.h"

#include <math.h>

#pragma warning(disable:4244)


#if(COMPILE_FRUITS != 0)

void KidneySurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KIDNEY_SURFACE )

	pasuli_vartype cv = cos(v);
	pasuli_vartype c3v = cos(3*v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype s3v = sin(3*v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	
	pasuli_vartype xy = (3*cv - c3v);

	P_X( cu*xy );
	P_Y( su*xy );
	P_Z( 3*sv - s3v );

	xy = (3*cv - c3v);
	UD_X( -su*xy );
	UD_Y( cu*xy );
	UD_Z_CONST( 0 );

	xy = (3*s3v - 3*sv);
	VD_X( cu*xy );
	VD_Y( su*xy );
	VD_Z( 3*cv - 3*c3v );

	xy = (3*cv - c3v)*(3*cv - 3*c3v);
	N_X( cu*xy );
	N_Y( -su*xy );
	N_Z( -(3*s3v - 3*sv)*(3*cv - c3v) );

	xy = (3*cv - c3v);
	UUD_X( -cu*xy );
	UUD_Y( -su*xy );
	UUD_Z( 0 );

	xy = (3*s3v - 3*sv);
	UVD_X( -su*xy );
	UVD_Y( cu*xy );
	UVD_Z( 0 );

	xy = (9*c3v -3*cv);
	VVD_X( cu*xy );
	VVD_Y( su*xy );
	VVD_Z( 9*s3v - 3*sv );
}
#endif


#if(COMPILE_FRUITS != 0)
void AppleSurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( APPLE_SURFACE )

	pasuli_vartype sin_v = sin(v);
	pasuli_vartype x_or_y_mul = 4 + 3.8*cos(v);

	P_X( cos(u)*x_or_y_mul );
	P_Y( sin(u)*x_or_y_mul );
	P_Z( (cos(v) + sin_v - 1)*(1 + sin_v)*log(1 - MY_PI*v/10.0) + 7.5*sin_v );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_FRUITS != 0)
void Apple2_Surface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( APPLE2_SURFACE )

	pasuli_vartype R1 = constants[0];
	pasuli_vartype xy = R1 + constants[1]*cos(v);
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv2 = 2.0*cos(v);
	pasuli_vartype sv2 = 2.0*sin(v);
	pasuli_vartype c5u = cos(5.0*u);

	P_X( cu*xy + pow(v/MY_PI, 20) );
	P_Y( su*xy + c5u*0.25 );
	P_Z( -2.3*log(1 - v*0.3157) + 3*sv2 + cv2 );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif





#if(COMPILE_FRUITS != 0)
void LemonSurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LEMON_SURFACE )

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
	pasuli_vartype xy = sqrt(R*R - u*u) - r;

	P_X( xy*sv );
	P_Y( xy*cv );
	P_Z( u );

	UD_X( -sv/xy );
	UD_Y( -cv/xy );
	UD_Z_CONST( 1 );


	xy = sqrt(R*R - u*u) - r;
	VD_X( xy*cv );
	VD_Y( -(xy*sv) );
	VD_Z_CONST( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif

pasulidefdesc_ct def_fruits_constants[] = {1.5, 0.5};

#if(COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddKidneySurface = {
PSLDD_ID( KIDNEY_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
0 , 2 , -0.5f , 0.5 , 0};
#endif
#if(COMPILE_DESC_FRUITS != 0)
char *descKidneySurface = 
"start; \
name: Kidney Surface; \
cat: fruits; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi : 2; \
vstart: pi : -0.5; \
vend: pi : 0.5; \
x: cos(u)*(3*cos(v) - cos(3*v)); \
y: sin(u)*(3*cos(v) - cos(3*v)); \
z: 3*sin(v) - sin(3*v); "
#if(COMPILE_DESC_DERIV_U_FRUITS != 0)
"xu: -sin(u)*(3*cos(v) - cos(3*v)); \
yu: cos(u)*(3*cos(v) - cos(3*v)); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_FRUITS != 0)
"xv: 3*cos(u)*(sin(3*v) - sin(v)); \
yv: 3*sin(u)*(sin(3*v) - sin(v)); \
zv: 3*cos(v) - 3*cos(3*v); "
#endif
#if(COMPILE_DESC_NORMAL_FRUITS != 0)
"xn: 3*cos(u)*(3*cos(v) - cos(3*v))*(cos(v) - cos(3*v)); \
yn: -3*sin(u)*(3*cos(v) - cos(3*v))*(cos(v) - cos(3*v)); \
zn: -(3*sin(3*v) - 3*sin(v))*(3*cos(v) - cos(3*v)); "
#endif
#if(COMPILE_DESC_DERIV2_U_FRUITS != 0)
"xuu: -cos(u)*(3*cos(v) - cos(3*v)); \
yuu: -sin(u)*(3*cos(v) - cos(3*v)); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_FRUITS != 0)
"xuv: -3*sin(u)*(sin(3*v) - sin(v)); \
yuv: 3*cos(u)*(sin(3*v) - sin(v)); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_FRUITS != 0)
"xvv: 3*cos(u)*(3*cos(3*v) -cos(v)); \
yvv: 3*sin(u)*(3*cos(3*v) -3*cos(v)); \
zvv: 3*(3*sin(3*v) - sin(v)); "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddAppleSurface = {
PSLDD_ID( APPLE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
0, 2 , -1 , 1 , 0};
#endif
#if(COMPILE_DESC_FRUITS != 0)
char *descAppleSurface = 
"start; \
name: Apple Surface; \
utype: closed; \
vtype: closed; \
cat: fruits; \
ustart: 0; \
uend: pi : 2 ; \
vstart:pi: -1; \
vend: pi : 1; \
x: cos(u)*(4 + 3.8*cos(v)); \
y: sin(u)*(4 + 3.8*cos(v)); \
z: (cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+7.5*sin(v); "
#if(COMPILE_DESC_DERIV_U_FRUITS != 0)
"xu: -sin(u)*(4 + 3.8*cos(v)); \
yu: cos(u)*(4 + 3.8*cos(v)); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_FRUITS != 0)
"xv: -3.8*cos(u)*sin(v); \
yv: -3.8*sin(u)*sin(v); \
zv: 7.5*cos(v) - log(1 - (pi*v)/10)*(1+sin(v)*(1-2*cos(v)) - 2*cos(v)*cos(v)) + pi*cos(v)*(1+sin(v)+cos(v))/(pi*v - 10); "
#endif
#if(COMPILE_DESC_NORMAL_FRUITS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_FRUITS != 0)
"xuu: -cos(u)*(4 + 3.8*cos(v)); \
yuu: -sin(u)*(4 + 3.8*cos(v)); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_FRUITS != 0)
"xuv: 3.8*sin(u)*sin(v); \
yuv: -3.8*cos(u)*sin(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_FRUITS != 0)
"xvv: -3.8*cos(u)*cos(v); \
yvv: -3.8*cos(v)*sin(u); \
zvv: log(1-v*pi)*(-2-cos(v)-4*cos(v)*sin(v)+4*cos(v)*cos(v)) + \
pi*(1-2*cos(v)*(sin(v)-cos(v)) +sin(v))/((5-0.5*v*pi) \
- pi*pi*cos(v)(1+sin(v)+cos(v))/((100 - 10*pi*v)^2) - 7.5*sin(v)); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddApple2_Surface = {
PSLDD_ID( APPLE2_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1, -1, 1 , def_fruits_constants};
#endif
#if(COMPILE_DESC_FRUITS != 0)
char *descApple2_Surface = 
"start; \
name: Apple Surface (V2); \
utype: closed; \
vtype: closed; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: pi : -1; \
vend: pi : 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
x: cos(u)*(R + r*cos(v)) + (v/pi)^(20); \
y: sin(u)*(R + r*cos(v)) + 0.25*cos(5*u); \
z: -2.3*log(1 - v*0.3157) + 6*sin(v) + 2*cos(v); "
#if(COMPILE_DESC_DERIV_U_FRUITS != 0)
"xu: -sin(u)*(R + r*cos(v)); \
yu: cos(u)*(R + r*cos(v)) - 1.25*sin(5*u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_FRUITS != 0)
"xv: 20*(v^19)/(pi^20) - r*cos(u)*sin(v); \
yv: -r*sin(u)*sin(v); \
zv: 6*cos(v)-2*sin(v) + (0.72611)/(1-0.3157*v); "
#endif
#if(COMPILE_DESC_NORMAL_FRUITS != 0)
"xn: cos(u)*(R*(6*cos(v)-2*sin(v)+(1/(1.3772 - 0.434783*v)) \
-2*r*cos(v)*sin(v))+6*r*cos(v)*cos(v) + \
(r*cos(v))/(1.3772-0.434783*v)) + \
sin(5*u)*(-7.5*cos(v) + 1/(0.347826*v-1.10176) + 2.5*sin(v)); \
yn: sin(u)*(cos(v)*(6*(R+r*cos(v)) + (0.72611*r)/(1-0.3157*v)) + (0.72611*R)/(1-0.3157*v) - 2*R*sin(v)); \
zn: sin(v)*(R*r-1.25r*cos(u)*sin(5*u) + r*r*cos(v)) + (v^19)*(-20*cos(u)*(cos(u)+cos(v)) + 25*sin(5*u))/(pi^20); "
#endif
#if(COMPILE_DESC_DERIV2_U_FRUITS != 0)
"xuu: -cos(u)*(R + cos(v)); \
yuu: -sin(u)*(R+r*cos(v)) - 6.25*cos(5*u); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_FRUITS != 0)
"xuv: r*sin(u)*sin(v); \
yuv: -r*cos(u)*sin(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_FRUITS != 0)
"xvv: -r*cos(u)*cos(v) + 380*(v^18)/(pi^20); \
yvv: -r*cos(v)*sin(u); \
zvv: (0.229233)/((1-0.3157v)^2) - 6*sin(v) - 2*cos(v); "
#endif
"end;";
#endif



#if(COMPILE_DEF_DESC_FRUITS != 0)
PaSuLiDefDesc pslddLemonSurface = {
PSLDD_ID( LEMON_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CALC_U_START|PASULI_CALC_U_END| \
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0,0, 0 , 2 , def_fruits_constants};
#endif
#if(COMPILE_DESC_FRUITS != 0)
//f means formula
char *descLemonSurface = 
"start; \
name: Lemon Surface; \
cat: fruits; \
utype: closed; \
vtype: closed; \
ustart: f : -sqrt(R*R-r*r); \
uend: f : sqrt(R*R-r*r); \
vstart: 0; \
vend: pi : 2; \
c:1:R: 2; \
c:2:r: 1; \
x: (sqrt(R^2 - u^2) - r)*sin(v); \
y: (sqrt(R^2 - u^2) - r)*cos(v); \
z: u; "
#if(COMPILE_DESC_DERIV_U_FRUITS != 0)
"xu: -u*sin(u)/(sqrt(R*R-u*u)); \
yu: -u_cos(v)/(sqrt(R*R-u*u)); \
zu: 1; "
#endif
#if(COMPILE_DESC_DERIV_V_FRUITS != 0)
"xv: cos(v)*(sqrt(R*R-u*u)-r); \
yv: -sin(v)*(sqrt(R*R-u*u)-r); \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_FRUITS != 0)
"xn: sin(v)*(sqrt(R*R-u*u)-r); \
yn: cos(v)*(sqrt(R*R-u*u)-r); \
zn: u-(r*u)/(sqrt(R*R-u*u)); "
#endif
#if(COMPILE_DESC_DERIV2_U_FRUITS != 0)
"xuu: -R*R*sin(v)/(sqrt(R*R-u*u)); \
yuu: -R*R*cos(v)/(sqrt(R*R-u*u)); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_FRUITS != 0)
"xuv: -u*cos(v)/(sqrt(R*R-u*u)); \
yuv: u*sin(v)/(sqrt(R*R-u*u)); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_FRUITS != 0)
"xvv: sin(v)*(sqrt(R*R-u*u) - r); \
yvv: cos(v)*(sqrt(R*R-u*u) - r); \
zvv: 0; "
#endif
"end;";
#endif

