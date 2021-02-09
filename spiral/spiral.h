#ifndef __SPIRAL_
#define __SPIRAL_

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"
#include "spiral_desc.h"
#include <math.h>

#if(COMPILE_SPIRAL != 0)

void ArchimedicSpiral(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void HyperbolicSpiral(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void FermatSpiral(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void TanhSpiral(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void LogSpiral(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

#endif


#endif


