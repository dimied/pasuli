#ifndef __PARAMETRIC_SURFACE_SHELLS_DECLARATIONS__
#define __PARAMETRIC_SURFACE_SHELLS_DECLARATIONS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"

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


#if(COMPILE_DESC_SHELLS != 0)

extern char* descCornucopia;
extern char* descSnail;
extern char* descSeashell;
extern char* descSnailSurface;
extern char* descSnails;
extern char* descPseudohelicerasSubcatenatum;
extern char* descAstroceras;
extern char* descBellerophina;
extern char* descEuhoplites;
extern char* descNautilus;
extern char* descNaticaStellata;
extern char* descMyaArenaria;
#endif


#if(COMPILE_DEF_DESC_SHELLS != 0)
extern PaSuLiDefDesc pslddCornucopia;
extern PaSuLiDefDesc pslddSnail;
extern PaSuLiDefDesc pslddSeashell;
extern PaSuLiDefDesc pslddSnailSurface;
extern PaSuLiDefDesc pslddSnails;
extern PaSuLiDefDesc pslddPseudohelicerasSubcatenatum;
extern PaSuLiDefDesc pslddAstroceras;
extern PaSuLiDefDesc pslddBellerophina;
extern PaSuLiDefDesc pslddEuhoplites;
extern PaSuLiDefDesc pslddNautilus;
extern PaSuLiDefDesc pslddNaticaStellata;
extern PaSuLiDefDesc pslddMyaArenaria;
#endif

#endif
