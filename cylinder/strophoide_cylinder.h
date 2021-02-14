#ifndef __PASULI_STROPHOIDE_CYLINDER__
#define __PASULI_STROPHOIDE_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_STROPHOIDE_CYLINDER != 0)
void StrophoideCylinder(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO);
#endif

#endif