
#include "natica_stellata.h"
#include "shells_c_includes.h"

#if (USE_NATICA_STELLATA != 0)

#include "snails.h"

pasuli_consttype NaticaStellataParams[] = {
    2.6f, 2.4f, 1.0f, 1.25f, -2.8f, 0.18f};

void NaticaStellata(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO)
{

    //int k = 0;
    //double u , v;
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
/**
a : 2.6
b : 2.4 
c 	: 	1.0 	
h 	: 	1.25 	
k 	: 	-2.8 	
w 	: 	0.18 	
umin 	: 	-20.0 	
umax 	: 	1.0
*/
char *descNaticaStellata = "";
#endif