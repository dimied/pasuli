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

#endif