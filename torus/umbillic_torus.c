
#include "umbillic_torus.h"
#include "torus_c_includes.h"

#if (USE_UMBILLIC_TORUS != 0)

void UmbillicTorus(pasuli_vartype u,
				   pasuli_vartype v,
				   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(UMBILLIC_TORUS)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	u = u / 3.0; //u = u/3.0

	pasuli_calctype u3_minus_2v = u - 2 * v;
	pasuli_calctype u3_plus_v = u + v;

	pasuli_calctype cos_u3_minus_2v = cos(u3_minus_2v);
	pasuli_calctype sin_u3_minus_2v = sin(u3_minus_2v);

	pasuli_calctype cos_u3_plus_v = cos(u3_plus_v);
	pasuli_calctype sin_u3_plus_v = sin(u3_plus_v);

	pasuli_calctype factor = 7.0 + cos_u3_minus_2v + 2 * cos_u3_plus_v;

	P_X(sin_u * factor);
	P_Y(cos_u * factor);
	P_Z(sin_u3_minus_2v + 2 * sin_u3_plus_v);

	pasuli_vartype ud_factor = (2 * sin_u3_plus_v + sin_u3_minus_2v) / 3.0;

	UD_X(cos_u * factor - sin_u * ud_factor);
	UD_Y(-sin_u * factor - cos_u * ud_factor);
	UD_Z((2 * cos_u3_plus_v + cos_u3_minus_2v) / 3.0);

	// Ignore scaling by 2
	factor = sin_u3_minus_2v - sin_u3_plus_v;
	VD_X(sin_u * factor);
	VD_Y(cos_u * factor);
	VD_Z(cos_u3_plus_v - cos_u3_minus_2v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddUmbillicTorus = {
PSLDD_ID( UMBILLIC_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI|\
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-1 , 1 , -1 , 1 , torus_def_constants };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descUmbillicTorus =
	"name: Umbillic torus;\
cat: torus;\
ut: c; vt: c;\
us:pi: -1; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
c1:R: 1.5; c2:r: 0.5;\
x: sin(u)*(7+cos(u/3-2*v)+2*cos(u/3+v));  \
y: cos(u)*(7+cos(u/3-2*v)+2*cos(u/3+v));\
z: sin(u/3-2*v)+2*sin(u/3+v);\
xu: cos(u)*(7+cos(u/3-2*v)+2*cos(u/3+v))-sin(u)*(2*sin(u/3+v)+sin(u/3-2*v))/3;\
yu: -sin(u)*(7+cos(u/3-2*v)+2*cos(u/3+v))-cos(u)*(2*sin(u/3+v)+sin(u/3-2*v))/3;\
zu: (2*cos(u/3+v)+cos(u/3-2*v))/3;\
xv: 2*sin(u)*(sin(u/3-2*v)-sin(u/3+v));\
yv: 2*cos(u)*((sin(u/3-2*v)-sin(u/3+v)));\
zv: 2*(cos(u/3+v)-cos(u/3-2*v));";
#endif