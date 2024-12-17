
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress_algos.h"

extern void* pTempMemory;
extern void* pCompressResult2;
extern void decompressCall(char *p, int s);

int compress2Hits = 0;

int compress2(char **pNames, int size, int verbose)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];

        resSize += strlen(p) + 1 - 2;
    }
    resSize++;

    pCompressResult2 = malloc(resSize);
    memset(pCompressResult2, 0, resSize);

    char *pResult = (char *)pCompressResult2;

    int cs = 0;
    char *lastP = 0;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        int s = strlen(p) - 2;
        // Error case
        if (s > COMPRESS2_FORWARD_LIMIT)
        {
            return resSize * 2;
        }

        if (lastP != 0)
        {
            char *p1 = p + 2;
            char *p2 = lastP + 2;
            int runIdx = 0, cmpRes = -1;

            while (*p1 != 0 && *p2 != 0)
            {
                if (*p1 != *p2)
                {
                    cmpRes = runIdx;
                    break;
                }
                ++p1;
                ++p2;
                ++runIdx;
            }
            if (cmpRes > 0)
            {
                // printf("Diff:I: @%i | %s <> %s\n", cmpRes, lastP, p);
                //  cmpRes-=2;
                int cmpRes1 = strlen(lastP + 2) - cmpRes;
                int cmpRes2 = strlen(p + 2) - cmpRes;
                // printf("Diff:R: @%i & %i | %s <> %s\n", cmpRes1, cmpRes2, lastP, p);

                // Hit? Can we encode?
                if (cmpRes1 > 0 && cmpRes1 <= COMPRESS2_BACKWARD_LIMIT && cmpRes2 > 0 && cmpRes2 <= COMPRESS2_FORWARD_LIMIT)
                {
                    if (verbose)
                    {
                        printf("HIT: %s & %s\n", lastP, p);
                    }

                    ++compress2Hits;
                    *pResult = (char)(((cmpRes1) << 5) | cmpRes2);
                    ++pResult;
                    cs++;
                    memcpy(pResult, p + 2 + cmpRes, cmpRes2);
                    pResult += cmpRes2;
                    cs += cmpRes2;
                    lastP = p;
                    continue;
                }
            }
        }
        *pResult = (char)s;
        ++pResult;
        cs++;
        memcpy(pResult, p + 2, s);
        pResult += (s);
        cs += s;
        lastP = p;
        //++pResult;
    }
    return cs;
}

void decompress2(int cs)
{
    char *ptr = pTempMemory;
    unsigned char *p = (unsigned char *)pCompressResult2;
    int lastS = 0, sb, s;

    do
    {
        s = (int)*p;
        ++p;

        sb = s >> 5;
        s = s & COMPRESS2_FORWARD_LIMIT;

        if (sb > 0)
        {
            // printf("GO BACK %i\n",sb);
            ptr -= sb;
            lastS -= sb;
        }
        else
        {
            ptr = memset(pTempMemory, 0, 100);
            lastS = 0;
        }
        ptr = memcpy(ptr, p, s);
        ptr = ptr + s;
        // printf("D? %s\n", pTempMemory);

        decompressCall(pTempMemory, lastS + s);
        lastS += s;
        p += s;

        cs -= (s + 1);
    } while (cs > 0);
}