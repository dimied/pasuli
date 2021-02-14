
#include "lemniskate_cylinder.h"
#include "cylinder_c_includes.h"

#if (USE_LEMNISKATE_CYLINDER != 0)

void LemniskateCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LEMNISKATE_CYLINDER )

	pasuli_consttype r = constants[0];
	pasuli_consttype H = constants[1];

	pasuli_consttype su = sin(u);
	pasuli_consttype cu = cos(u);
	pasuli_consttype x_u = su*su + 1.0;

	P_X( r*cu/(x_u) );
	P_Y( H*v );
	P_Z( r*su*cu/(x_u) );

	pasuli_consttype x_u_q = x_u*x_u;
	pasuli_consttype cuq = cu*cu;
	pasuli_consttype suq = su*su;

	UD_X( -2*r*cuq*su/(x_u_q) - r*su/x_u);
	UD_Y_CONST( 0 );
	UD_Z( -2*r*cuq*suq/(x_u_q) + r*(cuq - suq)/x_u);

	VD_X_CONST( 0 );
	VD_Y_CONST( H );
	VD_Z_CONST( 0 );

	N_X( H*r*(3*suq - 1)/(x_u_q) );
	N_Y( 0 );
	N_Z( H*r*(-2 - cuq)*su/(x_u_q) );
}
#endif


#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct lc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddLemniskateCylinder = {
PSLDD_ID( LEMNISKATE_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2), 
-1, 1 , 0, 1 , 0};	//lc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descLemniskateCylinder = 
"name: Lemniskate-Cylinder; \
ut: c; \
vt: o; \
us:pi: -1; ue:pi: 1; \
vs: 0; ve: 1; \
c1:r: 1.0; c2:H: 1.0; \
x: r*cos(u)/(1 + sin(u)^2); \
y: H*v; \
z: r*sin(u)*cos(u)/(1 + sin(u)^2); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: r*(-2 - cos(u)*cos(u))/((1 + sin(u)^2)^2); \
yu: 0; \
zu: r*(1-3*sin(u)*sin(u))/((1 + sin(u)^2)^2); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xn: H*r*(3*sin(u)*sin(u) - 1)/((1 + sin(u)^2)^2); \
yn: 0; \
zn: H*r*(-2 - cos(u)*cos(u))*sin(u)/((1 + sin(u)^2)^2); "
#endif
"xuu: r*cos(u)*(sin(u)*sin(u)*(5+cos(u)*cos(u))-1-2*cos(u)^2 + 4*sin(u)^2)/((1+sin(u)^2)^3); \
yuu: 0; \
zuu: 2*r*(-5+3*sin(u)*sin(u))*cos(u)*sin(u)/((1+sin(u)^2)^3); "
"xuv: 0; \
yuv: 0; \
zuv 0; "
"xvv: 0; \
yvv: 0; \
zvv 0; "
"end;";
#endif