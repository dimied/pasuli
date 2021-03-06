#ifndef __PASULI_CORNUCOPIA__
#define __PASULI_CORNUCOPIA__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CORNUCOPIA != 0)
void Cornucopia(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SHELLS != 0)
HEADER_DESC_PTR(descCornucopia)
#endif

#endif