
#include "kuens_surface.h"
#include "surfaces_c_includes.h"

#if (USE_KUENS_SURFACE != 0)
void KuensSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(KUENS_SURFACE)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = cos(u);

	pasuli_calctype sin_v = sin(u);
	pasuli_calctype h = 1 + u * u * sin_v * sin_v;

	P_X(2 * (cos_u + u * sin_u) * sin_v / h);
	P_Y(2 * (sin_u - u * cos_u) * sin_v / h);
	P_Z(log(tan(v * 0.2)) + 2 * cos(v) / h);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKuensSurface = {
	PSLDD_ID(KUENS_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED,
	-4.3f, 4.3f, 0.03f, 3.11f, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descKuensSurface =
	"name: Kuens Surface; \
ut:c; vt:c; \
us: -4.3; ue: 4.3; \
vs: 0.01; ve: 3.11; \
a1:h: 1 + u*u*sin(v)*sin(v); \
x: (2*(cos(u) + u sin(u))*sin(v))/h; \
y: (2*(-u*cos(u) + sin(u))*sin(v))/h; \
z: log(tan(v/2)) + 2*cos(v)/h; ";
#endif