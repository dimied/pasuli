#ifndef __PASULI_PAPER_BAG__
#define __PASULI_PAPER_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PAPER_BAG != 0)
void PaperBag(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#endif