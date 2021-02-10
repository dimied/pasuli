#ifndef __PARAMETRIC_SURFACE_LIBRARY_CYLINDER_DESCRIPTION_HEADER_INCL__
#define __PARAMETRIC_SURFACE_LIBRARY_CYLINDER_DESCRIPTION_HEADER_INCL__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"

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

