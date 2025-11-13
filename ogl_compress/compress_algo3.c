#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_algos.h"

//extern void* pTempMemory;
extern void* pCompressResult3;
extern char* glParts[];
extern int numGLParts;
extern void decompressCall(char *p, int s);


#define NAME_PARTS_SIZE 16
typedef struct _NameParts
{
    int numParts;
    unsigned char parts[NAME_PARTS_SIZE];
} NameParts;

#define COMPRESS3_MARKER 0xFF

#define LAST_ALGO 1

int compress3(char **names, int numberOfNames)
{
    int cs = 0;
    int numParts = numGLParts;
    int allocSize = numParts * sizeof(int);
    int *pPartsCounts = (int *)malloc(allocSize);
    int *pPartsLengths = (int *)malloc(allocSize);

    if (pPartsCounts == 0)
    {
        printf("compress3: FAILED TO ALLOCATE COUNTS\n");
        return 0x1000;
    }
    if (pPartsLengths == 0)
    {
        free(pPartsCounts);
        printf("compress3: FAILED TO ALLOCATE LENGTHS\n");
        return 0x1000;
    }
    int nameAllocSize = sizeof(NameParts) * numberOfNames;
    NameParts *pNameParts = (NameParts *)malloc(nameAllocSize);

    if (pNameParts == 0)
    {
        free(pPartsCounts);
        free(pPartsLengths);
        printf("compress3: FAILED TO ALLOCATE NAME PARTS\n");
        return 0x1000;
    }

    const int mappingAllocSize = numParts;
    unsigned char *pMapping = (unsigned char *)malloc(mappingAllocSize);
    memset(pPartsCounts, 0, allocSize);
    memset(pPartsLengths, 0, allocSize);
    memset(pNameParts, 0, nameAllocSize);
    memset(pMapping, 0, mappingAllocSize);

    printf("#parts=%i\n", numParts);

    for (int i = 0; i < numParts; i++)
    {
        if (glParts[i] != 0)
        {
            // printf("?%s\n", glParts[i]);
            pPartsLengths[i] = strlen(glParts[i]);
        }
    }

    char funcNameBuffer[200];

    int pass = 0;
    int numNameParts = 0;
    int success = 1;

    while (pass < 1 && success == 1)
    {
        for (int checkNameIdx = 0; checkNameIdx < numberOfNames && success == 1; checkNameIdx++)
        {
            char *pName = names[checkNameIdx];

            if (pName == strstr(pName, "gl"))
            {
                pName += 2;
            }

            char nameSize = strlen(pName);
            memset(funcNameBuffer, 0, 200);
            memcpy(funcNameBuffer, pName, nameSize);

            char *p = funcNameBuffer;

            int currentParts = 0;

            while (*p != 0)
            {
                // char *pHit = 0;
                int hitIdx = -1;
                for (int partIdx = 0; partIdx < numParts; partIdx++)
                {
                    char *pSearch = glParts[partIdx];
                    if (pSearch == 0 || pPartsLengths[partIdx] == 0)
                    {
                        continue;
                    }
                    char *pPos = strstr(p, pSearch);
                    if (pPos == p)
                    {
                        // pHit = pPos;
                        hitIdx = partIdx;
                    }
                }
                if (hitIdx > 0)
                {
                    p += pPartsLengths[hitIdx];
                    if (pass == 0)
                    {
                        ++pPartsCounts[hitIdx];
                        ++currentParts;
                    }
                    int pIdx = pNameParts[checkNameIdx].numParts;
                    if (pIdx >= NAME_PARTS_SIZE)
                    {
                        success = 3;
                        break;
                    }
                    pNameParts[checkNameIdx].parts[pIdx] = hitIdx;
                    ++pNameParts[checkNameIdx].numParts;
                }
                else
                {
                    printf("Failed? %s | %s\n", p, funcNameBuffer);
                    success = 2;
                    break;
                }
                //++p;
            }

            numNameParts += currentParts;
        }
        //
        ++pass;
    }

    if (success != 1)
    {
        free(pPartsCounts);
        free(pPartsLengths);
        free(pNameParts);
        free(pMapping);
        return 0x10000;
    }

    int funcPartSizeSum = 0;
    int hits = 0;

    for (int i = 0; i < numParts; i++)
    {
        if (pPartsCounts[i] > 0)
        {
#if 0
            printf("%i : '%s'\n", pPartsCounts[i], glParts[i]);
#endif
            // mapping orig index to new index(+1), no 0 values
            pMapping[i] = hits + 1;
            ++hits;
            funcPartSizeSum += pPartsLengths[i];
        }
    }
    // Dict length + (no num names) + lengths + hits(i.e size bytes for every entry)
    // + 1
    cs += 1 + funcPartSizeSum + hits + numNameParts + numberOfNames + 1;

#if LAST_ALGO
    cs -= hits;
#endif

    unsigned char *pResult = (unsigned char *)malloc(cs);
    int sizeTrack = 0;

    if (pResult != 0)
    {
        memset(pResult, 0, cs);
        pCompressResult3 = pResult;
        unsigned char *p = pResult;
        //*p = (unsigned char)numberOfNames;
        //++p;
#if LAST_ALGO == 0
        *p = (unsigned char)hits;
        ++p;
        sizeTrack += 1;
#endif

        for (int partIdx = 0; partIdx < numParts; partIdx++)
        {
            if (pPartsCounts[partIdx] > 0)
            {
                // printf("%i : %s\n", pPartsCounts[i], glParts[i]);
                int l = pPartsLengths[partIdx];
                //*p = (unsigned char)l;
                //++p;
                memcpy(p, glParts[partIdx], l);

#if LAST_ALGO
                p += l - 1;
                *p |= 0x80;
                sizeTrack += l;
#else
                p += l;
                *p = (unsigned char)COMPRESS3_MARKER;

                sizeTrack += l + 1;
#endif
                ++p;
                if (sizeTrack >= cs)
                {
                    success = 5;
                    break;
                }
            }
        }
        if (success == 1)
        {
#if LAST_ALGO
            *p = COMPRESS3_MARKER;
            ++p;
            sizeTrack++;
#endif
            for (int nameIdx = 0; nameIdx < numberOfNames && success == 1; nameIdx++)
            {
                int numParts = pNameParts[nameIdx].numParts;
                //*p = (unsigned char)numParts;
                //++p;
                //++sizeTrack;
                if (sizeTrack >= cs)
                {
                    printf("Overflow @%i| %i<>%i\n", nameIdx, sizeTrack, cs);
                    success = 5;
                    break;
                }
                for (int pIdx = 0; pIdx < numParts; pIdx++)
                {
                    int idxOfName = pNameParts[nameIdx].parts[pIdx];
                    int mapped = pMapping[idxOfName];
                    *p = (unsigned char)mapped;
                    ++p;
                    ++sizeTrack;
                    if (sizeTrack >= cs)
                    {
                        printf("Overflow @%i| %i<>%i | p=%i(%s)\n",
                               nameIdx, sizeTrack, cs, pIdx, glParts[idxOfName]);
                        success = 5;
                        break;
                    }
                }
                *p = (unsigned char)COMPRESS3_MARKER;
                ++p;
                ++sizeTrack;
                if (sizeTrack >= cs)
                {
                    printf("Overflow @%i| %i<>%i\n",
                           nameIdx, sizeTrack, cs);
                    success = 5;
                    break;
                }
            }
            if (success == 1)
            {
                *p = 0;
            }
        }
    }
    else
    {
        success = 6;
    }

    free(pPartsCounts);
    free(pPartsLengths);
    free(pNameParts);
    free(pMapping);
    if (success != 1)
    {
        return 0x100000;
    }
    printf("RES: L =?= S: %i =?= %i | Hits=%i\n", cs, sizeTrack, hits);

    return cs;
}

void decompress3(int cs, unsigned char *pData)
{
    // int i = *pData;
    //++pData;

#if 0
    char buffer[100];
#if DECOMPRESS3_VERBOSE
    // char *pIn = pData;
#endif
int i = *pData;
    ++pData;
    char *pDict[300];
    char **pDictCurrent = pDict;
    memset(pDict, 0, sizeof(char *) * 300);
    // Fill dictionary
    while (i > 0)
    {
        *pDictCurrent = (char *)pData;
        ++pDictCurrent;
        while (*pData != COMPRESS3_MARKER)
        {
            ++pData;
        }
        ++pData;
        --i;
    }
clearbuf:
    memset(buffer, 0, 100);
    while (*pData != 0)
    {
#if DECOMPRESS3_VERBOSE > 1
        printf("PARSE\n");
#endif

        int val = *pData;
        if (val == COMPRESS3_MARKER)
        {
            // call!
            // decompressCall(pTempMemory, lastS + s);
            //memset(buffer, 0, 100);
            ++pData;
            goto clearbuf;
            i=0;
        }
        else
        {
            char *p = buffer;
            char *pPart = pDict[val - 1];
#if DECOMPRESS3_VERBOSE
            printf("IDX %i|%i|%p|%p\n", i, val, (void *)pPart, (void *)pIn);
#endif
            while (*pPart != COMPRESS3_MARKER)
            {
                *p = *pPart;
                ++p;
                ++pPart;
                ++i;
            }
        }
        ++pData;
    }
#endif
#if 0
char buffer[100];
#if DECOMPRESS3_VERBOSE
    // char *pIn = pData;
#endif
int i = *pData;
    ++pData;
    int s, val;    
    unsigned char *pDict[200];
    unsigned char *pName = pData;
    char *p;
clearbuf:
    s = 0;
    //p = buffer;
    p = memset(buffer, 0, 100);
    //
    while (*pData != 0)
    {
        val = *pData;
#if DECOMPRESS3_VERBOSE
        printf("PARSE: %x | %x\n", i, val);
#endif
        if (i > 0)
        {
            if (val == COMPRESS3_MARKER)
            {
                pDict[s] = pName;
                ++s;
                pName = pData + 1;
                --i;
            }
        }
        else
        {
            if (val == COMPRESS3_MARKER)
            {
// call!
#if DECOMPRESS3_VERBOSE
                printf("F: %s\n", buffer);
#endif
                // decompressCall(pTempMemory, lastS + s);
                ++pData;
                goto clearbuf;
            }
            else
            {
                unsigned char *pPart = pDict[val - 1];
#if DECOMPRESS3_VERBOSE
                printf("IDX %i|%i|%p|%p\n", i, val, (void *)pPart, (void *)pIn);
#endif
                while (*pPart != COMPRESS3_MARKER)
                {
#if DECOMPRESS3_VERBOSE
                    printf("P:%i\n", (unsigned char)(*pPart));
#endif
                    *p = *pPart;
                    ++p;
                    ++pPart;
                    ++s;
                }
            }
        }

        ++pData;
    }
#endif
#if LAST_ALGO
    unsigned char buffer[100];
    int s = 1, val;
    unsigned char *pDict[200];
    unsigned char **pDictTemp = pDict;
    unsigned char *pName = buffer;
    memset(pDict, 0, 200 * sizeof(unsigned char *));
    unsigned char *p = pData;

    while (*pData != 0)
    {
        val = *pData;
        // printf("?%i|%x|%c?\n", s, val, val);
        if (s)
        {
            if (val > 0x80)
            {
                if (val == COMPRESS3_MARKER)
                {
                    s = 0;
                }
                else
                {
                    //*pData = (val&0x7F);
                    *pDictTemp = p;
                    ++pDictTemp;
                    p = pData + 1;
#if 0
                    char d = *p;
                    *p = 0;
                    *pData =val&0x7F;
                    printf("E: %s\n", pData);
                    *pData =val;
                    *p = d;
#endif
                }
            }
        }
        else
        {
            if (val != COMPRESS3_MARKER)
            {
                p = pDict[val - 1];
                while (*p < 0x80)
                {
                    *pName = *p;
                    ++pName;
                    ++p;
                }
                *pName = (*p) & 0x7F;
                ++pName;
            }
            else
            {
#if DECOMPRESS3_VERBOSE == 0
                printf("F:%s\n", buffer);
#endif
                // call
                memset(buffer, 0, 100);
                pName = buffer;
            }
        }

        ++pData;
    }
#endif
}