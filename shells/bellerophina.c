
#include "bellerophina.h"
#include "shells_c_includes.h"

#if (USE_BELLEROPHINA != 0)
#include "snails.h"

pasuli_consttype BellerophinaParams[] = {
    0.85f, 1.2f, 1.0f, 0.75f, 0.0f, 0.06f};

void Bellerophina(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO)
{

    //int k = 0;
    //double u , v;
    PASULI_SET_TYPE_ID(BELLEROPHINA)
    Snails(u, v, &BellerophinaParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddBellerophina = {
	PSLDD_ID(BELLEROPHINA)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
		PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
	-10, -1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
a : 0.85
b : 1.2 
c 	: 	1.0 	
h 	: 	0.75 	
k 	: 	0.0 	
w 	: 	0.06 	
umin 	: 	-10.0 	
umax 	: 	-1.0
*/
char *descBellerophina = "";
#endif