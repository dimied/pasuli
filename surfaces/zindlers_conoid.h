#ifndef __PASULI_ZINDLERS_CONOID__
#define __PASULI_ZINDLERS_CONOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ZINDLERS_CONOID != 0)
void ZindlersConoid(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO);
#endif

#endif