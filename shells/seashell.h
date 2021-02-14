#ifndef __PASULI_SEASHELL__
#define __PASULI_SEASHELL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SEASHELL != 0)
void Seashell(pasuli_vartype u,
			  pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#endif