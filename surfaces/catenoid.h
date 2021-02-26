#ifndef __PASULI_CATENOID__
#define __PASULI_CATENOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CATENOID != 0)
void Catenoid(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCatenoid)
#endif
#endif