#ifndef __PASULI_SPHERE__
#define __PASULI_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#include "ellipsoid.h"
#include "open_sphere.h"
#include "pseudosphere.h"
#include "sphere_v.h"
#include "sphere_uv.h"
#include "twisted_sphere.h"
#include "wave_sphere.h"

#if (USE_SPHERE != 0)
void Sphere(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPHERE != 0)
extern char *descSphere;
extern char *descEllipsoid;
extern char *descSphereV;
extern char *descOpenSphere;
extern char *descSphereUV;
extern char *descTwistedSphere;
extern char *descWaveSphere;
extern char *descPseudoSphere;
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
extern PaSuLiDefDesc pslddSphere;
extern PaSuLiDefDesc pslddEllipsoid;
extern PaSuLiDefDesc pslddSphereV;
extern PaSuLiDefDesc pslddOpenSphere;
extern PaSuLiDefDesc pslddSphereUV;
extern PaSuLiDefDesc pslddTwistedSphere;
extern PaSuLiDefDesc pslddWaveSphere;
extern PaSuLiDefDesc pslddPseudoSphere;
#endif

#endif
