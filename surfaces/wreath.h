#ifndef __PASULI_WREATH__
#define __PASULI_WREATH__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WREATH != 0)
void Wreath(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descWreath)
#endif

#endif