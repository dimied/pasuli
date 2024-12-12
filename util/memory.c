

#include "memory.h"
#if USE_MY_DATA_OP_DEBUG
#include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>

#define REALLOC_NULL_CHECK 0

#ifndef USE_NO_REGISTER
#define USE_NO_REGISTER 1
#endif

#if USE_NO_REGISTER
#define REGISTER
#else
#define REGISTER register
#endif

void clear2(void *pData, unsigned int size)
{
    if (pData != NULL)
    {
#if USE_FAST_CLEAR_MEM
        REGISTER unsigned char *pChars;
        REGISTER unsigned int *pUInts = (unsigned int *)pData;
        while (size > 3)
        {
            *pUInts = 0;
            ++pUInts;
            size -= 4;
        }
        pChars = (unsigned char *)pUInts;
        while (size > 0)
        {
            *pChars = 0;
            ++pChars;
            --size;
        }
#else
        memset(pData, 0, size);
#endif
    }
}

int myDataOp(int op, unsigned char **pData, unsigned int size, unsigned int oldSize)
{
    if (pData == NULL)
    {
        return DATA_OP_RESULT_PARAM_INVALID;
    }
    unsigned char *pMem = *pData, *pMem2;
#if REALLOC_NULL_CHECK
    if ((op & (REALLOC_FREE | REALLOC_INVERT)) != 0 && pMem == NULL)
    {
        return 1;
    }
#endif
    int res = DATA_OP_RESULT_INVALID;

    switch (op & REALLOC_NULLIFY_MASK)
    {
    case REALLOC_ALLOC_IF_NEEDED:
        if (pMem != NULL)
        {
            return DATA_OP_RESULT_OK;
        }
    case REALLOC_ALLOC:
        pMem = (unsigned char *)malloc(size);
        if (pMem != NULL)
        {
            *pData = pMem;
            res = DATA_OP_RESULT_OK;
            // return DATA_OP_RESULT_OK;
        }
        break;
    case REALLOC_FREE:
#if REALLOC_NULL_CHECK != 1
        if (pMem != NULL)
        {
#endif
#if USE_MY_DATA_OP_DEBUG
            printf("FREE?");
#endif
            free(pMem);
            *pData = NULL;
#if USE_MY_DATA_OP_DEBUG
            printf("FREE!\n");
#endif
            res = DATA_OP_RESULT_OK;
            // return DATA_OP_RESULT_OK;
#if REALLOC_NULL_CHECK != 1
        }
        break;
#endif

    case REALLOC_REALLOC:
#if USE_REALLOC_NO_COPY
    case REALLOC_REALLOC_NO_COPY:
#endif
        // printf("TRY REALLOC %i for %p\n", size, pData);
        pMem2 = (unsigned char *)malloc(size);
        if (pMem2 != NULL)
        {
            if (pMem != NULL)
            {
#if USE_REALLOC_NO_COPY
                if (op != REALLOC_REALLOC_NO_COPY)
                {
#endif
                    memcpy(pMem2, pMem, oldSize);
#if USE_REALLOC_NO_COPY
                }
#endif
                free(pMem);
            }
            *pData = pMem2;
            res = DATA_OP_RESULT_OK;
            // return DATA_OP_RESULT_OK;
        }
        break;
    case REALLOC_INVERT:
#if REALLOC_NULL_CHECK != 1
        if (pMem != NULL)
        {
#endif
            while (size > 0)
            {
                *pMem = ~(*pMem);
                ++pMem;
                --size;
            }
            res = DATA_OP_RESULT_OK;
            // return DATA_OP_RESULT_OK;
#if REALLOC_NULL_CHECK != 1
        }
        break;
#endif
    }
    if (res == 0 && ((op & REALLOC_NULLIFY) != 0))
    {
        clear2(*pData, size);
    }
    return res;
}
