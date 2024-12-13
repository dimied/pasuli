

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ogl_test.h"

#define NAMES_COUNT 20

char *names[NAMES_COUNT] = {
    "glClear",
    "glClearAccum",
    "glClearColor",
    "glClearDepth",
    "glClearIndex",
    "glColorMask",
    "glColorPointer",
    //
    "glDepthFunc",
    "glDepthMask",
    "glDepthRange",
    "glDrawArrays",
    "glIndexMask",
    "glIndexPointer",
    "glLoadIdentity",
    "glLoadTransposeMatrixd",

    "glMatrixMode",
    "glMultTransposeMatrixf",
    "glOrtho",
    "glPopMatrix",
    "glPushMatrix",
    //
};

void *pCompressResult = NULL;
void *pCompressResult2 = NULL;
char **pDecompressResult = NULL;

int compressSize = 0;

int sizes(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        resSize += strlen(pNames[i]) + 1;
    }
    return resSize;
}

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

#define COMPRESS2_BACKWARD_LIMIT 0x7
#define COMPRESS2_FORWARD_LIMIT 0x1F

int compress2Hits = 0;
int compress2(char **pNames, int size)
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
    char *lastP = NULL;

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i];
        int s = strlen(p) - 2;
        // Error case
        if (s > COMPRESS2_FORWARD_LIMIT)
        {
            return resSize * 2;
        }

        if (lastP != NULL)
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
                    printf("HIT: %s & %s\n", lastP, p);
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

void decompressCall(char *p, int s);

#define TEMP_MEMORY_SIZE 1024
void *pTempMemory;

void decompress()
{
    char *p = (char *)pCompressResult;

    for (int i = 0; i < NAMES_COUNT; i++)
    {
        int s = (int)*p;
        decompressCall(p + 1, s);
        p += s + 1;
    }
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

int callIdx = 0;
/**
 * This will be the dymamic loader.
 */
void decompressCall(char *p, int s)
{
    char *rp = (char *)malloc(s + 3);
    pDecompressResult[callIdx] = rp;
    *rp = 'g';
    ++rp;
    *rp = 'l';
    ++rp;
    memcpy(rp, p, s);
    rp[s] = 0;
    callIdx++;
}

void checkDecompress()
{
    if (pDecompressResult)
    {
        char *p;
        for (int i = 0; i < NAMES_COUNT; i++)
        {
            p = pDecompressResult[i];
            if (p == NULL)
            {
                printf("DECOMPRESS FAILED @%i\n", i);
            }
            else
            {
                int res = strcmp(names[i], p);
                if (res != 0)
                {
                    printf("%i|RES =%i\n", i, res);
                    printf("O: %s\n", names[i]);
                    printf("C: %s\n", p);
                }
            }
        }
        return;
    }
    printf("Decompress failed\n");
}

#include "ogl_names.h"

int main()
{
    printf("OGL TEST\n");
#if 0
    int is = sizes(names, NAMES_COUNT);
    int cs = compress(names, NAMES_COUNT);
    int cs2 = compress2(names, NAMES_COUNT);

    //printf("|1|%s\n", (char *)pCompressResult);
    //printf("|2|%s\n", (char *)pCompressResult2);
    printf("HITS(2) = %i\n", compress2Hits);

    pTempMemory = malloc(TEMP_MEMORY_SIZE);

    pDecompressResult = (char **)malloc(NAMES_COUNT * sizeof(char *));

    decompress();
    checkDecompress();
    callIdx = 0;
    decompress2(cs2);
    checkDecompress();

    //3rd option: split names
    // - store names as list
    // - use indices to merge strings
    // - one byte index for raw values
    // - signed bytes means that indices follow to be merged

    printf("\nIS=%i | CS=%i | CS2=%i\n\n", is, cs, cs2);
#endif

    int size = 0,l;
    OGL_FUNC_DESC *pNames = getNames(&size);
    printf("#names = %i\n", size);

    for (int i = 0; i < size; i++)
    {
        char *p = pNames[i].name;
        l = 0;
        while (l < OGL_FUNC_DESC_NAME_LENGTH)
        {
            if (p[l] == 0)
            {
                break;
            }
            l++;
        }
        if (l == OGL_FUNC_DESC_NAME_LENGTH)
        {
            printf("HIT: @%i\n", i);
        }
    }

    return 0;
}