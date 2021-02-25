#ifndef __PASULI_MONKEY_SADDLE2__
#define __PASULI_MONKEY_SADDLE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MONKEY_SADDLE2 != 0)
void MonkeySaddle2(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif