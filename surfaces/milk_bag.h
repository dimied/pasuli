#ifndef __PASULI_MILK_BAG__
#define __PASULI_MILK_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MILK_BAG != 0)
void MilkBag(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO);
#endif

#endif