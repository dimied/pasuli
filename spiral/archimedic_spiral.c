
#include "archimedic_spiral.h"
#include "spiral_c_includes.h"

#if (USE_ARCHIMEDIC_SPIRAL != 0)
void ArchimedicSpiral(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ARCHIMEDIC_SPIRAL)

	P_X(u * cos(u));
	P_Y(v * (*constants));
	P_Z(sin(u));
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
z: u*sin(u); "
#if (COMPILE_DESC_DERIV_U_SPIRAL != 0)
	"xu: cos(u) - u*sin(u); \
yu: 0; \
zu: sin(u) + u*cos(u); "
#endif
#if (COMPILE_DESC_DERIV_V_SPIRAL != 0)
	"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_SPIRAL != 0)
	"xn: -H*(sin(u) + u*cos(u)); \
yn: 0; \
zn: H*(cos(u) - u*sin(u)); "
#endif
	"xuu: -2*sin(u) - u*cos(u); \
yuu: 0; \
zuu: 2*cos(u) - u*sin(u); "
	"xuv: 0; \
yuv: 0; \
zuv: 0; "
	"xvv: 0; \
yvv: 0; \
zvv: 0; "
	"end;";
#endif
