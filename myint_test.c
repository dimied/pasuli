
#include <stdio.h>
#include <string.h>
#include "log_stack.h"
#include "memory.h"
#include "myint_test.h"
#include "myint_test_data.h"

#define NUM_TEST_CHARS 48
// res = myintOp(INT_OP_INIT_ALL, &test1, &test2, &result);
char printChars[NUM_TEST_CHARS];

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
    

    printf("Clear ...\n");
    myintCleanup();
    myintOp(INT_OP_CLEAR_ALL, &test1, &test2, &result);
    printf("Clear done\n");
}

#define TEST_CHARS_SIZE 60

void testPrint() {
    IntTest* pTests = addTests;
    print("Test print?\n");
    char testChars[TEST_CHARS_SIZE];
    clear2(testChars, TEST_CHARS_SIZE);

    for(int i=0; i < NUM_MYINT_TESTS;i++) {
        const char* expected = pTests->ptrA;
        printBytes(pTests->aBytes, pTests->numBytesA, testChars, TEST_CHARS_SIZE);
        int res = strcmp()
    }
    print("Test print!\n");
}

void testAddition() {
    MYINT test1;
    MYINT test2;
    MYINT result;
}
void testSubtraction() {

}
void testMultiplication() {

}
void testDivision() {
    MYINT test1;
    MYINT test2;
    MYINT result;
    int okTests = 0;
    int failedTests = 0;
    unsigned int f = 0, s=0;

    int res;
    unsigned int fLimit = 0x1000, sLimit = 0x1000;

        unsigned char adds[] = {1, 2, 3, 5, 7, 11, 13, 17};
    int idxF = 0, idxS = 0, hasFailed = 0;
    unsigned int testIdx = 0;

    unsigned short* pUShort1, * pUShort2;

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
}