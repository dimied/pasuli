#ifndef __PASULI_TRIPLE_POINT_TWIST__
#define __PASULI_TRIPLE_POINT_TWIST__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_POINT_TWIST != 0)
void TriplePointTwist(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif