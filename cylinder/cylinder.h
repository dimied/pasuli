#ifndef __PASULI_CYLINDER_
#define __PASULI_CYLINDER_

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"
#include "cylinder_desc.h"
#include <math.h>


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


void initConstCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstEpizykloidCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstHypozykloidCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstLemniskateCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstStrophoideCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstZissoideCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstVersieraAgnesiCylinder(PaSuLiObject* pO, pasuli_consttype* constants);
void initConstGaussCylinder(PaSuLiObject* pO, pasuli_consttype* constants);


#endif


