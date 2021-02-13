#ifndef __PASULI_MONKEY_SADDLE__
#define __PASULI_MONKEY_SADDLE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MONKEY_SADDLE != 0)
void MonkeySaddle(double u, double v,
                  double *constants, PaSuLiObject *pO);
#endif

#endif