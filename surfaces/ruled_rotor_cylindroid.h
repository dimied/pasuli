#ifndef __PASULI_RULED_ROTOR_CYLINDROID__
#define __PASULI_RULED_ROTOR_CYLINDROID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_RULED_ROTOR_CYLINDROID != 0)
void RuledRotorCylindroid(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descRuledRotorCylindroid)
#endif

#endif