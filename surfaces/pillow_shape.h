#ifndef __PASULI_PILLOW_SHAPE__
#define __PASULI_PILLOW_SHAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PILLOW_SHAPE != 0)
void PillowShape(pasuli_vartype u, pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#endif