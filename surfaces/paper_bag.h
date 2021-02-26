#ifndef __PASULI_PAPER_BAG__
#define __PASULI_PAPER_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PAPER_BAG != 0)
void PaperBag(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descPaperBag)
#endif

#endif