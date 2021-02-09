#ifndef __PARAMETRIC_SURFACE_LIBRARY_VERSION_1_0_0_DEFS__
#define __PARAMETRIC_SURFACE_LIBRARY_VERSION_1_0_0_DEFS__

#include "../particle.h"				//Addoption to my ba..thesis

#define PASULI_FLOAT				0x1
#define PASULI_DOUBLE				0x2
#define PASULI_TYPE_DEF_BIT_LENGTH	0x2

#define MY_PI						3.14159265358979323846f
#define MY_PI_HALF					MY_PI*0.5f

#define PASULIOBJECT_POS	1
#define PASULIOBJECT_UD		1
#define PASULIOBJECT_VD		1
#define PASULIOBJECT_N		1
#define PASULIOBJECT_UUD	1
#define PASULIOBJECT_UVD	1
#define PASULIOBJECT_VVD	1

#if( 0 )
typedef double pasuli_vartype;
typedef double pasuli_consttype;
typedef double CoordType;
#else
#define pasuli_vartype		double
#define pasuli_consttype	double
#define CoordType double
#endif
//typedef float pasuli_vartype;
//typedef float pasuli_consttype;




#if( 1 )

typedef Particle	PaSuLiObject;
//#define PaSuLiObject	Particle
//#define PaSuLiObject	Par3D

#else

typedef struct {
#if(PASULIOBJECT_POS != 0)
	pasuli_vartype pos[3];			// position vector
#endif
#if(PASULIOBJECT_UD != 0)
	pasuli_vartype ud[3];			//derivative in u-direction
#endif
#if(PASULIOBJECT_VD != 0)
	pasuli_vartype vd[3];			//derivative in v-direction
#endif
#if(PASULIOBJECT_N != 0)
	CoordType n[3];				//normal
#endif

#if(PASULIOBJECT_UUD != 0)
	CoordType uud[3];			//derivative in u-direction & u-direction
#endif

#if(PASULIOBJECT_UVD != 0)
	CoordType uvd[3];			//derivative in u-direction & v-direction
#endif

#if(PASULIOBJECT_VVD != 0)
	CoordType vvd[3];			//derivative in v-direction two times
#endif
} PaSuLiObject;
#endif

typedef void (*parsurFunc)(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO);

#define USE_INITCONST		0

void initConstAll( PaSuLiObject* pO, pasuli_consttype value );
//void initConstDefault(PaSuLiObject* pO, pasuli_consttype* constants);

#endif

