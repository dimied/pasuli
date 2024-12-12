
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../util/memory.h"
#include "../util/output.h"
#include "myint.h"
#include "../util/log_stack.h"

#if USE_TEMP_MEMORY

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
#endif

#if USE_TEMP_MEMORY
void myintCleanup()
{
    if (tempMemory != NULL)
    {
        free(tempMemory);
        tempMemory = NULL;
    }
    tempMemorySize = 0;
}
#endif

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
    clear2(pMyInt, sizeof(MYINT));
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
        unsigned int s = pData->size;
        if (pChars != NULL && s != 0)
        {
            pChars += s;
            --pChars;

            while (s > 0 && *pChars == 0)
            {
                --s;
                --pChars;
            }
            pData->used_size = s;
        }
    }
}

int intOps = 0;

unsigned char *myintClearBytes(MYINT *pSrc)
{
    clear2(pSrc->data.pBytes, pSrc->size);
    return pSrc->data.pBytes;
}

int myintOpShort(int op, MYINT *pSrc)
{
    return myintOp(op, pSrc, NULL, NULL, NULL);
}

int myintInit(MYINT *pMyInt)
{
    nullifyMyInt(pMyInt);
    int res = checkOrRealloc(pMyInt, INITIAL_INIT_SIZE);
    if (res)
    {
        return res;
    }
    myintClearBytes(pMyInt);
    return res;
}

int myintInitMany(int num, MYINT **pMyInt)
{
    for (int i = 0; i < num; i++)
    {
        int res = myintInit(pMyInt[i]);
        if (res)
        {
            return res;
        }
    }
    return 0;
}

int myintClear(MYINT *pSrc)
{
    int res = myDataOp(REALLOC_FREE, (unsigned char **)&pSrc->data.pBytes, 0, 0);
    if (res == 0)
    {
        pSrc->size = 0;
        pSrc->used_size = 0;
#if 0
        if (pSrc->rest != NULL)
        {
            res = myintClear(pSrc->rest);
        }
#endif
    }
    return res;
}

int myintStoreRest(MYINT *pRest, uint64_t restValue)
{
    if (restValue > 0)
    {
        if (pRest != NULL)
        {
            if (0 != checkOrRealloc(pRest, 8))
            {
                return INT_ALLOCATION_ERROR;
            }
            void *pFrom = myintClearBytes(pRest);
            *((uint64_t *)pFrom) = restValue;
            return 0;
        }
        return INT_MISSING_REST;
    }
    return 0;
}

int myintOp(int op, MYINT *pSrc, MYINT *pSrc2, MYINT *pResult, MYINT *pRest)
{
#if 0
    if (intOps > 0)
    {
        printf("OP: %x\n", op);
    }
#endif
    int res = 1;

    unsigned int sizeVal, resultValue = 0, resIdx = 0, i = 0, a = 0, b = 0, t = 0;
    // MYINT *pRest = NULL;
    unsigned char *pSrc1Chars = pSrc->data.pBytes, *pSrc2Chars = pSrc2->data.pBytes;
    unsigned char *pFrom, *pFromEnd, *pSub, *pTo, *pTemp;
    int diff;

#if INT_DEBUG_SHOW_CMP || INT_DEBUG_SHOW_SUB || INT_DEBUG_SHOW_DIV
    char *logStack;
#endif
#if USE_AB_INIT
    if (op >= INT_OP_CMP_ABS && op <= INT_OP_DIV)
    {
        adjust(pSrc);
        adjust(pSrc2);
        a = pSrc->used_size;
        b = pSrc2->used_size;
    }
#endif
    res = INT_COMMAND_ERROR;

    switch (op)
    {
    case INT_OP_ZERO:
        myintClearBytes(pSrc);
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
#if USE_AB_INIT != 1
        a = pSrc->used_size;
        b = pSrc2->used_size;
#endif
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
        // same length, check bytes
        if (a != 0)
        {
            --a;
            pSrc1Chars += a;
            pSrc2Chars += a;
            ++a;
            do
            {
                diff = (int)(*pSrc1Chars) - (int)(*pSrc2Chars);
                if (diff < 0)
                {
                    return INT_RESULT_CMP_LESS;
                }
                else if (diff > 0)
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
#if USE_AB_INIT != 1
        a = pSrc->used_size;
        b = pSrc2->used_size;
#endif
        sizeVal = a < b ? b : a;
        ++sizeVal;

        res = checkOrRealloc(pResult, sizeVal);
        if (res)
        {
            return res;
        }

        pFrom = myintClearBytes(pResult);
        memcpy(pFrom, pSrc1Chars, a);

#define ADD_BY_PTR_CMP 0

#if ADD_BY_PTR_CMP
        pFromEnd = pSrc2Chars + b - 1;
        while (pSrc2Chars <= pFromEnd)
#else
        for (; i < b; ++i)
#endif
        {
            resultValue += (unsigned int)(*pFrom) + (unsigned int)(*pSrc2Chars);

            *pFrom = (unsigned char)(resultValue & 0xFF);
            resultValue >>= 8;
            ++pFrom;
            ++pSrc2Chars;
        }

        while (resultValue > 0)
        {
            resultValue = (unsigned int)(*pFrom) + resultValue; //(resultValue & 0xFF);
            *pFrom = (unsigned char)(resultValue & 0xFF);
            resultValue >>= 8;
            ++pFrom;
        }

        adjust(pResult);
        return 0;
    case INT_OP_SUB:
#if USE_AB_INIT != 1
        a = pSrc->used_size;
        b = pSrc2->used_size;
#endif
        res = myintOp(INT_OP_CMP_ABS, pSrc, pSrc2, NULL, NULL);
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
            myintClearBytes(pResult);
#if INT_DEBUG_SHOW_SUB
            logStack = getLine();
            if (logStack != NULL)
            {
                snprintf(logStack, STACK_LINE_SIZE - 1, "EQUAL\n");
            }
#endif
            return 0;
        }

#if INT_DEBUG_SHOW_SUB
        printf("ALLOC RESULT!\n");
#endif
        res = checkOrRealloc(pResult, a);
        if (res)
        {
            return res;
        }

        pFrom = myintClearBytes(pResult);
        // pFrom = pResult->data.pBytes;
        // clear2(pFrom, pResult->size);

        memcpy(pFrom, pSrc1Chars, a);
#if 0
        pFromEnd = pFrom + a - 1;
        while (*pFromEnd == 0 && pFrom != pFromEnd)
        {
            --pFromEnd;
            --a;
        }
#endif
        pResult->used_size = a;

        pSub = pSrc2Chars;
        diff = 0;
        while (b > 0)
        {
            diff = (int)(*pFrom) - (int)(*pSub) - diff;

            if (diff < 0)
            {
                diff += 0x200;
            }
            *pFrom = (unsigned char)(diff & 0xFF);
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
            *pFrom = (unsigned char)(diff & 0xFF);
            diff >>= 8;
            ++pFrom;
            --a;
        }
        // pFrom = pResult->data.pBytes;
        if (diff > 0)
        {
            myintClearBytes(pResult);
            // clear2(pFrom, pResult->size);
            pResult->used_size = 0;
            return 1;
        }

        adjust(pResult);
        return 0;

    case INT_OP_MUL:
#if USE_AB_INIT != 1
        a = pSrc->used_size;
        b = pSrc2->used_size;
#endif
        sizeVal = a + b;
        res = checkOrRealloc(pResult, sizeVal);
        if (res)
        {
            return res;
        }
        pFrom = myintClearBytes(pResult);
        // pFrom = pResult->data.pBytes;
        // clear2(pFrom, pResult->size);

        if (b == 0)
        {
            pResult->used_size = 0;
            return 0;
        }

        for (; i < a; i++)
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
#if USE_AB_INIT != 1
        adjust(pSrc);
        adjust(pSrc2);
        a = pSrc->used_size;
        b = pSrc2->used_size;
#endif
        // Division by zero?
        if (0 == b || ((b == 1) && (*pSrc2Chars) == 0))
        {
            return 1;
        }

#if 0
        if(pRest == NULL) {

        }
        res = myDataOp(REALLOC_ALLOC_IF_NEEDED | REALLOC_NULLIFY, (unsigned char **)&pResult->rest, sizeof(MYINT), 0);
        if (res)
        {
            return INT_ALLOCATION_ERROR;
        }
        //pRest = pResult->rest;
#else
        // MYINT *pRest = pResult->rest;
        if (pRest == NULL)
        {
            pRest = (MYINT *)malloc(sizeof(MYINT));
            if (pRest == NULL)
            {
                return INT_ALLOCATION_ERROR;
            }
            nullifyMyInt(pRest);
            // pResult->rest = pRest;
        }
#endif
        res = myintOp(INT_OP_CMP_ABS, pSrc, pSrc2, NULL, NULL);
        pResult->sign = 0;

        pFrom = myintClearBytes(pRest);
        // pFrom = pRest->data.pBytes;
        // clear2(pFrom, pRest->size);
        pRest->used_size = 0;
#if INT_DEBUG_SHOW_DIV
        logStack = getLine();
        if (logStack != NULL)
        {
            snprintf(logStack, STACK_LINE_SIZE - 1, "SRC: %i|SRC2: %i\n", a, b);
        }
#endif

        // pTo = pResult->data.pBytes;

        if (res == INT_RESULT_CMP_LESS)
        {
            myintClearBytes(pResult);
            // clear2(pTo, pResult->size);
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
            res = checkOrRealloc(pResult, 4);
            if (res)
            {
                return res;
            }
#if 0
            if (pTo == NULL)
            {
                res = myDataOp(REALLOC_ALLOC_IF_NEEDED, (unsigned char **)&pResult->data.pBytes, 4, 0);
                if (res)
                {
                    return res;
                }
            }
#endif
            myintClearBytes(pResult);
            // clear2(pResult->data.pBytes, pResult->size);
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

            pTo = myintClearBytes(pResult);

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

                *((uint64_t *)pResult->data.pBytes) = result64;

                res = myintStoreRest(pRest, rest64);
#if INT_DEBUG_SHOW_DIV
                logStack = getLine();
                if (logStack != NULL)
                {
                    snprintf(logStack, STACK_LINE_SIZE, "(=)%lu / %lu = %lu (%lu)\n",
                             divFrom64, div64, result64, rest64);
                }
#endif
                // return 0;
                break;
            }
            if (0 != checkOrRealloc(pResult, a - b + 2))
            {
                return INT_ALLOCATION_ERROR;
            }

            pTo = myintClearBytes(pResult);
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
                *pTo = (unsigned char)(result64 & 0xFF);
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
            // pResult->used_size = i;
#if 0
            if (rest64 > 0)
            {
                if (0 != checkOrRealloc(pRest, 8))
                {
                    return INT_ALLOCATION_ERROR;
                }
                pFrom = myintClearBytes(pRest);
                *((uint64_t *)pFrom) = rest64;
            }
#endif

            res = myintStoreRest(pRest, rest64);
            break;
            // adjust(pRest);
            // adjust(pResult);
            // return 0;
            //  printf("N: %x\n", divFrom64);

            // free(pTemp);
        }
#endif
    }
    if (res == 0 && op == INT_OP_DIV)
    {
        adjust(pRest);
        adjust(pResult);
        return 0;
    }
    return res;
    // return INT_COMMAND_ERROR;
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
