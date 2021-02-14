
#include "wave_sphere.h"
#include "sphere_c_includes.h"

#if (USE_WAVE_SPHERE != 0)
void WaveSphere(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(WAVE_SPHERE)

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
	double ccu = cos(cu);
	double scu = sin(cu);
	double u_scu = u * scu;
	double u_ccu = u * ccu;

	P_X(u_ccu * cv);
	P_Y(u_ccu * sv);
	P_Z(u_scu);

	double xy = (ccu + u_scu * su);
	UD_X(cv * xy);
	UD_Y(sv * xy);
	UD_Z(scu - u_ccu * su);

	VD_X(-u_ccu * sv);
	VD_Y(u_ccu * cv);
	VD_Z_CONST(0);

	xy = u * (-scu + u_ccu * su) * ccu;
	N_X(cv * xy);
	N_Y(sv * xy);
	N_Z(u_ccu * (ccu + u * scu * su));

	xy = u_scu * cu + u * ccu * su * su + 2 * scu * su;
	UUD_X(cv * xy);
	UUD_Y(sv * xy);
	UUD_Z(u_ccu * cu + u_scu * su * su + 2 * ccu * su);

	xy = (ccu + u_scu * su);
	UVD_X(-sv * xy);
	UVD_Y(cv * xy);
	UVD_Z_CONST(0);

	VVD_X(-u_ccu * cv);
	VVD_Y(u_ccu * sv);
	VVD_Z_CONST(0);
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddWaveSphere = {
	PSLDD_ID(WAVE_SPHERE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI |
		PASULI_FULL_IMPL,
	0, 14, 0, 2, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descWaveSphere =
	"name: wave sphere; \
cat: sphere; \
ut: c; vt: c; \
us: 0; ue: 14; \
vs: 0; ve:pi: 2; \
x: u*cos(cos(u))*cos(v); \
y: u*cos(cos(u))*sin(v); \
z: u*sin(cos(u)); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
yu: sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
zu: sin(cos(u)) - u*cos(cos(u))*sin(u); "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: -u*cos(cos(u))*sin(v); \
yv: u*cos(v)*cos(cos(u)); \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: u*cos(cos(u))(u*cos(cos(u)*sin(u)-sin(cos(u))))*cos(v); \
yn: u*cos(cos(u))(u*cos(cos(u)*sin(u)-sin(cos(u))))*sin(v); \
zn: u*(cos(cos(u))^2 + u*cos(cos(u))*sin(u)*sin(cos(u))); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: cos(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u))); \
yuu: sin(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u))); \
zuu: -(cos(cos(u))*(2*sin(u) + u*cos(u)) + u*sin(cos(u))*sin(u)*sin(u)); "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: -sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
yuv: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_SPHERE != 0)
	"xvv: -u*cos(cos(u))*cos(v); \
yvv: -u*sin(v)*cos(cos(u)); \
zvv: 0; "
#endif
	"end;";
#endif