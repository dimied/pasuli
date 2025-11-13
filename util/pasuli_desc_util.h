#ifndef __PASULI_DESC_UTIL__
#define __PASULI_DESC_UTIL__

#include "../pasuli_defs.h"

void initConstAll(PaSuLiObject *pO, pasuli_consttype value);

void copyDefDesc(PaSuLiDefDesc *pDD, int iSurfaceType,
				 unsigned int dstType, void *pRange, void *pConstants);
#endif