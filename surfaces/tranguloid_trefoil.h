#ifndef __PASULI_TRANGULOID_TREFOIL__
#define __PASULI_TRANGULOID_TREFOIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRANGULOID_TREFOIL != 0)
void TranguloidTrefoil(pasuli_vartype u, pasuli_vartype v,
					   pasuli_consttype *constants,
					   PaSuLiObject *pO);
#endif

#endif