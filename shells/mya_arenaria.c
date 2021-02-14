
#include "mya_arenaria.h"
#include "shells_c_includes.h"

#if (USE_MYA_ARENARIA != 0)
#include "snails.h"

pasuli_consttype MyaArenariaParams[] = {
    0.85f, 1.6f, 3.0f, 0.9f, 0, 2.5f};

void MyaArenaria(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO)
{

    //int k = 0;
    //double u , v;
    PASULI_SET_TYPE_ID(MYA_ARENARIA)
    Snails(u, v, &MyaArenariaParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddMyaArenaria = {
    PSLDD_ID(MYA_ARENARIA)
            PASULI_U_CLOSED |
        PASULI_V_CLOSED |
        PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(9) |
        PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
    -1, 0.52f, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
a : 0.85
b : 1.6 
	c 	: 	3.0 	
	h 	: 	0.9 	
	k 	: 	0 	
	w 	: 	2.5 	
	umin 	: 	-1.0 	
	umax 	: 	0.52
*/
char *descMyaArenaria = "";
#endif
