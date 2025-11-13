#ifndef __PASULI_PSEUDODEVELOPABLE_HELICOID__
#define __PASULI_PSEUDODEVELOPABLE_HELICOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PSEUDODEVELOPABLE_HELICOID != 0)
void PseudodevelopableHelicoid(pasuli_vartype u,
                               pasuli_vartype v,
                               pasuli_consttype *constants,
                               PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descPseudodevelopableHelicoid)
#endif

#endif