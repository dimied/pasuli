
#include "snail_surface.h"
#include "shells_c_includes.h"

#if (USE_SNAIL_SURFACE != 0)
void SnailSurface(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SNAIL_SURFACE)

	P_X(cos(v) * u * sin(u));
	P_Y(cos(v) * u * cos(u));
	P_Z(-(u * sin(v)));
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnailSurface = {
	PSLDD_ID(SNAIL_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI | PASULI_CONST_COUNT(0),
	0, 2, -1, 1, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
u \in [0, 2pi]
v \in [-pi, pi]

x = u cos(v) sin(u)
y = u cos(u) cos(v)
z = -u sin(v)
*/
char *descSnailSurface = "";
#endif
