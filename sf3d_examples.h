#ifndef __PARAMETRIC_SURFACE_LIBRARY_SUPERFORMULA_3D_EXAMPLES__
#define __PARAMETRIC_SURFACE_LIBRARY_SUPERFORMULA_3D_EXAMPLES__

#include "pasuli_defs.h"


void getSF3DExamplesConstants(unsigned int exampleNum, pasuli_consttype* pC);

#define MAX_NUM_OF_SUPERFORMULA_3D_EXAMPLES		32

#define SF3D_PB_OFFSET			1
#define SF3D_PB_CUBE			(25 - SF3D_PB_OFFSET)
#define SF3D_PB_CONE			(26 - SF3D_PB_OFFSET)
#define SF3D_PB_DIAMOND			(27 - SF3D_PB_OFFSET)
#define SF3D_PB_SPHERE			(28 - SF3D_PB_OFFSET)
#define SF3D_PB_PRISM			(29 - SF3D_PB_OFFSET)
#define SF3D_PB_CYLINDER		(30 - SF3D_PB_OFFSET)
#define SF3D_PB_HEXAGON			(31 - SF3D_PB_OFFSET)
#define SF3D_PB_PENTAGON		(32 - SF3D_PB_OFFSET)

#define SF3D_PACK_TYPE_FLOAT	0
#define SF3D_PACK_TYPE_USHORT	1
#define SF3D_PACK_TYPE_UINT		2
#define SF3D_PACK_TYPE			SF3D_PACK_TYPE_USHORT
//typedef double				sf3d_packtype;
//typedef float					sf3d_packtype;
typedef unsigned short			sf3d_packtype;
//typedef unsigned int			sf3d_packtype;

///////////////   Macros  /////////////

#define SF3D_RATIONAL_USHORT(X,Y)		(((X&0x3F)<<7) + (Y&0x3F))
#define SF3D_NEG_RATIONAL_USHORT(X,Y)	((((X&0x3F)<<7) + (Y&0x3F))|0x8000)
#define SF3D_NATURAL_USHORT(X)			(((X&0x3F)<<7) + 1)
#define SF3D_NEG_WHOLE_USHORT(X)		((((X&0x3F)<<7) + 1)|0x8000)
#define SF3D_NATURAL10_USHORT(X)		((((X&0x3F)<<7) + 1)|0x4000)
#define SF3D_EXTRACT_SIGN_USHORT(X)		((X & 0x8000) ? -1 : 1 )
#define SF3D_EXTRACT_USHORT_TO_DOUBLE(X)	(SF3D_EXTRACT_SIGN_USHORT(X)*((X & 0x4000) ? 10 : 1)*((X>>7)&0x3F)/(X&0x3F))

#define SF3D_RATIONAL_UINT(X,Y)			((X<<15) + Y)
#define SF3D_NEG_RATIONAL_UINT(X,Y)		(((X<<15) + Y)|0x80000000)
#define SF3D_NATURAL_UINT(X)				((X<<15) + 1)
#define SF3D_NEG_WHOLE_UINT(X)			(((X<<15) + 1)|0x80000000)
#define SF3D_NATURAL10_UINT(X)			(((X<<15) + 1)|0x40000000)
#define SF3D_EXTRACT_SIGN_UINT(X)		((X & 0x80000000) ? -1 : 1 )
#define SF3D_EXTRACT_UINT_TO_DOUBLE(X)	((SF3D_EXTRACT_SIGN_UINT(X))*((X & 0x40000000) ? 10 : 1)*((X>>15)&0x3FFF)/(X&0x3FFF))

#if(SF3D_PACK_TYPE == SF3D_PACK_TYPE_USHORT)
//rational number
#define SF3D_RATIONAL(X,Y)			SF3D_RATIONAL_USHORT(X,Y)
#define SF3D_NEG_RATIONAL(X,Y)		SF3D_NEG_RATIONAL_USHORT(X,Y)
//Natural number
#define SF3D_NATURAL(X)				SF3D_NATURAL_USHORT(X)	
#define SF3D_NATURAL10(X)			SF3D_NATURAL10_USHORT(X)

#define SF3D_NEG_WHOLE(X)			SF3D_NEG_WHOLE_USHORT(X)

#define SF3D_EXTRACT_DOUBLE(X)		SF3D_EXTRACT_USHORT_TO_DOUBLE(X)
#else 
#if(SF3D_PACK_TYPE == SF3D_PACK_TYPE_UINT)
#define SF3D_RATIONAL(X,Y)			SF3D_RATIONAL_UINT(X,Y)
#define SF3D_NEG_RATIONAL(X,Y)		SF3D_NEG_RATIONAL_UINT(X,Y)
//Natural number
#define SF3D_NATURAL(X)				SF3D_NATURAL_UINT(X)	
#define SF3D_NATURAL10(X)			SF3D_NATURAL10_UINT(X)

#define SF3D_NEG_WHOLE(X)			SF3D_NEG_WHOLE_UINT(X)

#define SF3D_EXTRACT_DOUBLE(X)		SF3D_EXTRACT_UINT_TO_DOUBLE(X)
#else

#define SF3D_RATIONAL(X,Y)			(X/Y)
#define SF3D_NEG_RATIONAL(X,Y)		-(X/Y)
//Natural number
#define SF3D_NATURAL(X)				X
#define SF3D_NATURAL10(X)			X*10

#define SF3D_NEG_WHOLE(X)			-X

#define SF3D_EXTRACT_DOUBLE(X)		X
#endif

#endif

typedef struct _SuperFormula3D_Desc{
	sf3d_packtype constants[12];
} SuperFormula3D_Desc;


extern SuperFormula3D_Desc examplePB1;
extern SuperFormula3D_Desc examplePB2;
extern SuperFormula3D_Desc examplePB3;
extern SuperFormula3D_Desc examplePB4;
extern SuperFormula3D_Desc examplePB5;
extern SuperFormula3D_Desc examplePB6;
extern SuperFormula3D_Desc examplePB7;
extern SuperFormula3D_Desc examplePB8;
extern SuperFormula3D_Desc examplePB9;

extern SuperFormula3D_Desc examplePB10;
extern SuperFormula3D_Desc examplePB11;
extern SuperFormula3D_Desc examplePB12;
extern SuperFormula3D_Desc examplePB13;
extern SuperFormula3D_Desc examplePB14;
extern SuperFormula3D_Desc examplePB15;
extern SuperFormula3D_Desc examplePB16;
extern SuperFormula3D_Desc examplePB17;
extern SuperFormula3D_Desc examplePB18;
extern SuperFormula3D_Desc examplePB19;

extern SuperFormula3D_Desc examplePB20;
extern SuperFormula3D_Desc examplePB21;
extern SuperFormula3D_Desc examplePB22;
extern SuperFormula3D_Desc examplePB23;
extern SuperFormula3D_Desc examplePB24;

extern SuperFormula3D_Desc examplePBCube;
extern SuperFormula3D_Desc examplePBCone;
extern SuperFormula3D_Desc examplePBCylinder;
extern SuperFormula3D_Desc examplePBDiamond;
extern SuperFormula3D_Desc examplePBPrism;

extern SuperFormula3D_Desc examplePBSphere;
extern SuperFormula3D_Desc examplePBHexagon;
extern SuperFormula3D_Desc examplePBPentagon;

#endif

