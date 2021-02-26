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

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descMonkeySaddle2)
#endif
#endif