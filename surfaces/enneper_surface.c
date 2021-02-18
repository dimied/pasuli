
#include "enneper_surface.h"
#include "../pasuli_macros.h"
#include <math.h>

#if (USE_ENNEPER_SURFACE != 0)
void EnneperSurface(pasuli_vartype u, pasuli_vartype v,
					double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ENNEPER_SURFACE)

	pasuli_calctype u_pow2 = u * u;
	pasuli_calctype v_pow2 = v * v;

	P_X(u * (1 - (u_pow2 / 3) + v_pow2));
	P_Y(v * (1 - (v_pow2 / 3) + u_pow2));
	P_Z(u_pow2 - v_pow2);

	UD_X(1 - u_pow2 + v_pow2);
	UD_Y(2 * u * v);
	UD_Z(2 * u);

	VD_X(2 * u * v);
	VD_Y(1 + u_pow2 - v_pow2);
	VD_Z(-2 * v);

	pasuli_calctype normal_xy = 1 + u_pow2 + v_pow2;
	pasuli_calctype normal_z = u_pow2 + v_pow2;
	N_X(-2 * u * normal_xy);
	N_Y(2 * v * normal_xy);
	N_Z(1 - normal_z * normal_z);

	// No factor 2
	UUD_X(-u);
	UUD_Y(v);
	UUD_Z_CONST(1);
	// No factor 2
	UVD_X(v);
	UVD_Y(u);
	UVD_Z_CONST(0);
	// No factor 2
	VVD_X(u);
	VVD_Y(-v);
	VVD_Z(-1);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurface = {
	PSLDD_ID(ENNEPER_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_FULL_IMPL,
	-2, 2, -2, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface =
	"name: Enneper Surface; \
ut: c; vt: c; \
us: -2; ue: 2; \
vs: -2; ve: 2; \
x: u - (u^3/3) + u*v*v; \
y: v - (v^3/3) + v*u*u; \
z: u*u - v*v; \
xu: 1 - u*u + v*v; \
yu: 2*u*v; \
zu: 2*u; \
xv: 2*u*v; \
yv: 1 + u*u - v*v; \
zv: -2*v; \
xn: -2*u*(1+u*u+v*v); \
yn: 2*v*(1+u*u+v*v); \
zn: 1-((u*u + v*v)^2); \
xuu: -2*u; \
yuu: 2*v; \
zuu: 2; \
xuv: 2*v; \
yuv: 2*u; \
zuv: 0; \
xvv: 2*u; \
yvv: -2*v; \
zvv: -2; ";
#endif