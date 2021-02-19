
#include "hyperbolic_octahedron.h"
#include "surfaces_c_includes.h"

#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
void HyperbolicOctahedron(pasuli_vartype u, pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPERBOLIC_OCTAHEDRON)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_u_cos_v = cos_u * cos_v;
	pasuli_calctype sin_u_cos_v = sin_u * cos_v;

	P_X(cos_u_cos_v * cos_u_cos_v * cos_u_cos_v);
	P_Y(sin_u_cos_v * sin_u_cos_v * sin_u_cos_v);
	P_Z(sin_v * sin_v * sin_v);

	// Skip scaling by 3
	UD_X(-cos_u * cos_u * cos_v * cos_v * cos_v * sin_u);
	UD_Y(cos_u * cos_v * cos_v * cos_v * sin_u * sin_u);
	UD_Z(0);

	// Skip scaling by 3
	pasuli_calctype common = (cos_v * sin_v < 0) ? -1 : 1;

	VD_X(-cos_u * cos_u * cos_u * cos_v * common);
	VD_Y(-sin_u * sin_u * sin_u * cos_v * common);
	VD_Z(common * sin_v);

	// Skip scaling by 9, skip cos_v^4
	common = (cos_u * sin_u * sin_v < 0) ? -1 : 1;
	N_X(common * sin_u * sin_v);
	N_Y(common * cos_u * sin_v);
	N_Z(common * cos_u * sin_u * cos_v);

	// Skip scaling by 3
	UUD_X(cos_u * cos_v * cos_v * cos_v * (3 * sin_u * sin_u - 1));
	UUD_Y(sin_u * cos_v * cos_v * cos_v * (2 - 3 * sin_u * sin_u));
	UUD_Z_CONST(0);

	// Skip scaling by 9
	UVD_X(cos_u * cos_u * cos_v * cos_v * sin_u * sin_v);
	UVD_Y(-cos_u * cos_v * cos_v * sin_u * sin_u * sin_v);
	UVD_Z_CONST(0);

	// Skip scaling by 3
	VVD_OP(common = (3 * sin_v * sin_v - 1) * cos_v);
	VVD_X(cos_u * cos_u * cos_u * common);
	VVD_Y(sin_u * sin_u * sin_u * common);
	VVD_Z(sin_v * (2 - 3 * sin_v * sin_v));
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicOctahedron = {
	PSLDD_ID(HYPERBOLIC_OCTAHEDRON)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI | PASULI_FULL_IMPL,
	-0.5, 0.5, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descHyperbolicOctahedron =
	"name: Hyperbolic Octahedron; \
ut:c; vt:c; \
us:pi: -0.5; ue:pi: 0.5; \
vs:pi: -1; ve:pi: 1; \
x: (cos(u)*cos(v))^(3); \
y: (sin(u)*cos(v))^(3); \
z: sin(v)^(3); \
xu: -3*(cos(u)^2)*(cos(v)^3)*sin(u); \
yu: 3*cos(u)*(cos(v)^3)*(sin(u)^2); \
zu: 0; \
xv: -3*(cos(u)^3)*(cos(v)^2)*sin(v); \
yv: -3*(cos(v)^2)*(sin(u)^3)*sin(v); \
zv: 3*cos(v)*sin(v)^2; \
xn: 9*cos(u)*(cos(v)^4)*(sin(u)^2)*(sin(v)^2); \
yn: 9*(cos(u)^2)*(cos(v)^4)*sin(u)*(sin(v)^2); \
zn: 9*(cos(u)^2*sin(u)^2*cos(v)^5*sin(v)); \
xuu: 3*cos(u)*(cos(v)^3)*(3*sin(u)^2 - 1); \
yuu: 3*sin(u)*(cos(v)^3)*(2-3*sin(u)*sin(u)); \
zuu: 0; \
xuv: 9*((cos(u)*cos(v))^2)*sin(u)*sin(v); \
yuv: -9*(cos(u)*(cos(v)^2)*(sin(u)^2)*sin(v); \
zuv: 0; \
xvv: 3*(cos(u)^3)*(3*sin(v)^2 - 1)*cos(v); \
yvv: 3*(sin(u)^3)*(3*sin(v)^2 - 1)*cos(v); \
zvv: 3*sin(v)*(2-3*sin(v)*sin(v));";
#endif