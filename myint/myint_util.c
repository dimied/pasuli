

#include "myint_util.h"


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