
#include "pseudoheliceras_subcatenatum.h"
#include "shells_c_includes.h"

#if (USE_PSEUDOHELICERAS_SUBCATENATUM != 0)
#include "snails.h"

pasuli_consttype PseudohelicerasSubcatenatumParams[] = {
    1, 1.6f, 1.6f, 1.0f, 1.5f, -7.0f, 0.075f};

void PseudohelicerasSubcatenatum(pasuli_vartype u,
                                 pasuli_vartype v,
                                 pasuli_consttype *constants,
                                 PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(PSEUDOHELICERAS_SUBCATENATUM)
    Snails(u, v, &PseudohelicerasSubcatenatumParams[0], pO);
}

#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddPseudohelicerasSubcatenatum = {
    PSLDD_ID(PSEUDOHELICERAS_SUBCATENATUM)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED | PASULI_CALC_U_START | PASULI_CALC_U_END |
        PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
        PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
    -50, -1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
char *descPseudohelicerasSubcatenatum = "name: Pseudo-Heliceras Subcatenatum;\
cat: shells;\
kindof: Snails;\
ut: c; vt: c;\
us: -50; ue: -1;\
c1:R: 1; c2:a: 1.6;\
c3:b: 1.6; c4:c: 1;\
c5:h: 1.5; c6:k: -7;\
c7:w: 0.075;";
#endif