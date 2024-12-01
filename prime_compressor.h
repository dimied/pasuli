#ifndef __PRIME_NUMBER_COMPRESSOR__
#define __PRIME_NUMBER_COMPRESSOR__

/*
typedef struct _LINT
{
	union
	{
		unsigned int* x;//polynomial data
		unsigned char* byte_data;
	};
	unsigned long long size;//allocated size, measured in blocks of 32 bits
	unsigned long long used_size;//actual space occupied by the number, measured in blocks of 32 bits
	unsigned char sign;//0=positive,anything else=negative
}LINT;
*/

extern int compressType;

void compress(void* pData, int size, void*pResultData, int resultSize);
#endif