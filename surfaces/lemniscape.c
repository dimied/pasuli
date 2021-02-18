
#include "lemniscape.h"
#include "surfaces_c_includes.h"

#if (USE_LEMNISCAPE != 0)
void Lemniscape(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LEMNISCAPE)

	double sqrt_abs_sin_2u_cos_u = sqrt((double)fabs(sin(2 * u)));
	double sqrt_abs_sin_2u_sin_u = sqrt_abs_sin_2u_cos_u * sin(u);
	sqrt_abs_sin_2u_cos_u *= cos(u);

	double cos_v = cos(v);

	P_X(sqrt_abs_sin_2u_cos_u * cos_v);
	P_Y(sqrt_abs_sin_2u_sin_u * cos_v);
	P_Z(2.0 * pO->pos[0] * pO->pos[1] * tan(v) +
		pO->pos[0] * pO->pos[0] -
		pO->pos[1] * pO->pos[1]);

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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLemniscape = {
	PSLDD_ID(LEMNISCAPE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
	0, 1, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descLemniscape =
	"name: Lemniscape; \
ut:c; vt:c; \
us: 0; ue:pi: 1; \
vs: 0; ve:pi: 1; \
x: cos(v)*sqrt(abs(sin(2*u)))*cos(u); \
y: cos(v)*sqrt(abs(sin(2*u)))*sin(u); \
z: x*x - y*y + 2*x*y*tan(v)^(2);  \
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
";
#endif