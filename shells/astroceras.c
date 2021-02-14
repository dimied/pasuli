
#include "astroceras.h"
#include "shells_c_includes.h"

#if (USE_ASTROCERAS != 0)
#include "snails.h"

pasuli_consttype AstrocerasParams[] = {
	1.25f, 1.25f, 1.0f, 3.5f, 0.0f, 0.12f};

void Astroceras(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{

	//int k = 0;
	//double u , v;
	Snails(u, v, &AstrocerasParams[0], pO);
	PASULI_SET_TYPE_ID(ASTROCERAS)
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
/**
a : 1.25
b : 1.25 
c 	: 	1.0 	
h 	: 	3.5 	
k 	: 	0.0 	
w 	: 	0.12 	
umin 	: 	-40.0 	
umax 	: 	-1.0
*/
char *descAstroceras = "";
#endif