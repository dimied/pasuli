#ifndef __PASULI_CATENOID__
#define __PASULI_CATENOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CATENOID != 0)
void Catenoid(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif