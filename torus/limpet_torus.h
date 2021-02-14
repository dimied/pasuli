#ifndef __PASULI_LIMPET_TORUS__
#define __PASULI_LIMPET_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descLimpetTorus;

#if (USE_LIMPET_TORUS != 0)
void LimpetTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#endif