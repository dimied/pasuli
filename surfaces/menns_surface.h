#ifndef __PASULI_MENNS_SURFACE__
#define __PASULI_MENNS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MENNS_SURFACE != 0)
void MennsSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#endif