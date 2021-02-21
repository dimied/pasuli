
#include "euhoplites.h"
#include "shells_c_includes.h"

#if (USE_EUHOPLITES != 0)

#include "snails.h"

pasuli_consttype EuhoplitesParams[] = {
	1, 0.6f, 0.4f, 1.0f, 0.9f, 0.0f, 0.1626f};

void Euhoplites(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EUHOPLITES)
	Snails(u, v, &EuhoplitesParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddEuhoplites = {
	PSLDD_ID(EUHOPLITES)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
		PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
	-40, -1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
char *descEuhoplites = "name: Euhoplites;\
cat: shells;\
kindof: Snails;\
ut: c; vt: c;\
us: -40; ue: -1;\
c1:R: 1; c2:a: 0.6;\
c3:b: 0.4; c4:c: 1;\
c5:h: 0.9; c6:k: 0;\
c7:w: 0.1626;";
#endif
