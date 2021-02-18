
#include "hyperbolic_octahedron.h"
#include "surfaces_c_includes.h"

#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
void HyperbolicOctahedron(pasuli_vartype u, pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPERBOLIC_OCTAHEDRON)

	double y_sincos = cos(v);
	double x_coscos = cos(u) * y_sincos;
	y_sincos *= sin(u);
	double sv = sin(v);

	P_X(x_coscos * x_coscos * x_coscos);
	P_Y(y_sincos * y_sincos * y_sincos);
	P_Z(sv * sv * sv);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
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
ut:c; \
vt:c; \
us:pi: -0.5; \
ue:pi: 0.5; \
vs:pi: -1; \
ve:pi: 1; \
x: (cos(u)*cos(v))^(3); \
y: (sin(u)*cos(v))^(3); \
z: sin(v)^(3); "
	"xu: -3*(cos(u)^2)*(cos(v)^3)*sin(u); \
yu: 3*cos(u)*(cos(v)^3)*(sin(u)^2); \
zu: 0; "
	"xv: -3*(cos(u)^3)*(cos(v)^2)*sin(v); \
yv: -3*(cos(v)^2)*(sin(u)^3)*sin(v); \
zv: 3*cos(v)*sin(v)*sin(v); "
	"xn: 9*cos(u)*(cos(v)^4)*(sin(u)^2)*(sin(v)^2); \
yn: 9*(cos(u)^2)*(cos(v)^4)*sin(u)*(sin(v)^2); \
zn: 9*(cos(u)^2)*(cos(v)^5)*(sin(u)^2)*sin(v); "
	"xuu: 3*cos(u)*(cos(v)^3)*(2-3*cos(u)*cos(u)); \
yuu: 3*sin(u)*(cos(v)^3)*(2-3*sin(u)*sin(u)); \
zuu: 0; "
	"xuv: 9*((cos(u)*cos(v))^2)*sin(u)*sin(v); \
yuv: -9*(cos(u)*(cos(v)^2)*(sin(u)^2)*sin(v); \
zuv: 0; "
	"xvv: 3*(2-3*cos(v)*cos(v))*(cos(u)^3)*cos(v); \
yvv: 3*(2-3*cos(v)*cos(v))*(sin(u)^3)*cos(v); \
zvv: 3*sin(v)*(2-3*sin(v)*sin(v)); "
	"";
#endif