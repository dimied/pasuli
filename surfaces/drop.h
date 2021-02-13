#ifndef __PASULI_DROP__
#define __PASULI_DROP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DROP != 0)
void Drop(double u, double v, 
			  double* constants, 
			  PaSuLiObject* pO);
#endif

#endif