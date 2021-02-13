#ifndef __PASULI_MAEDERS_OWL__
#define __PASULI_MAEDERS_OWL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MAEDERS_OWL != 0)
void MaedersOwl(double u, double v,
                double *constants, PaSuLiObject *pO);
#endif

#endif