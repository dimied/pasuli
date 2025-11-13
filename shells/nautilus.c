
#include "nautilus.h"
#include "shells_c_includes.h"

#if (USE_NAUTILUS != 0)

#include "snails.h"

pasuli_consttype NautilusParams[] = {
	1, 1.0f, 0.6f, 1.0f, 1.0f, 0.0f, 0.18f};

void Nautilus(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(NAUTILUS)
	Snails(u, v, &NautilusParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddNautilus = {
	NAUTILUS,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(2) |
		PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
	-20, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
char *descNautilus = "name: Nautilus;\
cat: shells;\
kindof: Snails;\
ut: c; vt: c;\
us: -20; ue: 1;\
c1:R: 1; c2:a: 1;\
c3:b: 0.6; c4:c: 1;\
c5:h: 1; c6:k: 0;\
c7:w: 0.18;";
#endif