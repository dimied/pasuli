#ifndef __PASULI_SNAILS__
#define __PASULI_SNAILS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SNAILS != 0)
void Snails(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO);
#endif

#endif