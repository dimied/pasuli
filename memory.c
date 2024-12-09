
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

void clear2(void *pData, unsigned int size)
{
    if (pData != NULL)
    {
        unsigned char *pChars = (unsigned char *)pData;
        unsigned char *pCharsEnd = pChars + size;
        while (pChars != pCharsEnd)
        {
            *pChars = 0;
            ++pChars;
        }
    }
}


int myDataOp(int op, unsigned char **pData, unsigned int size, unsigned int oldSize)
{
    void *pMem;
    switch (op)
    {
    case REALLOC_ALLOC:
        // printf("TRY ALLOC %i for %p\n", size, pData);
        pMem = malloc(size);
        if (pMem != NULL)
        {
            *pData = (unsigned char *)pMem;
            return 0;
        }
        break;
    case REALLOC_FREE:
        if (*pData != NULL)
        {
            printf("FREE?");
            free(*pData);
            *pData = NULL;
            printf("FREE!\n");
            return 0;
        }
        break;
    case REALLOC_REALLOC:
        // printf("TRY REALLOC %i for %p\n", size, pData);
        pMem = malloc(size);
        if (pMem != NULL)
        {
            if (*pData != NULL)
            {
                memcpy(pMem, *pData, oldSize);
                myDataOp(REALLOC_FREE, pData, 0, 0);
            }
            *pData = (unsigned char *)pMem;
            return 0;
        }
        break;
    }
    return 1;
}
