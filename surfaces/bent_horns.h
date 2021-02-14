#ifndef __PASULI_BENT_HORNS__
#define __PASULI_BENT_HORNS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BENT_HORNS != 0)
void BentHorns(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO);
#endif

#endif