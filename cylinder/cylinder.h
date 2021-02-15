#ifndef __PASULI_CYLINDER__
#define __PASULI_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CYLINDER != 0)
void Cylinder(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_CYLINDER != 0)
extern char *descCylinder;
extern char *descEpizykloidCylinder;
extern char *descHypozykloidCylinder;
extern char *descLemniskateCylinder;
extern char *descStrophoideCylinder;
extern char *descZissoideCylinder;
extern char *descVersieraAgnesiCylinder;
extern char *descGaussCylinder;
#endif

#if (COMPILE_DEF_DESC_CYLINDER != 0)
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
