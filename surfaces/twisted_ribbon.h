#ifndef __PASULI_TWISTED_RIBBON__
#define __PASULI_TWISTED_RIBBON__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_RIBBON != 0)
void TwistedRibbon(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTwistedRibbon)
#endif

#endif