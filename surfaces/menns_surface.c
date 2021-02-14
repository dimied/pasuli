
#include "menns_surface.h"
#include "surfaces_c_includes.h"

#if (USE_MENNS_SURFACE != 0)
void MennsSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(MENNS_SURFACE)

	double a = constants[0];
	double u2 = u * u;

	P_X(u);
	P_Y(v);
	P_Z(a * u2 * u2 + u2 * v - v * v);

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
end;";
#endif