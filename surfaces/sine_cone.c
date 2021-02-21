
#include "sine_cone.h"
#include "surfaces_c_includes.h"

#if (USE_SINE_CONE != 0)

void SineCone(pasuli_vartype u,
			  pasuli_vartype v,
			  double *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SINE_CONE)

	pasuli_consttype K = constants[0];
	pasuli_consttype N = constants[1];

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_Nv = cos(N * v);

	P_X(u * cos_v);
	P_Y(u * sin_v);
	P_Z(K * u * cos_Nv);

	UD_X(cos_v);
	UD_Y(sin_v);
	UD_Z(K * cos_Nv);

	pasuli_calctype sin_Nv = sin(N * v);
	VD_X(-u * sin_v);
	VD_Y(u * cos_v);
	VD_Z(-K * N * u * sin_Nv);

	N_X(-K * u * (N * sin_v * sin_Nv - cos_v * cos_Nv));
	N_Y(K * u * (N * cos_v * sin_Nv - sin_v * cos_Nv));
	N_Z(u);

	UUD_ALL(0);

	UVD_X(-sin_v);
	UVD_Y(cos_v);
	UVD_Z(-K * N * sin_Nv);

	VVD_X(-u * cos_v);
	VVD_Y(-u * sin_v);
	VVD_Z(-K * N * N * u * cos_Nv);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineCone = {
PSLDD_ID( 0 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
-10, 10 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descSineCone =
	"name: Sine Cone;\
ut:c; vt:c;\
us: -10; ue: 10;\
vs:pi: -1; ve:pi: 1;\
c1:k: 1.5; c2:N: 0.5;\
x: u*cos(v);\
y: u*sin(v);\
z: k*u*cos(N*v);\
xu: cos(v);\
yu: sin(v);\
zu: k*cos(N*v);\
xv: -u*sin(v);\
yv: u *cos(v);\
zv: -k *N *u *sin(N *v);\
xn: -k *u *(n *sin(v) * sin(N * v) - cos(v) * cos(N * v));\
yn: k *u *(n *cos(v) * sin(n * v) - sin(v) * cos(n * v));\
zn: u;\
xuu:0;\
yuu:0;\
zuu:0;\
xuv: -sin(v);\
yuv: cos(v);\
zuv: -k *N *sin(n *v);\
xvv: -u *cos(v);\
yvv: -u *sin(v);\
zvv: -k *N *N *u *cos(n *v);";
#endif