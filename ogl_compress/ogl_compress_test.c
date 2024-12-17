
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ogl_compress_test.h"
#include "gl_parts.h"
#include "compress_algos.h"

char *names[] = {
    "glBegin",
    "glBindBuffer",
    "glBindVertexArray",
    "glBufferData",
    "glClear",
    "glClearAccum",
    "glClearColor",
    "glClearDepth",
    "glClearIndex",
    "glColorf",
    "glColorMask",
    "glColorPointer",
    //
    "glDepthFunc",
    "glDepthMask",
    "glDepthRange",
    "glDrawArrays",
    "glDrawElements",
    "glEnable",
    "glEnableVertexAttribArray",
    "glEnd",
    "glGenBuffers",
    "glGenVertexArrays",
    "glGetError",
    "glIndexMask",
    "glIndexPointer",
    "glLoadIdentity",
    "glLoadTransposeMatrixd",

    "glMatrixMode",
    "glMultTransposeMatrixf",
    "glOrtho",
    "glPopMatrix",
    "glPushMatrix",
    "glRotatef",
    "glVertex3f",
    "glNormal3f",
    "glVertexAttribPointer",
    //
};

#define NAMES_COUNT (sizeof(names) / sizeof(char *))

#define TEMP_MEMORY_SIZE 1024
void *pTempMemory;

void *pCompressResult = 0;
void *pCompressResult2 = 0;
void *pCompressResult3 = 0;
void *pCompressResult4 = 0;
void *pCompressResult5 = 0;
char **pReverseResult = 0;

int compressSize = 0;

int callIdx = 0;

void checkResult()
{
    if (pReverseResult)
    {
        char *p;
        for (int i = 0; i < NAMES_COUNT; i++)
        {
            p = pReverseResult[i];
            if (p == 0)
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

/**
 * This will be the dymamic loader.
 */
void decompressCall(char *p, int s)
{
    char *rp = (char *)malloc(s + 3);
    pReverseResult[callIdx] = rp;
    *rp = 'g';
    ++rp;
    *rp = 'l';
    ++rp;
    memcpy(rp, p, s);
    rp[s] = 0;
    callIdx++;
}

int sizes(char **pNames, int size)
{
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        resSize += strlen(pNames[i]) + 1;
    }
    return resSize;
}

typedef struct _CompressTestResult
{
    char *pName;
    int cs;
    int code;
} CompressTestResult;

void compressTest()
{
    int is = sizes(names, NAMES_COUNT);
    int cs = compress(names, NAMES_COUNT);
    int cs2 = compress2(names, NAMES_COUNT, 0);
    int cs3 = compress3(names, NAMES_COUNT);
    int cs4 = compress4(names, NAMES_COUNT);
    int cs5 = compress5(names, NAMES_COUNT, 2); //2 for "gl"

    printf("HITS(2) = %i\n", compress2Hits);

    pTempMemory = malloc(TEMP_MEMORY_SIZE);

    int reverseSize = NAMES_COUNT * sizeof(char *);
    pReverseResult = (char **)malloc(reverseSize);
    memset(pReverseResult, 0, reverseSize);

    // printf("|1|%s\n", (char *)pCompressResult);
    decompress();
    checkResult();

    // printf("|2|%s\n", (char *)pCompressResult2);
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress2(cs2);
    checkResult();

    // printf("|3|%s|\n", (char *)pCompressResult3);
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress3(cs3, pCompressResult3);

    void *pRes4 = malloc(cs4);
    memset(pRes4, 0, cs4);
    memcpy(pRes4, pCompressResult4, cs4);

    // printf("|4|%s|\n", (char *)pCompressResult4);
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress4(pCompressResult4, &decompressCall);
    checkResult();

    // printf("|4asm|%s|\n", (char *)pRes4);
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress4asm(pRes4, &decompressCall);
    checkResult();
    free(pRes4);

    printf("|5|@%p|\n", pCompressResult5);
    printf("|5|%s|%li\n",  (char *)pCompressResult5, strlen(pCompressResult5));
    callIdx = 0;
    memset(pReverseResult, 0, reverseSize);
    decompress5(pCompressResult5, &decompressCall);
    checkResult();

    CompressTestResult results[] = {
        {cs : cs, code : DECOMPRESS_SIZE, pName : "1"},
        {cs : cs2, code : DECOMPRESS2_SIZE, pName : "2"},
        {cs : cs3, code : DECOMPRESS3_SIZE, pName : "3"},
        {cs : cs4, code : DECOMPRESS4_SIZE, pName : "4"},
        {cs : cs4, code : DECOMPRESS4ASM_SIZE, pName : "4asm"},
        {cs : cs5, code : DECOMPRESS5_SIZE, pName : "5"},
    };

    printf("\nIS=%i\n", is);
    int numRes = sizeof(results) / sizeof(CompressTestResult);
    for (int i = 0; i < numRes; i++)
    {
        printf("%s:CS+DC= %i + %i(%x) = %i\n", results[i].pName, results[i].cs, results[i].code, results[i].code, results[i].cs + results[i].code);
    }
}