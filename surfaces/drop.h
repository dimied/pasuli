#ifndef __PASULI_DROP__
#define __PASULI_DROP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DROP != 0)
void Drop(pasuli_vartype u, pasuli_vartype v, 
			  double* constants, 
			  PaSuLiObject* pO);
#endif

#endif