#ifndef __PASULI_MILK_BAG__
#define __PASULI_MILK_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MILK_BAG != 0)
void MilkBag(double u, double v,
             double *constants,
             PaSuLiObject *pO);
#endif

#endif