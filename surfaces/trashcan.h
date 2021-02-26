#ifndef __PASULI_TRASHCAN__
#define __PASULI_TRASHCAN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRASHCAN != 0)
void Trashcan(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTrashcan)
#endif

#endif