#ifndef __SUPERFORMULA_3D_PARAMETRIC_SURFACE_
#define __SUPERFORMULA_3D_PARAMETRIC_SURFACE_

#include "../pasuli_defs.h"


#define PASULI_SF3D_SAVE_STATE		0
typedef PaSuLiObject		PaSuLiSF3DObject;

#define GET_UD_X			(pO->ud[0])
#define GET_UD_Y			(pO->ud[1])
#define GET_UD_Z			(pO->ud[2])
#define GET_VD_X			(pO->vd[0])
#define GET_VD_Y			(pO->vd[1])
#define GET_VD_Z			(pO->vd[2])

typedef float pasuli_sf3d_calctype;
typedef float pasuli_sf3d_vartype;
typedef float pasuli_sf3d_consttype;

#define PASULI_SF3D_OBJECT_POS			1
#define PASULI_SF3D_OBJECT_UD			1
#define PASULI_SF3D_OBJECT_VD			1
#define PASULI_SF3D_OBJECT_N			1
/**
* Only first derivatives and normal are available
*/
void SuperFormula3D(pasuli_sf3d_vartype rho, pasuli_sf3d_vartype phi,
					pasuli_sf3d_consttype* pConstants, PaSuLiSF3DObject* pO);

#define SUPER_FORMULA_PARAMETER_A_LOWER_BOUND		0.01
#define SUPER_FORMULA_PARAMETER_B_LOWER_BOUND		0.01
#define	SUPER_FORMULA_PARAMETER_A_UPPER_BOUND		10
#define	SUPER_FORMULA_PARAMETER_B_UPPER_BOUND		10

extern char* descSuperFormula3D;

const pasuli_consttype pasuli_sf3d_a_lower_bound = \
	SUPER_FORMULA_PARAMETER_A_LOWER_BOUND;
const pasuli_consttype pasuli_sf3d_a_upper_bound = \
	SUPER_FORMULA_PARAMETER_A_UPPER_BOUND;
const pasuli_consttype pasuli_sf3d_b_lower_bound = \
	SUPER_FORMULA_PARAMETER_B_LOWER_BOUND;
const pasuli_consttype pasuli_sf3d_b_upper_bound = \
	SUPER_FORMULA_PARAMETER_B_UPPER_BOUND;


//pConstants[0 .. 5] = a1, b1, m1, n11, n12, n13
//pConstants[6 .. 11] = a2, b2, m2, n21, n22, n23

#endif

