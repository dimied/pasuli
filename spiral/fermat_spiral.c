
#include "fermat_spiral.h"
#include "spiral_c_includes.h"

#if (USE_FERMAT_SPIRAL != 0)
void FermatSpiral(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(FERMAT_SPIRAL)

	double c = constants[0];

	P_X(sqrt(u) * cos(u));
	P_Y(v * c);
	P_Z(sqrt(u) * sin(u));
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
z: sqrt(u)*sin(u); "
#if (COMPILE_DESC_DERIV_U_SPIRAL != 0)
	"xu: (0.5*cos(u) - u*sin(u))/sqrt(u); \
yu: 0; \
zu: (0.5*sin(u) + u*cos(u))/sqrt(u); "
#endif
#if (COMPILE_DESC_DERIV_V_SPIRAL != 0)
	"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_SPIRAL != 0)
	"xn: -H*(0.5*sin(u)+u*cos(u))/sqrt(u); \
yn: 0; \
zn: H*(0.5*cos(u) - u*sin(u))/sqrt(u); "
#endif
	"xuu: -(0.25*cos(u) + u*sin(u) + u*u*cos(u))/(u*sqrt(u)); \
yuu: 0; \
zuu: -(0.25*sin(u) - u*cos(u) + u*u*sin(u))/(u*sqrt(u)); "
	"xuv: 0; \
yuv: 0; \
zuv: 0; "
	"xvv: 0; \
yvv: 0; \
zvv: 0; "
	"end;";
#endif