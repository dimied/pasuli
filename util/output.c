
#include <stdio.h>
#include "output.h"
#include "memory.h"


void sprintHex(unsigned char *vals, unsigned int sss, char *pResult, unsigned int size)
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

void printResultLine(int t, float u, float v, float *pRes)
{
    printf("%i| (%.4f %.4f) -> (%.8f %.8f %.8f)\n", t, u, v, pRes[0], pRes[1], pRes[2]);
}
