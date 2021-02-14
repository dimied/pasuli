#ifndef __PASULI_FRESNEL__
#define __PASULI_FRESNEL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FRESNEL != 0)
void Fresnel(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO);
#endif

#endif