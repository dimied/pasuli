#include <stdio.h> // printf
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#include "interpreter.h"
#include "interpreter_progs.h"

#include "myint.h"
#include "log_stack.h"
#include "prime_compressor.h"

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

void testInts()
{
    printf("Start tests\n");
    MYINT test1;
    MYINT test2;
    MYINT result;

    int res = myintOp(INT_OP_INIT_ALL, &test1, &test2, &result);

    printf("Allocated! %i\n", res);

    unsigned int f = 1;
    unsigned int *pUInt = (unsigned int *)test1.data.pBytes;
    test1.used_size = 1;
    *pUInt = f;

    unsigned int s = 0x1210;
    pUInt = (unsigned int *)test2.data.pBytes;
    test2.used_size = 2;
    *pUInt = s;

    res = myintOp(INT_OP_ADD, &test1, &test2, &result);
    pUInt = (unsigned int *)result.data.pBytes;
    // unsigned short *pUShort = (unsigned short *)result.pBytes;
    printf("%i|ADD %i|%x + %i|%x = %i|%x\n", res, f, f, s, s, *pUInt, *pUInt);

    unsigned short *pUShort1 = 0, *pUShort2 = 0;
    pUShort1 = (unsigned short *)test1.data.pBytes;
    pUShort2 = (unsigned short *)test2.data.pBytes;
    f = 256;
    s = 1;
    *pUShort1 = f;
    test1.used_size = 2;
    *pUShort2 = s;

    res = myintOp(INT_OP_MUL, &test1, &test2, &result);
    pUInt = (unsigned int *)result.data.pBytes;
    printf("%i|MUL %i|%x + %i|%x = %i|%x\n", res, f, f, s, s, *pUInt, *pUInt);

    int okTests = 0, failedTests = 0;

    printf("MUL-TEST!");

    unsigned char adds[] = {1, 2, 3, 5, 7, 11, 13, 17};
    int idxF = 0, idxS = 0, hasFailed = 0;
    unsigned int expectedUInt = 0, testIdx = 0;
    // unsigned long long int expectedULong = 0;
    f = 0;

    MYINT add1;
    MYINT add2;

    myintOp(INT_OP_INIT_SRC | INT_OP_INIT_SRC2, &add1, &add2, &result);

    unsigned int fLimit = 0x1000, sLimit = 0x1000;

    while (f < fLimit)
    {
        pUShort1 = (unsigned short *)test1.data.pBytes;
        *pUShort1 = f;
        s = 0;
        while (s < sLimit)
        {
            pUShort2 = (unsigned short *)test2.data.pBytes;
            *pUShort2 = s;

            expectedUInt = f * s;
            hasFailed = 0;
            res = myintOp(INT_OP_MUL, &test1, &test2, &result);
            pUInt = (unsigned int *)result.data.pBytes;
            if (res == 0 && (expectedUInt == *pUInt))
            {
                ++okTests;
            }
            else
            {
                ++failedTests;
                hasFailed = 1;
            }
            if (hasFailed > 0 && failedTests < 20)
            {
                printf("Failed: %i * %i = %i|%x <> Ex=%i|%x\n",
                       *pUShort1, *pUShort2, *pUInt, *pUInt, expectedUInt, expectedUInt);
            }
            if (failedTests > 30)
            {
                break;
            }

            s += adds[idxS % 8];
            testIdx++;
            if (testIdx % 1000000 == 0)
            {
                printf("Test %i\n", testIdx);
            }
            idxS++;
        }
        f += adds[idxF % 8];
        idxF++;
        if (failedTests > 30)
        {
            break;
        }
    }

    printf("MUL-TEST-END: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("Last: %i|%x * %i|%x => %i|%x\n", *pUShort1, *pUShort1, *pUShort2, *pUShort2, *pUInt, *pUInt);

#define NUM_TEST_CHARS 48
    // res = myintOp(INT_OP_INIT_ALL, &test1, &test2, &result);
    char printChars[NUM_TEST_CHARS];

    printf("---\n");
    res = printMyInt(&test1, printChars, NUM_TEST_CHARS);
    printf("%i|SRC:%s\n", res, printChars);

    res = printMyInt(&test2, printChars, NUM_TEST_CHARS);
    printf("%i|SRC2:%s\n", res, printChars);
    res = printMyInt(&result, printChars, NUM_TEST_CHARS);
    printf("%i|RES:%s\n", res, printChars);

    unsigned char vals[] = {
        0x35,
        0x34,
        0x0A,
        0xfE,

        0x37,
        0x56,
        0x01,
        0x54,

        0x3,
        0x0,
        0x30,
        0x2,

        0x23,
        0xC,
        0xD,
        0xD2,
        0xA3,
        0x18};
    const char *expectedStr = "2146440093795495460279912293993145927611445";
    // unsigned char vals2[sizeof(vals)];
    size_t sss = sizeof(vals);
    printf("S: %li\n", sss);

    for (size_t i = 0; i < sss; i++)
    {
        unsigned char vvv = vals[sss - i - 1];
        printf("%x%x", vvv >> 4, vvv & 0xF);
    }
    printf("\n");
    MYINT testVal;
    testVal.data.pBytes = vals;
    testVal.used_size = sss;
    res = printMyInt(&testVal, printChars, NUM_TEST_CHARS);

    printf("%i|TEST: \n%s\n%s\n", res, printChars, expectedStr);

    printf("---\n");

    okTests = 0;
    failedTests = 0;
    f = 0;

    while (f < fLimit)
    {
        pUShort1 = (unsigned short *)test1.data.pBytes;
        *pUShort1 = f;
        s = 0;
        while (s < sLimit)
        {
            clearStack();
            pUShort2 = (unsigned short *)test2.data.pBytes;
            *pUShort2 = s;

            int expectedInt = f - s;
            hasFailed = 0;
            res = myintOp(INT_OP_SUB, &test1, &test2, &result);
            unsigned short *pUShort3 = (unsigned short *)result.data.pBytes;
            int value = *pUShort3;
            if (result.sign)
            {
                value = -value;
            }
            if (res == 0 && (expectedInt == value))
            {
                ++okTests;
            }
            else
            {
                ++failedTests;
                hasFailed = 1;
            }
            if (hasFailed > 0 && failedTests < 20)
            {
                printf("%i|Failed: %i - %i = %i|%x <> Ex=%i|%x\n", res,
                       *pUShort1, *pUShort2, value, value, expectedInt, expectedInt);

                printStack();
            }
            if (failedTests > 30)
            {
                break;
            }

            s += adds[idxS % 8];
            testIdx++;
            if (testIdx % 1000000 == 0)
            {
                printf("Test %i\n", testIdx);
            }
            idxS++;
        }
        f += adds[idxF % 8];
        idxF++;
        if (failedTests > 30)
        {
            break;
        }
    }
    printf("SUB-TEST-END: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("---\n");
    okTests = 0;
    failedTests = 0;
    f = 0;

    while (f < fLimit)
    {
        pUShort1 = (unsigned short *)test1.data.pBytes;
        *pUShort1 = f;
        s = 2;
        while (s < sLimit)
        {
            clearStack();
            pUShort2 = (unsigned short *)test2.data.pBytes;
            *pUShort2 = s;

            unsigned int expectedRest = f % s;
            unsigned int expected = f / s;
            hasFailed = 0;
            res = myintOp(INT_OP_DIV, &test1, &test2, &result);
            unsigned short *pUShort3 = (unsigned short *)result.data.pBytes;
            unsigned int value = *pUShort3;
            unsigned int rest = 0;
            if (res == 0)
            {
                if (expected == value && result.rest != NULL)
                {
                    if (result.rest->used_size == 0)
                    {
                        if (expectedRest == 0)
                        {
                            okTests++;
                        }
                        else
                        {
                            hasFailed++;
                        }
                    }
                    else
                    {
                        unsigned short *pUShort4 = (unsigned short *)result.rest->data.pBytes;
                        if (pUShort4 != NULL)
                        {
                            rest = *pUShort4;
                            if (rest == expectedRest)
                            {
                                ++okTests;
                            }
                            else
                            {
                                hasFailed = 1;
                            }
                        }
                        else
                        {
                            hasFailed = 1;
                        }
                    }
                }
                else
                {
                    hasFailed = 1;
                }
            }
            else
            {
                hasFailed = 1;
            }

            failedTests += hasFailed;

            if (hasFailed > 0 && failedTests < 20)
            {
                printf("%i|Failed: %i / %i = %i|%x (rest=%i|%x) <> Ex=%i|%x (rest=%i|%x)\n", res,
                       *pUShort1, *pUShort2,
                       value, value,
                       rest, rest,
                       expected, expected,
                       expectedRest, expectedRest);

                printStack();
            }
            if (failedTests > 30)
            {
                break;
            }

            s += adds[idxS % 8];
            testIdx++;
            if (testIdx % 1000000 == 0)
            {
                printf("Test %i\n", testIdx);
            }
            idxS++;
        }
        f += adds[idxF % 8];
        idxF++;
        if (failedTests > 30)
        {
            break;
        }
    }

    printf("DIV-TEST-END: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("---\n");
    unsigned char *pChars = test1.data.pBytes;
    test1.data.pBytes = vals;
    test1.size = 18;
    test1.used_size = 18;
    pUShort2 = (unsigned short *)test2.data.pBytes;
    *pUShort2 = 1018;
    test2.used_size = 2;
    const char *expectedDivResult = "2108487321999504381414452155199553956396";
    const char *expectedDivRest = "317";
    res = myintOp(INT_OP_DIV, &test1, &test2, &result);
    test1.data.pBytes = pChars;
    printf("DIV => %i\n", res);

    clear2(printChars, NUM_TEST_CHARS);
    int resI = printMyInt(&result, printChars, NUM_TEST_CHARS);
    printf("%i!%s\n", resI, printChars);
    printf("%i?%s\n", resI, expectedDivResult);

    clear2(printChars, NUM_TEST_CHARS);
    resI = printMyInt(result.rest, printChars, NUM_TEST_CHARS);
    printf("%i!%s\n", resI, printChars);
    printf("%i?%s\n", resI, expectedDivRest);

    printf("Clear ...\n");
    myintCleanup();
    myintOp(INT_OP_CLEAR_ALL, &test1, &test2, &result);
    printf("Clear done\n");
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
    unsigned char *pCompressorRes = (unsigned char *)malloc(CIRCLE_PROG_BYTES);

    compress(circleProgs, CIRCLE_PROG_BYTES, pCompressorRes, CIRCLE_PROG_BYTES);

    /*
    unsigned char val[4];
    unsigned int valI = 0x01020305;
    unsigned int* pVX = (unsigned int*)&val[0];
    *pVX = valI;
    printf("V: %i %i %i %i\n", val[0], val[1], val[2], val[3]);
    */

    // testInts();
    testCompress();

    printf("PTR-SIZE: %li\n", sizeof(unsigned char *));

    // compress(0, circleProgs, CIRCLE_PROG_BYTES, pCompressorRes, CIRCLE_PROG_BYTES);

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
        0x56};
    char pResult2[80] = {0};
    int res = printBytes(testData, sizeof(testData), pResult2, 20);
    printf("%i|%s\n", res, pResult2);
    unsigned char pResult[20] = {0};
    compressType = 0;
    compress(testData, sizeof(testData), pResult, 20);
    printf("COMPRESS!\n");
}
