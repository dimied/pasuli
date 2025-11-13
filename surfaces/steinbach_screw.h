#ifndef __PASULI_STEINBACH_SCREW__
#define __PASULI_STEINBACH_SCREW__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_STEINBACH_SCREW != 0)
void SteinbachScrew(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSteinbachScrew)
#endif

#endif