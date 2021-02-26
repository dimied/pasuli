#ifndef __PASULI_SPIRAL__
#define __PASULI_SPIRAL__

#include "../pasuli_defs.h"
#include "archimedic_spiral.h"
#include "fermat_spiral.h"
#include "hyperbolic_spiral.h"
#include "log_spiral.h"
#include "tanh_spiral.h"

#if (COMPILE_DEF_DESC_SPIRAL != 0)
extern PaSuLiDefDesc pslddArchimedicSpiral;
extern PaSuLiDefDesc pslddHyperbolicSpiral;
extern PaSuLiDefDesc pslddFermatSpiral;
extern PaSuLiDefDesc pslddTanhSpiral;
extern PaSuLiDefDesc pslddLogSpiral;
#endif

#endif
