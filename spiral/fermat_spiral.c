
#include "fermat_spiral.h"
#include "spiral_c_includes.h"

#if (USE_FERMAT_SPIRAL != 0)
void FermatSpiral(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(FERMAT_SPIRAL)

	pasuli_consttype H = constants[0];
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype rootOfU = sqrt(u);
	pasuli_calctype rootOfU_cos_u = rootOfU * cos_u;
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype rootOfU_sin_u = rootOfU * sin_u;

	P_X(rootOfU_cos_u);
	P_Y(v * H);
	P_Z(rootOfU_sin_u);

	pasuli_calctype u_cos_u = u * cos_u;
	pasuli_calctype u_sin_u = u * sin_u;
	// No division by sqrt(u)
	UD_X(0.5 * cos_u - u_sin_u);
	UD_Y_CONST(0);
	UD_Z(0.5 * sin_u + u_cos_u);

	VD_X_CONST(0);
	VD_Y_CONST(H);
	VD_Z_CONST(0);

	// NO multiplication by H and no division by sqrt(u)
	N_X(-(0.5 * sin_u + u_cos_u));
	N_Y_CONST(0);
	N_Z(0.5 * cos_u - u_sin_u);

	// No division by u*sqrt(u)
	UUD_X(-(0.25 * cos_u + u * sin_u + u * u_cos_u));
	UUD_Y_CONST(0);
	UUD_Z(-(0.25 * sin_u - u_cos_u + u * sin_u));

	UVD_ALL(0);

	VVD_ALL(0);
}
#endif

#if (COMPILE_DEF_DESC_SPIRAL != 0)
PaSuLiDefDesc pslddFermatSpiral = {
	PSLDD_ID(FERMAT_SPIRAL)
			PASULI_U_CLOSED |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(1),
	0, 10, 0, 1, 0};
#endif
#if (COMPILE_DESC_SPIRAL != 0)
char *descFermatSpiral =
	"name: Fermat Spiral; \
cat: spiral; \
ut: c; vt: o; \
us: 0; ue: 10; \
vs: 0; ve: 1; \
c1:H: 1; \
x: sqrt(u)*cos(u); \
y: H*v; \
z: sqrt(u)*sin(u); \
xu: (0.5*cos(u) - u*sin(u))/sqrt(u); \
yu: 0; \
zu: (0.5*sin(u) + u*cos(u))/sqrt(u); \
xv: 0; \
yv: H; \
zv: 0; \
xn: -H*(0.5*sin(u)+u*cos(u))/sqrt(u); \
yn: 0; \
zn: H*(0.5*cos(u) - u*sin(u))/sqrt(u); \
xuu: -(0.25*cos(u) + u*sin(u) + u*u*cos(u))/(u*sqrt(u)); \
yuu: 0; \
zuu: -(0.25*sin(u) - u*cos(u) + u*u*sin(u))/(u*sqrt(u)); \
xuv: 0; yuv: 0; zuv: 0; \
xvv: 0; yvv: 0; zvv: 0; ";
#endif