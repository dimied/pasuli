#ifndef __PASULI_HELICOID__
#define __PASULI_HELICOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HELICOID != 0)
void Helicoid(double u, double v,
              double *constants, PaSuLiObject *pO);
#endif

#endif