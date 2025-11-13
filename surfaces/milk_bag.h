#ifndef __PASULI_MILK_BAG__
#define __PASULI_MILK_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MILK_BAG != 0)
void MilkBag(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descMilkBag)
#endif

#endif