
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_algos.h"
#include "ogl_compress_types.h"

extern void* pTempMemory;
extern void* pCompressResult4;
extern void decompressCall(char *p, int s);


int compress4(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        resSize += strlen(pNames[i]) - 2;
    }
    ++resSize;
    void *pMem = malloc(resSize);
    memset(pMem, 0, resSize);
    pCompressResult4 = pMem;

    unsigned char *pUC = (unsigned char *)pMem;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        p += 2;
        int len = strlen(p);
        memcpy(pUC, p, len);
        pUC += len - 1;
        // set marker
        *pUC = 0x80 | (*pUC);
        ++pUC;
    }
    printf("SIZES: %i <> %li\n", resSize, pUC - (unsigned char *)pMem);

    return resSize;
}

void decompress4(unsigned char *pData, decompressFPtr func)
{
    unsigned char *pLast = pData;
    while (*pData != 0)
    {
        int val = *pData;
        if (val > 0x80)
        {
            *pData = (val) & 0x7F;

            ++pData;
            val = *pData;
            // int s = pData - pLast;
            *pData = 0;
            (*func)((char *)pLast, (pData - pLast));
            *pData = val;
            pLast = pData;
            continue;
        }
        ++pData;
    }
}

void decompress4asm(unsigned char *pData, decompressFPtr func)
{
    unsigned char *pLast = pData;
    while (*pData != 0)
    {
        int val = *pData;
        if (val > 0x80)
        {
            *pData = (val) & 0x7F;
            // val = *pData;
            //*pData = 0;
            (*func)((char *)pLast, (pData + 1 - pLast));
            *pData = val;
            ++pData;
            pLast = pData;
            continue;
        }
        ++pData;
    }
}
