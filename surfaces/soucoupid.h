#ifndef __PASULI_SOUCOUPOID__
#define __PASULI_SOUCOUPOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SOUCOUPOID != 0)
void Soucoupoid(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSoucoupoid)
#endif

#endif