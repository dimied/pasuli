#ifndef __PASULI_EUHOPLITES__
#define __PASULI_EUHOPLITES__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EUHOPLITES != 0)
void Euhoplites(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SHELLS != 0)
HEADER_DESC_PTR(descEuhoplites)
#endif

#endif