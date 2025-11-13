#ifndef __PASULI_VASE_HEAD__
#define __PASULI_VASE_HEAD__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_VASE_HEAD != 0)
void VaseHead(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descVaseHead)
#endif

#endif