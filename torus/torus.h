#ifndef __PARAMETRIC_SURFACE_LIBRARY_TORUS_DECLARATIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_TORUS_DECLARATIONS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"
#include "torus_desc.h"
#include <math.h>


#if(COMPILE_TORUS != 0)

void Torus(pasuli_vartype u, pasuli_vartype v, 
			pasuli_consttype* constants, PaSuLiObject* pO);



void EightTorus(pasuli_vartype u, pasuli_vartype v ,
				pasuli_consttype* constants, PaSuLiObject* pO);

void TwistedEightTorus(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void UmbillicTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void WaveTorus(pasuli_vartype u, pasuli_vartype v, 
			  pasuli_consttype* constants, PaSuLiObject* pO);

void EllipticTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void SaddleTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);	//?!?

void BraidedTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void LimpetTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void StrangledTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void AstroidTorus(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void TricuspoidTorus1(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void TricuspoidTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void NethroidTorus1(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void NethroidTorus2(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void LemniskateTorus1(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void LemniskateTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void EpizykloidTorus1(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void EpizykloidTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void HypozykloidTorus1(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void HypozykloidTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void PiriformTorus1(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void PiriformTorus2(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void BicornTorus1(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void BicornTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void CardioidTorus1(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void CardioidTorus2(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);

void CassinianOvalTorus1(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void CassinianOvalTorus2(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void GeronoLemniskateTorus1(pasuli_vartype u, pasuli_vartype v, 
							pasuli_consttype* constants, PaSuLiObject* pO);

void GeronoLemniskateTorus2(pasuli_vartype u, pasuli_vartype v, 
							pasuli_consttype* constants, PaSuLiObject* pO);

void CurlyTorus1(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void CurlyTorus2(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void SpiralTorus(pasuli_vartype u, pasuli_vartype v, 
				pasuli_consttype* constants, PaSuLiObject* pO);

void TorusKnot(pasuli_vartype u, pasuli_vartype v, 
			  pasuli_consttype* constants, PaSuLiObject* pO);

void GearTorus(pasuli_vartype u, pasuli_vartype v, 
			  pasuli_consttype* constants, PaSuLiObject* pO);

#endif

#if(COMPILE_DESC_TORUS != 0)
	extern char* descTorus;
#endif


#endif




