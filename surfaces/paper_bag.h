#ifndef __PASULI_PAPER_BAG__
#define __PASULI_PAPER_BAG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PAPER_BAG != 0)
void PaperBag(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif