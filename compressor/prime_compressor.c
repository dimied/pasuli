#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prime_compressor.h"
#include "../myint/myint.h"
#include "../util/memory.h"

int compressType = 1;

#define NUM_PRIMES 256
#define NUM_PRIMES_ALL 256 * 240 // 1024 * 500
#define NUM_PRIMES_TO_CHECK NUM_PRIMES * 4

#if NUM_PRIMES_ALL < NUM_PRIMES_TO_CHECK
#define NUM_PRIMES_ALL NUM_PRIMES
#endif

#define NUM_PRIMES_ALL_RESERVE (NUM_PRIMES_ALL + 2)

#define BYTE_LIMIT 256

#define COMPRESS_INIT_STEP 0
#define COMPRESS_CHECK_DIVISIBALITY_STEP 1

#define NUM_SIMPLE_CHECKS 100

#include <sys/time.h>
#include "../util/util_macros.h"

#define PRINT_CHARS_SIZE 80

char printCompressChars[PRINT_CHARS_SIZE];
char printCompressChars2[PRINT_CHARS_SIZE];
char printCompressChars3[20];

void compress(void *pData, unsigned int size, void *pResultData, int resultSize)
{
    unsigned int *primes = (unsigned int *)malloc(NUM_PRIMES_ALL_RESERVE * sizeof(int));
    unsigned int *primesSq = (unsigned int *)malloc(NUM_PRIMES_ALL_RESERVE * sizeof(uint64_t));
    int *primesCounters = (int *)malloc(NUM_PRIMES_ALL_RESERVE * sizeof(int));
    unsigned char *pCurrentData = (unsigned char *)malloc(size * sizeof(char));
    memcpy(pCurrentData, pData, size);
    primes[0] = 2;
    primes[1] = 3;
    primesSq[0] = 4;
    primesSq[1] = 9;
    // primes[2] = 5;
    int i = 0, primeIdx = 2; //, mode = 0;
    unsigned int p = 5;
    // unsigned char *pUC = (unsigned char *)pResultData;
    // unsigned char *pSrcUC = (unsigned char *)pData;
    timeval tp;
    timeval tp2;
    printf("LIMIT: %u", NUM_PRIMES_ALL);

    gettimeofday(&tp, NULL);

    while (primeIdx < NUM_PRIMES_ALL && p < 0x70000000)
    {
        i = 1;

        while (i < primeIdx && (p % primes[i] != 0))
        {
            if (primesSq[i] > p)
            {
                i = primeIdx;
                break;
            }
            ++i;
        }
        if (i == primeIdx)
        {
            primes[primeIdx] = p;
            primesSq[primeIdx++] = (uint64_t)p * (uint64_t)p;
        }

        p += 2;
#if 0
        i = 2;

        while (i < primeIdx && (p % primes[i] != 0))
        {
            ++checks;
            ++checks;
            if (primesSq[i] > p)
            {
                p2 = p;
                break;
            }
            ++i;
        }
        if (i == primeIdx)
        {
            p2 = p;
        }

        if(p2 > 0) {
            primes[primeIdx] = p2;
            primesSq[primeIdx++] = (uint64_t)p2 * (uint64_t)p2;
        }

        p += 4;
#endif
    }
    gettimeofday(&tp2, NULL);

    long long int start2 = TIME_MICRO(tp), duration2 = TIME_MICRO(tp2);

    duration2 -= start2;

    if (compressType == 0)
    {
        i = 0;
        int numTries = 1; // 256 * 16;
        unsigned int resUInt, add = 0;
        int testIdx = 0, restValue = 0;
        MYINT testedNumber;
        MYINT divisor;
        MYINT adder;
        MYINT result;
        nullifyMyInt(&testedNumber);
        nullifyMyInt(&divisor);
        nullifyMyInt(&adder);
        nullifyMyInt(&result);

        int res = myDataOp(REALLOC_ALLOC, &testedNumber.data.pBytes, size, 0);
        if (res != 0)
        {
            printf("ALLOC FAILED!\n");
            return;
        }
        
        memcpy(testedNumber.data.pBytes, pCurrentData, size);
        testedNumber.used_size = size;
        testedNumber.size = size;

        clear2(printCompressChars, PRINT_CHARS_SIZE);
        printMyInt(&testedNumber, printCompressChars, PRINT_CHARS_SIZE);
        res = strlen(printCompressChars);
        printf("|%s|%i|%u\n", printCompressChars, res, size);

        res = myintOp(INT_OP_INIT_ALL, &divisor, &adder, &result);
        if (res != 0)
        {
            printf("INIT FAILED!\n");
            return;
        }

        // Different scenarios
        // px: prime x, ex: exponent for prime px
        // 1. pure
        // 2. invert
        // 3. incrementing/adding to different bytes
        // 4. reversing input
        // 5. switching nibbles
        // 6. inverting only a subset of byte bits
        //   e.g. 0110 1100 means invert only these bits
        // 7. extending prime range by
        //   storing bitmask describing used primes and
        //   e.g. each bits stands for several primes
        //   0110 1000 means 0-7 not used, 8-15 16-23 32-39 used
        // 8. find patterns and cut them out
        // 9. find sum of products with minimal distance to result
        //  p1e1...pnen + pxex...pyey + ...
        // TODO:
        //  collect and compare results

        numTries = 4;

        unsigned char *pTemp = testedNumber.data.pBytes;
        unsigned char *pDiv = divisor.data.pBytes;
        unsigned short *pUShort;
        int lastPrimesIdx = NUM_PRIMES_TO_CHECK;

        while (testIdx < numTries)
        {
            printf("++%i+++\n",testIdx);
            for (int i = 0; i <= lastPrimesIdx; i++)
            {
                primesCounters[i] = 0;
            }
            if (testedNumber.data.pBytes != pTemp)
            {
                printf("FREE!\n");
                free(testedNumber.data.pBytes);
                //free(testedNumber.data.pBytes);
                testedNumber.data.pBytes = (unsigned char*)malloc(size);
                memcpy(testedNumber.data.pBytes, pCurrentData, size);
                //testedNumber.data.pBytes = pTemp;
                testedNumber.used_size = size;
                testedNumber.size = size;
            }
            if (divisor.data.pBytes != pDiv)
            {
                printf("Divisor change: %i\n", testIdx);
            }

            if (1==0 && testIdx > 0)
            {
                res = memcmp(testedNumber.data.pBytes, pCurrentData, size);
                printf("CMP: %i\n", res);
            }

            //memcpy(pTemp, pCurrentData, size);

            if (1 == 0 && add > 0 && add < 256)
            {
                printf("ADD: %i\n", add);
                adder.data.pBytes[0] = (unsigned char)add;
                adder.used_size = 1;
                res = myintOp(INT_OP_ADD, &testedNumber, &adder, &result);
                if (res)
                {
                    printf("ADD FAILED: %i\n", res);
                    break;
                }

                testedNumber.data.pBytes = result.data.pBytes;
                testedNumber.size = result.size;
                testedNumber.used_size = result.used_size;

                result.data.pBytes = NULL;
                result.size = 0;
                result.used_size = 0;
            }

            restValue = 0;
            pUShort = divisor.data.pShorts;
            
            primeIdx = 0;

            printf("DIVs?%i\n", primeIdx);
            for (; primeIdx < NUM_PRIMES;)
            {
                unsigned int prime = primes[primeIdx];
                if (prime < 256)
                {
                    divisor.data.pBytes[0] = (unsigned char)prime;
                    divisor.used_size = 1;
                }
                else
                {
                    *pUShort = (unsigned short)prime;
                    divisor.used_size = 2;
                }

                clear2(printCompressChars3, 20);
                printMyInt(&divisor, printCompressChars3, 20);
                printf("DIV| %s | %u/%u\n", 
                printCompressChars3, divisor.used_size, divisor.size);

                MYINT *pRest = result.rest;
                if (pRest != NULL)
                {
                    clear2(pRest->data.pBytes, pRest->size);
                    pRest->used_size = 0;
                }

                res = myintOp(INT_OP_DIV, &testedNumber, &divisor, &result);
                if (res != 0)
                {
                    printf("DIV FAILED!\n");
                    break;
                }
                
                restValue = -1;
                
                pRest = result.rest;
                if (pRest != NULL)
                {
                    restValue = 0;
                    for (resUInt = 0; resUInt < pRest->used_size; resUInt++)
                    {
                        restValue |= (pRest->data.pBytes[resUInt] << (8 * resUInt));
                    }
                    
                    printf("REST: %u | %i | %u ? %u| %x %x\n", 
                    prime, restValue, 
                    divisor.used_size, pRest->used_size,
                    pRest->data.pBytes[0], pRest->data.pBytes[1]
                    );
                    clear2(pRest->data.pBytes, pRest->size);
                    pRest->used_size = 0;
                }

                if (restValue == 0)
                {
                    clear2(printCompressChars2, PRINT_CHARS_SIZE);
                    printMyInt(&testedNumber, printCompressChars2, PRINT_CHARS_SIZE);

                    clear2(printCompressChars, PRINT_CHARS_SIZE);
                    printMyInt(&result, printCompressChars, PRINT_CHARS_SIZE);
                    printf("%i %% %s \n", prime, printCompressChars2);
                    printf("%i|%s =?> %u\n", prime, printCompressChars, result.used_size);
                    free(testedNumber.data.pBytes);
                    testedNumber.data.pBytes = result.data.pBytes;
                    testedNumber.used_size = result.used_size;
                    testedNumber.size = result.size;

                    result.data.pBytes = NULL;
                    result.used_size = 0;
                    result.size = 0;
                    primesCounters[primeIdx]++;
                }
                else
                {
                    ++primeIdx;
                }
                if (testedNumber.used_size < 4)
                {
                    printf("BREAK: Tested number less 4 bytes\n");
                    break;
                }
            }

            lastPrimesIdx = -1;
            resUInt = 0;
            for (primeIdx = 0; primeIdx < NUM_PRIMES; primeIdx++)
            {
                if (primesCounters[primeIdx])
                {
                    printf("%i : %i\n", primes[primeIdx], primesCounters[primeIdx]);
                    resUInt++;
                    lastPrimesIdx = primeIdx;
                }
            }
            resUInt *= 2;
            unsigned int resSize = resUInt + testedNumber.used_size;

            printf(">PS+RS: %u +%u = %u ? %u | @%i\n", resUInt, testedNumber.used_size, resSize, size, lastPrimesIdx);

            ++testIdx;

            add += 1;
        }
        res = myintOp(INT_OP_CLEAR_ALL, &divisor, &adder, &result);
        if (res != 0)
        {
            printf("CLEAR FAILED!\n");
            return;
        }
    }
    else
    {
        // TODO decompress
    }

    printf("Prime time %llu (micro) | %llu (milli)\n", duration2, duration2 / 1000);
    printf("Last prime: %i\n", primes[NUM_PRIMES_ALL - 1]);
    free(primes);
    free(primesSq);
    free(primesCounters);
    free(pCurrentData);
}