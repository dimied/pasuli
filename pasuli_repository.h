#ifndef __PASULI_FUNCTION_REPOSITORY__
#define __PASULI_FUNCTION_REPOSITORY__

#include "pasuli_cfg.h"
#include "pasuli_const.h"
#include "pasuli_defs.h"

extern unsigned int numberOfPasuliRepositoryItems;

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
int findDefaultConstants(unsigned int id, double* pConstants, int size);

#endif