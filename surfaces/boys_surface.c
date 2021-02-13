
#include "boys_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_BOYS_SURFACE != 0)
void BoysSurface(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BOYS_SURFACE )

	double a = sqrt(2.0);
	double b = 2 - a*sin(3*u)*sin(2*v);
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
	double xz1, xz2;


	xz1 = a*cv*cv;
	xz2 = cu*sin(2*v)/b;
	P_X( xz1*cos(2*u) + xz2 );
	P_Y( 3*cv*cv/b );
	P_Z( xz1*sin(2*u) + xz2 );

	UD_X( -su );
	UD_Y( cu );
	UD_Z_CONST( 0 );

	VD_X_CONST( 0 );
	VD_Y( -sv );
	VD_Z( cv );

	N_X( cu*cv );
	N_Y( -su*cv );
	N_Z( su*cv );

	UUD_X( -cu );
	UUD_Y( -su );
	UUD_Z_CONST( 0 );

	UVD_X_CONST( 0 );
	UVD_Y_CONST( 0 );
	UVD_Z_CONST( 0 );

	VVD_X_CONST( 0 );
	VVD_Y( cv );
	VVD_Z( sv );
}
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBoysSurface = {
PSLDD_ID( BOYS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI| PASULI_CONST_COUNT(0),
-0.5, 0.5 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBoysSurface =
"start; \
name: Boys Surface; \
ut:c; \
vt:c; \
us:pi: -0.5; \
ue:pi: 0.5; \
vs:0; \
ve:pi: 1; \
a1:a: sqrt(2) ; \
a2:b: 2 - a*sin(3*u)*sin(2*v); \
x: a*cos(v)*cos(v)*cos(2*u) + cos(u)*sin(2*v)/b; \
y: 3*cos(v)*cos(v)/b; \
z: a*cos(v)*cos(v)*sin(2*u) + cos(u)*sin(2*v)/b; "
#if(COMPILE_DESC_DERIV_U_SURFACES != 0)
"xu: (3*a*cos(u)*cos(3*u)*sin(2*v)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2) - 2*a*cos(v)*cos(v)*sin(2*u) + \
(sin(u)*sin(2*v))/(a*sin(2*v)*sin(3*u)-2); \
yu: (9*a*cos(v)*cos(v)*cos(3*u)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2); \
zu: (3*a*cos(u)*cos(3*u)*sin(2*v)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2) + 2*a*cos(v)*cos(v)*cos(2*u) + \
(sin(u)*sin(2*v))/(a*sin(2*v)*sin(3*u)-2); "
#endif
#if(COMPILE_DESC_DERIV_V_SURFACES != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
"xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif