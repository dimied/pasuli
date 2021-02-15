
#include "spring2.h"
#include "surfaces_c_includes.h"

#if (USE_SPRING2 != 0)
void Spring2(pasuli_vartype u, pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPRING2)

	double R = constants[0];
	double r = constants[1];
	double h = constants[2];
	double w = R * R + r * r;

	double rr_cos_u = R + r * cos(u);
	double rr_sin_u = R + r * sin(u);
	double rh_sin_u_w = r * h * sin(u) / w;
	double Rrsu = R * r * sin(u) / w;
	double cv = cos(v);
	double sv = sin(v);

	P_X(rr_cos_u * cv + rh_sin_u_w * sv);
	P_Y(rr_cos_u * sv + rh_sin_u_w * cv);
	P_Z(h * sv + Rrsu);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
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
PaSuLiDefDesc pslddSpring2 = {
PSLDD_ID( SPRING2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
-1, 1 , 0 , 5 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descSpring2 =
	"name: Spring 2; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs: 0; ve:pi: 5; \
c1:R: 1.5; c2:r: 0.5; c3:h: 1.0; \
a1:w: sqrt(R*R + r*r); \
x: (R + r*cos(u))*cos(v) + r*h*sin(u)*sin(v)/w; \
y: (R + r*cos(u))*sin(v) - r*h*sin(u)*cos(v)/w; \
z: h*v + R*r*sin(u)/w; \
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
