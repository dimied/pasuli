#ifndef __PASULI_GOBLET__
#define __PASULI_GOBLET__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_GOBLET != 0)
void Goblet(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descGoblet)
#endif

#endif