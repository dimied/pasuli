
#include <stdio.h> // printf
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#include "util/output.h"
#include "interpreter/interpreter.h"
#include "interpreter/interpreter_progs.h"

#include "myint/myint.h"
#include "util/log_stack.h"
#include "util/util_macros.h"
#include "compressor/prime_compressor.h"
#include "myint/myint_test.h"
#include "interpreter_example_tests.h"

float constants[] = {PI};

float circleParams[] = {1};

float uParams[] = {0, PI * 0.5, PI};
float vParams[] = {0, PI, 2 * PI};
char nParamsU = 3, nParamsV = 3;

void sphereExample(float u, float v, float *pParams, float *pResults)
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
            sphereExample(pU[i], pV[j], circleParams, pResults);
        }
    }
    zeroWithinLimit(pRes, 0.000001, nU * nV * 3);
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

void interpreter_tests() {
    // Verwirrend
    // char a = *(pResult++);
    //  printf("Interpreter test %i\n", CMD_SETUP_LOAD_PARAMS(1));

    size_t allocSize = nParamsV * nParamsU * 3;
    float *pResults = (float *)malloc(allocSize * sizeof(float));
    float *pResults2 = (float *)malloc(allocSize * sizeof(float));
    nullify(pResults, allocSize);
    nullify(pResults2, allocSize);
    // float *pRes = pResults;
    float *pRes2 = pResults2;

    // parseCodeText(CIRCLE_PROG_BYTES, circleProgs);

    struct timeval tp;
    struct timeval tp2;

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
            sphereExample(uParams[i], vParams[j], circleParams, pResults2);
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


}