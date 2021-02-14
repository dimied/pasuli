#ifndef __PASULI_ARCHIMEDIC_SPIRAL__
#define __PASULI_ARCHIMEDIC_SPIRAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ARCHIMEDIC_SPIRAL != 0)
void ArchimedicSpiral(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif