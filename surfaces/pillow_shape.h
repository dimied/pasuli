#ifndef __PASULI_PILLOW_SHAPE__
#define __PASULI_PILLOW_SHAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PILLOW_SHAPE != 0)
void PillowShape(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif