#ifndef __PASULI_MYA_ARENARIA__
#define __PASULI_MYA_ARENARIA__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MYA_ARENARIA != 0)
void MyaArenaria(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO);
#endif

#endif