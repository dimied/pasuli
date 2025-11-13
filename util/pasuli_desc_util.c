
#include "pasuli_desc_util.h"
#include "../pasuli_const.h"
#include "../pasuli_defs.h"
#include "../pasuli_macros.h"


void initConstAll( PaSuLiObject* pO, pasuli_consttype value ) {

	P_X( value );
	P_Y( value );
	P_Z( value );

	UD_X( value );
	UD_Y( value );
	UD_Z( value );

	VD_X( value );
	VD_Y( value );
	VD_Z( value );

	N_X( value );
	N_Y( value );
	N_Z( value );

	UUD_X( value );
	UUD_Y( value );
	UUD_Z( value );

	UVD_X( value );
	UVD_Y( value );
	UVD_Z( value );

	VVD_X( value );
	VVD_Y( value );
	VVD_Z( value );
}

void copyDefDesc(PaSuLiDefDesc* pDD, int iSurfaceType,
				unsigned int dstType, void* pRange, void* pConstants) {

	pasulidefdesc_pt ddProperty;

	if((pRange == 0)&&(pConstants ==0)) {
		return;
	}

	if((pDD == 0)&&(iSurfaceType >= 0)) {
		// TODO
		//pDD = (PaSuLiDefDesc*)getPaSuLiPointer( iSurfaceType ,
		//									PASULI_INFO_DEF_DESC_PTR);
		if( pDD == 0) {
			//std::cout<< "Invalid pointer @ "<< iSurfafeType <<std::endl;
			return;
		}
		ddProperty = pDD->properties;
	} else {
		ddProperty = pDD->properties;
	}
	double rangeMul[4] = {1.0, 1.0, 1.0, 1.0};

	if(ddProperty & PASULI_U_START_PI) { 
		rangeMul[0] = 3.14159265358979323846; 
	}
	if(ddProperty & PASULI_U_END_PI) { 
		rangeMul[1] = 3.14159265358979323846; 
	}
	if(ddProperty & PASULI_V_START_PI) { 
		rangeMul[2] = 3.14159265358979323846; 
	}
	if(ddProperty & PASULI_V_END_PI) { 
		rangeMul[3] = 3.14159265358979323846; 
	}

	if(pRange != 0) {
	if( dstType & PASULI_FLOAT) {
		float* fpRange = (float*) pRange;
		fpRange[0] = (float)(((double)pDD->u_start)*rangeMul[0]);
		fpRange[1] = (float)(((double)pDD->u_end)*rangeMul[1]);
		fpRange[2] = (float)(((double)pDD->v_start)*rangeMul[2]);
		fpRange[3] = (float)(((double)pDD->v_end)*rangeMul[3]);
		
	} else {
		if( dstType & PASULI_DOUBLE) {
			double* dpRange = (double*) pRange;
			dpRange[0] = pDD->u_start*rangeMul[0];
			dpRange[1] = pDD->u_end*rangeMul[1];
			dpRange[2] = pDD->v_start*rangeMul[2];
			dpRange[3] = pDD->v_end*rangeMul[3];
		}
	}
	}

	dstType >>= PASULI_TYPE_DEF_BIT_LENGTH;
	int count = GET_PASULI_CONST_COUNT(pDD->properties);
	int i = 0;

	if(pConstants != 0 ) {
	if( dstType & PASULI_FLOAT) {
		float* fpC = (float*) pConstants;
		if(pDD->constants == 0) {
			while(i < count) {
				fpC[i] = (float) 1;
				i++;
			}
		} else {
		while(i < count) {
			fpC[i] = (float) pDD->constants[i];
			i++;
		}
		}
	} else {
		if( dstType & PASULI_DOUBLE) {
			double* dpC = (double*) pConstants;
				if(pDD->constants == 0) {
					while(i < count) {
					dpC[i] = (double) 1.0;
					i++;
					}
				} else {
			
			while(i < count) {
				dpC[i] = (double) pDD->constants[i];
				i++;
			}	
					}
				}
	}
	}
}


#define MAX_SEPARATORS		6

enum PASULI_TEXT_DESC_ELEMENT_TYPE {
	PASULI_TEXT_DESC_START = 1,
	PASULI_TEXT_DESC_CAT,
	PASULI_TEXT_DESC_UTYPE,
	PASULI_TEXT_DESC_VTYPE,

	PASULI_TEXT_DESC_USTART, PASULI_TEXT_DESC_UEND,
	PASULI_TEXT_DESC_VSTART, PASULI_TEXT_DESC_VEND,
	PASULI_TEXT_DESC_CONSTANT, PASULI_TEXT_DESC_FUNCTION,

	PASULI_TEXT_DESC_X, PASULI_TEXT_DESC_Y, PASULI_TEXT_DESC_Z,
	PASULI_TEXT_DESC_XU, PASULI_TEXT_DESC_YU, PASULI_TEXT_DESC_ZU,
	PASULI_TEXT_DESC_XV, PASULI_TEXT_DESC_YV, PASULI_TEXT_DESC_ZV,
	PASULI_TEXT_DESC_XN, PASULI_TEXT_DESC_YN, PASULI_TEXT_DESC_ZN,
	PASULI_TEXT_DESC_XUU, PASULI_TEXT_DESC_YUU, PASULI_TEXT_DESC_ZUU,
	PASULI_TEXT_DESC_XUV, PASULI_TEXT_DESC_YUV, PASULI_TEXT_DESC_ZUV,
	PASULI_TEXT_DESC_XVV, PASULI_TEXT_DESC_YVV, PASULI_TEXT_DESC_ZVV,

	PASULI_TEXT_DESC_END
};