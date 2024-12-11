#include <stdio.h> // printf
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#include "interpreter.h"
#include "interpreter_progs.h"

#include "myint.h"
#include "log_stack.h"
#include "prime_compressor.h"
#include "myint_test.h"

float constants[] = {PI};

float circleParams[] = {1};

float uParams[] = {0, PI * 0.5, PI};
float vParams[] = {0, PI, 2 * PI};
char nParamsU = 3;
char nParamsV = 3;

void sphere(float u, float v, float *pParams, float *pResults)
{
    float r = *pParams;
    float rsin = r * sinf(u);
    *pResults = rsin * cosf(v);
    ++pResults;
    *pResults = rsin * sinf(v);
    ++pResults;
    *pResults = r * cosf(u);
}

int interpreterRes;

void testInterpreter(int nU, int nV, float *pU, float *pV, float *pResults)
{
    interpreterRes = parseCode(
        pU,
        nU,
        pV,
        nV,
        DEFINE_STEPS(1, 1),
        constants,
        circleParams,
        CIRCLE_PROG_BYTES,
        circleProgs,
        pResults);

    zeroWithinLimit(pResults, 0.000001, nU * nV * 3);
}

void testRaw(int nU, int nV, float *pU, float *pV, float *pResults)
{
    float *pRes = pResults;
    for (int i = 0; i < nU; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            sphere(pU[i], pV[j], circleParams, pResults);
        }
    }
    zeroWithinLimit(pRes, 0.000001, nU * nV * 3);
}

void printResultLine(int t, float u, float v, float *pRes)
{
    printf("%i| (%.4f %.4f) -> (%.8f %.8f %.8f)\n", t, u, v, pRes[0], pRes[1], pRes[2]);
}

void printResult(float *pRes, float *pRes2)
{
    for (int i = 0; i < nParamsU; i++)
    {
        for (int j = 0; j < nParamsV; j++)
        {
            printResultLine(1, uParams[i], vParams[j], pRes);
            printResultLine(2, uParams[i], vParams[j], pRes2);
            pRes += 3;
            pRes2 += 3;
            printf("\n-\n");
        }
    }
}

void clear(void *pData, unsigned int size)
{
    if (pData != NULL)
    {
        unsigned char *pChars = (unsigned char *)pData;
        unsigned char *pCharsEnd = pChars + size;
        while (pChars != pCharsEnd)
        {
            *pChars = 0;
            ++pChars;
        }
    }
}


void testCompress();

int main()
{
    // Verwirrend
    // char a = *(pResult++);
    //  printf("Interpreter test %i\n", CMD_SETUP_LOAD_PARAMS(1));
#if 0
    size_t allocSize = nParamsV * nParamsU * 3;
    float *pResults = (float *)malloc(allocSize * sizeof(float));
    float *pResults2 = (float *)malloc(allocSize * sizeof(float));
    nullify(pResults, allocSize);
    nullify(pResults2, allocSize);
    // float *pRes = pResults;
    float *pRes2 = pResults2;

    // parseCodeText(CIRCLE_PROG_BYTES, circleProgs);

    timeval tp;
    timeval tp2;

    setParseCodeOptions(0);

    gettimeofday(&tp, NULL);

    parseCode(
        uParams,
        nParamsU,
        vParams,
        nParamsV,
        DEFINE_STEPS(1, 1),
        constants,
        circleParams,
        CIRCLE_PROG_BYTES,
        circleProgs,
        pResults);

    gettimeofday(&tp2, NULL);
    long long int start = TIME_MICRO(tp);
    long long int end = TIME_MICRO(tp2);

    long long int duration = end - start;

    gettimeofday(&tp, NULL);

    for (int i = 0; i < nParamsU; i++)
    {
        for (int j = 0; j < nParamsV; j++)
        {
            sphere(uParams[i], vParams[j], circleParams, pResults2);
            pResults2 += 3;
        }
    }

    pResults2 = pRes2;
    zeroWithinLimit(pResults2, 0.000001, nParamsU * nParamsV * 3);

    gettimeofday(&tp2, NULL);

    long long int start2 = TIME_MICRO(tp);
    long long int end2 = TIME_MICRO(tp2);

    long long int duration2 = end2 - start2;
    pResults2 = pRes2;

    ////
    size_t nU = 1000, nV = 1000;

    float *pU = (float *)malloc(nU * sizeof(float));
    float *pV = (float *)malloc(nV * sizeof(float));
    size_t resSize = nU * nV * 3;
    size_t resAllocSize = resSize * sizeof(float);
    float *pResX = (float *)malloc(resAllocSize);
    float *pResX2 = (float *)malloc(resAllocSize);

    setParseCodeOptions(0);

    if (pU != NULL && pV != NULL && pResX != NULL)
    {
        nullify(pResX, resSize);
        gettimeofday(&tp, NULL);
        testInterpreter(nU, nV, pU, pV, pResX);
        gettimeofday(&tp2, NULL);

        OverflowInfo info;
        getOverflowInfo(&info);

        printf("\nINT-RES: %i| u=%i , v=%i , mode=%i \n", interpreterRes, info.indexU, info.indexV, info.mode);
    }
    long long int durationX = (TIME_MICRO(tp2)) - (TIME_MICRO(tp));

    if (pU != NULL && pV != NULL && pResX2 != NULL)
    {
        nullify(pResX2, resSize);
        gettimeofday(&tp, NULL);
        testRaw(nU, nV, pU, pV, pResX2);
        gettimeofday(&tp2, NULL);
    }
    long long int durationX2 = (TIME_MICRO(tp2)) - (TIME_MICRO(tp));

    if (pU != NULL)
    {
        free(pU);
    }
    if (pV != NULL)
    {
        free(pV);
    }
    if (pResX != NULL)
    {
        free(pResX);
    }
    if (pResX2 != NULL)
    {
        free(pResX2);
    }
    ////
    // float pRes = pResults;
    // printResult(pRes, pRes2);

    free(pResults);
    free(pResults2);
    printf("1|Time(micro): %llu\n", duration);
    printf("2|Time(micro): %llu\n", duration2);
    if (duration2 < 1)
    {
        duration2 = 1;
    }
    printf("X|Time: 1/2 = %llu\n", duration / duration2);

    printf("(%li, %li)=>%li\n", nU, nV, nU * nV);
    printf("1|Time(micro): %llu\n", durationX);
    printf("2|Time(micro): %llu\n", durationX2);
    if (durationX < 1)
    {
        durationX = 1;
    }
    if (durationX2 < 1)
    {
        durationX2 = 1;
    }
    printf("X|Time: 1/2 = %llu, 2/1 = %llu\n", durationX / durationX2, durationX2 / durationX);
#endif
    //unsigned char *pCompressorRes = (unsigned char *)malloc(CIRCLE_PROG_BYTES);

    //compress(circleProgs, CIRCLE_PROG_BYTES, pCompressorRes, CIRCLE_PROG_BYTES);

    /*
    unsigned char val[4];
    unsigned int valI = 0x01020305;
    unsigned int* pVX = (unsigned int*)&val[0];
    *pVX = valI;
    printf("V: %i %i %i %i\n", val[0], val[1], val[2], val[3]);
    */
#if 1
    testBasics();
    printf("----\n");
    testPrint();
    printf("----\n");
    testAddition();
    printf("----\n");
    testSubtraction();
    printf("----\n");
    testMultiplication();
    printf("----\n");
    testDivision();
    printf("----\n");
#endif
    printTestResults();
    testCompress();

    printf("PTR-SIZE: %li\n", sizeof(unsigned char *));

    return 0;
}

void testCompress()
{
    printf("COMPRESS?\n");
    unsigned char testData[] = {
        0xFE,
        0xA,
        0xBA,
        0x01,
        0x10,
        0x23,
        0x54,
        0x74,
        0x43,
        0x56,
        0x4,
        0x1,
        0x12,
        0x32,
        0x56,
        0x91,
        0x81,
        0x53,
        0x19,
        0xA3,
        0x00,
        0x12,
        0x39,
        0x95
        };
    char pResult2[80] = {0};
    int res = printBytes(testData, sizeof(testData), pResult2, 40);
    printf("%i|%s\n", res, pResult2);
    
    unsigned char pResult[20] = {0};
    compressType = 0;
    compress(testData, sizeof(testData), pResult, 20);
    printf("COMPRESS!\n");
}
