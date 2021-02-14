#ifndef __PASULI_VERSIERA_AGNESI_CYLINDER__
#define __PASULI_VERSIERA_AGNESI_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_VERSIERA_AGNESI_CYLINDER != 0)
void VersieraAgnesiCylinder(pasuli_vartype u,
							pasuli_vartype v,
							pasuli_consttype *constants,
							PaSuLiObject *pO);
#endif

#endif
