#ifndef __PASULI_HECTOR_GUINARDS_SURFACE__
#define __PASULI_HECTOR_GUINARDS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HECTOR_GUINARDS_SURFACE != 0)
void HectorGuinardsSurface(pasuli_vartype u,
                           pasuli_vartype v,
                           pasuli_consttype *constants,
                           PaSuLiObject *pO);
#endif

#endif