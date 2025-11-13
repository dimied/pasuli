
#include "wave_torus.h"
#include "torus_c_includes.h"

#if (USE_WAVE_TORUS != 0)

void WaveTorus(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(WAVE_TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype a = constants[2];
	pasuli_consttype N = constants[3];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype cos_Nu = cos(N * u);
	pasuli_calctype sin_Nu = sin(N * u);

	pasuli_calctype z_factor = r + a * sin_Nu;
	pasuli_calctype factor = cos_v * z_factor + R;

	pasuli_calctype pos_x = factor * cos_u;
	pasuli_calctype pos_y = factor * sin_u;

	P_X(pos_x);
	P_Y(pos_y);
	P_Z(z_factor * sin_v);

	pasuli_calctype ud_factor = a * N * cos_Nu;

	UD_X(ud_factor * cos_u - pos_y);
	UD_Y(ud_factor * sin_u + pos_x);
	UD_Z(ud_factor * sin_v);

	// Ignore scaling by (r + a*sin(n*u))
	z_factor = PASULI_CALC_SIGN(z_factor);
	VD_X(-z_factor * sin_v * cos_u);
	VD_Y(-z_factor * sin_v * sin_u);
	VD_Z(z_factor * cos_v);

	PASULI_CALC_NORMAL_FROM_UD_VD
}
#endif

#include "torus_const.h"

/*
#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddWaveTorus = {
	WAVE_TORUS,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, torus_def_constants};
#endif
*/

#if (COMPILE_DESC_TORUS != 0)
char *descWaveTorus =
	"name: Wave torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1.5; c2:r:0.5; c3:a:1; c4:n:1;\
x: (R+cos(v)*(r+a*sin(n*u)))*cos(u);\
y: (R+cos(v)*(r+a*sin(n*u)))*sin(u);\
z: (r+a*sin(n*u))*sin(v);\
xu: a*n*cos(u)*cos(v)*cos(n*u)-(R+cos(v)*(r+a*sin(n*u)))*sin(u);\
yu: a*n*sin(u)*cos(v)*cos(n*u)+(R+cos(v)*(r+a*sin(n*u)))*cos(u);\
zu: a*n*cos(n*u)*sin(v);\
xv: -(r+a*sin(n*u))*sin(v)*cos(u);\
yv: -(r+a*sin(n*u))*sin(v)*sin(u);\
zv: (r+a*sin(n*u))*cos(v);";
#endif