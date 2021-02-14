
#include "trefoil_knots2.h"
#include "surfaces_c_includes.h"

#if (USE_TREFOIL_KNOTS2 != 0)

void TrefoilKnots2(double u, double v,
				   double *constants,
				   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TREFOIL_KNOTS2)

	double R = constants[0];
	double r = constants[1];
	double a = constants[2];
	double N = constants[3];
	double r_cos_u;
	double r_sin_u;
	double x_u;
	double z_u;
	double rcv = r * cos(v);

	r_cos_u = r * cos(u);
	r_sin_u = r * sin(u);
	z_u = R * (1 + a * cos(N * u));
	x_u = z_u * cos(u);
	z_u *= sin(u);
	u = a * sin(N * u);

	P_Y(r * sin(v) + u);
	P_X(rcv * r_cos_u + x_u);
	P_Z(rcv * r_sin_u + z_u);

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
PaSuLiDefDesc pslddTrefoilKnots2 = {
PSLDD_ID( TREFOIL_KNOTS2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0, 4 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots2 =
	"name: Trefoil Knots 2; \
ut:c; vt:c; \
us: 0; ue:pi: 4; \
vs: 0; ve:pi: 2; \
c1:R: 1.5; c2:r: 0.5; c3:a: 1.0; c4:N: 1.0; \
x: r*cos(v)*cos(u) + R*cos(u)*(1 + a*cos(N*u)); \
y: r*sin(v) + a*sin(N*u); \
z: r*cos(v)*sin(u) + R*sin(u)*(1 + a*cos(N*u)); \
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