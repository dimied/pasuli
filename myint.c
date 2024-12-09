
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "memory.h"
#include "myint.h"
#include "log_stack.h"

unsigned char *tempMemory = NULL;
unsigned int tempMemorySize = 0;

unsigned char *getTempMemory(unsigned int size)
{
    if (size <= tempMemorySize)
    {
        clear2(tempMemory, size);
        return tempMemory;
    }
    unsigned char *pMem = (unsigned char *)malloc(size);
    if (pMem == NULL)
    {
        return NULL;
    }
    free(tempMemory);
    tempMemory = pMem;
    tempMemorySize = size;
    clear2(pMem, size);
    return pMem;
}

void myintCleanup()
{
    if (tempMemory != NULL)
    {
        free(tempMemory);
        tempMemory = NULL;
    }
    tempMemorySize = 0;
}

void reverseUCharArray(unsigned char *pArray, unsigned int size)
{
    if (pArray != NULL && size > 0)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            unsigned char t = pArray[i];
            --size;
            pArray[i] = pArray[size];
            pArray[size] = t;
        }
    }
}

void nullifyMyInt(MYINT *pMyInt)
{
    if (pMyInt != NULL)
    {
        clear2(pMyInt, sizeof(MYINT));
    }
}
int checkOrRealloc(MYINT *pResult, unsigned int sizeVal)
{
    if (sizeVal > pResult->size)
    {
        if (myDataOp(REALLOC_REALLOC, (unsigned char **)&pResult->data.pBytes, sizeVal, pResult->size))
        {
            return INT_ALLOCATION_ERROR;
        }
        pResult->size = sizeVal;
    }
    return 0;
}

void adjust(MYINT *pData)
{
    if (pData != NULL)
    {
        unsigned char *pChars = pData->data.pBytes;
        if (pChars != NULL)
        {
            --pChars;
            unsigned int s = pData->size;
            unsigned char *pEnd = pChars + s;

            while (s > 0 && pChars != pEnd && *pEnd == 0)
            {
                --s;
                --pEnd;
            }
            pData->used_size = s;
        }
    }
}

int intOps = 0;

int myintOp(int op, MYINT *pSrc, MYINT *pSrc2, MYINT *pResult)
{
    if (intOps > 0)
    {
        printf("OP: %x\n", op);
    }
    int res, initOrClear = op & INT_OP_INIT_ALL;
    if (initOrClear != 0 && op >= INT_OP_INIT_SRC && op <= INT_OP_INIT_ALL)
    {
        if (INT_INTERNAL_CHECK_INIT(initOrClear, INT_OP_INIT_RESULT))
        {
            res = myintOp(INT_OP_INIT_SRC, pResult, pSrc2, pResult);
            if (res)
            {
                return res;
            }
        }

        if (INT_INTERNAL_CHECK_INIT(initOrClear, INT_OP_INIT_SRC2))
        {
            res = myintOp(INT_OP_INIT_SRC, pSrc2, pSrc2, pResult);
            if (res)
            {
                return res;
            }
        }

        if (INT_INTERNAL_CHECK_INIT(initOrClear, INT_OP_INIT_SRC))
        {
            nullifyMyInt(pSrc);
            res = myDataOp(REALLOC_ALLOC, (unsigned char **)&pSrc->data.pBytes, INITIAL_INIT_SIZE, 0);
            if (res)
            {
                return res;
            }
            clear2(pSrc->data.pBytes, INITIAL_INIT_SIZE);
            pSrc->size = INITIAL_INIT_SIZE;
            pSrc->used_size = 0;
        }
        return 0;
    }

    initOrClear = op & INT_OP_CLEAR_ALL;
    if (initOrClear != 0 && op <= INT_OP_CLEAR_ALL)
    {
        res = 1;
        if (INT_INTERNAL_CHECK_CLEAR(initOrClear, INT_OP_CLEAR_RESULT))
        {
            res = myintOp(INT_OP_CLEAR_SRC, pResult, pSrc2, pResult);
        }

        if (INT_INTERNAL_CHECK_CLEAR(initOrClear, INT_OP_CLEAR_SRC2))
        {
            res = myintOp(INT_OP_CLEAR_SRC, pSrc2, pSrc2, pResult);
        }

        if (INT_INTERNAL_CHECK_CLEAR(initOrClear, INT_OP_CLEAR_SRC))
        {
            res = myDataOp(REALLOC_FREE, (unsigned char **)&pSrc->data.pBytes, 0, 0);
            if (res == 0)
            {
                pSrc->size = 0;
                pSrc->used_size = 0;

                if (pSrc->rest != NULL)
                {
                    res = myintOp(INT_OP_CLEAR_SRC, pSrc->rest, NULL, NULL);
                }
            }
        }
        return res;
    }

    unsigned int sizeVal, resultValue = 0, i, a, b, t;
    unsigned char *pSrc1Chars = pSrc->data.pBytes, *pSrc2Chars = pSrc2->data.pBytes;
    unsigned char *pFrom, *pFromEnd, *pSub;
    unsigned int resIdx = 0, resIdx2 = 0;
    int diff;
    #if INT_DEBUG_SHOW_SUB
        char *logStack;
#endif

    switch (op)
    {
    case INT_OP_ZERO:
        clear2(pSrc->data.pBytes, pSrc->size);
        return 0;
    case INT_OP_ONE:
        res = myintOp(INT_OP_ZERO, pSrc, NULL, NULL);
        if (res == 0)
        {
            pSrc->data.pBytes[0] = 1;
            pSrc->used_size = 1;
        }
        return res;
    case INT_OP_CMP_ABS:
        a = pSrc->used_size;
        b = pSrc2->used_size;
#if INT_DEBUG_SHOW_SUB
        logStack = getLine();
        if (logStack != NULL)
        {
            snprintf(logStack, STACK_LINE_SIZE - 1, "a=%u|b=%u\n", a, b);
        }
#endif
        if (a < b)
        {
            return INT_RESULT_CMP_LESS;
        }
        if (a > b)
        {
            return INT_RESULT_CMP_GREATER;
        }
        i = a;
        pSrc1Chars += (a - 1);
        pSrc2Chars += (a - 1);
        /// if a and b have the same degree check each degree individually
        while (i > 0)
        {
            a = *pSrc1Chars;
            b = *pSrc2Chars;
            if (a < b)
            {
                return INT_RESULT_CMP_LESS;
            }
            if (a > b)
            {
                return INT_RESULT_CMP_GREATER;
            }
            --pSrc1Chars;
            --pSrc2Chars;
            --i;
        }
        return INT_RESULT_CMP_EQUAL;

    case INT_OP_ADD:
        // printf("ADD!\n");
        a = pSrc->used_size;
        b = pSrc2->used_size;
        sizeVal = a < b ? b : a;

        res = checkOrRealloc(pResult, sizeVal + 1);
        if (res)
        {
            return res;
        }

        pFrom = pResult->data.pBytes;

        for (i = 0; i < sizeVal; i++)
        {
            if (i < a)
            {
                resultValue += *pSrc1Chars;
            }
            if (i < b)
            {
                resultValue += *pSrc2Chars;
            }
            *pFrom = resultValue & 0xFF;
            resultValue >>= 8;
            ++pFrom;
            ++pSrc1Chars;
            ++pSrc2Chars;
        }

        if (resultValue > 0)
        {
            i++;
            res = checkOrRealloc(pResult, i);
            if (res)
            {
                return res;
            }
            *pFrom = resultValue & 0xFF;
        }
        pResult->used_size = i;

        return 0;
    case INT_OP_SUB:
        // printf("SUB!\n");
        a = pSrc->used_size;
        b = pSrc2->used_size;
        res = myintOp(INT_OP_CMP_ABS, pSrc, pSrc2, NULL);
        pResult->sign = 0;

        if (res == INT_RESULT_CMP_LESS)
        {
            pSrc1Chars = pSrc2->data.pBytes;
            pSrc2Chars = pSrc->data.pBytes;
            pResult->sign = 1;
            t = a;
            a = b;
            b = t;
            /*
            b = pSrc->used_size;
            a = pSrc2->used_size;
            */
        }
        else if (res == INT_RESULT_CMP_EQUAL)
        {
            clear2(pResult->data.pBytes, pResult->size);
            pResult->used_size = 0;
#if INT_DEBUG_SHOW_SUB
            logStack = getLine();
            if (logStack != NULL)
            {
                snprintf(logStack, STACK_LINE_SIZE - 1, "EQUAL\n");
            }
#endif
            return 0;
        }
        if (a > pResult->size)
        {
#if INT_DEBUG_SHOW_SUB
            printf("ALLOC RESULT!\n");
#endif
            res = myDataOp(REALLOC_REALLOC, (unsigned char **)&pResult->data.pBytes,
                           a, pResult->size);
            if (res != 0)
            {
                return res;
            }
            pResult->size = a;
        }

        pFrom = pResult->data.pBytes;
        clear2(pFrom, pResult->size);
        memcpy(pFrom, pSrc1Chars, a);
        pFromEnd = pFrom + a - 1;
        while (*pFromEnd == 0 && pFrom != pFromEnd)
        {
            --pFromEnd;
            --a;
        }
        pResult->used_size = a;
        int tempI;

        pSub = pSrc2Chars;
        diff = 0;
        while (b > 0)
        {
            tempI = (int)(*pSub);
#if INT_DEBUG_SHOW_SUB
            int aaa = diff;
#endif
            diff = (int)(*pFrom) - tempI - diff;
#if INT_DEBUG_SHOW_SUB
            logStack = getLine();
            if (logStack != NULL)
            {
                snprintf(logStack, STACK_LINE_SIZE, "@%i: %i - %i - %i = %i\n", b, *pFrom, tempI, aaa, diff);
            }
#endif
            if (diff < 0)
            {
                diff += 0x200;
            }
            *pFrom = diff & 0xFF;
            diff >>= 8;
            ++pFrom;
            ++pSub;
            --b;
            --a;
        }
        if (diff > 0)
        {
            while (a > 0 && diff > 0)
            {
                diff = (*pFrom) - diff;
                if (diff < 0)
                {
                    diff += 0x200;
                }
                *pFrom = diff & 0xFF;
                diff >>= 8;
                ++pFrom;
                --a;
            }
            if (diff > 0)
            {
                clear2(pResult->data.pBytes, pResult->size);
                pResult->used_size = 0;
                return 1;
            }
        }
        a = pResult->used_size;
        pFrom = pResult->data.pBytes;
        pFromEnd = pFrom + a - 1;
        while (*pFromEnd == 0 && pFrom != pFromEnd)
        {
            --pFromEnd;
            --a;
        }
        pResult->used_size = a;

        return 0;
        // break;
    case INT_OP_MUL:
        // printf("MUL!\n");
        a = pSrc->used_size;
        sizeVal = a + pSrc2->used_size;
        res = checkOrRealloc(pResult, sizeVal);
        if (res)
        {
            return res;
        }
        clear2(pResult->data.pBytes, pResult->size);

        resultValue = 0;

        for (i = 0; i < a; i++)
        {
            resIdx = i;

            pSrc2Chars = pSrc2->data.pBytes;
            b = pSrc2->used_size;

            while (b > 0)
            {
                resultValue = (*pSrc1Chars) * (*pSrc2Chars);
                resIdx2 = resIdx;

                do
                {
                    resultValue = pResult->data.pBytes[resIdx2] + resultValue;
                    pResult->data.pBytes[resIdx2++] = resultValue & 0xFF;
                    resultValue >>= 8;
                } while (resultValue > 0);
                ++resIdx;
                ++pSrc2Chars;
                --b;
            }

            ++pSrc1Chars;
        }
        pResult->used_size = resIdx2;

        return 0;
    // printf("RES: %i\n", resultValue);
    case INT_OP_DIV:
        adjust(pSrc);
        adjust(pSrc2);
        a = pSrc->used_size;
        b = pSrc2->used_size;
        res = myintOp(INT_OP_CMP_ABS, pSrc, pSrc2, NULL);
        pResult->sign = 0;

        MYINT *pRest = pResult->rest;
        if (pRest == NULL)
        {
            pRest = (MYINT *)malloc(sizeof(MYINT));
            if (pRest == NULL)
            {
                return INT_ALLOCATION_ERROR;
            }
            clear2(pRest, sizeof(MYINT));
            pResult->rest = pRest;
        }
        if (pRest->data.pBytes != NULL)
        {
            clear2(pRest->data.pBytes, pRest->size);
        }
#if INT_DEBUG_SHOW_DIV
        logStack = getLine();
        if (logStack != NULL)
        {
            snprintf(logStack, STACK_LINE_SIZE - 1, "SRC: %i|SRC2: %i\n", a, b);
        }
#endif
        // printf("SRC: %i|SRC2: %i\n", a, b);

        // Division by zero
#if 1
        if (0 == b || ((b == 1) && pSrc2Chars[0] == 0))
        {
            return 1;
        }
#endif
        if (res == INT_RESULT_CMP_LESS)
        {
            // printf("REALLOC?\n");
            clear2(pResult->data.pBytes, pResult->size);
            pResult->used_size = 0;

            res = checkOrRealloc(pResult->rest, a);
            if (res != 0)
            {
#if INT_DEBUG_SHOW_DIV
                logStack = getLine();
                if (logStack != NULL)
                {
                    snprintf(logStack, STACK_LINE_SIZE - 1, "LESS(REST):%i\n", res);
                }
#endif
                return INT_ALLOCATION_ERROR;
            }
            // printf("REALLOC!%i %p %i\n", res, pRest->data.pBytes, a);
            if (a > 0)
            {
                memcpy(pRest->data.pBytes, pSrc1Chars, a);
            }
            pRest->used_size = a;
            return 0;
        }
        if (res == INT_RESULT_CMP_EQUAL)
        {
            clear2(pResult->data.pBytes, pResult->size);
            pResult->data.pBytes[0] = 1;
            pResult->used_size = 1;
            if (pRest->size > 0)
            {
                clear2(pRest->data.pBytes, pRest->size);
            }
            pRest->used_size = 0;

            return 0;
        }
#if 1
        uint64_t div64 = 0, divFrom64 = 0, rest64, result64;
        // Divisor can fit into 8 bytes?
        if (8 >= pSrc2->used_size)
        {
            // printf("64BIT!\n");
            div64 = fromBytes(pSrc2Chars, pSrc2->used_size);

            // printf("STORED: %lu\n", div64);
            // Dividend can fit into 8 bytes?
            if (8 >= pSrc->used_size)
            {
                divFrom64 = fromBytes(pSrc1Chars, pSrc->used_size);

                rest64 = divFrom64 % div64;
                result64 = divFrom64 / div64;

                // printf("STORED:1: %lu/%lu = %lu (->%lu)\n", divFrom64, div64, result64, rest64);
                if (0 != checkOrRealloc(pResult, 8))
                {
                    return INT_ALLOCATION_ERROR;
                }
                if (0 != checkOrRealloc(pRest, 8))
                {
                    return INT_ALLOCATION_ERROR;
                }
                *((uint64_t *)pRest->data.pBytes) = rest64;
                *((uint64_t *)pResult->data.pBytes) = result64;
                adjust(pRest);
                adjust(pResult);
                return 0;
            }
            if (0 != checkOrRealloc(pRest, pSrc2->used_size))
            {
                return INT_ALLOCATION_ERROR;
            }
            if (0 != checkOrRealloc(pResult, pSrc->used_size - pSrc2->used_size + 1))
            {
                return INT_ALLOCATION_ERROR;
            }
            unsigned char *pTemp = getTempMemory(pSrc->used_size);
            if (pTemp == NULL)
            {
                return INT_ALLOCATION_ERROR;
            }

            // void *CopyRes =
            memcpy(pTemp, pSrc1Chars, pSrc->used_size);
            b = pSrc2->used_size;
            pFromEnd = pTemp + (pSrc->used_size - b);
            divFrom64 = fromBytes(pFromEnd, b);
            i = 0;
            while (pFromEnd != pTemp)
            {
                if (i > 0)
                {
                    divFrom64 <<= 8;
                    divFrom64 |= (*pFromEnd);
                }
                result64 = divFrom64 / div64;
                rest64 = divFrom64 % div64;
                pResult->data.pBytes[i] = (unsigned char)result64;
                divFrom64 = rest64;
                ++i;
                --pFromEnd;
            }
            if (i > 0)
            {
                divFrom64 <<= 8;
                divFrom64 |= (*pFromEnd);
            }
            result64 = divFrom64 / div64;
            rest64 = divFrom64 % div64;
            pResult->data.pBytes[i] = (unsigned char)result64;
            ++i;
            reverseUCharArray(pResult->data.pBytes, i);
            pResult->used_size = i;
            i = 0;
            while (rest64 > 0)
            {
                pRest->data.pBytes[i] = (unsigned char)rest64 & 0xFF;
                ++i;
                rest64 >>= 8;
            }
            pRest->used_size = i;
            return 0;
            // printf("N: %x\n", divFrom64);

            // free(pTemp);
        }

#endif
    }
    return INT_COMMAND_ERROR;
}

int printMyInt(MYINT *pSrc, char *pResult, unsigned int resultLength)
{
    if (pSrc == NULL)
    {
        return 1;
    }
    if (resultLength < 2)
    {
        return 1; // Not enough space, needs to be null-terminated
    }

    if (pSrc->used_size == 0)
    {
        clear2(pResult, resultLength);
        *pResult = '0';
        return 0;
    }

    return printBytes(pSrc->data.pBytes, pSrc->used_size, pResult, resultLength);
}

int printBytes(unsigned char *p, unsigned int size, char *pResult, unsigned int resultLength)
{
    if (resultLength < 2)
    {
        return 1; // Not enough space, needs to be null-terminated
    }
    //
    clear2(pResult, resultLength);

    if (size == 1 && (*p) < 100)
    {
        if (*p < 10)
        {
            *pResult = '0' + (*p);
        }
        else
        {
            if (resultLength == 2)
            {
                return 1;
            }
            *pResult = '0' + ((*p) / 10);
            ++pResult;
            *pResult = '0' + ((*p) % 10);
        }
        return 0;
    }

    unsigned int i = 0;
#if 0
    unsigned long long int res = 0;
    if (pSrc->used_size <= sizeof(res) && resultLength > 20)
    {
        while (i < pSrc->used_size)
        {
            res |= (*p) << (8 * i);
            ++p;
            ++i;
        }
        sprintf(pResult, "%llu", res);
        return 0;
    }
#endif

#define VALUE(V) ((V) & 0xF)
#define EXP_VALUE(V) ((V) >> 4)
    // start from the end and move it later to the beginning
    unsigned char *pResultUC = (unsigned char *)pResult;
    unsigned char *pLastCurrent, *pLast = pResultUC + (resultLength - 2);
    // lowest 4 bits is result, highest 4 bits is number to add
    *pLast = ((*p) & 0x7) | (0x4 << 4);
    i = 0;
    unsigned int last, overflow = 0, currentByteShift = 3;
    int numShifts = 1;

    // shift > 8  means abort
    do
    {
        unsigned int valCurrent, resCurrent, val = p[i];
        // printf("@%i = %i|%x\n", i, val, val);

        while (currentByteShift < 8)
        {
            valCurrent = val >> currentByteShift;
            if (valCurrent & 0x1)
            {
                pLastCurrent = pLast;
#if 0
                int b = VALUE(*pLast) + VALUE(*(pLast - 1)) * 10 + VALUE(*(pLast - 2)) * 100 + VALUE(*(pLast - 3)) * 1000;
                printf("BIT< %i|%i | <<%i\n", currentByteShift, b, numShifts);
                b = EXP_VALUE(*pLast) + EXP_VALUE(*(pLast - 1)) * 10 + EXP_VALUE(*(pLast - 2)) * 100 + EXP_VALUE(*(pLast - 3)) * 1000;
                printf("BIT-E< %i|%u\n", currentByteShift, b);
#endif
                // generate 2^n value
                while (numShifts > 0)
                {
                    overflow = 0;
                    pLastCurrent = pLast;
                    // Multiply
                    while (pLastCurrent != pResultUC)
                    {
                        resCurrent = *pLastCurrent;
                        last = EXP_VALUE(resCurrent);
                        last = 2 * last + overflow;
                        overflow = last / 10;
                        last = last % 10;
                        resCurrent = (last << 4) | VALUE(resCurrent);
                        *pLastCurrent = resCurrent;
                        --pLastCurrent;
                    }
#if 0
                    // b = EXP_VALUE(*pLast) + EXP_VALUE(*(pLast - 1)) * 10 + EXP_VALUE(*(pLast - 2)) * 100 + EXP_VALUE(*(pLast - 3)) * 1000;
                    // printf("BIT-E^ %i|%u (%u)\n", currentByteShift, b, numShifts);
#endif
                    if (pLastCurrent == pResultUC)
                    {
                        resCurrent = *pLastCurrent;
                        last = EXP_VALUE(resCurrent);
                        last = last * 2 + overflow;
                        // can't fit?
                        if (last > 9)
                        {
                            currentByteShift = 9;
                            break;
                        }
                        resCurrent = (last << 4) | VALUE(resCurrent);
                        *pLastCurrent = resCurrent;
                    }
                    --numShifts;
                }
                if (currentByteShift > 8)
                {
                    // 2^n can't fit, i.e. also the result of addition won't fit
                    break;
                }
#if 0
                // b = EXP_VALUE(*pLast) + EXP_VALUE(*(pLast - 1)) * 10 + EXP_VALUE(*(pLast - 2)) * 100 + EXP_VALUE(*(pLast - 3)) * 1000;
                // printf("BIT~ %i|%u\n", currentByteShift, b);
#endif
                overflow = 0;
                pLastCurrent = pLast;
                unsigned char *pResultFrontUC = pResultUC;
                // Find non-zero in result
                while (pResultFrontUC != pLast)
                {
                    if (VALUE(*pResultFrontUC) != 0)
                    {
                        break;
                    }
                    ++pResultFrontUC;
                }
                // Start: stored + 2^n
                while (pLastCurrent != pResultUC)
                {
                    resCurrent = *pLastCurrent;
                    last = VALUE(resCurrent) + EXP_VALUE(resCurrent) + overflow;
                    overflow = last / 10;
                    last = last % 10;

                    *pLastCurrent = (resCurrent & 0xF0) | last;
                    pLastCurrent--;
                }
                if (pLastCurrent == pResultUC)
                {
                    resCurrent = *pLastCurrent;
                    last = VALUE(resCurrent) + EXP_VALUE(resCurrent) + overflow;
                    if (last > 9)
                    {
                        currentByteShift = 9;
                        break;
                    }
                    *pLastCurrent = (resCurrent & 0xF0) | last;
                }
                else
                {
                }
#if 0
                b = VALUE(*pLast) + VALUE(*(pLast - 1)) * 10 + VALUE(*(pLast - 2)) * 100 + VALUE(*(pLast - 3)) * 1000;
                printf("BIT> %i|%u\n", currentByteShift, b);
                b = EXP_VALUE(*pLast) + EXP_VALUE(*(pLast - 1)) * 10 + EXP_VALUE(*(pLast - 2)) * 100 + EXP_VALUE(*(pLast - 3)) * 1000;
                printf("BIT-E> %i|%u\n", currentByteShift, b);
#endif
            }
            if (currentByteShift > 8)
            {
                break;
            }
            ++numShifts;
            // else nothing
            ++currentByteShift;
        }
        if (currentByteShift > 8)
        {
            break;
        }
        currentByteShift = 0;
        ++i;
    } while (i < size);

    if (currentByteShift > 8)
    {
        clear2(pResult, resultLength);
        return 2;
    }
    // move characters to the front
    pLast = pResultUC + (resultLength - 1);
    pLastCurrent = pResultUC;
    int a = 0;
    // find first non zero
    while (pLastCurrent != pLast && ((*pLastCurrent & 0xF) == 0))
    {
        ++pLastCurrent;
        a++;
    }
    // printf("FOUND AFTER: %i | %i  | %p %p\n", a, *pLastCurrent, pLastCurrent, pLast);
    if (pLastCurrent != pLast)
    {
        a = 0;
        while (pLastCurrent != pLast)
        {
            *pResultUC = ((*pLastCurrent) & 0xF) + '0';
            ++pResultUC;
            ++pLastCurrent;
            a++;
        }
        // printf("MOVED %i\n", a);
        a = 0;
        while (pResultUC != pLast)
        {
            *pResultUC = 0;
            ++pResultUC;
            a++;
        }
        // printf("ZERO %i\n", a);
    }
    else
    {
        while (pResultUC != pLast)
        {
            *pResultUC = ((*pResultUC) & 0xF) + '0';
            ++pResultUC;
        }
    }

    return 0;
}

uint64_t fromBytes(unsigned char *pBytes, unsigned int size)
{

    if (size == 8)
    {
        return *((uint64_t *)pBytes);
    }
    uint64_t result = 0;
    unsigned int i = 0;
    while (i < size)
    {
        result |= (*pBytes) << (i * 8);
        ++pBytes;
        ++i;
    }
    return result;
}
