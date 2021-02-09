#ifndef __PARAMETRIC_SURFACE_LIBRARY_FRUITS_FUNCTION_DECLARATIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_FRUITS_FUNCTION_DECLARATIONS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"
#include "fruits_desc.h"
#include <math.h>


#if(COMPILE_FRUITS != 0)

void KidneySurface(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void AppleSurface(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);


void Apple2_Surface(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);


void LemonSurface(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

#endif


#endif


