#ifndef __PASULI_JEENER_KLEIN_SURFACE__
#define __PASULI_JEENER_KLEIN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_JEENER_KLEIN_SURFACE != 0)
void JeenerKleinSurface(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO);
#endif

#endif