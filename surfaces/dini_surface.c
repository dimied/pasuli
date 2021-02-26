
#include "dini_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_DINI_SURFACE != 0)
void DiniSurface(pasuli_vartype u, pasuli_vartype v,
				 double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(DINI_SURFACE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(a * cos_u * sin_v);
	P_Y(a * sin_u * sin_v);
	P_Z(a * (cos_v + log(tan(v * 0.5))) + b * u);

	UD_X(-PASULI_COND_COPY_POS_Y(a * sin_u * sin_v));
	UD_Y(PASULI_COND_COPY_POS_X(a * cos_u * sin_v));
	UD_Z(b);

	VD_X(a * cos_u * cos_v);
	VD_Y(a * sin_u * cos_v);
	// 1/sin(v) - sin(v) = (1-sin(v)^2)/sin(v) = cos(v)^2/sin(v) = cos(v)*cot(v)
	VD_Z(a * cos_v * atan(v));

	// Ignore a
	
	pasuli_calctype normal_factor = (a < 0) ? -1 : 1;

	N_X(normal_factor * (a * cos_u - a * cos_u * sin_v * sin_v - b * cos_v * sin_u));
	N_Y(normal_factor * (a * sin_u - a * sin_u * sin_v * sin_v + b * cos_v * cos_u));
	N_Z(-normal_factor * a * cos_v * sin_v);
	
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDiniSurface = {
PSLDD_ID( DINI_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 4 , 0.01f , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descDiniSurface =
	"name: Dini Surface;\
ut:c; vt:c;\
us:0; ue:pi: 4;\
vs: 0.01: ve:pi:1;\
c1:a: 1.5; c2:b: 0.5;\
x: a*cos(u)*sin(v);\
y: a*sin(u)*sin(v);\
z: a*(cos(v) + ln(tan(v/2))) + b*u;\
xu: -a*sin(u)*sin(v);\
yu: a*cos(u)*sin(v);\
zu: b;\
xv: a*cos(u)*cos(v);\
yv: a*sin(u)*cos(v);\
zv: a*(1/sin(v) - sin(v));\
xn: a*a*cos(u) - a*a*cos(u)*sin(v)^2 - a*b*cos(v)*sin(u);\
yn: a*a*sin(u) - a*a*sin(u)*sin(v)^2 + a*b*cos(u)*cos(v);\
zn: -a^2*cos(v)*sin(v); ";
#endif