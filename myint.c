
#include <stdio.h>
#include "memory.h"
#include "myint.h"

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

int myintOp(int op, MYINT *pSrc, MYINT *pSrc2, MYINT *pResult)
{
    int res, initOrClear = op & INT_OP_INIT_ALL;
    if (initOrClear != 0 && op >= INT_OP_INIT_SRC && op <= INT_OP_INIT_ALL)
    {
        if (INT_INTERNAL_CHECK_INIT(initOrClear, INT_OP_INIT_RESULT))
        {
            // printf("INIT RES\n");
            res = myintOp(INT_OP_INIT_SRC, pResult, pSrc2, pResult);
            if (res)
            {
                return res;
            }
        }

        if (INT_INTERNAL_CHECK_INIT(initOrClear, INT_OP_INIT_SRC2))
        {
            // printf("INIT SRC2\n");
            myintOp(INT_OP_INIT_SRC, pSrc2, pSrc2, pResult);
            if (res)
            {
                return res;
            }
        }

        if (INT_INTERNAL_CHECK_INIT(initOrClear, INT_OP_INIT_SRC))
        {
            // printf("INIT SRC\n");
            clear2(pSrc, sizeof(MYINT));
            if (myDataOp(REALLOC_ALLOC, (unsigned char **)&pSrc->data.pBytes, INITIAL_INIT_SIZE, 0))
            {
                return 1;
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

        if (INT_INTERNAL_CHECK_CLEAR(initOrClear, INT_OP_CLEAR_RESULT))
        {
            myintOp(INT_OP_CLEAR_SRC, pResult, pSrc2, pResult);
        }

        if (INT_INTERNAL_CHECK_CLEAR(initOrClear, INT_OP_CLEAR_SRC2))
        {
            myintOp(INT_OP_CLEAR_SRC, pSrc2, pSrc2, pResult);
        }

        if (INT_INTERNAL_CHECK_CLEAR(initOrClear, INT_OP_CLEAR_SRC))
        {
            myDataOp(REALLOC_FREE, (unsigned char **)&pSrc->data.pBytes, 0, 0);
            // myDataOp(REALLOC_FREE, (unsigned char **)&pSrc->pBuffer, 0, 0);
            pSrc->size = 0;
            pSrc->used_size = 0;
            // pSrc->buffer_size = 0;

            if (pSrc->rest != NULL)
            {
                myintOp(INT_OP_CLEAR_SRC, pSrc->rest, NULL, NULL);
            }
        }
        return 0;
    }

    unsigned int sizeVal, resultValue = 0, i, a, b;
    unsigned char *pSrc1Chars = pSrc->data.pBytes, *pSrc2Chars = pSrc2->data.pBytes;

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
        if (a < b)
        {
            return INT_RESULT_CMP_LESS;
        }
        if (a > b)
        {
            return INT_RESULT_CMP_GREATER;
        }

        i = a - 1;
        /// if a and b have the same degree check each degree individually
        while (i >= 0)
        {
            a = pSrc->data.pBytes[i];
            b = pSrc2->data.pBytes[i];
            if (a < b)
            {
                return INT_RESULT_CMP_LESS;
            }
            if (a > b)
            {
                return INT_RESULT_CMP_GREATER;
            }
            --i;
        }
        return INT_RESULT_CMP_EQUAL;

    case INT_OP_ADD:
        // printf("ADD!\n");
        sizeVal = pSrc->used_size < pSrc2->used_size ? pSrc->used_size : pSrc2->used_size;

        res = checkOrRealloc(pResult, sizeVal);
        if (res)
        {
            return res;
        }
        a = pSrc->used_size;
        b = pSrc2->used_size;

        for (i = 0; i < sizeVal; i++)
        {
            if (i < a)
            {
                resultValue += pSrc->data.pBytes[i];
            }
            if (i < b)
            {
                resultValue += pSrc2->data.pBytes[i];
            }
            // printf("SUM = %i|%x\n", resultValue, resultValue);
            pResult->data.pBytes[i] = resultValue & 0xFF;
            resultValue >>= 8;
        }

        pResult->used_size = i;

        if (resultValue > 0)
        {
            res = checkOrRealloc(pResult, i + 1);
            if (res)
            {
                return res;
            }
            pResult->data.pBytes[i] = resultValue & 0xFF;
        }

        return 0;
    case INT_OP_SUB:
        // printf("ADD!\n");
        sizeVal = pSrc->used_size < pSrc2->used_size ? pSrc->used_size : pSrc2->used_size;
        break;
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
        unsigned int resIdx = 0, resIdx2 = 0;

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
    clear2(pResult, resultLength);

    if (pSrc->used_size == 0)
    {
        *pResult = '0';
        return 0;
    }

    unsigned char *p = pSrc->data.pBytes;
    if (pSrc->used_size == 1 && (*p) < 10)
    {
        *pResult = '0' + (*p);
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

#define VALUE(V)   ((V)&0xF)
#define EXP_VALUE(V)   ((V)>>4)
    // start from the end and move it later to the beginning
    unsigned char* pResultUC = (unsigned char*)pResult;
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
        printf("@%i = %i|%x\n", i, val, val);

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
                    //b = EXP_VALUE(*pLast) + EXP_VALUE(*(pLast - 1)) * 10 + EXP_VALUE(*(pLast - 2)) * 100 + EXP_VALUE(*(pLast - 3)) * 1000;
                    //printf("BIT-E^ %i|%u (%u)\n", currentByteShift, b, numShifts);
                    
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
                //b = EXP_VALUE(*pLast) + EXP_VALUE(*(pLast - 1)) * 10 + EXP_VALUE(*(pLast - 2)) * 100 + EXP_VALUE(*(pLast - 3)) * 1000;
                //printf("BIT~ %i|%u\n", currentByteShift, b);
                overflow = 0;
                pLastCurrent = pLast;
                unsigned char* pResultFrontUC = pResultUC;
                //Find non-zero in result
                while (pResultFrontUC != pLast)
                {
                    if(VALUE(*pResultFrontUC) != 0) {
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
                } else {

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
    } while (i < pSrc->used_size);

    if (currentByteShift > 8)
    {
        clear2(pResult, resultLength);
        return 1;
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
    printf("FOUND AFTER: %i | %i  | %p %p\n", a, *pLastCurrent, pLastCurrent, pLast);
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
        printf("MOVED %i\n", a);
        a = 0;
        while (pResultUC != pLast)
        {
            *pResultUC = 0;
            ++pResultUC;
            a++;
        }
        printf("ZERO %i\n", a);
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