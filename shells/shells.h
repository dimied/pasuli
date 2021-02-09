#ifndef __PARAMETRIC_SURFACE_SHELLS_DECLARATIONS__
#define __PARAMETRIC_SURFACE_SHELLS_DECLARATIONS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"
#include "shells_desc.h"
#include <math.h>

#if(COMPILE_SHELLS != 0)

void Cornucopia(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Snail(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Seashell(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void SnailSurface(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Snails(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void PseudohelicerasSubcatenatum(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Astroceras(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Bellerophina(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Euhoplites(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void Nautilus(double u, double v, 
			  double* constants, PaSuLiObject* pO);

void NaticaStellata(double u, double v, 
					double* constants, PaSuLiObject* pO);

void MyaArenaria(double u, double v, 
			  double* constants, PaSuLiObject* pO);

#endif




#endif


