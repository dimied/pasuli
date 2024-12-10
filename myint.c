
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

void sprintHex(unsigned char *vals, size_t sss, char *pResult, unsigned int size)
{

    if (vals != NULL && pResult != NULL)
    {
        unsigned int j = 0;
        for (size_t i = 0; i < sss; i++)
        {
            unsigned char vvv = vals[sss - i - 1];
            if (j + 1 < size)
            {
                snprintf(pResult + j, size - j, "%x%x", vvv >> 4, vvv & 0xF);
            }

            j += 2;
        }
    }
}

unsigned char zero = 0;

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

    unsigned int sizeVal, resultValue = 0, resIdx = 0, i, a, b, t;
    unsigned char *pSrc1Chars = pSrc->data.pBytes, *pSrc2Chars = pSrc2->data.pBytes;
    unsigned char *pFrom, *pFromEnd, *pSub, *pTo, *pTemp;
    // unsigned int resIdx = 0;//, resIdx2 = 0;
    int diff;
    int tempI;

#if INT_DEBUG_SHOW_CMP || INT_DEBUG_SHOW_SUB || INT_DEBUG_SHOW_DIV
    char *logStack;
#endif

    switch (op)
    {
    case INT_OP_ZERO:
        clear2(pSrc->data.pBytes, pSrc->size);
        pSrc->used_size = 0;
        return 0;
#if 0
    case INT_OP_ONE:
        res = myintOp(INT_OP_ZERO, pSrc, NULL, NULL);
        if (res == 0)
        {
            pSrc->data.pBytes[0] = 1;
            pSrc->used_size = 1;
        }
        return res;
#endif
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
        if (a != 0)
        {
            --a;
            pSrc1Chars += a;
            pSrc2Chars += a;
            ++a;
            /// if a and b have the same degree check each degree individually
            do
            {
                tempI = (int)(*pSrc1Chars) - (int)(*pSrc2Chars);
                // b = *pSrc2Chars;
                if (tempI < 0)
                {
                    return INT_RESULT_CMP_LESS;
                }
                else if (tempI > 0)
                {
                    return INT_RESULT_CMP_GREATER;
                }
                --pSrc1Chars;
                --pSrc2Chars;
                --a;
            } while (a > 0);
        }

        return INT_RESULT_CMP_EQUAL;

    case INT_OP_ADD:
        a = pSrc->used_size;
        b = pSrc2->used_size;
        sizeVal = a < b ? b : a;
        ++sizeVal;

        res = checkOrRealloc(pResult, sizeVal);
        if (res)
        {
            return res;
        }

        pFrom = pResult->data.pBytes;
        clear2(pFrom, sizeVal);
        memcpy(pFrom, pSrc1Chars, a);

        for (i = 0; i < b; i++)
        {
            resultValue += (unsigned int)(*pFrom) + (unsigned int)(*pSrc2Chars);

            *pFrom = (unsigned char)(resultValue & 0xFF);
            resultValue >>= 8;
            ++pFrom;
            ++pSrc2Chars;
        }

        while (resultValue > 0)
        {
            resultValue = (unsigned int)(*pFrom) + (resultValue & 0xFF);
            *pFrom = (unsigned char)(resultValue & 0xFF);
            resultValue >>= 8;
            ++pFrom;
        }

        adjust(pResult);
        return 0;
    case INT_OP_SUB:
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
            return myintOp(INT_OP_ZERO, pResult, pSrc, NULL);
            // clear2(pResult->data.pBytes, pResult->size);
            // pResult->used_size = 0;
#if INT_DEBUG_SHOW_SUB
            logStack = getLine();
            if (logStack != NULL)
            {
                snprintf(logStack, STACK_LINE_SIZE - 1, "EQUAL\n");
            }
#endif
            // return 0;
        }

#if INT_DEBUG_SHOW_SUB
        printf("ALLOC RESULT!\n");
#endif
        res = checkOrRealloc(pResult, a);
        if (res)
        {
            return res;
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

        pSub = pSrc2Chars;
        diff = 0;
        while (b > 0)
        {
#if INT_DEBUG_SHOW_SUB
            int aaa = diff;
#endif
            diff = (int)(*pFrom) - (int)(*pSub) - diff;
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
        pFrom = pResult->data.pBytes;
        if (diff > 0)
        {
            // myintOp(INT_OP_ZERO, pResult, pSrc, NULL);
            clear2(pFrom, pResult->size);
            pResult->used_size = 0;
            return 1;
        }

        adjust(pResult);
        return 0;

    case INT_OP_MUL:
        // printf("MUL!\n");
        a = pSrc->used_size;
        b = pSrc2->used_size;
        sizeVal = a + b;
        res = checkOrRealloc(pResult, sizeVal);
        if (res)
        {
            return res;
        }
        pFrom = pResult->data.pBytes;
        clear2(pFrom, pResult->size);
        if (b == 0)
        {
            pResult->used_size = 0;
            return 0;
        }

        for (i = 0; i < a; i++)
        {
            resIdx = i;

            pSub = pSrc2Chars;
            t = b;
            sizeVal = (*pSrc1Chars);

            while (t > 0)
            {
                resultValue = (*pSub) * sizeVal;
                pFromEnd = pFrom + resIdx;

                do
                {
                    resultValue += (*pFromEnd);
                    *pFromEnd = (unsigned char)(resultValue & 0xFF);
                    resultValue >>= 8;
                    ++pFromEnd;
                } while (resultValue > 0);
                ++resIdx;
                ++pSub;
                --t;
            }

            ++pSrc1Chars;
        }

        adjust(pResult);
        return 0;

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
            nullifyMyInt(pRest);
            pResult->rest = pRest;
        }

        pFrom = pRest->data.pBytes;
        clear2(pFrom, pRest->size);
        pRest->used_size = 0;
#if INT_DEBUG_SHOW_DIV
        logStack = getLine();
        if (logStack != NULL)
        {
            snprintf(logStack, STACK_LINE_SIZE - 1, "SRC: %i|SRC2: %i\n", a, b);
        }
#endif
        // Division by zero?
        if (0 == b || ((b == 1) && (*pSrc2Chars) == 0))
        {
            return 1;
        }

        pTo = pResult->data.pBytes;

        if (res == INT_RESULT_CMP_LESS)
        {
            clear2(pTo, pResult->size);
            pResult->used_size = 0;

            res = checkOrRealloc(pRest, a);
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
            pFrom = pRest->data.pBytes;
            if (pFrom != NULL)
            {
                memcpy(pFrom, pSrc1Chars, a);
            }

            pRest->used_size = a;
            return 0;
        }
        if (res == INT_RESULT_CMP_EQUAL)
        {
            if (pTo == NULL)
            {
                res = myDataOp(REALLOC_ALLOC, (unsigned char **)&pResult->data.pBytes, 4, 0);
                if (res)
                {
                    return res;
                }
            }
            clear2(pResult->data.pBytes, pResult->size);
            pResult->data.pBytes[0] = 1;
            pResult->used_size = 1;
            // clear2(pFrom, pRest->size);
            // pRest->used_size = 0;

            return 0;
        }

#if 1
        uint64_t div64 = 0, divFrom64 = 0, rest64, result64;
        // Divisor can fit into 8 bytes?
        if (8 > b)
        {
            div64 = fromBytes(pSrc2Chars, b);
            pTo = pResult->data.pBytes;

            clear2(pTo, pResult->size);
            // clear2(pRest->data.pBytes, pRest->size);

            if (0 != checkOrRealloc(pRest, 8))
            {
                return INT_ALLOCATION_ERROR;
            }
            pFrom = pRest->data.pBytes;

#if INT_DEBUG_SHOW_DIV
            logStack = getLine();
            if (logStack != NULL)
            {
                *logStack = '<';
                logStack++;
                *logStack = '1';
                logStack++;
                *logStack = ':';
                logStack++;
                printBytes(pSrc1Chars, a, logStack, STACK_LINE_SIZE - 3);
                // sprintHex(pSrc1Chars, a, logStack, STACK_LINE_SIZE - 3);
            }
            logStack = getLine();
            if (logStack != NULL)
            {
                *logStack = '\n';
            }
#endif

#if INT_DEBUG_SHOW_DIV && 0
            logStack = getLine();
            if (logStack != NULL)
            {
                *logStack = '<';
                logStack++;
                *logStack = '1';
                logStack++;
                *logStack = ':';
                logStack++;
                sprintHex(pSrc1Chars, a, logStack, STACK_LINE_SIZE - 3);
            }
            logStack = getLine();
            if (logStack != NULL)
            {
                *logStack = '\n';
            }
#endif

            // Dividend can fit into 8 bytes?
            if (8 >= a)
            {
                divFrom64 = fromBytes(pSrc1Chars, a);

                result64 = divFrom64 / div64;
                rest64 = divFrom64 % div64;

                if (0 != checkOrRealloc(pResult, 8))
                {
                    return INT_ALLOCATION_ERROR;
                }

                *((uint64_t *)pFrom) = rest64;
                *((uint64_t *)pResult->data.pBytes) = result64;
                adjust(pRest);
                adjust(pResult);
#if INT_DEBUG_SHOW_DIV
                logStack = getLine();
                if (logStack != NULL)
                {
                    snprintf(logStack, STACK_LINE_SIZE, "(=)%lu / %lu = %lu (%lu)\n",
                             divFrom64, div64, result64, rest64);
                }
#endif
                return 0;
            }
            if (0 != checkOrRealloc(pResult, a - b + 1))
            {
                return INT_ALLOCATION_ERROR;
            }
            pTo = pResult->data.pBytes;

            clear2(pTo, pResult->size);
            clear2(pFrom, pRest->size);
#if 0
            pTemp = getTempMemory(pSrc->used_size);
            if (pTemp == NULL)
            {
                return INT_ALLOCATION_ERROR;
            }
#endif
            pTemp = pSrc1Chars;
            pFromEnd = pTemp + (a - b);
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

#if INT_DEBUG_SHOW_DIV
                logStack = getLine();
                if (logStack != NULL)
                {
                    snprintf(logStack, STACK_LINE_SIZE, "(S)%lu / %lu = %lu (%lu)\n",
                             divFrom64, div64, result64, rest64);
                }
#endif
                *pTo = (unsigned char)result64 & 0xFF;
                divFrom64 = rest64;
                ++pTo;
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

#if INT_DEBUG_SHOW_DIV
            logStack = getLine();
            if (logStack != NULL)
            {
                snprintf(logStack, STACK_LINE_SIZE, "(E)%lu / %lu = %lu (%lu)\n",
                         divFrom64, div64, result64, rest64);
            }
#endif
            if (result64 >= 0x100)
            {
                // pResult->data.pBytes[i]
                *pTo = (unsigned char)((result64 >> 8) & 0xFF);
                ++pTo;
                ++i;
            }
            // pResult->data.pBytes[i]
            *pTo = (unsigned char)result64 & 0xFF;
            ++pTo;
            ++i;
            reverseUCharArray(pResult->data.pBytes, i);
            //pResult->used_size = i;
            *((uint64_t *)pRest->data.pBytes) = rest64;
            adjust(pRest);
            adjust(pResult);
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

uint64_t fromBytes(void *pData, unsigned int size)
{
    if (size > 8)
    {
        size = 8;
    }
    uint64_t result = 0;
    unsigned int i = 0;
    unsigned char *pBytes = (unsigned char *)pData;
    if (size >= 4)
    {
        result = *((uint32_t *)pBytes);
        i = 32;
        pBytes += 4;
    }
    size <<= 3;
    while (i < size)
    {
        result |= ((uint64_t)(*pBytes)) << i;
        ++pBytes;
        i += 8;
    }
    return result;
}
