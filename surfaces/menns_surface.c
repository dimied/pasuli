
#include "menns_surface.h"
#include "surfaces_c_includes.h"

#if (USE_MENNS_SURFACE != 0)
void MennsSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(MENNS_SURFACE)

	pasuli_consttype a = constants[0];
	pasuli_calctype u2 = u * u;

	P_X(u);
	P_Y(v);
	P_Z(a * u2 * u2 + u2 * v - v * v);

	UD_X_CONST(1);
	UD_Y_CONST(0);
	UD_Z(4 * a * u * u2 + 2 * u * v);

	VD_X_CONST(0);
	VD_Y_CONST(1);
	VD_Z(u2 - 2 * v);

	N_X(-PASULI_COND_COPY_UD_Z(4 * a * u * u2 + 2 * u * v));
	N_Y(-PASULI_COND_COPY_VD_Z(u2 - 2 * v));
	N_Z_CONST(1);

	UUD_X_CONST(0);
	UUD_Y_CONST(0);
	UUD_Z(12 * a * u2 + 2 * v);

	UVD_X_CONST(0);
	UVD_Y_CONST(0);
	UVD_Z(2 * u);

	VVD_X_CONST(0);
	VVD_Y_CONST(0);
	VVD_Z(-2);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMennsSurface = {
PSLDD_ID( MENNS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descMennsSurface =
	"name: Menns Surface; \
ut:c; vt:c; \
us: -1; ue: 1; \
vs: -1; ve: 1; \
c1:a: 1.0; \
x: u; \
y: v; \
z: a*u^(4) + u*u*v - v*v; \
xu: 1; \
yu: 0; \
zu: 4*a*u^3 + 2*u*v; \
xv: 0; \
yv: 1; \
zv: u^2 - 2*v; \
xn: -4*a*u^3-2*u*v; \
yn: -u^2 + 2*v; \
zn: 1; \
xuu: 0; \
yuu: 0; \
zuu: 12*a*u^2 + 2*v; \
xuv: 0; \
yuv: 0; \
zuv: 2*u; \
xvv: 0; \
yvv: 0; \
zvv: -2; ";
#endif