
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
