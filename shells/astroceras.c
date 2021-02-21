
#include "astroceras.h"
#include "shells_c_includes.h"

#if (USE_ASTROCERAS != 0)
#include "snails.h"

pasuli_consttype AstrocerasParams[] = {
	1, 1.25f, 1.25f, 1.0f, 3.5f, 0.0f, 0.12f};

void Astroceras(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ASTROCERAS)
	Snails(u, v, &AstrocerasParams[0], pO);	
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddAstroceras = {
	PSLDD_ID(ASTROCERAS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_CALC_U_START | PASULI_CALC_U_END |
		PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
		PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
	-40, -1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
char *descAstroceras = "name: Astroceras;\
cat: shells;\
kindof: Snails;\
ut: c; vt: c;\
us: -40; ue: -1;\
c1:R: 1; c2:a: 1.25;\
c3:b: 1.25; c4:c: 1;\
c5:h: 3.5; c6:k: 0;\
c7:w: 0.12;";
#endif