#ifndef __PASULI_BOWTIE__
#define __PASULI_BOWTIE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOWTIE != 0)
void Bowtie(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO);
#endif

#endif