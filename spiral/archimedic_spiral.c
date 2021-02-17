
#include "archimedic_spiral.h"
#include "spiral_c_includes.h"

#if (USE_ARCHIMEDIC_SPIRAL != 0)
void ArchimedicSpiral(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ARCHIMEDIC_SPIRAL)

	pasuli_consttype H = constants[0];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype u_cos_u = u * cos_u;
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype u_sin_u = u * sin_u;

	P_X(u_cos_u);
	P_Y(v * H);
	P_Z(u_sin_u);

	UD_X(cos_u - u_sin_u);
	UD_Y_CONST(0);
	UD_Z(sin_u + u_cos_u);

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	// No scaling by H
	N_X(-PASULI_COND_COPY_VD_Z(sin_u + u_cos_u));
	N_Y_CONST(0);
	N_Z(PASULI_COND_COPY_VD_X(cos_u - u_sin_u));

	UUD_X(-(2 * sin_u + u_cos_u));
	UUD_Y_CONST(0);
	UUD_Z(2 * cos_u - u_sin_u);

	UVD_ALL(0);

	VVD_ALL(0);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddArchimedicSpiral = {
	PSLDD_ID(ARCHIMEDIC_SPIRAL)
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(1),
	0, 23, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descArchimedicSpiral =
	"name: Archimedic Spiral; \
cat: spiral; \
ut: c; vt: o; \
us: 0; ue: 23; \
vs: 0; ve: 1; \
c1:H: 1; \
x: u*cos(u); \
y: H*v; \
z: u*sin(u); \
xu: cos(u) - u*sin(u); \
yu: 0; \
zu: sin(u) + u*cos(u); \
xv: 0; \
yv: H; \
zv: 0; \
xn: -H*(sin(u) + u*cos(u)); \
yn: 0; \
zn: H*(cos(u) - u*sin(u)); \
xuu: -2*sin(u) - u*cos(u); \
yuu: 0; \
zuu: 2*cos(u) - u*sin(u); \
xuv: 0; yuv: 0; zuv: 0; \
xvv: 0; yvv: 0; zvv: 0; ";
#endif
