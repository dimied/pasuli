#ifndef __PASULI_FRUITS__
#define __PASULI_FRUITS__

#include "apple_surface.h"
#include "apple2_surface.h"
#include "kidney_surface.h"
#include "lemon_surface.h"

extern pasulidefdesc_ct def_fruits_constants[2];

#if (COMPILE_DESC_FRUITS != 0)

extern char *descKidneySurface;
extern char *descAppleSurface;
extern char *descApple2_Surface;
extern char *descLemonSurface;
#endif

#if (COMPILE_DEF_DESC_FRUITS != 0)

extern PaSuLiDefDesc pslddKidneySurface;
extern PaSuLiDefDesc pslddAppleSurface;
extern PaSuLiDefDesc pslddApple2_Surface;
extern PaSuLiDefDesc pslddLemonSurface;
#endif

#endif
