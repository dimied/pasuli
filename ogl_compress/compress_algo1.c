

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_algos.h"

extern void decompressCall(char *p, int s);
extern void* pCompressResult;

int compress(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];

        resSize += strlen(p) + 1 - 2;
    }
    resSize++;

    pCompressResult = malloc(resSize);
    memset(pCompressResult, 0, resSize);

    char *pResult = (char *)pCompressResult;

    int cs = 0;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        int s = strlen(p) - 2;
        *pResult = (char)s;
        ++pResult;
        cs++;
        memcpy(pResult, p + 2, s);
        pResult += (s);
        cs += s;
        //++pResult;
    }
    return cs;
}


void decompress()
{
    char *p = (char *)pCompressResult;
    while (*p != 0)
    {
        // int s = (int)*p;
        decompressCall(p + 1, *p);
        p += (*p) + 1;
    }
}

#define DECOMPRESS_PTR_SIZE 0x26
void decompressPtr(char *p)
{
    while (*p != 0)
    {
        // int s = (int)*p;
        decompressCall(p + 1, (*p));
        p += (*p) + 1;
    }
}

#define DECOMPRESS_B_SIZE 0x34
/*
void decompressB()
{
    char *p = (char *)pCompressResult;
    for (int i = 0; i < NAMES_COUNT; i++)
    {
        int s = (int)*p;
        decompressCall(p + 1, s);
        p += s + 1;
    }
}
*/