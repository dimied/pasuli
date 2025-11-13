#ifndef __PASULI_ANTISYMMETRIC_TORUS__
#define __PASULI_ANTISYMMETRIC_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ANTISYMMETRIC_TORUS != 0)
void AntisymmetricTorus(pasuli_vartype u,
						pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO);
#endif

#if (USE_ANTISYMMETRIC_TORUS != 0)
void AntisymmetricTorusArr(
						pasuli_vartype *pU,
						pasuli_size_t uCount,
						pasuli_vartype *pV,
						pasuli_size_t vCount,
						pasuli_consttype *constants,
						PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descAntisymmetricTorus)
#endif

#endif