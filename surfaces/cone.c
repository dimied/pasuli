
#include "cone.h"
#include "surfaces_c_includes.h"

#if (USE_CONE != 0)
void Cone(pasuli_vartype u, pasuli_vartype v,
		  pasuli_consttype *constants,
		  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CONE)

	pasuli_consttype a = constants[0];
	pasuli_calctype au = a * u;
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(au * cos_v);
	P_Y(au * sin_v);
	P_Z(u);

	UD_X(a * cos_v);
	UD_Y(a * sin_v);
	UD_Z_CONST(1);

	if (a < 0)
	{
		VD_X(u * sin_v);
		VD_Y(-u * cos_v);
		VD_Z_CONST(0);

		N_X(u * cos_v);
		N_Y(u * sin_v);
		N_Z(-a * u);

		UVD_X(sin_v);
		UVD_Y(-cos_v);
		UVD_Z_CONST(0);

		VVD_X(u * cos_v);
		VVD_Y(u * sin_v);
	}
	else
	{
		VD_X(-u * sin_v);
		VD_Y(u * cos_v);
		VD_Z_CONST(0);
		// Ignore a
		N_X(-u * cos_v);
		N_Y(-u * sin_v);
		N_Z(a * u);

		UVD_X(-sin_v);
		UVD_Y(cos_v);
		UVD_Z_CONST(0);

		VVD_X(-u * cos_v);
		VVD_Y(-u * sin_v);
		VVD_Z_CONST(0);
	}

	UUD_ALL(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCone = {
PSLDD_ID( CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
1, 3 , 0 , 2 , psldd_10_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descCone =
	"name: Cone;\
ut:c; vt:c;\
us: 1; ue: 3;\
vs:0; ve:pi:2;\
c1:a: 1;\
x: a*u*cos(v);\
y: a*u*sin(v);\
z: u;\
xu: a*cos(v);\
yu: a*sin(v);\
zu: 1;\
xv: -a*u*sin(v);\
yv: a*u*cos(v);\
zv: 0;\
xn: -a*u*cos(v);\
yn: -a*u*sin(v);\
zn: a*a*u;\
xuu: 0;\
yuu: 0;\
zuu: 0;\
xuv: -a*sin(v);\
yuv: a*cos(v);\
zuv: 0;\
xvv: -a*u*cos(v);\
yvv: -a*u*sin(v);\
zvv: 0;";
#endif