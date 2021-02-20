#ifndef __PASULI_MACRO_DEFINITIONS__
#define __PASULI_MACRO_DEFINITIONS__

#include "pasuli_cfg.h"

//#pragma warning(disable: 4244)

#define PASULI_USE_NORMAL_BY_CROSS_PRODUCT 1

#define PASULI_CALC_SIGN(F) ((F < 0) ? -1 : (F > 0 ? 1 : 0))

#define PASULI_CALC_FACTOR(F, CALC) \
	F = (CALC);                     \
	F = (F < 0) ? -1 : (F > 0 ? 1 : 0)

// Or 2*cos(v)^2-1
#define PASULI_TRIG_CALC_SUM_DIFFERENCE(C, S) (C * C - S * S)

// Position macros
#if (PASULIOBJECT_POS != 0)
#define P_X(V) pO->pos[0] = V
#define P_Y(V) pO->pos[1] = V
#define P_Z(V) pO->pos[2] = V
#define POS_OP(O) O
#else
#define P_X(V)
#define P_Y(V)
#define P_Z(V)
#define POS_OP(O)
#endif

// Macros for derivative with respect to U
#if (PASULIOBJECT_UD != 0)
#define UD_X(V)               \
	pasuli_calctype xu = (V); \
	pO->ud[0] = xu
#define UD_Y(V)               \
	pasuli_calctype yu = (V); \
	pO->ud[1] = yu
#define UD_Z(V)               \
	pasuli_calctype zu = (V); \
	pO->ud[2] = zu
#define UD_OP(O) O
#else

#if (PASULI_USE_NORMAL_BY_CROSS_PRODUCT != 1)
#define UD_X(V) pasuli_calctype xu = (V)
#define UD_Y(V) pasuli_calctype yu = (V)
#define UD_Z(V) pasuli_calctype zu = (V)

#else

#define UD_X(V)
#define UD_Y(V)
#define UD_Z(V)
#define UD_OP(O)
#endif

#endif

// Macros for derivative for V
#if (PASULIOBJECT_VD != 0)
#define VD_X(V)              \
	pasuli_vartype xv = (V); \
	pO->vd[0] = xv
#define VD_Y(V)              \
	pasuli_vartype yv = (V); \
	pO->vd[1] = yv
#define VD_Z(V)              \
	pasuli_vartype zv = (V); \
	pO->vd[2] = zv
#define VD_OP(O) O
#else
#if (PASULI_USE_NORMAL_BY_CROSS_PRODUCT != 1)
#define VD_X(V) pasuli_calctype xv = (V)
#define VD_Y(V) pasuli_calctype yv = (V)
#define VD_Z(V) pasuli_calctype zv = (V)

#else
#define VD_X(V)
#define VD_Y(V)
#define VD_Z(V)
#define VD_OP(O)
#endif
#endif

// Macros for Normal vector
#if (PASULIOBJECT_N != 0)
#define N_X(V) pO->n[0] = (V)
#define N_Y(V) pO->n[1] = (V)
#define N_Z(V) pO->n[2] = (V)
#define NORMAL_OP(O) O
#else
#define N_X(V)
#define N_Y(V)
#define N_Z(V)
#define NORMAL_OP(O)
#endif

#define MULTIPLY_NORMAL_BY_MINUS_ONE \
	pO->n[0] = -pO->n[0];            \
	pO->n[1] = -pO->n[1];            \
	pO->n[2] = -pO->n[2];

// Macros for 2.nd derivative with respect to U
#if (PASULIOBJECT_UUD != 0)
#define UUD_X(V) pO->uud[0] = V
#define UUD_Y(V) pO->uud[1] = V
#define UUD_Z(V) pO->uud[2] = V
#define UUD_ALL(V)  \
	pO->uud[0] = V; \
	pO->uud[1] = V; \
	pO->uud[2] = V
#define UUD_OP(O) O
#else
#define UUD_X(V)
#define UUD_Y(V)
#define UUD_Z(V)
#define UUD_ALL(V)
#define UUD_OP(O)
#endif

// Macros for 2.nd derivative with respect to U and V
#if (PASULIOBJECT_UVD != 0)
#define UVD_X(V) pO->uvd[0] = V
#define UVD_Y(V) pO->uvd[1] = V
#define UVD_Z(V) pO->uvd[2] = V
#define UVD_ALL(V)  \
	pO->uvd[0] = V; \
	pO->uvd[1] = V; \
	pO->uvd[2] = V;
#define UVD_OP(O) O
#else
#define UVD_X(V)
#define UVD_Y(V)
#define UVD_Z(V)
#define UVD_ALL(V)
#define UVD_OP(O)
#endif

// Macros for 2.nd derivative with respect to V
#if (PASULIOBJECT_VVD != 0)
#define VVD_X(V) pO->vvd[0] = V
#define VVD_Y(V) pO->vvd[1] = V
#define VVD_Z(V) pO->vvd[2] = V
#define VVD_ALL(V)  \
	pO->vvd[0] = V; \
	pO->vvd[1] = V; \
	pO->vvd[2] = V;
#define VVD_OP(O) O
#else
#define VVD_X(V)
#define VVD_Y(V)
#define VVD_Z(V)
#define VVD_ALL(V)
#define VVD_OP(O)
#endif

#if ((PASULIOBJECT_POS != 0) && (USE_INITCONST == 0))
#define P_X_CONST(V) pO->pos[0] = V
#define P_Y_CONST(V) pO->pos[1] = V
#define P_Z_CONST(V) pO->pos[2] = V
#else
#define P_X_CONST(V)
#define P_Y_CONST(V)
#define P_Z_CONST(V)
#endif

#if ((PASULIOBJECT_UD != 0) && (USE_INITCONST == 0))
#define UD_X_CONST(V) pO->ud[0] = V
#define UD_Y_CONST(V) pO->ud[1] = V
#define UD_Z_CONST(V) pO->ud[2] = V
#else
#define UD_X_CONST(V)
#define UD_Y_CONST(V)
#define UD_Z_CONST(V)
#endif

#if ((PASULIOBJECT_VD != 0) && (USE_INITCONST == 0))
#define VD_X_CONST(V) pO->vd[0] = V
#define VD_Y_CONST(V) pO->vd[1] = V
#define VD_Z_CONST(V) pO->vd[2] = V
#else
#define VD_X_CONST(V)
#define VD_Y_CONST(V)
#define VD_Z_CONST(V)
#endif

#if ((PASULIOBJECT_N != 0) && (USE_INITCONST == 0))
#define N_X_CONST(V) pO->n[0] = V
#define N_Y_CONST(V) pO->n[1] = V
#define N_Z_CONST(V) pO->n[2] = V
#else
#define N_X_CONST(V)
#define N_Y_CONST(V)
#define N_Z_CONST(V)
#endif

#if ((PASULIOBJECT_UUD != 0) && (USE_INITCONST == 0))
#define UUD_X_CONST(V) pO->uud[0] = V
#define UUD_Y_CONST(V) pO->uud[1] = V
#define UUD_Z_CONST(V) pO->uud[2] = V
#define UUD_CONST_ALL(V) \
	pO->uud[0] = V;      \
	pO->uud[1] = V;      \
	pO->uud[2] = V
#else
#define UUD_X_CONST(V)
#define UUD_Y_CONST(V)
#define UUD_Z_CONST(V)
#define UUD_CONST_ALL(V)
#endif

#if ((PASULIOBJECT_UVD != 0) && (USE_INITCONST == 0))
#define UVD_X_CONST(V) pO->uvd[0] = V
#define UVD_Y_CONST(V) pO->uvd[1] = V
#define UVD_Z_CONST(V) pO->uvd[2] = V
#define UVD_CONST_ALL(V) \
	pO->uvd[0] = V;      \
	pO->uvd[1] = V;      \
	pO->uvd[2] = V
#else
#define UVD_X_CONST(V)
#define UVD_Y_CONST(V)
#define UVD_Z_CONST(V)
#define UVD_CONST_ALL(V)
#endif

#if ((PASULIOBJECT_VVD != 0) && (USE_INITCONST == 0))
#define VVD_X_CONST(V) pO->vvd[0] = V
#define VVD_Y_CONST(V) pO->vvd[1] = V
#define VVD_Z_CONST(V) pO->vvd[2] = V
#define VVD_CONST_ALL(V) \
	pO->vvd[0] = V;      \
	pO->vvd[1] = V;      \
	pO->vvd[2] = V
#else
#define VVD_X_CONST(V)
#define VVD_Y_CONST(V)
#define VVD_Z_CONST(V)
#define VVD_CONST_ALL(V)
#endif

#define USE_PREPARED_POS 1

#if (USE_PREPARED_POS != 0)
#define PREPARE_POS_X(D) double tempX = D
#define ASSIGN_PREP_POS_X(D) tempX
#define PREPARE_POS_Y(D) double tempY = D
#define ASSIGN_PREP_POS_Y(D) tempY
#define PREPARE_POS_Z(D) double tempZ = D
#define ASSIGN_PREP_POS_Z(D) tempZ
#else
#define PREPARE_POS_X(D)
#define ASSIGN_PREP_POS_X(D) D
#define PREPARE_POS_Y(D)
#define ASSIGN_PREP_POS_Y(D) D
#define PREPARE_POS_Z(D)
#define ASSIGN_PREP_POS_Z(D) D
#endif

#if (PASULIOBJECT_POS != 0)
#define PASULI_COND_COPY_POS_X(D) (pO->pos[0])
#define PASULI_COND_COPY_POS_Y(D) (pO->pos[1])
#define PASULI_COND_COPY_POS_Z(D) (pO->pos[2])
#else
#define PASULI_COND_COPY_POS_X(D) (D)
#define PASULI_COND_COPY_POS_Y(D) (D)
#define PASULI_COND_COPY_POS_Z(D) (D)
#endif

#if (PASULIOBJECT_UD != 0)
#define PASULI_COND_COPY_UD_X(D) (pO->ud[0])
#define PASULI_COND_COPY_UD_Y(D) (pO->ud[1])
#define PASULI_COND_COPY_UD_Z(D) (pO->ud[2])
#else
#define PASULI_COND_COPY_UD_X(D) (D)
#define PASULI_COND_COPY_UD_Y(D) (D)
#define PASULI_COND_COPY_UD_Z(D) (D)
#endif

#if (PASULIOBJECT_VD != 0)
#define PASULI_COND_COPY_VD_X(D) (pO->vd[0])
#define PASULI_COND_COPY_VD_Y(D) (pO->vd[1])
#define PASULI_COND_COPY_VD_Z(D) (pO->vd[2])
#else
#define PASULI_COND_COPY_VD_X(D) (D)
#define PASULI_COND_COPY_VD_Y(D) (D)
#define PASULI_COND_COPY_VD_Z(D) (D)
#endif

#if (PASULIOBJECT_N != 0)
#define PASULI_COND_COPY_N_X(D) (pO->n[0])
#define PASULI_COND_COPY_N_Y(D) (pO->n[1])
#define PASULI_COND_COPY_N_Z(D) (pO->n[2])
#else
#define PASULI_COND_COPY_N_X(D) (D)
#define PASULI_COND_COPY_N_Y(D) (D)
#define PASULI_COND_COPY_N_Z(D) (D)
#endif

#if (PASULIOBJECT_UUD != 0)
#define PASULI_COND_COPY_UUD_X(D) (pO->uud[0])
#define PASULI_COND_COPY_UUD_Y(D) (pO->uud[1])
#define PASULI_COND_COPY_UUD_Z(D) (pO->uud[2])
#else
#define PASULI_COND_COPY_UUD_X(D) (D)
#define PASULI_COND_COPY_UUD_Y(D) (D)
#define PASULI_COND_COPY_UUD_Z(D) (D)
#endif

#if (PASULIOBJECT_UVD != 0)
#define PASULI_COND_COPY_UVD_X(D) (pO->uvd[0])
#define PASULI_COND_COPY_UVD_Y(D) (pO->uvd[1])
#define PASULI_COND_COPY_UVD_Z(D) (pO->uvd[2])
#else
#define PASULI_COND_COPY_UVD_X(D) (D)
#define PASULI_COND_COPY_UVD_Y(D) (D)
#define PASULI_COND_COPY_UVD_Z(D) (D)
#endif

#if (PASULIOBJECT_VVD != 0)
#define PASULI_COND_COPY_VVD_X(D) (pO->vvd[0])
#define PASULI_COND_COPY_VVD_Y(D) (pO->vvd[1])
#define PASULI_COND_COPY_VVD_Z(D) (pO->vvd[2])
#else
#define PASULI_COND_COPY_VVD_X(D) (D)
#define PASULI_COND_COPY_VVD_Y(D) (D)
#define PASULI_COND_COPY_VVD_Z(D) (D)
#endif

#define PASULI_NORMAL      \
	N_X(yu *zv - zu * yv); \
	N_Y(xu *zv - zu * xv); \
	N_Z(xu *yv - yu * xv);

#define PASULI_CALC_NORMAL_FROM_UD_VD \
	N_X(yu *zv - zu * yv);            \
	N_Y(xu *zv - zu * xv);            \
	N_Z(xu *yv - yu * xv);
//PASULI_NORMAL_VARS_DEF
//PASULI_NORMAL

#define PASULI_2ND_DERIVATIVES_START \
	if (1 == 1)                      \
	{
#define PASULI_2ND_DERIVATIVES_END }

#endif
