#ifndef __PASULI_CYLINDER__
#define __PASULI_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"


void Cylinder(pasuli_vartype u, pasuli_vartype v, 
			pasuli_consttype* constants, PaSuLiObject* pO);

void EpizykloidCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void HypozykloidCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void LemniskateCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);


void StrophoideCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);


void ZissoideCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void VersieraAgnesiCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

void GaussCylinder(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO);


//void initConstCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
//void initConstEpizykloidCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstHypozykloidCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstLemniskateCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstStrophoideCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstZissoideCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstVersieraAgnesiCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstGaussCylinder(PaSuLiObject* pO, pasuli_consttype* constants);

#if(COMPILE_DESC_CYLINDER != 0)
extern char* descCylinder;
extern char* descEpizykloidCylinder;
extern char* descHypozykloidCylinder;
extern char* descLemniskateCylinder;
extern char* descStrophoideCylinder;
extern char* descZissoideCylinder;
extern char* descVACylinder;
extern char* descGaussCylinder;
#endif

#if(COMPILE_DEF_DESC_CYLINDER != 0)
extern PaSuLiDefDesc pslddCylinder;
extern PaSuLiDefDesc pslddEpizykloidCylinder;
extern PaSuLiDefDesc pslddHypozykloidCylinder;
extern PaSuLiDefDesc pslddLemniskateCylinder;
extern PaSuLiDefDesc pslddStrophoideCylinder;
extern PaSuLiDefDesc pslddZissoideCylinder;
extern PaSuLiDefDesc pslddVACylinder;
extern PaSuLiDefDesc pslddGaussCylinder;
#endif

#endif


