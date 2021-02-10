#ifndef __PASULI_SPIRAL__
#define __PASULI_SPIRAL__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"

#if(COMPILE_SPIRAL != 0)

void ArchimedicSpiral(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void HyperbolicSpiral(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void FermatSpiral(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void TanhSpiral(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void LogSpiral(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

#endif

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


