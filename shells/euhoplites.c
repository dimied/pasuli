
#include "euhoplites.h"
#include "shells_c_includes.h"

#if (USE_EUHOPLITES != 0)

#include "snails.h"

pasuli_consttype EuhoplitesParams[] = {
	0.6f, 0.4f, 1.0f, 0.9f, 0.0f, 0.1626f};

void Euhoplites(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{

	//int k = 0;
	//double u , v;
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
/**
a : 0.6
b : 0.4 
c 	: 	1.0 	
h 	: 	0.9 	
k 	: 	0.0 	
w 	: 	0.1626 	
umin 	: 	-40.0 	
umax 	: 	-1.0
*/
char *descEuhoplites = "";
#endif
