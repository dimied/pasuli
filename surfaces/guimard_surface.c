
#include "guimard_surface.h"
#include "surfaces_c_includes.h"

#if (USE_GUIMARD_SURFACE != 0)
void GuimardSurface(pasuli_vartype u, pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(GUIMARD_SURFACE)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(((1 - u) * a + b * u) * cos_v);
	P_Y(b * u * sin_v);
	P_Z(c * u * sin_v * sin_v);

	UD_X(cos_v * (b - a));
	UD_Y(b * sin_v);
	UD_Z(c * sin_v * sin_v);

	pasuli_consttype vd_x_common = a * (u - 1) - b * u;
	VD_X(sin_v * vd_x_common);
	VD_Y(b * u * cos_v);
	VD_Z(2 * c * u * cos_v * sin_v);

	N_X(b * c * u * cos_v * sin_v * sin_v);
	// 2*a*c*u*cos(v)^2*sin(v) + a*c*u*sin(v)^3
	// - a*c*sin(v)^3
	// - 2*b*c*u*cos(v)^2*sin(v) - b*c*u*sin(v)^3
	// =
	// 2*a*c*u*cos(v)^2*sin(v) + a*c*u*sin(v)*(1-cos(v)^2)
	// - a*c*sin(v)*(1-cos(v)^2)
	// - 2*b*c*u*cos(v)^2*sin(v) - b*c*u*sin(v)*(1-cos(v)^2)
	// =
	// a*c*u*sin(v)*(cos(v)^2 + 1)
	// + a*c*sin(v)*(cos(v)^2 - 1)
	// - b*c*u*sin(v)*(cos(v)^2+1)
	// = c*sin(v)*(u*(a-b)*(cos(v)^2 + 1) + a*(cos(v)^2 -1) )
	N_Y(c * sin_v * (u * (a - b) * (cos_v * cos_v + 1) + a * (cos_v * cos_v - 1)));
	N_Z(-a * b * u + a * b * sin_v * sin_v + b * b * u);

	UUD_ALL(0);

	UVD_X(sin_v * (a - b));
	UVD_Y(b * cos_v);
	UVD_Z(2 * c * cos_v * sin_v);

	VVD_X(cos_v * vd_x_common);
	VVD_Y(-b * u * sin_v);
	VVD_Z(2 * c * u * (cos_v * cos_v - sin_v * sin_v));
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddGuimardSurface = {
PSLDD_ID( GUIMARD_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descGuimardSurface =
	"name: Guimard Surface;\
ut:c; vt:c;\
us: -1; ue: 1;\
vs: -1; ve: 1;\
c1:a: 1.5; c2:b: 0.5; c3:c: 1.0;\
x: ((1 - u)*a + u*b)*cos(v);\
y: b*u*sin(v);\
z: c*u*sin(v)*sin(v);\
xu: cos(v)(b-a);\
yu: b*sin(v);\
zu: c*sin(v)^2;\
xv: sin(v)*(a*(u-1) - b*u);\
yv: b*u*cos(v);\
zv: 2*c*u*cos(v)*sin(v);\
xn: b*c*u*cos(v)*sin(v)^2;\
yn: 2*a*c*u*cos(v)^2*sin(v) + a*c*u*sin(v)^3 - a*c*sin(v)^3 - 2*b*c*u*cos(v)^2*sin(v) - b*c*u*sin(v)^3;\
zn: -a*b*u + a*b*sin(v)^2 + b^2*u;\
xuu: 0;\
yuu: 0;\
zuu: 0;\
xuv: sin(v)*(a-b);\
yuv: b*cos(v);\
zuv: 2*c*cos(v)*sin(v);\
xvv: cos(v)*(a*(u-1) - b*u);\
yvv: -b*u*sin(v);\
zvv: 2*c*u*(cos(v)^2 - sin(v)^2);";
#endif
