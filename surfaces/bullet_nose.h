#ifndef __PASULI_BULLET_NOSE__
#define __PASULI_BULLET_NOSE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BULLET_NOSE != 0)
void BulletNose(double u, double v,
                double *constants,
                PaSuLiObject *pO);
#endif

#endif