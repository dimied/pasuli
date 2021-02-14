#ifndef __PASULI_BONAN_JEENER_KLEIN_SURFACE__
#define __PASULI_BONAN_JEENER_KLEIN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BONAN_JEENER_KLEIN_SURFACE != 0)
void BonanJeenerKleinSurface(pasuli_vartype u, pasuli_vartype v,
							 pasuli_consttype *constants,
							 PaSuLiObject *pO);
#endif

#endif