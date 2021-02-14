#ifndef __PASULI_NAUTILUS__
#define __PASULI_NAUTILUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_NAUTILUS != 0)
void Nautilus(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#endif