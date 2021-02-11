#ifndef __PASULI_APPROXIMATION_PART_INCLUDED__
#define __PASULI_APPROXIMATION_PART_INCLUDED__

#include "pasuli_defs.h"


#define PASULI_APPROX_DIFFERENCE		0.0001

typedef double pasuli_approx_type;

void approximatePaSuLi(int whatToApproximate, 
					pasuli_vartype u, 
					pasuli_vartype v,
					pasuli_consttype* pC, 
					PaSuLiObject* pO,
					parsurFunc f);

#define PASULI_APPROXIMATE_UD	1
#define PASULI_APPROXIMATE_VD	2
#define PASULI_APPROXIMATE_N	4
#define PASULI_APPROXIMATE_UUD	8
#define PASULI_APPROXIMATE_UVD	0x10
#define PASULI_APPROXIMATE_VVD	0x20
#define PASULI_APPROXIMATE_ALL	0x3F

#endif


