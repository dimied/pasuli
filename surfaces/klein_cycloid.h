#ifndef __PASULI_KLEIN_CYCLOID__
#define __PASULI_KLEIN_CYCLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KLEIN_CYCLOID != 0)
void KleinCycloid(double u, double v,
                  double *constants,
                  PaSuLiObject *pO);
#endif

#endif