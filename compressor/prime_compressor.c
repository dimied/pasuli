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

int highBitIndex(uint64_t val) {
    int bit = 0;
    while(val > 0) {
        ++bit;
        val >>=1;
    }
    return bit;
}

void tryDiffCompress(void *pData, unsigned int size, void *pResultData, int resultSize, int *pRealSize);

void compress(void *pData, unsigned int size, void *pResultData, int resultSize, int *pRealSize) {
    primeStrategy(pData, size, pResultData, resultSize, pRealSize);
}

void tryDiffCompress(void *pData, unsigned int size, void *pResultData, int resultSize, int *pRealSize)
{
    char *pChars = (char *)pData;
    short *pShorts = (short *)pData;
    uint32_t *pUints = (uint32_t *)pData;
    uint64_t *pUint64s = (uint64_t *)pData;
    int maxDiffPos = 0;
    int maxDiffNeg = 0x100;
    int maxDiffChar = 0;
    int lastC = *pChars;

    int bitIdx=0;
    int numVals = 0;
    for (int i = 1; i < size; i++)
    {
        int diff = pChars[i] - lastC;
        if (diff < 0)
        {
            if (maxDiffNeg > diff)
            {
                maxDiffNeg = diff;
            }
            diff += 0x100;
            if (maxDiffChar < diff)
            {
                maxDiffChar = diff;
            }
        }
        else
        {
            if (maxDiffPos < diff)
            {
                maxDiffPos = diff;
            }
        }
        ++numVals;
        lastC = pChars[i];
    }
    bitIdx = highBitIndex(maxDiffChar);
    printf("MAX-DIFF:char: %i : %i | %i | %i ?%i?\n",numVals, maxDiffNeg, maxDiffPos, maxDiffChar, bitIdx);
    int32_t lastShort = pShorts[0];
    int64_t diffInt = 0;
    int64_t maxDiffShort = 0;
    numVals = 0;
    for (int i = 1; i < size / 2; i++)
    {
        diffInt = pShorts[i] - lastShort;
        if (diffInt < 0)
        {
            diffInt += 0x10000;
        }
        if (maxDiffShort < diffInt)
        {
            maxDiffShort = diffInt;
        }
        ++numVals;
        lastShort = pShorts[i];
    }
    bitIdx = highBitIndex(maxDiffShort);
    printf("MAX-DIFF:short: %i : %li ?%i?\n",numVals, maxDiffShort, bitIdx);
    uint32_t lastUint = pUints[0];
    int64_t diffInt64 = 0;
    int64_t maxDiffInt64 = 0;
    numVals = 0;
    for (int i = 1; i < size / 4; i++)
    {
        diffInt64 = pUints[i] - lastUint;
        if (diffInt64 < 0)
        {
            diffInt64 += 0x100000000;
        }
        if (maxDiffInt64 < diffInt64)
        {
            maxDiffInt64 = diffInt64;
        }
        ++numVals;
        lastUint = pUints[i];
    }
    bitIdx = highBitIndex(maxDiffInt64);
    printf("MAX-DIFF:uint: %i : %li ?%i?\n",numVals, maxDiffInt64, bitIdx);

    uint64_t lastUint64 = pUint64s[0];
    diffInt64 = 0;
    uint64_t diffUInt64 = 0;
    uint64_t maxDiffUInt64 = 0;
    numVals = 0;

#define MAX_UINT 0xFFFFFFFFul
#define MAX_UINT64 ((MAX_UINT<<32)|MAX_UINT)

    for (int i = 1; i < size / 8; i++)
    {
        diffInt64 = pUint64s[i] - lastUint64;
        if (diffInt64 < 0)
        {
            diffInt64 = -diffInt64;
            diffUInt64 = MAX_UINT64 - diffInt64;
        } else {
            diffUInt64 = diffInt64;
        }
        if (maxDiffUInt64 < diffUInt64)
        {
            maxDiffUInt64 = diffUInt64;
        }
        lastUint64 = pUint64s[i];
        ++numVals;
    }
    bitIdx = highBitIndex(maxDiffUInt64);
    printf("MAX-DIFF:uint64: %i : %li | %lx ?%i?\n",numVals, maxDiffInt64, maxDiffUInt64, bitIdx);
    if(bitIdx < 64) {
        int bitSave = 64-bitIdx;
        bitSave *= numVals;
        bitSave--;
        printf("Bits to save? %i\n", bitSave);

    }
    
}

void primeStrategy(void *pData, unsigned int size, void *pResultData, int resultSize, int *pRealSize)
{
    unsigned int *primes = (unsigned int *)malloc(NUM_PRIMES_ALL_RESERVE * sizeof(int));
    unsigned int *primesSq = (unsigned int *)malloc(NUM_PRIMES_ALL_RESERVE * sizeof(uint64_t));
    int *primesCounters = (int *)malloc(NUM_PRIMES_ALL_RESERVE * sizeof(int));
    unsigned char *primeSizes = (unsigned char *)malloc(NUM_PRIMES_ALL_RESERVE);
    //
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
    struct timeval tp;
    struct timeval tp2;
    printf("LIMIT: %u\n", NUM_PRIMES_ALL);

    gettimeofday(&tp, NULL);
    unsigned char ps;

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
            ps = 1;
            if (p > 0xFF)
            {
                ++ps;
                if (p > 0xFFFF)
                {
                    ++ps;
                }
                if (p > 0xFFFFFF)
                {
                    ++ps;
                }
            }
            primeSizes[primeIdx] = ps;
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
        MYINT rest;
        nullifyMyInt(&testedNumber);
        nullifyMyInt(&divisor);
        nullifyMyInt(&adder);
        nullifyMyInt(&result);
        nullifyMyInt(&rest);

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

        INT_INIT_CALL3(res, &divisor, &adder, &result);
        // res = myintInit(&divisor);
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

        numTries = 50;//0xFFFF - 1;

        // unsigned char *pTemp = testedNumber.data.pBytes;
        //  unsigned char *pDiv = divisor.data.pBytes;
        //  unsigned short *pUShort;
        int lastPrimesIdx = NUM_PRIMES_TO_CHECK;
        MYINT *pRest;
        unsigned char *pRestUchars;

        int *tryHits = (int *)malloc(numTries * sizeof(int));
        memset(tryHits, 0, numTries * sizeof(int));

        while (testIdx < numTries)
        {
            if(testIdx%100 == 0) {
                printf("++%i+++\n", testIdx);
            }
            

            for (int i = 0; i <= lastPrimesIdx; i++)
            {
                primesCounters[i] = 0;
            }
            if (testedNumber.data.pBytes != NULL)
            {
                // printf("FREE!\n");
                free(testedNumber.data.pBytes);
                testedNumber.data.pBytes = (unsigned char *)malloc(size);
                memcpy(testedNumber.data.pBytes, pCurrentData, size);
                // testedNumber.data.pBytes = pTemp;
                testedNumber.used_size = size;
                testedNumber.size = size;
            }

            if (add > 0)
            {
                //printf("ADD: %i\n", add);
                if (add < 256)
                {
                    adder.data.pBytes[0] = (unsigned char)add;
                    adder.used_size = 1;
                }
                else if (add < 256 * 256)
                {
                    adder.data.pShorts[0] = (unsigned short)add;
                    adder.used_size = 2;
                }

                res = myintOp(INT_OP_ADD, &testedNumber, &adder, &result, &rest);
                if (res)
                {
                    printf("ADD FAILED: %i\n", res);
                    break;
                }
                free(testedNumber.data.pBytes);

                testedNumber.data.pBytes = result.data.pBytes;
                testedNumber.size = result.size;
                testedNumber.used_size = result.used_size;

                result.data.pBytes = NULL;
                result.size = 0;
                result.used_size = 0;
            }

            restValue = 0;
            // pUShort = divisor.data.pShorts;

            primeIdx = 0;
            // unsigned int ds=0;
            // clear2(pUShort, divisor.size);
            divisor.used_size = 1;

            for (; primeIdx < NUM_PRIMES;)
            {
                unsigned int prime = primes[primeIdx];
                divisor.data.pUInts[0] = prime;
                if (prime > 0xFF)
                {
                    divisor.used_size = primeSizes[primeIdx];
                }

#if 0
                clear2(printCompressChars3, 20);
                printMyInt(&divisor, printCompressChars3, 20);
                ds = divisor.used_size;
                printf("DIV| %s | %u/%u\n", 
                printCompressChars3, divisor.used_size, divisor.size);
#endif
                pRest = &rest;
                if (pRest != NULL)
                {
                    if (pRest->size == 4)
                    {
                        *pRest->data.pUInts = 0;
                    }
                    else
                    {
                        clear2(pRest->data.pBytes, pRest->size);
                    }

                    pRest->used_size = 0;
                }

                res = myintOp(INT_OP_DIV, &testedNumber, &divisor, &result, &rest);
                if (res != 0)
                {
                    printf("DIV FAILED!\n");
                    break;
                }

                restValue = -1;

                pRest = &rest;
                if (pRest != NULL)
                {
                    restValue = 0;
                    pRestUchars = pRest->data.pBytes;
                    for (resUInt = 0; resUInt < pRest->used_size; resUInt++)
                    {
                        restValue |= ((*pRestUchars) << (8 * resUInt));
                        *pRestUchars = 0;
                        ++*pRestUchars;
                    }
#if 0
                    printf("REST: %u | %i | %u ? %u ? %u| %x %x | %x %x\n", 
                    prime, restValue, 
                    divisor.used_size, ds, pRest->used_size,
                    divisor.data.pBytes[0], divisor.data.pBytes[1],
                    pRest->data.pBytes[0], pRest->data.pBytes[1]
                    );
#endif
                    pRest->used_size = 0;
                }

                if (restValue == 0)
                {
                    clear2(printCompressChars2, PRINT_CHARS_SIZE);
                    printMyInt(&testedNumber, printCompressChars2, PRINT_CHARS_SIZE);

                    clear2(printCompressChars, PRINT_CHARS_SIZE);
                    printMyInt(&result, printCompressChars, PRINT_CHARS_SIZE);
#if 0
                    printf("%i %% %s \n", prime, printCompressChars2);
                    printf("%i|%s =?> %u\n", prime, printCompressChars, result.used_size);
#endif
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
                    //printf("%i : %i\n", primes[primeIdx], primesCounters[primeIdx]);
                    if (primeIdx < 256)
                    {
                        resUInt += 2;
                    }

                    lastPrimesIdx = primeIdx;
                }
            }
            if (lastPrimesIdx < 0x80)
            {
                resUInt /= 2;
            }
            //+1 for the number of used primes
            unsigned int resSize = 1 + resUInt + testedNumber.used_size;
            if (add > 0)
            {
                resSize += add < 256 ? 2 : 3;
            }


            //printf(">PS+RS: %u +%u = %u ? %u | @%i\n", resUInt, testedNumber.used_size, resSize, size, lastPrimesIdx);
            if (resSize < size)
            {
                tryHits[testIdx] = resSize;
            }

            ++testIdx;

            add += 1;
        }

        for (int testIdx = 0; testIdx < numTries; testIdx++)
        {
            if (tryHits[testIdx] > 0)
            {
                printf("H: %i -> %i\n", testIdx, tryHits[testIdx]);
            }
        }

        free(tryHits);
        INT_CLEAR_CALL3(res, &divisor, &adder, &result);
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
    free(primeSizes);
    free(primesCounters);
    free(pCurrentData);
}