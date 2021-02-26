#ifndef __PASULU_SPLINES__
#define __PASULU_SPLINES__

#include "../pasuli_defs.h"

void eval_BSpline(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);

void evaluate_BSpline();

#endif