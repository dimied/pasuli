
#include "cassinianoval_torus2.h"
#include "torus_c_includes.h"

#if (USE_CASSINIAN_OVAL_TORUS_2 != 0)
void CassinianOvalTorus2(pasuli_vartype u,
						 pasuli_vartype v,
						 pasuli_consttype *constants,
						 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CASSINIAN_OVAL_TORUS_2)

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];
	pasuli_consttype b = constants[2];

	a *= a;
	b *= b;

	pasuli_calctype M = a * cos(2.0 * v);
	M += sqrt(b * b + M * M - a * a);
	M = sqrt(M);

	pasuli_calctype factor = R + M * sin(v);

	P_X(factor * cos(u));
	P_Y(factor * sin(u));
	P_Z(M * cos(v));
}
#endif

#include "torus_desc.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCassinianOvalTorus2 = {
	PSLDD_ID(CASSINIAN_OVAL_TORUS_2)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(3),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descCassinianOvalTorus2 =
	"name: Cassinian Oval Torus 2; \
cat: torus; \
us: 0; ue:pi:2; \
vs: 0; ve:pi:2; \
c1:R:1; c2:a:1; c3:b:1; \
a1:M: 2*a*a*cos(2*v) + 2*sqrt((-a^4 + b^4) + a^4*cos(2*v)^2); \
x: (R + sqrt(M/2)*sin(v))*cos(u);\
y: (R + sqrt(M/2)*sin(v))*sin(u);\
z: sqrt(M/2)*cos(v);";
#endif
