
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_algos.h"
#include "ogl_compress_types.h"

extern void *pTempMemory;
extern void *pCompressResult4;
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

/**
 * Destroys input data.
 */
void decompress4asm(unsigned char *pData, decompressFPtr func)
{
    // decompress4(pData,func);
    // return;
#if 0
    asm(
        "push rbp\n"
        "mov rbp, rsp\n"
        "sub rsp, 0x20\n"
        //pData -> stack
        "mov QWORD PTR [rbp-0x18],rdi\n"
        //func -> stack
        "mov QWORD PTR [rbp-0x20],rsi\n"
        //pLast 
        "mov rbx, rdi\n"
        "leave\n"
        "ret\n"
    );
#endif
#if 1
    unsigned char *pLast = pData;
    int val;

    while (*pData != 0)
    {
        val = *pData;
        *pData = (val) & 0x7F;
        ++pData;
        if (val > 0x80)
        {
            (*func)((char *)pLast, (pData - pLast));
            pLast = pData;
        }
    }
#endif
}
