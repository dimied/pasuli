
#include "spring2.h"
#include "surfaces_c_includes.h"

#if (USE_SPRING2 != 0)

void Spring2(pasuli_vartype u,
			 pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPRING2)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype h = constants[2];

	pasuli_calctype w = sqrt(R * R + r * r);

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype R_r_cos_u = R + r * cos_u;

	pasuli_calctype r_h_sin_u_w = r * h * sin_u / w;
	pasuli_calctype R_r_sin_u_w = R * r * sin_u / w;
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(R_r_cos_u * cos_v + r_h_sin_u_w * sin_v);
	P_Y(R_r_cos_u * sin_v - r_h_sin_u_w * cos_v);
	P_Z(h * v + R_r_sin_u_w);

	UD_X(h * r * cos_u * sin_v / w - r * cos_v * sin_u);
	UD_Y(-h * r * cos_u * cos_v / w - r * sin_v * sin_u);
	UD_Z(r * R * cos_u / w);

	VD_X(h * r * cos_v * sin_u / w - (r * cos_u + R) * sin_v);
	VD_Y(h * r * sin_v * sin_u / w + (r * cos_u + R) * cos_v);
	VD_Z(h);

	PASULI_CALC_NORMAL_FROM_UD_VD
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
	"name: Spring 2;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
vs:0; ve:pi: 5;\
c1:R: 1.5; c2:r: 0.5; c3:h: 1.0;\
a1:w: sqrt(R*R + r*r);\
x: (R + r*cos(u))*cos(v) + r*h*sin(u)*sin(v)/w;\
y: (R + r*cos(u))*sin(v) - r*h*sin(u)*cos(v)/w;\
z: h*v + R*r*sin(u)/w;\
xu: h*r*cos(u)*sin(v)/sqrt(R*R + r*r) - r*cos(v)*sin(u);\
yu: -h*r*cos(u)*cos(v)/sqrt(R*R + r*r) - r*sin(v)*sin(u);\
zu: r*R*cos(u)/sqrt(R*R + r*r);\
xv: h*r*cos(v)*sin(u)/sqrt(R*R + r*r) - (r*cos(u)+R)*sin(v);\
yv: h*r*sin(v)*sin(u)/sqrt(R*R + r*r) + (r*cos(u)+R)*cos(v);\
zv: h;";
#endif
