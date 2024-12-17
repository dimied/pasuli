#ifndef __PRIME_NUMBER_COMPRESSOR__
#define __PRIME_NUMBER_COMPRESSOR__

extern int compressType;

void compress(void *pData, unsigned int size, void *pResultData, int resultSize, int* pRealSize);

void primeStrategy(void *pData, unsigned int size, void *pResultData, int resultSize, int* pRealSize);

#endif