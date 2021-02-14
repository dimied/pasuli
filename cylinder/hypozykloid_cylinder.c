
#include "hypozykloid_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_HYPOZYKLOID_CYLINDER != 0)
void HypozykloidCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPOZYKLOID_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype h = constants[2];
	pasuli_consttype H = constants[3];
	R -= r;							//ATTENTION

	P_X( (R)*cos(u) + h*cos((R*u)/r) );
	P_Y( H*v );
	P_Z( (R)*sin(u) - h*sin((R*u)/r) );

	UD_X( h*(R)*sin((R)*u/r)/r -(R)*sin(u) );
	UD_Y_CONST( 0 );
	UD_Z( -h*(R)*cos((R)*u/r)/r + (R)*cos(u) );

	VD_X_CONST( 0 );
	VD_Y_CONST( H );
	VD_Z_CONST( 0 );

	N_X( H*(h*(R)*cos((R)*u/r)/r - (R)*cos(u)) );
	N_Y_CONST( 0 );
	N_Z( H*(h*(R)*sin((R)*u/r)/r -(R)*sin(u)) );
}
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
pasulidefdesc_ct hc_constants[] = {1.5, 1.0, 0.5, 1.0};
PaSuLiDefDesc pslddHypozykloidCylinder = {
PSLDD_ID(HYPOZYKLOID_CYLINDER)
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(4), 
-1, 1 , 0, 1 , hc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char* descHypozykloidCylinder = 
"name: Hypozykloid-Cylinder; \
ut: c; \
vt: o; \
us: pi : -1; \
ue: pi : 1; \
vs: 0; \
ve: 1; \
c1:R: 1.5; c2:r: 1.0; \
c3:h: 0.5; c4:H: 1.0; \
x: (R - r)*cos(u) + h*cos(((R - r)/r)*u); \
y: H*v; \
z: (R - r)*sin(u) - h*sin(((R - r)/r)*u); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: h*(R - r)*sin((R - r)*u/r)/r -(R - r)*sin(u); \
yu: 0; \
zu: -h*(R - r)*cos((R - r)*u/r)/r + (R - r)*cos(u); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: H*(h*(R - r)*cos((R - r)*u/r)/r - (R - r)*cos(u)); \
yn: 0; \
zn: H*(h*(R - r)*sin((R - r)*u/r)/r -(R - r)*sin(u)); "
#endif
"xuu: h*(2*R - r -R/r)*cos((R - r)*u/r)/r - (R-r)*cos(u) ; \
yuu: 0; \
zuu: h*(2*R - r -R/r)*sin((R - r)*u/r)/r - (R-r)*sin(u); "
"xuv: 0; \
yuv: 0; \
zuv 0; "
"xvv: 0; \
yvv: 0; \
zvv 0; "
"end;";
#endif