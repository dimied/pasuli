
#include "../particle.h"
#include "pasuli_defs.h"
#include "pasuli_const.h"
#include "../compile_config.h"
extern pasuli_name_type parsur_name_array[];

#if( 0 )

int tmain(int argc, _TCHAR* argv[]) {


	return 1;
}

#endif

#if( 1 )

#if( PASULI_DEBUG_MODE != 0)
#include <iostream>
PaSuLiTextDesc tD;
PaSuLiObject pasuliTestObject;
pasuli_consttype testConstants[12] = {1,1,1,1,1,1,  1,1,1,1,1,1};
int TestPaSuLi() {

	PaSuLiDefDesc* pDD;
	for(int j = 1; j < NUMB_OF_SURFACES; j++) {
		pDD = (PaSuLiDefDesc*)getPaSuLiPointer( j, PASULI_INFO_DEF_DESC_PTR );
		if(pDD != 0) {
		//if( pDD->_ID != j ) {
		//	return -(j+1);
		//	//break;
		//}
		}
	}

	double u = 0.1;
	double v = 0.1;

	for(int j = 1; j < NUMB_OF_SURFACES; j++) {
		parsurFunc pf = (parsurFunc)getPaSuLiPointer( j, PASULI_INFO_FUNC_PTR );

		if(pf != 0) {
			pf( u , v , testConstants, &pasuliTestObject );
			if( pasuliTestObject._ID != j ) {
				std::cout<< pasuliTestObject._ID << std::endl;
				return j;
			}
		}
	}
	for(int j = 1; j < NUMB_OF_SURFACES; j++) {
		pasuli_name_type* name = &parsur_name_array[j];
		if( name->_ID != j ) {
			std::cout<< "Name error @" << j<<"  there is "<< name->_ID << "\n";
			std::cout<< name->szName << std::endl;
			return j;
		}
	}

	char* pC = (char*)getPaSuLiPointer( PLANE , PASULI_INFO_DESC_PTR );
	std::cout<< "OLD\n" << pC << "\n";
	parsePaSuLiDesc( pC, &tD );
	std::cout<< "NEW\n";
	std::cout<< "Mem-size: "<< tD.memSize << "\n";
	std::cout<< tD.szName << std::endl;
	return -1;


}
#endif

#endif

