#ifndef __PASULI_SPHERE_ALL_SURFACES__
#define __PASULI_SPHERE_ALL_SURFACES__

#include "ellipsoid.h"
#include "open_sphere.h"
#include "pseudosphere.h"
#include "sphere.h"
#include "sphere_v.h"
#include "sphere_uv.h"
#include "twisted_sphere.h"
#include "wave_sphere.h"
#include "wrinkle_sphere.h"
#include "wrinkle_sphere2.h"

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