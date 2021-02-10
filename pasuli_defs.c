
#include "pasuli_const.h"
#include "pasuli_defs.h"
#include "pasuli_macros.h"

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
		pDD = (PaSuLiDefDesc*)getPaSuLiPointer( iSurfaceType ,
									PASULI_INFO_DEF_DESC_PTR);
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

void clearPaSuLiTextDesc(PaSuLiTextDesc* pTD) {

	if( pTD == 0 ) {
		return;
	}

	char* p = (char*) pTD;
	int l = sizeof(PaSuLiTextDesc);
	while( l > 0) {
		*p = '\0';
		p++;
		l--;
	}
	//if((pTD->memSize > 0)||(memPtr != 0)) {

	//}

	//pTD->ucConstCount = 0;
	//pTD->ucAbrCount = 0;
}


/////////////////////////   EXTRACTION OF INFORMATION

int contains_only(char* szSrcString, int srcLength, 
				char* szStringToBeIn, int secondLength, char fillChar) {
	if( (srcLength <= 0) || (secondLength <= 0) ||
		(szSrcString == 0) || (szStringToBeIn == 0) ) {
		return -1;			//wrong parameter
	}

	int i = 0;
	//search till first occurence
	while( (i < srcLength)&&(*szSrcString != *szStringToBeIn) && 
			(*szSrcString == fillChar) ) {
		szSrcString++;
		i++;
	}
	if( i == srcLength ) {
		return 0;
	}

	int i2 = 0;
	while( ( secondLength > 0) && (i < srcLength) ) {
		if( *szSrcString !=  *szStringToBeIn ) {
			break;
		}
		szSrcString++;
		szStringToBeIn++;
		i++;
		secondLength--;
	}

	if( secondLength > 0) {
		return 0;
	}
	if( i == srcLength ) {		//was at the end
		return 1;
	}
	while( (i < srcLength ) && (*szSrcString == fillChar) ) {
		i++;
	}
	return (i == srcLength ) ? 1 : 0;
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

char* lineStartNames[32] = {
"",
"start", "cat", "utype", "vtype",
"ustart", "uend", "vstart", "vend"
"c", "f",

"x", "y", "z",
"xu", "yu", "zu",
"xv", "yv", "zv",
"xn", "yn", "zn",
"xuu", "yuu", "zuu",
"xuv", "yuv", "zuv",
"xvu", "yvv", "zvv",
"end"
};

void parsePaSuLiDesc(char* szDescString, PaSuLiTextDesc *pPSLD) {

	if( (szDescString == 0)||(pPSLD == 0) ) {
		return;
	}

	//read till ";"
	//parse 
	//loop till end;

	char* start = szDescString;
	char* curPos = szDescString;
	char* endPos;
	char* starts[MAX_SEPARATORS];
	int curSepCount = 1;
	// TODO
	//bool descStart = false;

	while( *curPos != '\0') {		//!! szString
		
		curSepCount = 1;
		starts[0] = curPos;
		
		while( *curPos != ';' ) {

			if( *curPos == ':' ) {
				starts[curSepCount] = curPos + 1;
				++curPos;
				curSepCount++;
				if(curSepCount >= MAX_SEPARATORS ) {
					//ERROR
					break;
				}
				continue;
			}
			if( *curPos == '\0' ) {
				//ERROR
				break;
			}
			curPos++;
			
		}
		endPos = curPos;
		//LINE PARSED
		//INTERPRET
		int elemID = 0;
		for(int ij = 1; ij < 32; ij++) {
			if( contains_only( starts[0], starts[1] - starts[0], 
							lineStartNames[ij], 1, ' ' ) != 0) {

				elemID = PASULI_TEXT_DESC_START;
			}
		}

		switch(elemID) {

			case PASULI_TEXT_DESC_START:
			// TODO
									//descStart = true;
									break;
									
			case PASULI_TEXT_DESC_CAT:
									break;
			case PASULI_TEXT_DESC_UTYPE:
									break;						
			case PASULI_TEXT_DESC_VTYPE:
									break;
			case PASULI_TEXT_DESC_USTART:
									break;
			case PASULI_TEXT_DESC_UEND:
									break;
			case PASULI_TEXT_DESC_VSTART:
									break;
			case PASULI_TEXT_DESC_VEND:
									break;
			
			case PASULI_TEXT_DESC_CONSTANT:
									break;
			case PASULI_TEXT_DESC_FUNCTION:
									break;

			case PASULI_TEXT_DESC_X:
									break;
			case PASULI_TEXT_DESC_Y:
									break;
			case PASULI_TEXT_DESC_Z:
									break;

			case PASULI_TEXT_DESC_XU:
									break;
			case PASULI_TEXT_DESC_YU:
									break;
			case PASULI_TEXT_DESC_ZU:
									break;

			case PASULI_TEXT_DESC_XV:
									break;
			case PASULI_TEXT_DESC_YV:
									break;
			case PASULI_TEXT_DESC_ZV:
									break;

			case PASULI_TEXT_DESC_XN:
									break;
			case PASULI_TEXT_DESC_YN:
									break;
			case PASULI_TEXT_DESC_ZN:
									break;

			case PASULI_TEXT_DESC_XUU:
									break;
			case PASULI_TEXT_DESC_YUU:
									break;
			case PASULI_TEXT_DESC_ZUU:
									break;

			case PASULI_TEXT_DESC_XUV:
									break;
			case PASULI_TEXT_DESC_YUV:
									break;
			case PASULI_TEXT_DESC_ZUV:
									break;

			case PASULI_TEXT_DESC_XVV:
									break;
			case PASULI_TEXT_DESC_YVV:
									break;
			case PASULI_TEXT_DESC_ZVV:
									break;
			default:				break;
		}
		//LINE PARSED, GO TO NEXT LINE
		curPos++;
		
	}
}
