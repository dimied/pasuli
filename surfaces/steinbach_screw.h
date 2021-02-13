#ifndef __PASULI_STEINBACH_SCREW__
#define __PASULI_STEINBACH_SCREW__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_STEINBACH_SCREW != 0)
void SteinbachScrew(double u, double v,
                    double *constants, PaSuLiObject *pO);
#endif

#endif