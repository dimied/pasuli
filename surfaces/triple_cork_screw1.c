
#include "triple_cork_screw1.h"
#include "surfaces_c_includes.h"

#if (USE_TRIPLE_CORK_SCREW1 != 0)

void TripleCorkScrew1(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRIPLE_CORK_SCREW1)

	double Lu;
	double y_u;
	double z_u;

	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];
	N *= MY_PI;

	Lu = L * u;
	y_u = cos(u * N);
	z_u = sin(u * N);
	u = (1 - fabs((double)u));
	y_u *= u * R;
	z_u *= u * R;
	u *= r;

	P_X(Lu);
	P_Y(u * cos(v) + y_u);
	P_Z(u * sin(v) + z_u);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X(0);
	UD_Y(0);
	UD_Z(0);

	VD_X(0);
	VD_Y(0);
	VD_Z(0);

	N_X(0);
	N_Y(0);
	N_Z(0);

	UUD_X(0);
	UUD_Y(0);
	UUD_Z(0);

	UVD_X(0);
	UVD_Y(0);
	UVD_Z(0);

	VVD_X(0);
	VVD_Y(0);
	VVD_Z(0);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew1 = {
PSLDD_ID( TRIPLE_CORK_SCREW1 )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew1 =
	"name: Triple Cork Screw 1; \
ut: c; vt: c; \
us: -1; ue: 1; \
vs:pi: -1; ve:pi: 1; \
c1:R: 1.5; c2:r: 0.5; c3:L: 1.0; c4:N: 1.0; \
x: L*u; \
y: r*(1 - |u|)*cos(v) + R*(1 - |u|)*cos(u*N*pi); \
z: r*(1 - |u|)*sin(v) + R*(1 - |u|)*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
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