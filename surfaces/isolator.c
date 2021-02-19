
#include "isolator.h"
#include "surfaces_c_includes.h"

#if (USE_ISOLATOR != 0)
void Isolator(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ISOLATOR)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype sin_cu = sin(c * u);
	pasuli_calctype factor = a + b * sin_cu;
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(factor * sin_v);
	P_Y(factor * cos_v);
	P_Z(u);

	pasuli_calctype cos_cu = cos(c * u);
	UD_X(b * c * sin_v * cos_cu);
	UD_Y(b * c * cos_v * cos_cu);
	UD_Z_CONST(1);

	VD_X(PASULI_COND_COPY_POS_Y(factor * cos_v));
	VD_Y(-PASULI_COND_COPY_POS_X(factor * sin_v));
	VD_Z_CONST(0);

	// Ignore common factor
	factor = (factor < 0) ? -1 : (factor > 0 ? 1 : 0);
	N_X(factor * sin_v);
	N_Y(factor * cos_v);
	N_Z(-factor * b * c * cos_cu);

	// Ignore b*c*c*sin(c*u)
	factor = b * c * c * sin_cu;
	factor = (factor < 0) ? -1 : (factor > 0 ? 1 : 0);
	UUD_X(-factor * sin_v);
	UUD_Y(-factor * cos_v);
	UUD_Z_CONST(0);

	// Ignore b*c*cos(c*u)
	factor = b * c * cos_cu;
	factor = (factor < 0) ? -1 : (factor > 0 ? 1 : 0);
	UVD_X(factor * cos_v);
	UVD_Y(factor * sin_v);
	UVD_Z_CONST(0);

	//Ignore a+b*sin(c*u)
	factor = a + b * sin_cu;
	factor = (factor < 0) ? -1 : (factor > 0 ? 1 : 0);
	VVD_X(-factor * sin_v);
	VVD_Y(-factor * cos_v);
	VVD_Z_CONST(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddIsolator = {
PSLDD_ID( ISOLATOR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
1.5f, 9.5f , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descIsolator =
	"name: Isolator; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0; \
x: (a + b*sin(c*u))*sin(v); \
y: (a + b*sin(c*u))*cos(v); \
z: u; \
xu: b*c*sin(v)*cos(c*u); \
yu: b*c*cos(v)*cos(c*u); \
zu: 1; \
xv: (a+b*c*sin(c*u))*cos(v); \
yv: -(a+b*c*sin(c*u))*sin(v); \
zv: 0; \
xn: (a+b*sin(c*u))*sin(v); \
yn: (a+b*sin(c*u))*cos(v); \
zn: -b*c*cos(c*u)*(a + b*sin(c*u)); \
xuu: -b*c*c*sin(v)*sin(c*u); \
yuu: -b*c*c*cos(v)*sin(c*u); \
zuu: 0; \
xuv: b*c*cos(v)*cos(c*u); \
yuv: -b*c*sin(v)*cos(c*u); \
zuv: 0; \
xvv: -(a+b*sin(c*u))*sin(v); \
yvv: -(a+b*sin(c*u))*cos(v); \
zvv: 0; ";
#endif