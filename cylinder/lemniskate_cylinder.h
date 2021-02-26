#ifndef __PASULI_LEMNISKATE_CYLINDER__
#define __PASULI_LEMNISKATE_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LEMNISKATE_CYLINDER != 0)
void LemniskateCylinder(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_CYLINDER != 0)
HEADER_DESC_PTR(descLemniskateCylinder)
#endif

#endif