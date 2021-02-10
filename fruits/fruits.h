#ifndef __PARAMETRIC_SURFACE_LIBRARY_FRUITS_FUNCTION_DECLARATIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_FRUITS_FUNCTION_DECLARATIONS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

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


#if(COMPILE_DESC_FRUITS != 0)

extern char* descKidneySurface;
extern char* descAppleSurface;
extern char* descApple2_Surface;
extern char* descLemonSurface;
#endif

#if(COMPILE_DEF_DESC_FRUITS != 0)

extern PaSuLiDefDesc pslddKidneySurface;
extern PaSuLiDefDesc pslddAppleSurface;
extern PaSuLiDefDesc pslddApple2_Surface;
extern PaSuLiDefDesc pslddLemonSurface;
#endif

#endif
