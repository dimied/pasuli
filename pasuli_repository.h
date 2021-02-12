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

#endif