#ifndef __PASULI_SNAILS__
#define __PASULI_SNAILS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#define USE_SNAILS_SOMEWHERE (USE_SNAILS != 0) || (USE_ASTROCERAS != 0) || (USE_BELLEROPHINA != 0) || (USE_EUHOPLITES != 0) || (USE_MYA_ARENARIA != 0) || (USE_NATICA_STELLATA != 0) || (USE_NAUTILUS != 0) || (USE_PSEUDOHELICERAS_SUBCATENATUM != 0)

#if (USE_SNAILS_SOMEWHERE)
void Snails(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO);
#endif

#endif