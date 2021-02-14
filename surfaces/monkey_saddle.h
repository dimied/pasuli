#ifndef __PASULI_MONKEY_SADDLE__
#define __PASULI_MONKEY_SADDLE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MONKEY_SADDLE != 0)
void MonkeySaddle(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif