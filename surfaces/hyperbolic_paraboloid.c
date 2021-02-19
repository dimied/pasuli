
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

	UD_X_CONST(1);
	UD_Y_CONST(0);
	UD_Z(v);

	VD_X_CONST(0);
	VD_Y_CONST(1);
	VD_Z(u);

	N_X(-v);
	N_Y(-u);
	N_Z(1);

	UUD_ALL(0);

	UVD_X_CONST(0);
	UVD_Y_CONST(0);
	UVD_Z_CONST(1);

	VVD_ALL(0);
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
xn: -v; \
yn: -u; \
zn: 1; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 1; \
xvv: 0; \
yvv: 0; \
zvv: 0;";
#endif