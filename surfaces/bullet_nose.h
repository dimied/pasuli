#ifndef __PASULI_BULLET_NOSE__
#define __PASULI_BULLET_NOSE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BULLET_NOSE != 0)
void BulletNose(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBulletNose)
#endif

#endif