#ifndef __PASULI_REPOSITORY_FUNCTIONS__
#define __PASULI_REPOSITORY_FUNCTIONS__

#include "../pasuli_cfg.h"
#include "../pasuli_const.h"
#include "../pasuli_defs.h"

#define IMPL_POS 0x1
#define IMPL_UD 0x2
#define IMPL_VD 0x4
#define IMPL_N 0x8
#define IMPL_UUD 0x10
#define IMPL_UVD 0x20
#define IMPL_VVD 0x40
#define IMPL_ALL 0x7F
#define IMPL_ONLY_POS_UD_VD (IMPL_POS | IMPL_UD | IMPL_VD)
#define IMPL_NORMAL_BY_CROSS_PRODUCT 0x80
#define IMPL_NO_BEGIN_NORMAL IMPL_ONLY_POS_UD_VD | IMPL_NORMAL_BY_CROSS_PRODUCT

#define IMPL_NO_2DERIV 0x0F

#define IMPL_MINUS(ALL_VAL, TO_SUBTRACT) (ALL_VAL - (TO_SUBTRACT))

/**
 * \brief Tries to find function for the given ID of the parametric surface
 * 
 * \param [in] id ID of the surface
 */
parsurFunc findPasuliFunctionById(unsigned int id);

/**
 * \brief Tries to find default constants for the function of the given ID 
 * of the parametric surface
 * 
 * \param [in] id ID of the surface
 */
int findDefaultConstants(unsigned int id, double *pConstants, int size);

/**
 * \brief Gives information about the implemetation state of the surface.
 * 
 * \param[in] id surface ID
 * 
 * \returns a value representing the implementation state of the function for
 * the given surface ID
 */
unsigned char getImplementationState(unsigned int id);

typedef struct
{
    unsigned char id;
    parsurFunc pFunc;
} PaSuLiRepositoryItem;

#ifndef PASULI_STORE_DESC_NAME
#define PASULI_STORE_DESC_NAME 1
#endif

#ifndef PASULI_STORE_DESC_TEXT
#define PASULI_STORE_DESC_TEXT 1
#endif

typedef struct
{
	/**
	 * Surfaces ID
	 */
	unsigned char ID;
#if (PASULI_STORE_DESC_NAME != 0)
	char *pszName;
#endif
	/**
	 * Pointer to text description
	 */
#if (PASULI_STORE_DESC_TEXT != 0)
	char **pszDesc;
#endif
} PaSuLiTextDescType;

#endif