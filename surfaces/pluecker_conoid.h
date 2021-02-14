#ifndef __PASULI_PLUECKER_CONOID__
#define __PASULI_PLUECKER_CONOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLUECKER_CONOID != 0)
void PlueckerConoid(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif