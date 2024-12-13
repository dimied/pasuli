
//#if USE_START
#include <stdio.h> // printf
#include <stdlib.h>
//#include <gnu/lib-names.h>


#include <sys/time.h>
#include <math.h>

#include "util/output.h"
#include "interpreter/interpreter.h"
#include "interpreter/interpreter_progs.h"

#include "myint/myint.h"
#include "util/log_stack.h"
#include "compressor/prime_compressor.h"
#include "myint/myint_test.h"
#include "interpreter_example_tests.h"

void testCompress();

int main()
{
#if 1
    interpreter_tests();
    printf("----\n");
#endif
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
    printTestResults();
#endif
#if 1
    printf("\n---\n");
    testCompress();
#endif
    printf("MYINT-SIZE: %li\n", sizeof(MYINT));
    // printf("PTR-SIZE: %li\n", sizeof(unsigned char *));
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
        0x95,
        0x57,
        0x01,
        0x78,
        0x7D,
        0x11,
        0x93};
    char pResult2[80] = {0};
    int res = printBytes(testData, sizeof(testData), pResult2, 80);
    printf("%i|%s\n", res, pResult2);

    unsigned char pResult[30] = {0};
    compressType = 0;
    compress(testData, sizeof(testData), pResult, 30);
    printf("COMPRESS!\n");
}
