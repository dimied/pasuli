#ifndef __PASULI_EPIZYKLOID_CYLINDER__
#define __PASULI_EPIZYKLOID_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EPIZYKLOID_CYLINDER != 0)
void EpizykloidCylinder(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_CYLINDER!= 0)
HEADER_DESC_PTR(descEpizykloidCylinder)
#endif

#endif