#ifndef __PARAMETRIC_SURFACE_LIBRARY_SPIRAL_DESCRIPTION_HEADER_INCL__
#define __PARAMETRIC_SURFACE_LIBRARY_SPIRAL_DESCRIPTION_HEADER_INCL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if(COMPILE_DESC_SPIRAL != 0)
extern char* descArchimedicSpiral;
extern char* descHyperbolicSpiral;
extern char* descFermatSpiral;
extern char* descTanhSpiral;
extern char* descLogSpiral;
#endif



#if(COMPILE_DEF_DESC_SPIRAL != 0)
extern PaSuLiDefDesc pslddArchimedicSpiral;
extern PaSuLiDefDesc pslddHyperbolicSpiral;
extern PaSuLiDefDesc pslddFermatSpiral;
extern PaSuLiDefDesc pslddTanhSpiral;
extern PaSuLiDefDesc pslddLogSpiral;
#endif


#endif

