#ifndef __PASULI_PSEUDOHELICERAS_SUBCATENATUM__
#define __PASULI_PSEUDOHELICERAS_SUBCATENATUM__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PSEUDOHELICERAS_SUBCATENATUM != 0)
void PseudohelicerasSubcatenatum(pasuli_vartype u,
                                 pasuli_vartype v,
                                 pasuli_consttype *constants,
                                 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SHELLS != 0)
HEADER_DESC_PTR(descPseudohelicerasSubcatenatum)
#endif

#endif