
#include "nautilus.h"
#include "shells_c_includes.h"

#if (USE_NAUTILUS != 0)

#include "snails.h"

pasuli_consttype NautilusParams[] = {
	1.0f, 0.6f, 1.0f, 1.0f, 0.0f, 0.18f};

void Nautilus(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO)
{

	//int k = 0;
	//double u , v;
	PASULI_SET_TYPE_ID(NAUTILUS)
	Snails(u, v, &NautilusParams[0], pO);
}
#endif

#if (COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddNautilus = {
	PSLDD_ID(NAUTILUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_V_END_PI | PASULI_CONST_CONSTANTS | PASULI_CONST_COUNT(2) |
		PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
	-20, 1, 0, 2, 0};
#endif
#if (COMPILE_DESC_SHELLS != 0)
/**
a : 1.0
b : 0.6
c 	: 	1.0 	
h 	: 	1.0 	
k 	: 	0.0 	
w 	: 	0.18 	
umin 	: -20.0 	
umax 	: 	1.0
*/
char *descNautilus = "";
#endif