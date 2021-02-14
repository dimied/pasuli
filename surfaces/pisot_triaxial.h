#ifndef __PASULI_PISOT_TRIAXIAL__
#define __PASULI_PISOT_TRIAXIAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PISOT_TRIAXIAL != 0)
void PisotTriaxial(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#endif