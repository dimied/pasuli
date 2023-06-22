#ifndef __PASULI_TORUS_DECLARATIONS__
#define __PASULI_TORUS_DECLARATIONS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TORUS != 0)
void Torus(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO);
#endif

#if (USE_TORUS_MESH != 0)
void TorusMesh(pasuli_vartype *pU,
		   pasuli_size_t uCount,
		   pasuli_vartype *pV,
		   pasuli_size_t vCount,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO);
#endif

#if (USE_TORUS_SAMPLE != 0)
void TorusSample(pasuli_vartype *pUV,
		   pasuli_size_t uvCount,
		   pasuli_consttype *pConstants,
		   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descTorus)
#endif

#endif
