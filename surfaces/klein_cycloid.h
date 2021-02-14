#ifndef __PASULI_KLEIN_CYCLOID__
#define __PASULI_KLEIN_CYCLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KLEIN_CYCLOID != 0)
void KleinCycloid(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif