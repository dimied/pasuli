
#include "wave_sphere.h"
#include "sphere_c_includes.h"

#if (USE_WAVE_SPHERE != 0)
void WaveSphere(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(WAVE_SPHERE)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype cos_of_cos_u = cos(cos_u);
	pasuli_calctype sin_of_cos_u = sin(cos_u);
	pasuli_calctype u_sin_of_cos_u = u * sin_of_cos_u;
	pasuli_calctype u_cos_of_cos_u = u * cos_of_cos_u;

	P_X(u_cos_of_cos_u * cos_v);
	P_Y(u_cos_of_cos_u * sin_v);
	P_Z(u_sin_of_cos_u);

	pasuli_calctype vd_common = (cos_of_cos_u + u_sin_of_cos_u * sin_u);
	UD_X(cos_v * vd_common);
	UD_Y(sin_v * vd_common);
	UD_Z(sin_of_cos_u - u_cos_of_cos_u * sin_u);

	VD_X(-u_cos_of_cos_u * sin_v);
	VD_Y(u_cos_of_cos_u * cos_v);
	VD_Z_CONST(0);

	// No multiplication of u_cos_of_cos_u
	pasuli_calctype normal_common = (-sin_of_cos_u + u_cos_of_cos_u * sin_u);
	N_X(cos_v * normal_common);
	N_Y(sin_v * normal_common);
	N_Z((cos_of_cos_u + u_sin_of_cos_u * sin_u));

	vd_common = u_sin_of_cos_u * cos_u + u * cos_of_cos_u * sin_u * sin_u + 2 * sin_of_cos_u * sin_u;
	UUD_X(cos_v * vd_common);
	UUD_Y(sin_v * vd_common);
	UUD_Z(-(u_cos_of_cos_u * cos_u + u_sin_of_cos_u * sin_u * sin_u + 2 * cos_of_cos_u * sin_u));

	// No scaling
	// vd_common = (cos_of_cos_u + u_sin_of_cos_u * sin_u);
	UVD_X(-sin_v);
	UVD_Y(cos_v);
	UVD_Z_CONST(0);

	// No scaling by u_cos_of_cos_u
	VVD_X(-cos_v);
	VVD_Y(-sin_v);
	VVD_Z_CONST(0);
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddWaveSphere = {
	WAVE_SPHERE,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI |
		PASULI_FULL_IMPL,
	0, 14, 0, 2, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descWaveSphere =
	"name: Wave sphere;\
cat: sphere;\
ut: c; vt: c;\
us:0; ue: 14;\
vs:0; ve:pi:2;\
x: u*cos(cos(u))*cos(v);\
y: u*cos(cos(u))*sin(v);\
z: u*sin(cos(u));\
xu: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u)));\
yu: sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u)));\
zu: sin(cos(u)) - u*cos(cos(u))*sin(u);\
xv: -u*cos(cos(u))*sin(v);\
yv: u*cos(v)*cos(cos(u));\
zv: 0;\
xn: u*cos(cos(u))*(u*cos(cos(u))*sin(u)-sin(cos(u)))*cos(v);\
yn: u*cos(cos(u))*(u*cos(cos(u))*sin(u)-sin(cos(u)))*sin(v);\
zn: u*cos(cos(u))*(cos(cos(u)) + u*sin(u)*sin(cos(u)));\
xuu: cos(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u)));\
yuu: sin(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u)));\
zuu: -(cos(cos(u))*(2*sin(u) + u*cos(u)) + u*sin(cos(u))*sin(u)*sin(u));\
xuv: -sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u)));\
yuv: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u)));\
zuv: 0;\
xvv: -u*cos(cos(u))*cos(v);\
yvv: -u*sin(v)*cos(cos(u));\
zvv: 0; ";
#endif