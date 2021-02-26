
#include "waves.h"
#include "surfaces_c_includes.h"

#if (USE_WAVES != 0)

void Waves(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(WAVES)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype cos_bu = cos(b * u);
	pasuli_calctype cos_cv = cos(c * v);

	P_X(u);
	P_Y(v);
	P_Z(a * cos_bu * cos_cv);

	pasuli_calctype sin_bu = sin(b * u);

	UD_X_CONST(1);
	UD_Y_CONST(0);
	UD_Z(-a * b * sin_bu * cos_cv);

	pasuli_calctype sin_cv = sin(c * v);

	VD_X_CONST(0);
	VD_Y_CONST(1);
	VD_Z(-a * c * cos_bu * sin_cv);

	N_X(-PASULI_COND_COPY_UD_Z(-a * b * sin_bu * cos_cv));
	N_Y(-PASULI_COND_COPY_VD_Z(-a * c * cos_bu * sin_cv));
	N_Z(1);

	UUD_X_CONST(0);
	UUD_Y_CONST(0);
	UUD_Z(-b * b * PASULI_COND_COPY_POS_Z(a * cos_bu * cos_cv));

	UVD_X_CONST(0);
	UVD_Y_CONST(0);
	UVD_Z(a * b * c * sin_bu * sin_cv);

	VVD_X(0);
	VVD_Y(0);
	VVD_Z(-c * c * PASULI_COND_COPY_POS_Z(a * cos_bu * cos_cv));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWaves = {
PSLDD_ID( WAVES )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-2, 2 , -2 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descWaves =
	"name: Waves;\
ut:c; vt:c;\
us:pi: -2; ue:pi:2;\
vs:pi: -2; ve:pi:2;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: u;\
y: v;\
z: a*cos(b*u)*cos(c*v);\
xu: 1;\
yu: 0;\
zu: -a*b*sin(b*u)*cos(c*v);\
xv: 0;\
yv: 1;\
zv: -a*c*cos(b*u)*sin(c*v);\
xn: a*b*sin(b*u)*cos(c*v);\
yn: a*c*cos(b*u)*sin(c*v);\
zn: 1;\
xuu: 0;\
yuu: 0;\
zuu: -a*b*b*cos(b*u)*cos(c*v);\
xuv: 0;\
yuv: 0;\
zuv: a*b*c*sin(b*u)*sin(c*v);\
xvv: 0;\
yvv: 0;\
zvv: -a*c*c*cos(b*u)*cos(c*v);";
#endif