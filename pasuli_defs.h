#ifndef __PARAMETRIC_SURFACE_LIBRARY_VERSION_DEFS__
#define __PARAMETRIC_SURFACE_LIBRARY_VERSION_DEFS__

#define PASULI_FLOAT 0x1
#define PASULI_DOUBLE 0x2
#define PASULI_TYPE_DEF_BIT_LENGTH 0x2

#define MY_PI 3.14159265358979323846f
#define MY_PI_HALF MY_PI * 0.5f

#define PASULIOBJECT_POS 1
#define PASULIOBJECT_UD 1
#define PASULIOBJECT_VD 1
#define PASULIOBJECT_N 1
#define PASULIOBJECT_UUD 1
#define PASULIOBJECT_UVD 1
#define PASULIOBJECT_VVD 1

#define pasuli_vartype double
#define pasuli_consttype double
#define pasuli_calctype double
#define CoordType double

typedef struct
{
#if (PASULIOBJECT_POS != 0)
	pasuli_vartype pos[3]; // position vector
#endif

#if (PASULIOBJECT_UD != 0)
	pasuli_vartype ud[3]; //derivative in u-direction
#endif

#if (PASULIOBJECT_VD != 0)
	pasuli_vartype vd[3]; //derivative in v-direction
#endif

#if (PASULIOBJECT_N != 0)
	CoordType n[3]; //normal
#endif

#if (PASULIOBJECT_UUD != 0)
	CoordType uud[3]; //derivative in u-direction & u-direction
#endif

#if (PASULIOBJECT_UVD != 0)
	CoordType uvd[3]; //derivative in u-direction & v-direction
#endif

#if (PASULIOBJECT_VVD != 0)
	CoordType vvd[3]; //derivative in v-direction two times
#endif
} PaSuLiObject;

typedef void (*parsurFunc)(pasuli_vartype u, pasuli_vartype v,
						   pasuli_consttype *constants, PaSuLiObject *pO);

#define USE_INITCONST 0

#define PARTICLE_POS 1
#define PARTICLE_N 1
#define PARTICLE_VD 1
#define PARTICLE_UD 1
#define PARTICLE_UUD 1
#define PARTICLE_UVD 1
#define PARTICLE_VVD 1

typedef float pasulidefdesc_ct;			 //const type
typedef float pasulidefdesc_vt;			 //variable type
typedef unsigned short pasulidefdesc_pt; //property type

#define PASULI_U_CLOSED 0x1
#define PASULI_V_CLOSED 0x2
#define PASULI_U_PI 0x4
#define PASULI_V_PI 0x8
#define PASULI_U_START_PI PASULI_U_PI
#define PASULI_U_END_PI PASULI_U_PI
#define PASULI_V_START_PI PASULI_V_PI
#define PASULI_V_END_PI PASULI_V_PI

#define PASULI_CALC_U 0x10
#define PASULI_CALC_V 0x20
#define PASULI_CALC_U_START PASULI_CALC_U
#define PASULI_CALC_U_END PASULI_CALC_U
#define PASULI_CALC_V_START PASULI_CALC_V
#define PASULI_CALC_V_END PASULI_CALC_V
#define PASULI_DERIV1_IMPL 0x40
#define PASULI_DERIV2_IMPL 0x80
#define PASULI_FULL_IMPL (PASULI_DERIV1_IMPL | PASULI_DERIV2_IMPL)

#define PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS 0x100
#define PASULI_CONST_CONSTANTS 0x200

#define PASULI_DEF_CONSTANTS_1 0x400
//#define PASULI_DEF_CONSTANTS_2  0x800
#define PASULI_DEF_CONSTANTS_3 (PASULI_DEF_CONSTANTS_1 + PASULI_DEF_CONSTANTS_2)

//4 bits( = 15 valid values) should be enough, except for SuperFormula
#define PASULI_CONST_COUNT(X) (X << 12) 
										

#define GET_PASULI_CONST_COUNT(X) ((X >> 12) & 0xF)
#define PASULI_ARE_CONSTANTS_CONST(X) (X & PASULI_CONST_CONSTANTS)
#define PASULI_IS_FULL_IMPLEMENTED(X) (X & PASULI_FULL_IMPL)

typedef struct _PaSuLiDefDesc
{
#if (USE_ID_IN_PSLDD != 0)
	unsigned short _ID;
#endif
	pasulidefdesc_pt properties;
	pasulidefdesc_vt u_start;
	pasulidefdesc_vt u_end;
	pasulidefdesc_vt v_start;
	pasulidefdesc_vt v_end;
	pasulidefdesc_ct *constants;
} PaSuLiDefDesc;

//Following two macros should be ORed
#define COPY_DEFDESC_RANGE_TYPE(X) (X)
#define COPY_DEFDESC_CONST_TYPE(X) (X << PASULI_TYPE_DEF_BIT_LENGTH)
#define COPY_DEFDESC_TYPES(R, C) ((R) | ((C << PASULI_TYPE_DEF_BIT_LENGTH)))

void copyDefDesc(PaSuLiDefDesc *pDD, int iSurfaceType,
				 unsigned int dstType, void *pRange, void *pConstants);

#define MAX_DESC_LENGTH 512

/**
 * Used for description of parameteric surfaces
 */
typedef struct _PaSuLiTextDesc
{
	//unsigned short memSize;
	//char* memPtr;
	//unsigned char ucConstCount;
	//unsigned char ucAbrCount;

	char szName[32];
	char szCat[16];
	char szTypeU; //o : open, c : closed, u : unknown, \0 : unknown
	char szTypeV; //o : open, c : closed, u : unknown, \0 : unknown
	char szStartU[8];
	char szEndU[8];
	char szStartV[8];
	char szEndV[8];
	char szConstNames[8][4];
	char szConstValues[8][8];
	char szConstConstraints[8][8];
	/*
	char szX[MAX_DESC_LENGTH];
	char szY[MAX_DESC_LENGTH];
	char szZ[MAX_DESC_LENGTH];
	char szXu[MAX_DESC_LENGTH];
	char szYu[MAX_DESC_LENGTH];
	char szZu[MAX_DESC_LENGTH];
	char szXv[MAX_DESC_LENGTH];
	char szYv[MAX_DESC_LENGTH];
	char szZv[MAX_DESC_LENGTH];
	char szXn[MAX_DESC_LENGTH];
	char szYn[MAX_DESC_LENGTH];
	char szZn[MAX_DESC_LENGTH];
	char szXuu[MAX_DESC_LENGTH];
	char szYuu[MAX_DESC_LENGTH];
	char szZuu[MAX_DESC_LENGTH];
	char szXuv[MAX_DESC_LENGTH];
	char szYuv[MAX_DESC_LENGTH];
	char szZuv[MAX_DESC_LENGTH];
	char szXvv[MAX_DESC_LENGTH];
	char szYvv[MAX_DESC_LENGTH];
	char szZvv[MAX_DESC_LENGTH];
	*/
} PaSuLiTextDesc;

//void clearDesc(PaSuLiDesc* p);
void parsePaSuLiDesc(char *szDescString, PaSuLiTextDesc *pPSLD);
void clearPaSuLiTextDesc(PaSuLiTextDesc *pTD);

void initConstAll(PaSuLiObject *pO, pasuli_consttype value);
//void initConstDefault(PaSuLiObject* pO, pasuli_consttype* constants);

#include "pasuli_custom_defs.h"

#endif
