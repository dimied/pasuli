#ifndef __PASULI_ISOLATOR__
#define __PASULI_ISOLATOR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ISOLATOR != 0)
void Isolator(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descIsolator)
#endif

#endif