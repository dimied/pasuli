
#include "bellerophina.h"
#include "shells_c_includes.h"

#if (USE_BELLEROPHINA != 0)
#include "snails.h"

pasuli_consttype BellerophinaParams[] = {
    1, 0.85f, 1.2f, 1.0f, 0.75f, 0.0f, 0.06f};

void Bellerophina(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{
    PASULI_SET_TYPE_ID(BELLEROPHINA)
    Snails(u, v, &BellerophinaParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddBellerophina = {
    BELLEROPHINA,
            PASULI_U_CLOSED |
        PASULI_V_CLOSED |
        PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
        PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
    -10, -1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
char *descBellerophina = "name: Bellerophina;\
cat: shells;\
kindof: Snails;\
ut: c; vt: c;\
us: -10; ue: -1;\
c1:R: 1; c2:a: 0.85;\
c3:b: 1.2; c4:c: 1;\
c5:h: 0.75; c6:k: 0;\
c7:w: 0.06;";
#endif