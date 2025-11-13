
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../util/log_stack.h"
#include "../util/memory.h"
#include "../util/output.h"
#include "myint_util.h"
#include "myint_test.h"
#include "myint_test_data.h"

#define NUM_TEST_CHARS 48
// res = myintOp(INT_OP_INIT_ALL, &test1, &test2, &result);
char printChars[NUM_TEST_CHARS];

const unsigned char adds[] = {1, 2, 3, 5, 7, 11, 13, 17};

#define TEST_CHARS_SIZE 60
char testChars[TEST_CHARS_SIZE];
char testRestChars[TEST_CHARS_SIZE];

int testIdx = 0;
char *testResults[10] = {NULL};

char *getTestPrintChars()
{
    if (testIdx < 10)
    {
        char *pMem = (char *)malloc(TEST_CHARS_SIZE);
        testResults[testIdx] = pMem;
        testIdx++;
        return pMem;
    }
    return NULL;
}

void printHex(unsigned char *vals, size_t sss)
{
    for (size_t i = 0; i < sss; i++)
    {
        unsigned char vvv = vals[sss - i - 1];
        printf("%x%x", vvv >> 4, vvv & 0xF);
    }
}

void testBasics()
{
    printf("Test Basics?\n");

    int okTests = 0, failedTests = 0;
    unsigned char testChars[8] = {0};
    unsigned char init = 0;
    while (init < 10)
    {
        uint64_t testValue = init;
        unsigned int byteCount = 1;
        while (byteCount <= 8)
        {
            if (byteCount > 1)
            {
                testValue = testValue << 8 | ((testValue & 0xFF) + 1);
            }
            *((uint64_t *)testChars) = testValue;

            uint64_t testResult = fromBytes(testChars, byteCount);
            if (testResult != testValue)
            {
                printf("FAIL:(E!=C)(%i) %lu|%lx != %lu|%lx\n", byteCount, testValue, testValue, testResult, testResult);
                ++failedTests;
            }
            else
            {
                ++okTests;
            }
            ++byteCount;
        }

        ++init;
    }
    char *pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "Basics-TEST: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);
    printf("Test Basics!\n");
}

void testPrint()
{
    IntTest *pTests;
    int okTests = 0, failedTests = 0;
    printf("Test print?\n");

    clear2(testChars, TEST_CHARS_SIZE);
    int res;

    IntTest *pTestsArr[] = {addTests, subTests, mulTests};

    for (int j = 0; j < 3; j++)
    {
        pTests = pTestsArr[j];
        for (int i = 0; i < NUM_MYINT_TESTS; i++)
        {
            clear2(testChars, TEST_CHARS_SIZE);
            const char *expected = pTests->ptrA;
            printBytes(pTests->aBytes, pTests->numBytesA, testChars, TEST_CHARS_SIZE);

            res = strcmp(expected, testChars);
            if (res != 0)
            {
                printf("C|%s\n", testChars);
                printf("E|%s\n", expected);
                ++failedTests;
            }
            else
            {
                ++okTests;
            }

            clear2(testChars, TEST_CHARS_SIZE);
            expected = pTests->ptrB;
            printBytes(pTests->bBytes, pTests->numBytesB, testChars, TEST_CHARS_SIZE);

            res = strcmp(expected, testChars);
            if (res != 0)
            {
                printf("C|%s\n", testChars);
                printf("E|%s\n", expected);
                ++failedTests;
            }
            else
            {
                ++okTests;
            }

            clear2(testChars, TEST_CHARS_SIZE);
            expected = pTests->ptrC;
            printBytes(pTests->cBytes, pTests->numBytesC, testChars, TEST_CHARS_SIZE);
            if (*expected == '-')
            {
                ++expected;
            }

            res = strcmp(expected, testChars);
            if (res != 0)
            {
                printf("C|%s\n", testChars);
                printf("E|%s\n", expected);
                ++failedTests;
            }
            else
            {
                ++okTests;
            }

            ++pTests;
        }
    }

    printf("PRINT-TEST: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("Test print!\n");
}

void testAddition()
{
    printf("Test ADD?\n");
    MYINT test1;
    MYINT test2;
    MYINT result;
    intOps = 0;
    int INT_INIT_CALL3(res, &test1, &test2, &result);

    printf("Allocated! %i\n", res);
    if (res)
    {
        printf("Aborted!\n");
    }

    int okTests = 0, failedTests = 0;

    IntTest *pTests = addTests;
    unsigned char *p1 = test1.data.pBytes,
                  *p2 = test2.data.pBytes,
                  *p3 = result.data.pBytes;

    for (int testIdx = 0; testIdx < NUM_MYINT_TESTS; testIdx++)
    {
        test1.data.pBytes = pTests->aBytes;
        test1.used_size = pTests->numBytesA;
        test1.size = test1.used_size;
        test2.data.pBytes = pTests->bBytes;
        test2.used_size = pTests->numBytesB;
        test2.size = test2.used_size;

        res = myintOp(INT_OP_ADD, &test1, &test2, &result, NULL);
        if (res == 0)
        {
            printMyInt(&result, testChars, NUM_TEST_CHARS);
            res = strcmp(testChars, pTests->ptrC);
            if (res != 0)
            {
                printf("A: %s + %s\n", pTests->ptrA, pTests->ptrB);
                printf("C: %s\n", testChars);
                printf("E: %s\n", pTests->ptrC);
                ++failedTests;
            }
            else
            {
                if (pTests->numBytesC == result.used_size)
                {
                    res = memcmp(pTests->cBytes, result.data.pBytes, result.used_size);
                    if (res == 0)
                    {
                        ++okTests;
                    }
                    else
                    {
                        ++failedTests;
                    }
                }
                else
                {
                    ++failedTests;
                }
            }
        }
        else
        {
            ++failedTests;
        }

        ++pTests;
    }
    test1.data.pBytes = p1;
    test2.data.pBytes = p2;
    if (okTests == 0 && failedTests == 0)
    {
        result.data.pBytes = p3;
    }

    char *pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "ADD-TEST: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);

    INT_CLEAR_CALL3(res, &test1, &test2, &result);
    intOps = 0;
    printf("Test ADD!%i\n", res);
}

void testSubtraction()
{
    printf("Test SUB?\n");
    MYINT test1;
    MYINT test2;
    MYINT result;

    int INT_INIT_CALL3(res, &test1, &test2, &result);

    printf("Allocated! %i\n", res);
    if (res)
    {
        printf("Aborted!\n");
    }

    int okTests = 0, failedTests = 0;
    int idxF = 0, idxS = 0, hasFailed = 0, value;
    unsigned int f = 0, s = 0;
    unsigned short *pUShort1, *pUShort2, *pUShort3;

    unsigned int fLimit = 0x1000, sLimit = 0x1000;

    while (f < fLimit)
    {
        pUShort1 = test1.data.pShorts;
        *pUShort1 = f;
        test1.used_size = f < 0x100 ? 1 : 2;
        s = 0;
        while (s < sLimit)
        {
            clearStack();
            test2.used_size = s < 0x100 ? 1 : 2;
            pUShort2 = test2.data.pShorts;
            *pUShort2 = s;

            int expectedInt = f - s;
            hasFailed = 0;
            res = myintOp(INT_OP_SUB, &test1, &test2, &result, NULL);
            pUShort3 = result.data.pShorts;
            value = *pUShort3;
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
            idxS++;
        }
        if (failedTests > 30)
        {
            break;
        }
        f += adds[idxF % 8];
        idxF++;
    }
    char *pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "SUB-TEST: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);

    IntTest *pTests = subTests;
    unsigned char *p1 = test1.data.pBytes, *p2 = test2.data.pBytes;

    okTests = 0;
    failedTests = 0;

    for (int testIdx = 0; testIdx < NUM_MYINT_TESTS; testIdx++)
    {
        test1.data.pBytes = pTests->aBytes;
        test1.used_size = pTests->numBytesA;
        test1.size = test1.used_size;
        test2.data.pBytes = pTests->bBytes;
        test2.used_size = pTests->numBytesB;
        test2.size = test2.used_size;

        res = myintOp(INT_OP_SUB, &test1, &test2, &result, NULL);
        if (res == 0)
        {
            char *pTestChars = testChars;
            printMyInt(&result, testChars + 1, NUM_TEST_CHARS - 1);
            if (result.sign)
            {
                *pTestChars = '-';
            }
            else
            {
                ++pTestChars;
            }

            res = strcmp(pTestChars, pTests->ptrC);
            if (res != 0)
            {
                printf("A: %s - %s\n", pTests->ptrA, pTests->ptrB);
                printf("C: %s\n", pTestChars);
                printf("E: %s\n", pTests->ptrC);
                ++failedTests;
            }
            else
            {
                if (pTests->numBytesC == result.used_size)
                {
                    res = memcmp(pTests->cBytes, result.data.pBytes, result.used_size);
                    if (res == 0)
                    {
                        ++okTests;
                    }
                    else
                    {
                        ++failedTests;
                    }
                }
                else
                {
                    ++failedTests;
                }
            }
        }
        else
        {
            ++failedTests;
        }

        ++pTests;
    }
    test1.data.pBytes = p1;
    test2.data.pBytes = p2;

    pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "SUB-TEST:2: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);

    INT_CLEAR_CALL3(res, &test1, &test2, &result);

    printf("Cleared! %i\n", res);
    printf("Test SUB!\n");
}
void testMultiplication()
{
    printf("Test MUL?\n");
    MYINT test1;
    MYINT test2;
    MYINT result;

    int INT_INIT_CALL3(res, &test1, &test2, &result);

    printf("Allocated! %i\n", res);
    if (res)
    {
        printf("Aborted!\n");
    }

    int okTests = 0, failedTests = 0;
    unsigned short *pUShort1 = 0, *pUShort2 = 0;

    int idxF = 0, idxS = 0, hasFailed = 0;
    unsigned int expectedUInt = 0, testIdx = 0;
    // unsigned long long int expectedULong = 0;
    unsigned int f = 0, s;
    unsigned int resultUInt = 0, ii;

    unsigned int fLimit = 0x1000, sLimit = 0x1000;

    while (f < fLimit)
    {
        test1.used_size = f < 0x100 ? 1 : 2;
        pUShort1 = (unsigned short *)test1.data.pBytes;
        *pUShort1 = f;

        s = 0;
        while (s < sLimit)
        {
            test2.used_size = s < 0x100 ? 1 : 2;
            pUShort2 = (unsigned short *)test2.data.pBytes;
            *pUShort2 = s;

            expectedUInt = f * s;
            hasFailed = 0;
            res = myintOp(INT_OP_MUL, &test1, &test2, &result, NULL);
            resultUInt = 0;
            ii = 0;
            while (ii < result.used_size)
            {
                resultUInt |= (result.data.pBytes[ii]) << (ii * 8);
                ++ii;
            }

            if (res == 0 && (expectedUInt == resultUInt))
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
                       *pUShort1, *pUShort2, resultUInt, resultUInt, expectedUInt, expectedUInt);
            }
            if (failedTests > 30)
            {
                break;
            }

            s += adds[idxS % 8];
            testIdx++;
            idxS++;
        }
        f += adds[idxF % 8];
        idxF++;
        if (failedTests > 30)
        {
            break;
        }
    }

    char *pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "MUL-TEST-END: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);

    if (failedTests > 0)
    {
        printf("Last: %i|%x * %i|%x => %i|%x\n", *pUShort1, *pUShort1, *pUShort2, *pUShort2, resultUInt, resultUInt);
    }

    IntTest *pTests = mulTests;
    unsigned char *p1 = test1.data.pBytes, *p2 = test2.data.pBytes;

    okTests = 0;
    failedTests = 0;

    for (int testIdx = 0; testIdx < NUM_MYINT_TESTS; testIdx++)
    {
        test1.data.pBytes = pTests->aBytes;
        test1.used_size = pTests->numBytesA;
        test1.size = test1.used_size;
        test2.data.pBytes = pTests->bBytes;
        test2.used_size = pTests->numBytesB;
        test2.size = test2.used_size;

        res = myintOp(INT_OP_MUL, &test1, &test2, &result, NULL);
        if (res == 0)
        {
            char *pTestChars = testChars;
            printMyInt(&result, testChars, NUM_TEST_CHARS);

            res = strcmp(pTestChars, pTests->ptrC);
            if (res != 0)
            {
                printf("A: %s * %s\n", pTests->ptrA, pTests->ptrB);
                printf("C: %s\n", pTestChars);
                printf("E: %s\n", pTests->ptrC);
                ++failedTests;
            }
            else
            {
                if (pTests->numBytesC == result.used_size)
                {
                    res = memcmp(pTests->cBytes, result.data.pBytes, result.used_size);
                    if (res == 0)
                    {
                        ++okTests;
                    }
                    else
                    {
                        ++failedTests;
                    }
                }
                else
                {
                    ++failedTests;
                }
            }
        }
        else
        {
            ++failedTests;
        }

        ++pTests;
    }
    test1.data.pBytes = p1;
    test2.data.pBytes = p2;

    pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "MUL-TEST-END:2: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);

    INT_CLEAR_CALL3(res, &test1, &test2, &result);

    printf("Cleared! %i\n", res);

    printf("Test MUL!\n");
}
void testDivision()
{
    printf("Test DIV?\n");
    MYINT test1;
    MYINT test2;
    MYINT result;
    MYINT rest;

    int restRes, restResInit, INT_INIT_CALL3(res, &test1, &test2, &result);
    INT_INIT_CALL1(restResInit, &rest);

    printf("Allocated! %x|%x\n", res, restResInit);

    int okTests = 0;
    int failedTests = 0;
    unsigned int f = 0, s = 0;

    unsigned int fLimit = 0x1000, sLimit = 0x500;

    unsigned char adds[] = {1, 2, 3, 5, 7, 11, 13, 17};
    int idxF = 0, idxS = 0, hasFailed = 0;
    unsigned int testIdx = 0;

    unsigned short *pUShort1, *pUShort2;

    // const char *expectedStr = "2146440093795495460279912293993145927611445";

    while (f < fLimit)
    {
        pUShort1 = (unsigned short *)test1.data.pBytes;
        *pUShort1 = f;
        test1.used_size = f < 0x100 ? 1 : 2;
        s = 2;
        while (s < sLimit)
        {
            clearStack();
            pUShort2 = (unsigned short *)test2.data.pBytes;
            *pUShort2 = s;
            test2.used_size = s < 0x100 ? 1 : 2;

            unsigned int expectedRest = f % s;
            unsigned int expected = f / s;
            hasFailed = 0;
            clear2(rest.data.pBytes, rest.size);
            res = myintOp(INT_OP_DIV, &test1, &test2, &result, &rest);
            unsigned short *pUShort3 = (unsigned short *)result.data.pBytes;
            unsigned int value = *pUShort3;
            if (result.used_size == 0)
            {
                value = 0;
            }
            if (result.used_size == 1)
            {
                value = value & 0xFF;
            }
            unsigned int restValue = 0;
            if (res == 0)
            {
                if (expected == value)
                {
                    if (rest.used_size == 0)
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
                        unsigned int numBytes = rest.used_size;
                        unsigned short *pUShort4 = (unsigned short *)rest.data.pBytes;
                        if (pUShort4 != NULL)
                        {
                            restValue = *pUShort4;
                            if (numBytes == 1)
                            {
                                restValue = restValue & 0xFF;
                            }
                            if (restValue == expectedRest)
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
                       f, s,
                       value, value,
                       restValue, restValue,
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

    char *pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "DIV-TEST-END: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);
    printf("---\n");
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
    unsigned char *pChars = test1.data.pBytes;
    test1.data.pBytes = vals;
    test1.size = 18;
    test1.used_size = 18;
    pUShort2 = (unsigned short *)test2.data.pBytes;
    *pUShort2 = 1018;
    test2.used_size = 2;
    const char *expectedDivResult = "2108487321999504381414452155199553956396";
    const char *expectedDivRest = "317";
    res = myintOp(INT_OP_DIV, &test1, &test2, &result, &rest);
    test1.data.pBytes = pChars;
    printf("DIV => %i\n", res);

    clear2(printChars, NUM_TEST_CHARS);
    int resI = printMyInt(&result, printChars, NUM_TEST_CHARS);
    if (0 != strcmp(printChars, expectedDivResult))
    {
        printf("%i!%s\n", resI, printChars);
        printf("%i?%s\n", resI, expectedDivResult);
    }

    clear2(printChars, NUM_TEST_CHARS);
    resI = printMyInt(&rest, printChars, NUM_TEST_CHARS);
    if (0 != strcmp(printChars, expectedDivRest))
    {
        printf("%i!%s\n", resI, printChars);
        printf("%i?%s\n", resI, expectedDivRest);
    }

    IntTest *pTests = divTests;
    unsigned char *p1 = test1.data.pBytes, *p2 = test2.data.pBytes;

    okTests = 0;
    failedTests = 0;

    for (int testIdx = 0; testIdx < NUM_MYINT_TESTS; testIdx++)
    {
        test1.data.pBytes = pTests->aBytes;
        test1.used_size = pTests->numBytesA;
        test1.size = test1.used_size;
        test2.data.pBytes = pTests->bBytes;
        test2.used_size = pTests->numBytesB;
        test2.size = test2.used_size;
        clearStack();

        res = myintOp(INT_OP_DIV, &test1, &test2, &result, &rest);
        if (res == 0)
        {
            clear2(testChars, NUM_TEST_CHARS);
            clear2(testRestChars, NUM_TEST_CHARS);
            printMyInt(&result, testChars, NUM_TEST_CHARS);
            
                printMyInt(&rest, testRestChars, NUM_TEST_CHARS);
            

            res = strcmp(testChars, pTests->ptrC);
            restRes = strcmp(testRestChars, pTests->ptrR);

            if (res != 0 || restRes != 0)
            {
                printf("%i|A: %s / %s\n", testIdx, pTests->ptrA, pTests->ptrB);
                printf("%i|C: %s\n", testIdx, testChars);
                printf("%i|E: %s\n", testIdx, pTests->ptrC);
                printf("%i|CR: %s\n", testIdx, testRestChars);
                printf("%i|ER: %s\n", testIdx, pTests->ptrR);

                printStack();
                ++failedTests;
            }
            else
            {
                if (pTests->numBytesC == result.used_size)
                {
                    res = memcmp(pTests->cBytes, result.data.pBytes, result.used_size);
                    if (res == 0)
                    {
                        ++okTests;
                    }
                    else
                    {
                        ++failedTests;
                    }
                }
                else
                {
                    ++failedTests;
                }
            }
        }
        else
        {
            ++failedTests;
        }
        if (failedTests > 30)
        {
            break;
        }

        ++pTests;
    }
    test1.data.pBytes = p1;
    test2.data.pBytes = p2;
    pText = getTestPrintChars();
    snprintf(pText, TEST_CHARS_SIZE, "DIV-TEST-END:2: #ok=%i, #failed=%i\n", okTests, failedTests);
    printf("%s", pText);

   INT_CLEAR_CALL3(res, &test1, &test2, &result);

    printf("Cleared! %i\n", res);

    printf("Test DIV!\n");
}

void printTestResults()
{
    for (int i = 0; i < testIdx; i++)
    {
        printf("%s", testResults[i]);
    }
    // testResults[testIdx]
}
