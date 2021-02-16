
#include "natica_stellata.h"
#include "shells_c_includes.h"

#if (USE_NATICA_STELLATA != 0)

#include "snails.h"

pasuli_consttype NaticaStellataParams[] = {
    1, 2.6f, 2.4f, 1.0f, 1.25f, -2.8f, 0.18f};

void NaticaStellata(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(NATICA_STELLATA)
    Snails(u, v, &NaticaStellataParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddNaticaStellata = {
	PSLDD_ID(NATICA_STELLATA)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
		PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
	-20, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
char *descNaticaStellata = "name: Natica Stellata; \
cat: shells; \
kindof: Snails; \
ut: c; vt: c; \
us: -20; ue: 1; \
c1:R: 1; c2:a: 2.6; \
c3:b: 2.4; c4:c: 1; \
c5:h: 1.25; c6:k: -2.8; \
c7:w: 0.18;";
#endif