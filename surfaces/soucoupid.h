#ifndef __PASULI_SOUCOUPOID__
#define __PASULI_SOUCOUPOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SOUCOUPOID != 0)
void Soucoupoid(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif