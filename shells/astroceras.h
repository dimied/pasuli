#ifndef __PASULI_ASTROCERAS__
#define __PASULI_ASTROCERAS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ASTROCERAS != 0)
void Astroceras(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SHELLS != 0)
HEADER_DESC_PTR(descAstroceras)
#endif

#endif