#ifndef __PASULI_DUPIN_CYCLIDE__
#define __PASULI_DUPIN_CYCLIDE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DUPIN_CYCLIDE != 0)
void DupinCyclide(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#endif