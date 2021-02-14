
#include "hyperbolic_paraboloid.h"
#include "surfaces_c_includes.h"

#if (USE_HYPERBOLIC_PARABOLOID != 0)
void HyperbolicParaboloid(pasuli_vartype u, pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPERBOLIC_PARABOLOID)

	P_X(u);
	P_Y(v);
	P_Z(u * v);

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
PaSuLiDefDesc pslddHyperbolicParaboloid = {
	PSLDD_ID(HYPERBOLIC_PARABOLOID)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descHyperbolicParaboloid =
	"name: Hyperbolic Paraboloid; \
ut: c; vt: c; \
us: -1; ue: 1; \
vs: -1; ve: 1; \
x: u; \
y: v; \
z: u*v; \
xu: 1; \
yu: 0; \
zu: v; \
xv: 0; \
yv: 1; \
zv: u; \
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